module top (
  input  [7:0] SW,     // SW0~SW7
  input        SW8,    // 使能信号
  output [2:0] LEDR,   // 编码结果
  output       LED4,   // 有效指示灯
  // output       LED8,   // LED8 对应 SW8,只是举一反三
  output [6:0] HEX0    // 数码管显示
);

  encoder_8_3 u_encoder (
    .x(SW),
    .en(SW8),
    .y(LEDR),
    .valid(LED4)
  );

  seg u_seg (
    .b(LEDR),  
    .h(HEX0)  
  );

  // assign LED8 = SW8;

endmodule
