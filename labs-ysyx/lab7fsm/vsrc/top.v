module top (
    input clk,
    input rst_n,
    input ps2_clk,
    input ps2_data,
    output [6:0] seg0, seg1, seg2, seg3, seg4, seg5,
    output [7:0] led
);

// 信号定义
wire [7:0] keycode;
wire ready;
wire overflow;
reg nextdata_n = 1;

// 记录前一个键码，用于判断是否按下还是松开
reg [7:0] prev_code;
wire is_break = (keycode == 8'hF0);

// 状态控制信号
reg [7:0] last_valid_code;
reg [7:0] ascii_code;
reg [7:0] press_count = 0;
reg break_flag = 0;

// 数码管显示
wire [6:0] hex0, hex1, hex2, hex3, hex4, hex5;

// 实例化键盘模块
ps2_keyboard keyboard (
    .clk(clk),
    .clrn(rst_n),
    .ps2_clk(ps2_clk),
    .ps2_data(ps2_data),
    .data(keycode),
    .ready(ready),
    .nextdata_n(nextdata_n),
    .overflow(overflow)
);

// ASCII查表ROM
ascii_rom lookup_rom (
    .scan_code(last_valid_code),
    .ascii_code(ascii_code)
);

// 数码管译码器
hex_decoder h0(.in(last_valid_code[3:0]), .out(hex0)); // 键码低位
hex_decoder h1(.in(last_valid_code[7:4]), .out(hex1)); // 键码高位
hex_decoder h2(.in(ascii_code[3:0]), .out(hex2));      // ASCII低位
hex_decoder h3(.in(ascii_code[7:4]), .out(hex3));      // ASCII高位
hex_decoder h4(.in(press_count[3:0]), .out(hex4));     // 次数低位
hex_decoder h5(.in(press_count[7:4]), .out(hex5));     // 次数高位

// 控制显示输出
assign {seg5, seg4, seg3, seg2, seg1, seg0} = break_flag ?
    {hex5, hex4, hex3, hex2, 7'b1111111, 7'b1111111} : 
    {hex5, hex4, hex3, hex2, hex1, hex0};

assign led = {overflow, ready, keycode[5:0]};

always @(posedge clk) begin
    if (!rst_n) begin
        press_count <= 0;
        last_valid_code <= 8'h00;
        nextdata_n <= 1;
        break_flag <= 0;
    end else begin
        nextdata_n <= 1;
        if (ready) begin
            nextdata_n <= 0;

            if (keycode == 8'hF0) begin
                break_flag <= 1; // 下一个字节是释放键
            end else if (break_flag) begin
                break_flag <= 0; // 释放键结束
            end else begin
                // 有效按键按下
                last_valid_code <= keycode;  // 触发 ascii_rom 输出更新
                press_count <= press_count + 1;
            end
        end
    end
end

endmodule
