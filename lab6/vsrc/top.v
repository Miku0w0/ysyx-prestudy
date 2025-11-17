module top(
    input wire clk,
    input wire reset_n,
    input wire button,
    output wire [6:0] seg0,
    output wire [6:0] seg1
);

    wire btn_pulse;
    wire [7:0] lfsr_reg;

    debounce u_debounce (
        .clk(clk),
        .reset_n(reset_n),
        .button(button),
        .btn_pulse(btn_pulse)
    );

    lfsr u_lfsr (
        .clk(clk),
        .reset_n(reset_n),
        .btn_pulse(btn_pulse),
        .lfsr_reg(lfsr_reg)
    );

    hex_to_7seg u_hex0 (
        .hex_digit(lfsr_reg[3:0]),
        .segments(seg0)
    );

    hex_to_7seg u_hex1 (
        .hex_digit(lfsr_reg[7:4]),
        .segments(seg1)
    );

endmodule
