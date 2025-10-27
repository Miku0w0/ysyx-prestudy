module clock_core (
    input clk,
    input rst,
    input clk_1hz,
    input btn_start,
    input btn_pause,
    input btn_reset,
    output reg [5:0] sec,
    output reg [5:0] min,
    output reg [4:0] hour
);
    reg running;
    reg clk_1hz_d;

    // 下降沿检测：clk_1hz 从高到低，表示“tick 到了”
    wire clk_1hz_edge = clk_1hz_d & ~clk_1hz;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            running <= 0;
            sec <= 0;
            min <= 0;
            hour <= 0;
            clk_1hz_d <= 0;
        end else begin
            clk_1hz_d <= clk_1hz;

            // 控制逻辑
            if (btn_start) running <= 1;
            if (btn_pause) running <= 0;
            if (btn_reset) begin
                sec <= 0;
                min <= 0;
                hour <= 0;
            end

            // 时间计数逻辑：只在 1Hz 的下降沿触发，避免秒级重复累加
            if (clk_1hz_edge && running) begin
                if (sec == 59) begin
                    sec <= 0;
                    if (min == 59) begin
                        min <= 0;
                        if (hour == 23)
                            hour <= 0;
                        else
                            hour <= hour + 1;
                    end else begin
                        min <= min + 1;
                    end
                end else begin
                    sec <= sec + 1;
                end
            end
        end
    end
endmodule
