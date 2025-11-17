module seg (
  input  [2:0] b,  //  编码结果
  output reg [6:0] h  // reg才能在always被赋值
);
  always @(*) begin  // 倒序gfdcba显示 + 共阳极（要0点亮）
    case (b)
      3'd0: h = 7'b1000000; // 0
      3'd1: h = 7'b1111001; // 1
      3'd2: h = 7'b0100100; // 2
      3'd3: h = 7'b0110000; // 3
      3'd4: h = 7'b0011001; // 4
      3'd5: h = 7'b0010010; // 5
      3'd6: h = 7'b0000010; // 6
      3'd7: h = 7'b1111000; // 7
      default: h = 7'b1111111; // 全暗
    endcase
  end
endmodule

/*
  assign segs[0] = 8'b11111101;
  assign segs[1] = 8'b01100000;
  assign segs[2] = 8'b11011010;
  assign segs[3] = 8'b11110010;
  assign segs[4] = 8'b01100110;
  assign segs[5] = 8'b10110110;
  assign segs[6] = 8'b10111110;
  assign segs[7] = 8'b11100000;
*/

/*    
case (b)
    3'd0: h = 7'b1111110; // 0
    3'd1: h = 7'b0110000; // 1
    3'd2: h = 7'b1101101; // 2
    3'd3: h = 7'b1111001; // 3
    3'd4: h = 7'b0110011; // 4
    3'd5: h = 7'b1011011; // 5
    3'd6: h = 7'b1011111; // 6
    3'd7: h = 7'b1110000; // 7
    default: h = 7'b0000000; // 全暗
  endcase
*/