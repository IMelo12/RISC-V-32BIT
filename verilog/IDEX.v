module IDEX(
    input jump,
    input [3:0]branch,
    input unsign,
    input mem_read,
    input ALU_WB,
    input WE,
    input mem_write,
    input [4:0]rs1,
    input [4:0]rs2,
    input [31:0]PC_IN,
    input immediate_select,
    input [31:0]immediate,
    input [3:0]ALU,
    input [4:0]rd,
    input [31:0]rs1_val,
    input [31:0]rs2_val,
    input clk,
    input clr,
    input stall,
    output reg jump_out,
    output reg [3:0]branch_out,
    output reg unsign_out,
    output reg mem_read_out,
    output reg ALU_WB_out,
    output reg WE_out,
    output reg mem_write_out,
    output reg [4:0]rs1_out,
    output reg [4:0]rs2_out,
    output reg [31:0]PC_IN_out,
    output reg immediate_select_out,
    output reg [31:0]immediate_out,
    output reg [3:0]ALU_out,
    output reg [4:0]rd_out,
    output reg [31:0]rs1_val_out,
    output reg [31:0]rs2_val_out
);

always@(negedge clk or posedge clr or posedge stall) begin
    if(clr | stall) begin 
        jump_out <= 1'b0;
        branch_out <= 4'b0;
        unsign_out <= 1'b0;
        mem_read_out <= 1'b0;
        ALU_WB_out <= 1'b0;
        WE_out <= 1'b0;
        mem_write_out <= 1'b0;
        rs1_out <= 5'b0;
        rs2_out <= 5'b0;
        PC_IN_out <= 32'b0;
        immediate_select_out <= 32'b0;
        immediate_out <= 1'b0;
        ALU_out <= 4'b0;
        rd_out <= 5'b0;
        rs1_val_out <= 32'b0;
        rs2_val_out <= 32'b0;
    end
    else begin 
        jump_out <= jump;
        branch_out <= branch;
        unsign_out <= unsign;
        mem_read_out <= mem_read;
        ALU_WB_out <= ALU_WB;
        WE_out <= WE;
        mem_write_out <= mem_write;
        rs1_out <= rs1;
        rs2_out <= rs2;
        PC_IN_out <= PC_IN;
        immediate_select_out <= immediate_select;
        immediate_out <= immediate_out;
        ALU_out <= ALU;
        rd_out <= rd;
        rs1_val_out <= rs1_val;
        rs2_val_out <= rs2_val;
    end
end

endmodule

        
