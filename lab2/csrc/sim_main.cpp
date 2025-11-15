#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"

const unsigned int SIM_TIME = 500;

int main(int argc, char**argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vtop *top = new Vtop;
    
    VerilatedVcdC *trace = new VerilatedVcdC;
    top->trace(trace, 0);  
    trace->open("build/waveform.vcd");  

    
    top->SW = 0;
    top->SW8 = 0;
    unsigned int time = 0;

    // 仿真主循环
    while (time < SIM_TIME && !Verilated::gotFinish()) {
        // 每10个时间单位改变一次输入
        switch(time) {
            case 10:  top->SW8 = 1; break;           // 使能编码器
            case 30:  top->SW = 0b00000001; break;   // 仅I0有效
            case 60:  top->SW = 0b00000011; break;   // I0和I1有效
            case 90:  top->SW = 0b00000100; break;   // 仅I2有效
            case 120: top->SW = 0b00001000; break;   // 仅I3有效
            case 150: top->SW = 0b00010000; break;   // 仅I4有效
            case 180: top->SW = 0b00100000; break;   // 仅I5有效
            case 210: top->SW = 0b01000000; break;   // 仅I6有效
            case 240: top->SW = 0b10000000; break;   // 仅I7有效
            case 270: top->SW = 0b11111111; break;   // 全部有效
            case 300: top->SW = 0b00000000; break;   // 全无效
            case 330: top->SW8 = 0; break;           // 关闭使能
            case 360: top->SW = 0b10000000; break;   // 使能关闭时输入
        }

        // 评估电路
        top->eval();
        
        // 写入波形数据
        trace->dump(time);
        
        // 时间递增
        time++;
    }

    // 清理资源
    trace->close();
    delete top;
    delete trace;
    
    return 0;
}