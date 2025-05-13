module registerFile(
input [4:0] select,
input [31:0]data_in,
input write_enable,
input clk,
input [4:0]rs2,
input [4:0]rs1,
output reg[31:0]rs1_out,
output reg[31:0]rs2_out
);

reg[31:0] register[31:0];

initial begin
	for(int i = 0; i<32; i++)
		register[i] <= 32'b0;
end

always@(posedge clk) begin
	if(write_enable) begin
		register[select] <= data_in;
	end
end

// asynchronus read
assign rs1_out = register[rs1];
assign rs2_out = register[rs2];

endmodule
		
		
		