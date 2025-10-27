module top (
    input clk,
    input rst,
    input btn_start,
    input btn_pause,
    input btn_reset,
    output [6:0] seg0,
    output [6:0] seg1,
    output led
);
    wire clk_1hz;
    wire [3:0] digit_l, digit_h;
    wire overflow;

    reg start = 0;
    reg pause = 0;

    // 控制按钮逻辑
    always @(posedge clk) begin
        if (btn_start) start <= 1;
        if (btn_pause) pause <= ~pause;
        if (btn_reset) begin
            start <= 0;
            pause <= 0;
        end
    end
    // 分频器
    clk_divider u_div (
        .clk(clk),
        .rst(rst),
        .clk_1hz(clk_1hz)
    );
    // 计数器
    bcd_counter u_cnt (
        .clk(clk),
        .rst(btn_reset),
        .clk_1hz(clk_1hz),
        .start(start),
        .pause(pause),
        .digit_l(digit_l),
        .digit_h(digit_h),
        .overflow(overflow)
    );
    // 计数闪灯器
    led_blinker u_led (
        .clk(clk),
        .rst(btn_reset),
        .trigger(overflow),
        .led(led)
    );
    // 七段数码管译码器
    seg_decoder u_seg0 (.bcd(digit_l), .seg(seg0));
    seg_decoder u_seg1 (.bcd(digit_h), .seg(seg1));
endmodule
