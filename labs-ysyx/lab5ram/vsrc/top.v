module top (
    input clk,           // 通常接 KEY[0]，每次按一下为一个时钟沿
    input [7:0] sw,      // SW[7:0]：输入数据
    input [3:0] addr,    // SW[3:0]：选择地址
    input we,            // SW[9]：写使能
    output [6:0] seg0,   // 显示低位
    output [6:0] seg1    // 显示高位
);

    wire [7:0] dout;

    regfile u_rf (
        .clk(clk),
        .we(we),
        .addr(addr),
        .din(sw),
        .dout(dout)
    );

    bcd7seg u_seg0 (
        .b(dout[3:0]),
        .h(seg0)
    );

    bcd7seg u_seg1 (
        .b(dout[7:4]),
        .h(seg1)
    );

endmodule
