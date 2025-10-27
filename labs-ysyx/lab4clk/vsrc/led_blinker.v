module led_blinker (
    input clk,
    input rst,
    input trigger,          // overflow 触发
    output reg led
);
    reg [7:0] led_cnt = 0;

    always @(posedge clk) begin
        if (rst) begin
            led_cnt <= 0;
            led <= 0;
        end else begin
            if (trigger) begin
                led_cnt <= 50;
            end else if (led_cnt > 0) begin
                led_cnt <= led_cnt - 1;
            end

            led <= (led_cnt > 0);
        end
    end
endmodule
