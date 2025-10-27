module shift (
    input clk,
    input en,
    input [2:0] ctrl,
    input [7:0] din,
    output reg [7:0] dout
);

    always @(posedge clk) begin
        if (en) begin
            case (ctrl)
                3'b001: dout <= din;                  // 置数
                3'b010: dout <= {1'b0, dout[7:1]};    // 逻辑右移
                default: dout <= dout;               // 其他指令不处理
            endcase
        end
    end
endmodule