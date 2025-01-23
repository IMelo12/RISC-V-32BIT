module ALU(
    input [31:0] a,
    input [31:0] b,
    input [12:0] imm,
    input [3:0]  select,

    output [31:0] result
)

`include "defines.v"

always @(*) begin
    case(select)
        `ALU_add: result <= a + b;
        `ALU_sub: result <= a - b;
        `ALU_xor: result <= a ^ b;
        `ALU_or:  result <= a | b;
        `ALU_and: result <= a & b;
        `ALU_sll: result <= a << b;
        `ALU_srl: result <= a >> b;
        `ALU_sra: result <= a >>> b;
        `ALU_slt: result <= (a < b)? 32'b1 : 32'b0;
        `ALU_sltu: result <= (a < b)? 32'b1 : 32'b0;
        `ALU_addi: result <= a + imm;
        `ALU_ori: result <= a | imm;
        `ALU_andi: result <= a & imm;
        `ALU_slli: result <= a << imm;
        `ALU_srli: result <= a >> imm;
        `ALU_srai: result <= a >>> imm;
        `ALU_slti: result <= (a < imm)? 32'b1 : 32'b0;
        `ALU_sltiu: result <= (a < imm)? 32'b1 : 32'b0;
    endcase
end

endmodule