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
    usleep(100);  // 此为500HZ。换算公式为f=5*10^5/u,u越大，f越小，T越长；控制模拟时钟频率，等待1000微秒，等待1毫秒，翻转两次才是一个周期还要乘以2
  }
  
  return 0;
}
