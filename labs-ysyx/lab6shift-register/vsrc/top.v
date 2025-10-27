module top (
    input clk,
    input btn,                // BTNC
    input [9:0] sw,           // SW[9:7]=控制信号，SW[7:0]=数据
    output [6:0] seg0,
    output [6:0] seg1,
    output [7:0] led
);

    wire [7:0] dout;

    // ===== 50Hz 慢时钟生成器（节拍器） =====
    reg [19:0] clk_div = 0;
    reg slow_clk = 0;

    always @(posedge clk) begin
        if (clk_div == 20'd999) begin
            clk_div <= 0;
            slow_clk <= ~slow_clk;
        end else begin
            clk_div <= clk_div + 1;
        end
    end

    // ===== 按钮上升沿检测（在慢时钟域） =====
    reg [2:0] btn_sync;
    always @(posedge slow_clk) begin
        btn_sync <= {btn_sync[1:0], btn};
    end
    wire step_edge = (btn_sync[2:1] == 2'b01);

    // ===== 调用移位模块 =====
    shift u_shift (
        .clk(slow_clk),
        .en(step_edge),
        .ctrl(sw[9:7]),
        .din(sw[7:0]),
        .dout(dout)
    );

    // ===== LED 调试信号输出（直接复制这段） =====
    assign led[7] = slow_clk;       // 上升沿检测标志
    assign led[6] = btn_sync[2];     // 同步器最高位
    assign led[5] = btn_sync[1];
    assign led[4] = btn_sync[0];
    assign led[3] = btn;             // 实时按钮值
    assign led[2] = step_edge;
    assign led[1:0] = dout[1:0];     // 输出的最低3位，用于观察移位是否成功

    // ===== 数码管显示移位结果 =====
    bcd7seg u_seg0 (.b(dout[3:0]), .h(seg0));
    bcd7seg u_seg1 (.b(dout[7:4]), .h(seg1));

endmodule