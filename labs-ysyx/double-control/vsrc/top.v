// top.v	
//双控开关
module top(
  input a,  // 输入端口
  input b,  // 输入端口
  output f  // 输出端口
);
  assign f = a ^ b;  // 功能实现
endmodule  // 模块定义结束
