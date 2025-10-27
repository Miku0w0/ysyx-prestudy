module mux241(
    input  [1:0] a0,   // 第一组2位输入
    input  [1:0] a1,   // 第二组2位输入
    input  [1:0] a2,   // 第三组2位输入
    input  [1:0] a3,   // 第四组2位输入
    input  [1:0] s,    // 2位选择信号
    output reg [1:0] y // 2位输出
);

always @(*) begin
    case (s)
        2'b00: y = a0;
        2'b01: y = a1;
        2'b10: y = a2;
        2'b11: y = a3;
        default: y = 2'b00; // 安全兜底
    endcase
end

endmodule
