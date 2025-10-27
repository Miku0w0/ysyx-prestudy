module six_seg_display (
    input [5:0] sec,
    input [5:0] min,
    input [4:0] hour,
    output [3:0] bcd0, bcd1, bcd2, bcd3, bcd4, bcd5
);

    wire [31:0] sec_32 = {26'b0, sec};   // 6 -> 32 bits
    wire [31:0] min_32 = {26'b0, min};   // 6 -> 32 bits
    wire [31:0] hour_32 = {27'b0, hour}; // 5 -> 32 bits

    wire [31:0] sec_mod10 = sec_32 % 10;
    wire [31:0] sec_div10 = sec_32 / 10;
    wire [31:0] min_mod10 = min_32 % 10;
    wire [31:0] min_div10 = min_32 / 10;
    wire [31:0] hour_mod10 = hour_32 % 10;
    wire [31:0] hour_div10 = hour_32 / 10;

    assign bcd0 = sec_mod10[3:0];
    assign bcd1 = sec_div10[3:0];
    assign bcd2 = min_mod10[3:0];
    assign bcd3 = min_div10[3:0];
    assign bcd4 = hour_mod10[3:0];
    assign bcd5 = hour_div10[3:0];
endmodule
