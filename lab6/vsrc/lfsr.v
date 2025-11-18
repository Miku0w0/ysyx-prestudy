module lfsr (
    input wire clk,
    input wire reset_n,
    input wire btn_pulse,
    output reg [7:0] lfsr_reg
);

    wire feedback;
    reg [7:0] next_lfsr;

    //  f(x) = x^8 + x^6 + x^5 + x^4 + 1(x^0)
    assign feedback = lfsr_reg[7] ^ lfsr_reg[5] ^ lfsr_reg[4] ^ lfsr_reg[3];

    always @(*) begin
        next_lfsr = {feedback, lfsr_reg[7:1]};
        if (next_lfsr == 8'b00000000)
            next_lfsr = 8'b10101101;  // 避免全零状态
    end

    always @(posedge clk or negedge reset_n) begin
        if (!reset_n)
            lfsr_reg <= 8'b10101101;  // 初始化值
        else if (btn_pulse)
            lfsr_reg <= next_lfsr;
    end

endmodule
