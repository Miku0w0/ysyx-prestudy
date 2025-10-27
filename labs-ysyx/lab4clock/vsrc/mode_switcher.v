module mode_switcher (
    input clk,
    input rst,
    input btn_mode,
    output reg mode
);
    reg btn_mode_last;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            mode <= 0;
            btn_mode_last <= 0;
        end else begin
            btn_mode_last <= btn_mode;
            if (btn_mode && !btn_mode_last)
                mode <= ~mode;
        end
    end
endmodule
