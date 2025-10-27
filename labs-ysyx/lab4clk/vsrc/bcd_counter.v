module bcd_counter (
    input clk,
    input rst,
    input clk_1hz,
    input start,
    input pause,
    output reg [3:0] digit_l = 0,
    output reg [3:0] digit_h = 0,
    output reg overflow = 0   // 到 99 时拉高一拍
);
    reg last_clk1hz = 0;
    wire rising_edge = clk_1hz && ~last_clk1hz;

    always @(posedge clk) begin
        last_clk1hz <= clk_1hz;
        overflow <= 0;

        if (rst) begin
            digit_l <= 0;
            digit_h <= 0;
        end else if (rising_edge && start && !pause) begin
            if (digit_l == 9) begin
                digit_l <= 0;
                if (digit_h == 9) begin
                    digit_h <= 0;
                    overflow <= 1;
                end else begin
                    digit_h <= digit_h + 1;
                end
            end else begin
                digit_l <= digit_l + 1;
            end
        end
    end
endmodule
