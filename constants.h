// this header turned out to be useless (RIP)



// opcodes
#define R_opcode 0b0110011
#define I_opcode 0b0010011
#define S_opcode 0b0100011
#define B_opcode 0b1100011
#define U_opcode 0b0110111
#define J_opcode 0b1101111

/*
// instruction opcodes
#define lw R_opcode 
#define sw S_opcode
#define add R_opcode
#define sub R_opcode
*/

// Register values
#define x0  0b00000
#define x1  0b00001
#define x2  0b00010
#define x3  0b00011
#define x4  0b00100
#define x5  0b00101
#define x6  0b00110
#define x7  0b11100
#define x8  0b10000
#define x9  0b10010
#define x10 0b10100
#define x11 0b10110
#define x12 0b11000
#define x13 0b11010
#define x14 0b11100
#define x15 0b11110
#define x16 0b10000
#define x17 0b10001
#define x18 0b10010
#define x19 0b10011
#define x20 0b10100
#define x22 0b10110
#define x23 0b10111
#define x24 0b11000
#define x25 0b11001
#define x26 0b11010
#define x27 0b11011
#define x28 0b11100
#define x29 0b11101
#define x30 0b11110
#define x31 0b11111

//funct3
#define add_func3 0b000
#define sub_func3 0b000
#define xor_func3 0b100
#define or_func3  0b110
#define and_func3 0b111
#define sll_func3 0b001
#define srl_func3 0b101
#define sra_func3 0b101
#define slt_func3 0b010
#define sltu_func3 0b011

#define addi_func3 0b000
#define xori_func3 0b100
#define ori_func3  0b110
#define andi_func3 0b111
#define slli_func3 0b001
#define srli_func3 0b101
#define srai_func3 0b101
#define slti_func3 0b010
#define sltui_func3 0b011

#define lb_func3 0b000
#define lh_func3 0b001
#define lw_func3 0b010
#define lbu_func3 0b100
#define lhu_func3 0b101

#define sb_func3 0b000
#define sh_func3 0b001
#define sw_func3 0b010

#define beq_func3 0b000
#define bne_func3 0b001
#define blt_func3 0b100
#define bge_func3 0b101
#define bltu_func3 0b110
#define bgeu_func3 0b111

#define jalr_func3 0b000

//funct7
#define add_func7 0b0000000
#define sub_func7 0b0010100
#define xor_func7 0b0000000
#define or_func7  0b0000000
#define and_func7 0b0000000
#define sll_func7 0b0000000
#define srl_func7 0b0000000
#define sra_func7 0b0010100
#define slt_func7 0b0000000
#define sltu_func7 0b0000000