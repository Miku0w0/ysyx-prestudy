module fsm_moore (
    input clk,
    input rst_n,  // 低电平复位
    input w,      // 输入 w
    output reg z, // 输出 z
    output reg [3:0] state_led  // 当前状态值输出
);
    typedef enum logic [3:0] {
        A = 4'd0, B = 4'd1, C = 4'd2, D = 4'd3, E = 4'd4,
        F = 4'd5, G = 4'd6, H = 4'd7, I = 4'd8
    } state_t;

    state_t state, next;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            state <= A;
        else
            state <= next;
    end

    always_comb begin
        case (state)
            A: next = w ? F : B;
            B: next = w ? F : C;
            C: next = w ? F : D;
            D: next = w ? F : E;
            E: next = w ? F : E;
            F: next = w ? G : B;
            G: next = w ? H : B;
            H: next = w ? I : B;
            I: next = w ? I : B;
            default: next = A;
        endcase
    end

    always_comb begin
        case (state)
            E, I: z = 1;
            default: z = 0;
        endcase
    end

    always_comb begin
        state_led = state;
    end
endmodule
