module top(
    input wire clk,
    input wire rst_n,
    input ps2_clk,
    input ps2_data,

    output wire [6:0] seg0,
    output wire [6:0] seg1,
    output wire [6:0] seg2,
    output wire [6:0] seg3,
    output wire [6:0] seg4,
    output wire [6:0] seg5
);

    // 内部信号
    wire [7:0] key_count;
    wire [7:0] ascii_code;
    wire [7:0] key_code;
    // wire key_press;
    wire key_press_edge;

    // 按键计数模块实例化
    count u_count (
        .clk(clk),
        .rst_n(rst_n),
        .key_press_edge(key_press_edge),
        .key_count(key_count)
    );

    // 键码转ASCII码的ROM模块实例化
    keycode_to_ascii u_keycode_to_ascii (
        .key_code(key_code),
        .ascii_code(ascii_code)
    );
    // PS/2键盘接收模块实例化
    ps2_receiver ps2_receiver_inst (
        .clk(clk),
        .rst_n(rst_n),
        .ps2_clk(ps2_clk),
        .ps2_data(ps2_data),
        .key_code(key_code),
        .key_press(),
        .key_press_edge(key_press_edge)
    );


    // 数码管显示编码模块实例化
    seg u_seg1 (
        .data(key_code[3:0]),
        .seg(seg0)
    );

    seg u_seg2 (
        .data(key_code[7:4]),
        .seg(seg1)
    );

    seg u_seg3 (
        .data(ascii_code[3:0]),
        .seg(seg2)
    );

    seg u_seg4 (
        .data(ascii_code[7:4]),
        .seg(seg3)
    );

    seg u_seg5 (
        .data(key_count[3:0]),
        .seg(seg4)
    );

    seg u_seg6 (
        .data(key_count[7:4]),
        .seg(seg5)
    );

endmodule
