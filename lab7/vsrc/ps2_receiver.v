module ps2_receiver(
    input wire clk,                 // 系统时钟
    input wire rst_n,               // 复位信号
    input wire ps2_clk,             // PS/2时钟信号
    input wire ps2_data,            // PS/2数据线

    output reg [7:0] key_code,      // 键盘扫描码
    output reg key_press,           // 按键按下标志
    output reg key_press_edge       // 按键按下上升沿脉冲信号
);

    // 存储PS/2接收的数据
    reg [9:0] ps2_buffer;
    reg [3:0] ps2_count;
    reg [2:0] ps2_clk_sync;
    reg [7:0] prev_code;
    reg break_flag;
    reg key_press_reg;

    // PS/2时钟同步
    always @(posedge clk) begin
        ps2_clk_sync <= {ps2_clk_sync[1:0], ps2_clk};
    end

    // 检测PS/2时钟下降沿(数据在此时更新)
    wire ps2_sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

    // PS/2数据接收逻辑 : 校验 + F0 break 处理 + 边沿输出
    always @(posedge clk or negedge rst_n) begin
        if (rst_n) begin
            // SW0清零时刻
            ps2_buffer <= 10'd0;
            ps2_count <= 4'd0;
            key_code <= 8'd0;
            key_press_reg <= 1'b0;
            prev_code <= 8'd0;
            break_flag <= 1'b0;
            key_press_edge <= 1'b0;
        end 
        else begin
            // 默认无按下边沿，未清零时刻
            key_press_edge <= 1'b0;  
            if (ps2_sampling) begin
                // 若有采样为下降边沿
                if (ps2_count == 4'd10) begin  
                    // 一帧数据接收完成(10位数据)，count清零
                    ps2_count <= 4'd0;
                    if ((ps2_buffer[0] == 1'b0) && (ps2_data == 1'b1) && (^ps2_buffer[9:0])) begin
                        // 验证起始位、停止位和奇偶校验
                        prev_code <= ps2_buffer[8:1];
                        if (ps2_buffer[8:1] == 8'hF0) begin
                            // 检测断码(0xF0)，表示按键松开
                            break_flag <= 1'b1;
                            key_press_reg <= 1'b0;  // 按键松开
                        end 
                        else begin
                            // 如果收到断码后的扫描码，表示按键松开
                            if (break_flag) begin
                                break_flag <= 1'b0;
                                key_press_reg <= 1'b0;  // 按键松开
                            end 
                            else begin
                                // 正常按键按下，会产生一个边沿信号
                                key_code <= ps2_buffer[8:1];
                                key_press_reg <= 1'b1;  // 按键按下
                                key_press_edge <= 1'b1; // 产生按下边沿
                            end
                        end
                    end
                end 
                else begin
                    // 逐位接收数据
                    ps2_buffer[ps2_count] <= ps2_data;
                    ps2_count <= ps2_count + 4'd1;
                end
            end
        end
    end
endmodule
