module top (
    input clk,
    input rst,
    input btn_start,
    input btn_pause,
    input btn_reset,
    input btn_mode,
    output reg led,
    output [6:0] seg0,
    output [6:0] seg1,
    output [6:0] seg2,
    output [6:0] seg3,
    output [6:0] seg4,
    output [6:0] seg5
);
    // 内部信号
    wire clk_1hz;
    wire [5:0] sec, min;
    wire [4:0] hour;
    wire [3:0] bcd0, bcd1, bcd2, bcd3, bcd4, bcd5;
    wire [3:0] stopwatch_l, stopwatch_h;
    wire stopwatch_overflow;
    wire mode;
    
    // 实例化模式切换模块
    mode_switcher u_mode_switcher (
        .clk(clk),
        .rst(rst),
        .btn_mode(btn_mode),
        .mode(mode)
    );

    // 时钟分频器
    clk_divider u_div (
        .clk(clk),
        .rst(rst),
        .clk_1hz(clk_1hz)
    );

    // 主时钟核心
    clock_core u_core (
        .clk(clk),
        .rst(rst),
        .clk_1hz(clk_1hz),
        .btn_start(btn_start),
        .btn_pause(btn_pause),
        .btn_reset(btn_reset),
        .sec(sec),
        .min(min),
        .hour(hour)
    );

    // BCD转换
    six_seg_display u_disp (
        .sec(sec),
        .min(min),
        .hour(hour),
        .bcd0(bcd0),
        .bcd1(bcd1),
        .bcd2(bcd2),
        .bcd3(bcd3),
        .bcd4(bcd4),
        .bcd5(bcd5)
    );

    // 秒表计数器
    bcd_counter u_stopwatch (
        .clk(clk),
        .rst(rst),
        .clk_1hz(clk_1hz),
        .start(btn_start),
        .pause(btn_pause),
        .digit_l(stopwatch_l),
        .digit_h(stopwatch_h),
        .overflow(stopwatch_overflow)
    );

    // LED闪烁器
    led_blinker u_led (
        .clk(clk),
        .rst(rst),
        .trigger(stopwatch_overflow),
        .led(led)
    );

    // 显示选择模块
    wire [3:0] disp_bcd0, disp_bcd1, disp_bcd2, disp_bcd3, disp_bcd4, disp_bcd5;

    display_mux u_disp_mux (
        .bcd5_clk(bcd5),
        .bcd4_clk(bcd4),
        .bcd3_clk(bcd3),
        .bcd2_clk(bcd2),
        .bcd1_clk(bcd1),
        .bcd0_clk(bcd0),
        .bcd1_stopwatch(stopwatch_h),
        .bcd0_stopwatch(stopwatch_l),
        .mode(mode),
        .disp_bcd5(disp_bcd5),
        .disp_bcd4(disp_bcd4),
        .disp_bcd3(disp_bcd3),
        .disp_bcd2(disp_bcd2),
        .disp_bcd1(disp_bcd1),
        .disp_bcd0(disp_bcd0)
    );

    // 数码管译码器连接显示
    seg_decoder u_seg0 (.bcd(disp_bcd0), .seg(seg0));
    seg_decoder u_seg1 (.bcd(disp_bcd1), .seg(seg1));
    seg_decoder u_seg2 (.bcd(disp_bcd2), .seg(seg2));
    seg_decoder u_seg3 (.bcd(disp_bcd3), .seg(seg3));
    seg_decoder u_seg4 (.bcd(disp_bcd4), .seg(seg4));
    seg_decoder u_seg5 (.bcd(disp_bcd5), .seg(seg5));

endmodule
