module debounce (
    input wire clk,
    input wire reset_n,
    input wire button,
    output reg btn_pulse
);

    reg [3:0] btn_shift_reg;
    reg btn_state, btn_state_prev;

    always @(posedge clk or negedge reset_n) begin
        if (!reset_n) begin
            btn_shift_reg <= 4'b1111;
            btn_state <= 1'b0;
        end else begin
            btn_shift_reg <= {btn_shift_reg[2:0], button};
            if (btn_shift_reg == 4'b0000 && !btn_state) begin
                btn_state <= 1'b1;
            end else if (btn_shift_reg == 4'b1111) begin
                btn_state <= 1'b0;
            end
        end
    end

    always @(posedge clk or negedge reset_n) begin
        if (!reset_n)
            btn_state_prev <= 1'b0;
        else
            btn_state_prev <= btn_state;
    end

    assign btn_pulse = ~btn_state_prev & btn_state;

endmodule
