module bcd7seg (
  input  [3:0] b,
  output reg [6:0] h
);
  always @(*) begin
    case (b)
      4'd0: h = 7'b1000000; // 0
      4'd1: h = 7'b1111001; // 1
      4'd2: h = 7'b0100100; // 2
      4'd3: h = 7'b0110000; // 3
      4'd4: h = 7'b0011001; // 4
      4'd5: h = 7'b0010010; // 5
      4'd6: h = 7'b0000010; // 6
      4'd7: h = 7'b1111000; // 7
      4'd8: h = 7'b0000000; // 8
      4'd9: h = 7'b0010000; // 9
      default: h = 7'b1111111; // 空白
    endcase
  end
endmodule
