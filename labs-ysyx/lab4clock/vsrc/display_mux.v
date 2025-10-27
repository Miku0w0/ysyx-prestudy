module display_mux (
    input [3:0] bcd5_clk, bcd4_clk, bcd3_clk, bcd2_clk, bcd1_clk, bcd0_clk,
    input [3:0] bcd1_stopwatch, bcd0_stopwatch,
    input mode,
    output [3:0] disp_bcd5, disp_bcd4, disp_bcd3, disp_bcd2, disp_bcd1, disp_bcd0
);
    assign {disp_bcd5, disp_bcd4, disp_bcd3, disp_bcd2, disp_bcd1, disp_bcd0} =
        (mode == 0) ? {bcd5_clk, bcd4_clk, bcd3_clk, bcd2_clk, bcd1_clk, bcd0_clk} :
                      {4'd0, 4'd0, 4'd0, 4'd0, bcd1_stopwatch, bcd0_stopwatch};
endmodule
