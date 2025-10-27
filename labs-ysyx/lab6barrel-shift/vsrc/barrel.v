module barrel (
    input  [7:0] din,         // 输入数据
    input  [2:0] shamt,       // 移位量
    input  [1:0] ctrl,        // 移位控制类型
    output reg [7:0] dout     // 输出数据
);

    always @(*) begin
        case (ctrl)
            2'b00: dout = din << shamt;  // 逻辑左移
            2'b01: dout = din >> shamt;  // 逻辑右移
            2'b10: dout = (din << shamt) | (din >> (8 - shamt)); // 循环左移
            2'b11: dout = (din >> shamt) | (din << (8 - shamt)); // 循环右移
            default: dout = din;
        endcase
    end

endmodule
