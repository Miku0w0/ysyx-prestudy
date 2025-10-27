module top(x0, x1, x2, x3, en, y0, y1);
    input x0, x1, x2, x3;
    input en;
    output reg y0, y1;

    integer i;
    reg [1:0] y;  // 内部变量

    always @(x0 or x1 or x2 or x3 or en) begin
        if (en) begin
            y = 0;
            if (x3) y = 3;
            else if (x2) y = 2;
            else if (x1) y = 1;
            else if (x0) y = 0;
        end else begin
            y = 0;
        end
    end

    always @(*) begin
        y1 = y[1];
        y0 = y[0];
    end
endmodule
