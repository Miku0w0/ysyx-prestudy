module top (
  input  [7:0] SW,     // SW0~SW7
  input        SW8,    // 使能信号
  output [2:0] LEDR,   // 编码结果
  output       LED4,   // 有效指示灯
  output [6:0] HEX0    // 数码管显示
);

  wire [2:0] y;
  wire       valid;

  encoder38 u_encoder (
    .x(SW),
    .en(SW8),
    .y(y),
    .valid(valid)
  );

  assign LEDR = y;
  assign LED4 = valid;

  seg u_seg (
    .b({1'b0, y}),  // 扩展成 4 位输入给译码器
    .h(HEX0)
  );

endmodule
