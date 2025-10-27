module shift (
    input clk,
    input en,
    input [2:0] ctrl,
    input [7:0] din,
    input in1,               // 拓展控制位，用于带输入移位
    output reg [7:0] dout
);

    always @(posedge clk) begin
        if (en) begin
            case (ctrl)
                3'b000: dout <= 8'b00000000;                 // 清零
                3'b001: dout <= din;                         // 置数
                3'b010: dout <= {1'b0, dout[7:1]};           // 逻辑右移
                3'b011: dout <= {dout[6:0], 1'b0};           // 逻辑左移
                3'b100: dout <= {dout[0], dout[7:1]};        // 循环右移
                3'b101: dout <= {dout[6:0], dout[7]};        // 循环左移
                3'b110: dout <= {in1, dout[7:1]};            // 带输入位右移
                3'b111: dout <= {dout[6:0], in1};            // 带输入位左移
                default: dout <= dout;
            endcase
        end
    end
endmodule
