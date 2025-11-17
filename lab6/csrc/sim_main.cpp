#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"

#define MAX_SIM_TIME 100000
#define CLK_PERIOD 10

vluint64_t simtime = 0;

// 时钟驱动函数
void tick_clk(Vtop* top, VerilatedVcdC* tfp){
    // 高电平
    top->clk = 1;
    simtime += CLK_PERIOD / 2;
    top->eval();
    tfp->dump(simtime);

    // 低电平
    top->clk = 0;
    simtime += CLK_PERIOD / 2;
    top->eval();
    tfp->dump(simtime);
}

// 生成按钮脉冲函数
void generate_button_pulse(Vtop* top, VerilatedVcdC* tfp) {
    // 按钮按下
    top->button = 1;
    for(int i = 0; i < 5; i++) {  // 保持5个时钟周期
        tick_clk(top, tfp);
    }
    
    // 按钮释放
    top->button = 0;
    for(int i = 0; i < 20; i++) {  // 释放后等待20个时钟周期
        tick_clk(top, tfp);
    }
}

int main(int argc, char** argv){
    // 初始化Verilator
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    
    // 创建顶层模块实例
    Vtop* top = new Vtop;
    
    // 创建波形跟踪文件
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 0);  // 99 = 跟踪深度
    tfp->open("build/waveform.vcd");
    
    // 初始化信号
    top->clk = 0;
    top->reset_n = 0;  // 复位
    top->button = 0;
    
    // 保持复位状态
    for(int i = 0; i < 10; i++) {
        tick_clk(top, tfp);
    }
    
    // 释放复位
    top->reset_n = 1;
    tick_clk(top, tfp);
    
    // 生成足够的按钮脉冲以完成一个完整周期 (255个状态)
    for(int t = 0; t < 300; t++){
    	generate_button_pulse(top, tfp);
    }
    
    top->eval();
    tfp->dump(simtime);

    
    // 清理
    tfp->close();
    delete top;
    delete tfp;

    return 0;
}