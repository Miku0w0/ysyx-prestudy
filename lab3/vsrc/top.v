module top(
    input [3:0] a,
    input [3:0] b,
    input [2:0] ctrl,
    output reg [3:0] res,
    output reg zero,
    output reg carry, 
    output reg overflow
  );

  reg [3:0] temp;

always@(*) begin
    zero = 0;
    temp = 0;
    case(ctrl)
      3'b000:
        begin
          {carry, res} = a + b;
          overflow = (a[3] == b[3])&&(res[3] != a[3]);
        end
      3'b001:
        begin
          temp = ((4'b1111) ^ b) + 1;
          {carry, res} = a + temp;
          overflow = (a[3] != b[3])&&(res[3] != a[3]);
        end
      3'b010:
        begin
          res = ~a;
          carry = 0;
          overflow = 0;
        end
      3'b011:
        begin
          res = a & b;
          carry = 0;
          overflow = 0;
        end
      3'b100:
        begin
          res = a | b;
          carry = 0;
          overflow = 0;
        end
      3'b101:
        begin
          res = a ^ b;
          carry = 0;
          overflow = 0;
        end
      3'b110:
        begin
          carry = 0;
          overflow = 0;
          if(a[3] == 1&&b[3] == 0)
            res = 1;
          else if(a[3] == 0&&b[3] == 1)
            res = 0;
          else
            res=(a < b) ? 1 : 0;
        end
      3'b111:
        begin
          carry = 0;
          overflow = 0;
          res = (a == b) ? 1 : 0;
        end
    endcase

    zero = (res == 4'b0000) ? 1 : 0;

  end
endmodule