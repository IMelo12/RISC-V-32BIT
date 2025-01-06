module instrcutiondecoder(
    input [31:0] instruction,
    output [4:0] rd,
    output [4:0] rs1,
    output [4:0] rs2,
    output [3:0] ALU,
    output immediate_select,
    output mem_write,
    output [3:0] branch,
    output unsign,
    output WE,
    output ALU_WB,
    output IDEX_Memread,
    output jump
);

always @(*) begin

    assign opcode = instrcution[6:0];
    assign rd = instrcution[11:7];
    assign rs1 = instrcution[19:15];
    assign rs2 = instrcution[24:20];

    //ALU CONTROL
    case(opcode) 

        7'b0010011, 7'b0000011, 7'b1100111: // I-type
        begin
    if()
        end

        7'b0100011: // S-type
        begin
        rs1 = instrcution[19:15];
        rs2 = instrcution[]
        end

        7'b1100011: // B-type
        begin
        rd = instruction[11:7];
        rs1 = instrcution[19:15];
        rs2 = instrcution[]
        end

        7'b0110111, 7'b0010111: // U-type
        begin
        rd = instruction[11:7];
        rs1 = instrcution[19:15];
        rs2 = instrcution[]
        end

        7'b1101111: // J-type
        begin
        rd = instruction[11:7];
        rs1 = instrcution[19:15];
        rs2 = instrcution[]
        end

    endcase
end

endmodule
    
    