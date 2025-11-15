#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"

vluint64_t sim_time = 0;

int main(int argc, char** argv){
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);
	
	Vtop* top = new Vtop;
	
	VerilatedVcdC* tfp = new VerilatedVcdC;
    	top->trace(tfp, 0);  
    	tfp->open("build/waveform.vcd");  


    	top->x0 = 0x00;
    	top->x1 = 0x01;
    	top->x2 = 0x02;
    	top->x3 = 0x03;
    	
    	struct TestCase {
        uint8_t y;    // 控制信号Y
        uint8_t exp_f;// 预期输出F
    	} test_cases[] = {
        {0x00, 0x00},  // Y=00 → F=X0=00
        {0x01, 0x01},  // Y=01 → F=X1=01
        {0x02, 0x02},  // Y=10 → F=X2=10
        {0x03, 0x03}   // Y=11 → F=X3=11
    	};
    	
    	int num_tests = sizeof(test_cases)/sizeof(test_cases[0]);
    	
    	for (int i = 0; i < num_tests; i++) {
        // 设置当前测试用例的控制信号Y
        top->y = test_cases[i].y;
        
        // 评估设计（计算输出）
        top->eval();
        
        tfp->dump(sim_time);
        sim_time += 10;  // 时间步长10ns
    	}
    	
    	// 仿真结束处理
    	tfp->dump(sim_time);  // 最后一步波形
    	
    	// 资源清理
    	tfp->close();
    	delete tfp;
    	delete top;
    	//Verilated::exit(0);
    	return 0;

}