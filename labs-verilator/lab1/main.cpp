#include "Vmux241.h"
#include "verilated.h"
#include "verilated_vcd_c.h"  // 引入波形头文件
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Verilated::traceEverOn(true);          // 启用波形追踪

    Vmux241* top = new Vmux241;
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 0);                     // 绑定信号
    tfp->open("wave.vcd");                  // 设置波形文件名

    // 模拟 4 个不同的选择信号 s
    for (int i = 0; i < 4; i++) {
        top->a0 = 0b00;
        top->a1 = 0b01;
        top->a2 = 0b10;
        top->a3 = 0b11;
        top->s  = i;

        top->eval();            // 模拟求值
        tfp->dump(i);           // 每个周期 dump 一帧波形

        std::cout << "s = " << i << ", y = " << (int)top->y << std::endl;
    }

    tfp->close();               // 关闭波形文件
    delete tfp;
    delete top;

    return 0;
}
