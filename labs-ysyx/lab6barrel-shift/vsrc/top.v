module top (
    input clk,
    input btn,                // BTNC
    input [9:0] sw,           // SW9~SW8=ctrl, SW2~SW0=shamt, SW7~SW3=din高位保留，SW7~SW0完整数据
    output [6:0] seg0,
    output [6:0] seg1,
    output [7:0] led
);

    wire [7:0] dout;

    // 实例化桶形移位器
    barrel u_barrel (
        .din(sw[7:0]),
        .shamt(sw[2:0]),
        .ctrl(sw[9:8]),
        .dout(dout)
    );

    // LED 直接显示 dout
    assign led = dout;

    // 数码管显示 dout 高低4位
    bcd7seg u_seg0 (.b(dout[3:0]), .h(seg0));
    bcd7seg u_seg1 (.b(dout[7:4]), .h(seg1));

endmodule
