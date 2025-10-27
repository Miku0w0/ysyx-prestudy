module clk_divider (
    input clk,
    input rst,
    output reg clk_1hz
);
    reg [25:0] cnt;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            cnt <= 0;
            clk_1hz <= 0;
        end else begin
            if (cnt == 20) begin
                cnt <= 0;
                clk_1hz <= ~clk_1hz; 
            end else begin
                cnt <= cnt + 1;
            end
        end
    end
endmodule
