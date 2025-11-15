module top(
    input clk,
    input rst,
    input ps2_clk,
    input ps2_data,
    output [7:0] seg1,
    output [7:0] seg2,
    output [7:0] seg3,
    output [7:0] seg4,
    output [7:0] seg5,
    output [7:0] seg6,
    output [7:0] seg7,
    output [7:0] seg8,
    output reg state_error,
    output overflow
);

wire [7:0] data;
reg ready;
wire ready_p1, ready_p2;
reg ready_d1, ready_d2;
reg nextdata_n;
reg [7:0] data_d1;
reg [7:0] seg_data_0;
reg [7:0] seg_data_1;
reg [7:0] seg_data_2;
reg [7:0] key_value;
reg [7:0] key_count;
reg [2:0] state;

// 状态定义
parameter IDLE = 3'b000;
parameter KEY_RECEIVED = 3'b001; 
parameter WAIT_RELEASE = 3'b010;
parameter RELEASE_RECEIVED = 3'b011;

assign ready_p1 = ready & !ready_d1;
assign ready_p2 = ready_d1 & !ready_d2;

// 您的 seg_hex 和 ps2 模块实例化保持不变
seg_hex seg_hex_u0(
    .i_seg(seg_data_0),
    .o_seg_0(seg1),
    .o_seg_1(seg2)
);

seg_hex seg_hex_u1(
    .i_seg(seg_data_1),
    .o_seg_0(seg3),
    .o_seg_1(seg4)
);

seg_hex seg_hex_u2(
    .i_seg(seg_data_2),
    .o_seg_0(seg5),
    .o_seg_1(seg6)
);

seg_hex seg_hex_u3(
    .i_seg(8'h00),
    .o_seg_0(seg7),
    .o_seg_1(seg8)
);

ps2 ps2_u1(
    .clk(clk),
    .clrn(!rst),
    .ps2_clk(ps2_clk),
    .ps2_data(ps2_data),
    .nextdata_n(nextdata_n),
    .data(data),
    .ready(ready),
    .overflow(overflow)
);

rom rom_u1(
    .key_value(key_value),
    .ascii_value(seg_data_1)
);
    
always @(*) begin
    seg_data_0 = key_value;
    seg_data_2 = key_count;
end
   
always @(posedge clk or posedge rst) begin
    if(rst) begin 
        ready_d1 <= 1'd0;
        ready_d2 <= 1'b0;
    end
    else begin
        ready_d1 <= ready;
        ready_d2 <= ready_d1;
    end
end

always @(posedge clk or posedge rst) begin
    if(rst) begin
        data_d1 <= 8'b0;
        nextdata_n <= 1'b1;
    end
    else if(ready_p1) begin
        nextdata_n <= 1'b0;
        data_d1 <= data;
    end
    else begin
        nextdata_n <= 1'b1;
    end
end

// 修复的状态机
always @(posedge clk or posedge rst) begin
    if(rst) begin
        state <= IDLE;
        key_value <= 8'b0;
        key_count <= 8'b0;
        state_error <= 1'b0;
    end
    else if(ready_p2) begin
        case(state)
            IDLE: begin
                if(data_d1 != 8'hF0) begin
                    // 收到正常键码，记录并等待释放
                    key_value <= data_d1;
                    state <= KEY_RECEIVED;
                    state_error <= 1'b0;
                end
            end
            
            KEY_RECEIVED: begin
                if(data_d1 == 8'hF0) begin
                    // 收到释放前缀
                    state <= WAIT_RELEASE;
                    state_error <= 1'b0;
                end
                else if(data_d1 != key_value) begin
                    // 收到不同的键码 - 可能是快速切换按键
                    // 更新键值但不改变状态
                    key_value <= data_d1;
                    state_error <= 1'b0;
                end
                // 如果收到相同的键码，保持状态不变
            end
            
            WAIT_RELEASE: begin
                if(data_d1 == key_value) begin
                    // 正确释放当前按键
                    key_count <= key_count + 1'b1;
                    state <= IDLE;
                    state_error <= 1'b0;
                end
                else if(data_d1 != 8'hF0) begin
                    // 收到不同的键码 - 可能是快速连续按键
                    // 不报错，开始处理新按键
                    key_value <= data_d1;
                    state <= KEY_RECEIVED;
                    state_error <= 1'b0;
                end
                else begin
                    // 连续收到释放前缀 - 错误
                    state <= IDLE;
                    state_error <= 1'b1;
                end
            end
            
            default: begin
                state <= IDLE;
                state_error <= 1'b1;
            end
        endcase
    end
end

endmodule