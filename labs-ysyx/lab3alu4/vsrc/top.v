module top (
  input  signed [3:0] A, B,
  input  [2:0] op,
  output reg signed [3:0] out,
  output reg zero, carry, overflow
);
  always @(*) begin
    overflow = 0;
    carry = 0;
    case (op)
      3'b000: begin // add
         {carry, out} = A + B;
         overflow = (A[3] == B[3]) && (out[3] != A[3]);
      end
      3'b001: begin // sub
         {carry, out} = A - B;
         overflow = (A[3] != B[3]) && (out[3] != A[3]);
      end
      3'b010: out = ~A;
      3'b011: out = A & B;
      3'b100: out = A | B;
      3'b101: out = A ^ B;
      3'b110: out = (A < B) ? 4'b0001 : 4'b0000;
      3'b111: out = (A == B) ? 4'b0001 : 4'b0000;
    endcase
    zero = (out == 4'b0000);
  end
endmodule
