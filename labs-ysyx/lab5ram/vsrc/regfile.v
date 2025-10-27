module regfile (
    input clk,
    input we,
    input [3:0] addr,       // 16个地址
    input [7:0] din,        // 输入数据
    output [7:0] dout       // 异步读出
);
    reg [7:0] ram [15:0];

    // 初始化寄存器堆内容
    initial begin
        $readmemh("vsrc/mem1.txt", ram, 0, 15);
    end

    // 写操作（上升沿）
    always @(posedge clk) begin
        if (we)
            ram[addr] <= din;
    end

    // 异步读
    assign dout = ram[addr];
endmodule
