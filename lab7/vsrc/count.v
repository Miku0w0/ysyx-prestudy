module count(
    input wire clk,
    input wire rst_n,
    input wire key_press_edge,
    output reg [7:0] key_count
);

    always @(posedge clk or negedge rst_n) begin
        if (rst_n) begin
            key_count <= 8'h00;   // BCD 00
        end else if (key_press_edge) begin

            // 个位未满 9，直接 +1
            if (key_count[3:0] < 4'd9) begin
                key_count[3:0] <= key_count[3:0] + 4'd1;
            
            // 个位满 9，则个位清零，处理十位
            end else begin
                key_count[3:0] <= 4'd0;

                if (key_count[7:4] < 4'd9)
                    key_count[7:4] <= key_count[7:4] + 4'd1;
                else
                    key_count[7:4] <= 4'd0; // 十位满 9，整个清零
            end
        end
    end

endmodule
