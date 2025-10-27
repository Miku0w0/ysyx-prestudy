#include <nvboard.h>
#include <Vtop.h>

static TOP_NAME dut;

void nvboard_bind_all_pins(TOP_NAME* top);


int main() {
  nvboard_bind_all_pins(&dut);
  nvboard_init();


  while(1) {
    dut.clk = !dut.clk;  // 自己翻转时钟
    dut.eval();
    nvboard_update();
    usleep(100);  // 控制模拟时钟频率
  }
  
  return 0;
}