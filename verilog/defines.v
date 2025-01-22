



`define OP_TYPE_R  7'b0110011
`define OP_TYPE_I  7'b0010011
`define OP_TYPE_I2 7'b0000011 //load
`define OP_TYPE_I3 7'b1100111 //jalr
`define OP_TYPE_I4 7'b1110011 //ecall, ebreak
`define OP_TYPE_S  7'b0100011
`define OP_TYPE_B  7'b1100011
`define OP_TYPE_J  7'b1101111
`define OP_TYPE_U  7'b0110111
`define OP_TYPE_U2 7'b0010111


// opcodes
`define OP_add  OP_TYPE_R
`define OP_sub  OP_TYPE_R
`define OP_xor  OP_TYPE_R
`define OP_or   OP_TYPE_R
`define OP_and  OP_TYPE_R
`define OP_sll  OP_TYPE_R
`define OP_srl  OP_TYPE_R
`define OP_sra  OP_TYPE_R
`define OP_slt  OP_TYPE_R
`define OP_sltu OP_TYPE_R

// funct3
`define funct3_add  3'b000
`define funct3_sub  3'b000
`define funct3_xor  3'b100
`define funct3_or   3'b110
`define funct3_and  3'b111
`define funct3_sll  3'b001
`define funct3_srl  3'b101
`define funct3_sra  3'b101
`define funct3_slt  3'b010
`define funct3_sltu 3'b011

`define funct3_addi  3'b000
`define funct3_xori  3'b100
`define funct3_ori   3'b110
`define funct3_andi  3'b111
`define funct3_slli  3'b001
`define funct3_srli  3'b101
`define funct3_srai  3'b101
`define funct3_slti  3'b010
`define funct3_sltiu 3'b011


// funct7
`define funct7_add  7'b0000000
`define funct7_sub  3'b0010100
`define funct7_xor  3'b0000000
`define funct7_or   3'b0000000
`define funct7_and  3'b0000000
`define funct7_sll  3'b0000000
`define funct7_srl  3'b0000000
`define funct7_sra  3'b0010100
`define funct7_slt  3'b0000000
`define funct7_sltu 3'b0000000

// datapath

/*--------------------------------------------------
 datapath signals are 11 bits wide
 0: immediate select
 1: mem_write - store
 2 - 5: branch
 6: unsign - sltu, sltui, lbu, lhu, bltu, bgeu
 7: write_enable - first 24 and 33-36
 8: alu_wb - first 19
 9: IDEX_memread - I_type
 10: jump

*/

`define DP_add   11'b00110000000
`define DP_sub   11'b00110000000
`define DP_xor   11'b00110000000
`define DP_or    11'b00110000000
`define DP_and   11'b00110000000
`define DP_sll   11'b00110000000
`define DP_srl   11'b00110000000
`define DP_sra   11'b00110000000
`define DP_slt   11'b00110000000
`define DP_sltu  11'b00110000000

`define DP_addi  11'b00110000001
`define DP_xori  11'b00110000001
`define DP_ori   11'b00110000001
`define DP_andi  11'b00110000001
`define DP_slli  11'b00110000001
`define DP_srli  11'b00110000001
`define DP_srai  11'b00110000001
`define DP_slti  11'b00110000001
`define DP_sltiu 11'b00111000001

`define DP_lb    11'b01010000000
`define DP_lh    11'b01010000000
`define DP_lw    11'b01010000000
`define DP_lbu   11'b01010000000
`define DP_lhu   11'b01010000000

`define DP_sb    11'b
`define DP_sh
`define DP_sw

`define DP_beq
`define DP_bne
`define DP_blt
`define DP_bge
`define DP_bltu
`define DP_bgeu

`define DP_jal
`define DP_jalr
`define DP_lui 
`define DP_auipc
`define DP_ecall
`define DP_ebreak
