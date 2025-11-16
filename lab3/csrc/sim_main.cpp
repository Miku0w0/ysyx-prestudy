#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"

const unsigned int TEST_CYCLES = 10;

struct testcase {
    uint8_t a;
    uint8_t b;
    uint8_t ctrl;
};

testcase testcases[] = {
    // 加法测试
    {0b0001, 0b0010, 0b000},
    {0b0111, 0b0001, 0b000},
    {0b1111, 0b1111, 0b000},
    {0b1000, 0b1000, 0b000},
    {0b0100, 0b1101, 0b000},
    
    // 减法测试
    {0b0100, 0b0010, 0b001},  
    {0b0001, 0b1111, 0b001},  
    {0b1000, 0b0001, 0b001},  
    {0b1100, 0b0011, 0b001},  
    
    // 逻辑运算测试
    {0b0000, 0b0000, 0b010},  
    {0b1010, 0b0000, 0b010},  
    {0b1010, 0b1100, 0b011},  
    {0b0000, 0b1111, 0b011},  
    {0b1010, 0b1100, 0b100},  
    {0b0000, 0b0000, 0b100},  
    {0b1010, 0b1100, 0b101},  
    {0b1111, 0b1111, 0b101},  
    
    // 比较测试
    {0b0010, 0b0100, 0b110},  
    {0b0100, 0b0010, 0b110},  
    {0b1000, 0b0111, 0b110},  
    {0b0101, 0b0101, 0b111},  
    {0b0101, 0b0110, 0b111},  
    {0b1000, 0b1000, 0b111}   
};

const int NUM_TEST_CASES = sizeof(testcases) / sizeof(testcase);

int main(int argc, char** argv){
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vtop* top = new Vtop;

    VerilatedVcdC* trace = new VerilatedVcdC;
    top->trace(trace, 0);
    trace->open("build/waveform.vcd");

    vluint64_t time = 0;

    for (int i = 0; i < NUM_TEST_CASES; i++){
        testcase& tc = testcases[i];
        top->a = tc.a;
        top->b = tc.b;
        top->ctrl = tc.ctrl;

        for (int cycle = 0; cycle < TEST_CYCLES; cycle++){
            top -> eval();
            trace -> dump(time++);
        }
    }

    top->eval();
    trace->dump(time);

    trace->close();
    delete top;
    delete trace;

    return 0;   
}