#include <nvboard.h>
#include <Vtop.h>

// 定义顶层模块实例
static TOP_NAME dut;

// 声明引脚绑定函数（由NVBoard自动生成）
void nvboard_bind_all_pins(TOP_NAME* top);

// 单时钟周期模拟函数

static void single_cycle() {
  dut.clk = 0;  // 时钟拉低
  dut.eval();   // 评估电路状态
  dut.clk = 1;  // 时钟拉高
  dut.eval();   // 评估电路状态
}

// 复位函数：维持复位状态n个时钟周期

static void reset(int n) {
  dut.rst_n = 0;  // 激活复位（高电平有效，根据实际设计可能需要修改）
  while (n-- > 0) {
    single_cycle();  // 执行n个复位周期
  }
  dut.rst_n = 1;  // 释放复位
}


int main() {
  // 绑定引脚并初始化NVBoard
  nvboard_bind_all_pins(&dut);
  nvboard_init();

  // 执行复位（10个时钟周期）
  reset(10);

  // 主仿真循环
  while (1) {
    // 更新NVBoard状态（读取输入设备）
    nvboard_update();
    dut.eval();
    
    // 执行一个时钟周期
    single_cycle();
  }

  // 清理NVBoard资源（实际不会执行到这里，因为上面是无限循环）
  nvboard_quit();
  return 0;
}