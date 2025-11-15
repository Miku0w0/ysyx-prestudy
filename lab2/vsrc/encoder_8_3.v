module encoder_8_3 ( // 编码器，位数8->3,编码为更少的输出位
  input  [7:0] x,
  input  en,  
  output reg [2:0] y,  
  output reg valid  // 有效信号
);
  integer i;
  always @(*) begin
    y = 3'b000;
    valid = 0;
    if (en) begin
      for (i = 7; i >= 0; i = i - 1) begin //高位优先循环开头逻辑
        if (x[i]) begin  
          y = i[2:0];  //开关编号用3位二进制表示
          valid = 1;  //至少出现一次1，有效信号
          break;  //高位优先，找到即停
        end
      end
    end
  end
endmodule
