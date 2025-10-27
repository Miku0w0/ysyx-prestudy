module encoder38 (
  input  [7:0] x,
  input        en,
  output reg [2:0] y,
  output reg       valid
);
  integer i;
  always @(*) begin
    y = 3'b000;
    valid = 0;
    if (en) begin
      for (i = 7; i >= 0; i = i - 1) begin
        if (x[i]) begin
          y = i[2:0];
          valid = 1;
          break;
        end
      end
    end
  end
endmodule
