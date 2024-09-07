#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "constants.h"

// Returns a hex representation (8-bits long)
void hex(uint32_t number, char* buff){
    sprintf(buff,"%08X",number);
}


// R_type instructions
typedef struct R_type{
    unsigned int funct7 : 7;
    unsigned int rs2 : 5;
    unsigned int rs1 : 5;
    unsigned int funct3 : 3;
    unsigned int rd : 5;
    unsigned int opcode : 7;
} R_type;


//I_Type Instructions
typedef struct I_type{
    unsigned int imm;
    unsigned int rs1;
    unsigned int funct3;
    unsigned int rd;
    unsigned int opcode;
    char *load;
}I_type;


// S_type instructions
typedef struct S_type{
    unsigned int imm;
    unsigned int rs2;
    unsigned int rs1;
    unsigned int funct3;
    unsigned int opcode;
}S_type;


// B_type instructions
typedef struct B_type{
    unsigned int imm;
    unsigned int rs2;
    unsigned int rs1;
    unsigned int funct3;
    unsigned int opcode;
}B_type;



// U_type instruction
typedef struct U_type{
    unsigned int imm;
    unsigned int rd;
    unsigned int opcode;
}U_type;


// J_type instruction
typedef struct J_type{
    unsigned int imm;
    unsigned int rd;
    unsigned int opcode;
}J_type;

/* ---------------------------------------------------------------------------------------------------------------------------------------------- */

// Returns a formated version of the R_type instruction 
uint32_t combine_R(R_type* init){
    return (init->funct7 << 25) | (init->rs2 << 20) | (init->rs1 << 15) | (init->funct3 << 12) | (init->rd << 7) | R_opcode;
}

uint32_t combine_I(I_type* init){
    // there are two different type of opcodes for the I_type instructions (0b000001 and 0010011)
    int opcode;
    if(init->load == "a"){
        opcode = 0b0000011;
    }else{
        opcode = I_opcode;
    }
    return (init->imm << 20) | (init->rs1 << 15) | (init->funct3 << 12) | (init->rd << 7) | init->opcode;
}

uint32_t combine_S(S_type* init){
    unsigned int imm_sL = init->imm >> 5;
    unsigned int imm_sR = (init->imm & 0b0000000000011111);
    return (imm_sL << 25) | (init->rs2 << 20) | (init->rs1 << 15) | (init->funct3 << 12) | (imm_sR << 7) | S_opcode;
}  

uint32_t combine_B(B_type* init){
    unsigned int imm_12 = init->imm & 0b10000000000000;
    unsigned int imm_L = init->imm & 0b00011111100000; // imm[10:5]
    unsigned int imm_R = init->imm & 0b00000000011110; // imm[4:1]
    unsigned int imm_11 = init->imm & 0b00100000000000;
    return (imm_12 << 31) | (imm_L << 26) | (init->rs2 << 20) | (init->rs1 << 15) | (init->funct3 << 12) | (imm_R << 8) | (imm_11 << 7) | B_opcode;
}  

uint32_t combine_U(U_type* init){
    return (init->imm << 11) | (init->rd << 7) | U_opcode;
}

uint32_t combine_J(J_type* init){
    unsigned int imm_20 = init->imm & 0b100000000000000000000;
    unsigned int imm_L = init->imm & 0b000000000011111111110; // imm[10:1]
    unsigned int imm_11 = init->imm & 0b000000000100000000000; 
    unsigned int imm_R =init->imm & 0b001111111100000000000; // imm[19:12]
    return ((imm_20 << 31) | (imm_L << 21) | (imm_11 << 21) | (imm_R << 12) | (init->rd << 7) | J_opcode);
}

/* ---------------------------------------------------------------------------------------------------------------------------------------------- */

// R-type instruction handlers
uint32_t handle_add(int* data) {
    R_type inst = {0b0000000, data[2], data[1], 0b000, data[3], 0b0110011};
    return combine_R(&inst);
}

uint32_t handle_sub(int* data) {
    R_type inst = {0b0100000, data[2], data[1], 0b000, data[3], 0b0110011};
    return combine_R(&inst);
}

uint32_t handle_sll(int* data) {
    R_type inst = {0b0000000, data[2], data[1], 0b001, data[3], 0b0110011};
    return combine_R(&inst);
}

uint32_t handle_slt(int* data) {
    R_type inst = {0b0000000, data[2], data[1], 0b010, data[3], 0b0110011};
    return combine_R(&inst);
}

uint32_t handle_sltu(int* data) {
    R_type inst = {0b0000000, data[2], data[1], 0b011, data[3], 0b0110011};
    return combine_R(&inst);
}

uint32_t handle_xor(int* data) {
    R_type inst = {0b0000000, data[2], data[1], 0b100, data[3], 0b0110011};
    return combine_R(&inst);
}

uint32_t handle_srl(int* data) {
    R_type inst = {0b0000000, data[2], data[1], 0b101, data[3], 0b0110011};
    return combine_R(&inst);
}

uint32_t handle_sra(int* data) {
    R_type inst = {0b0100000, data[2], data[1], 0b101, data[3], 0b0110011};
    return combine_R(&inst);
}

uint32_t handle_or(int* data) {
    R_type inst = {0b0000000, data[2], data[1], 0b110, data[3], 0b0110011};
    return combine_R(&inst);
}

uint32_t handle_and(int* data) {
    R_type inst = {0b0000000, data[2], data[1], 0b111, data[3], 0b0110011};
    return combine_R(&inst);
}

// I-type instruction handlers
uint32_t handle_addi(int* data) {
    I_type inst = {data[2], data[1], 0b000, data[3], 0b0010011,"n"};
    return combine_I(&inst);
}

uint32_t handle_slti(int* data) {
    I_type inst = {data[2], data[1], 0b010, data[3], 0b0010011,"n"};
    return combine_I(&inst);
}

uint32_t handle_sltiu(int* data) {
    I_type inst = {data[2], data[1], 0b011, data[3], 0b0010011,"n"};
    return combine_I(&inst);
}

uint32_t handle_xori(int* data) {
    I_type inst = {data[2], data[1], 0b100, data[3], 0b0010011,"n"};
    return combine_I(&inst);
}

uint32_t handle_ori(int* data) {
    I_type inst = {data[2], data[1], 0b110, data[3], 0b0010011,"n"};
    return combine_I(&inst);
}

uint32_t handle_andi(int* data) {
    I_type inst = {data[2], data[1], 0b111, data[3], 0b0010011,"n"};
    return combine_I(&inst);
}

uint32_t handle_slli(int* data) {
    I_type inst = {data[2] & 0b000000011111, data[1], 0b001, data[3], 0b0010011,"n"};
    return combine_I(&inst);
}

uint32_t handle_srli(int* data) {
    I_type inst = {data[2] & 0b000000011111, data[1], 0b101, data[3], 0b0010011,"n"};
    return combine_I(&inst);
}

uint32_t handle_srai(int* data) {
    I_type inst = {0b0100000 | (data[2] & 0x1F), data[1], 0b101, data[3], 0b0010011,"n"};
    return combine_I(&inst);
}

uint32_t handle_lb(int* data) {
    I_type inst = {data[2], data[1], 0b000, data[3], 0b0000011,"a"};
    return combine_I(&inst);
}

uint32_t handle_lh(int* data) {
    I_type inst = {data[2], data[1], 0b001, data[3], 0b0000011,"a"};
    return combine_I(&inst);
}

uint32_t handle_lw(int* data) {
    I_type inst = {data[3], data[2], 0b010, data[1], 0b0000011,"a"};
    return combine_I(&inst);
}

uint32_t handle_lbu(int* data) {
    I_type inst = {data[2], data[1], 0b100, data[3], 0b0000011,"a"};
    return combine_I(&inst);
}

uint32_t handle_lhu(int* data) {
    I_type inst = {data[2], data[1], 0b101, data[3], 0b0000011,"a"};
    return combine_I(&inst);
}

uint32_t handle_jalr(int* data) {
    I_type inst = {data[2], data[1], 0b000, data[3], 0b1100111};
    return combine_I(&inst);
}

// S-type instruction handlers
uint32_t handle_sb(int* data) {
    S_type inst = {(data[2]), data[3], data[1], 0b000, 0b0100011};
    return combine_S(&inst);
}

uint32_t handle_sh(int* data) {
    S_type inst = {(data[2]), data[3], data[1], 0b001, 0b0100011};
    return combine_S(&inst);
}

uint32_t handle_sw(int* data) {
    S_type inst = {(data[2]), data[3], data[1], 0b010, 0b0100011};
    return combine_S(&inst);
}

// B-type instruction handlers
uint32_t handle_beq(int* data) {
    B_type inst = {(data[3]), data[2], data[1], 0b000, 0b1100011};
    return combine_B(&inst);
}

uint32_t handle_bne(int* data) {
    B_type inst = {(data[3]), data[2], data[1], 0b001, 0b1100011};
    return combine_B(&inst);
}

uint32_t handle_blt(int* data) {
    B_type inst = {(data[3]), data[2], data[1], 0b100, 0b1100011};
    return combine_B(&inst);
}

uint32_t handle_bge(int* data) {
    B_type inst = {(data[3]), data[2], data[1], 0b101, 0b1100011};
    return combine_B(&inst);
}

uint32_t handle_bltu(int* data) {
    B_type inst = {(data[3]), data[2], data[1], 0b110, 0b1100011};
    return combine_B(&inst);
}

uint32_t handle_bgeu(int* data) {
    B_type inst = {(data[3]), data[2], data[1], 0b111, 0b1100011};
    return combine_B(&inst);
}

// U-type instruction handlers
uint32_t handle_lui(int* data) {
    U_type inst = {data[2], data[3], 0b0110111};
    return combine_U(&inst);
}

uint32_t handle_auipc(int* data) {
    U_type inst = {data[2], data[3], 0b0010111};
    return combine_U(&inst);
}

// J-type instruction handlers
uint32_t handle_jal(int* data) {
    J_type inst = {data[1], data[2], 0b1101111};
    return combine_J(&inst);
}

/* ---------------------------------------------------------------------------------------------------------------------------------------------- */

typedef enum instsruction_definitions {
    add, sub, xor, or, and, sll, srl, sra, slt, sltu,
    addi, xori, ori, andi, slli, srli, srai, slti, sltiu,
    lb, lh, lw, lbu, lhu,
    sb, sh, sw,
    beq, bne, blt, bge, bltu, bgeu,
    jal, jalr,
    lui, auipc
};

typedef uint32_t (*InstructionHandler)(int*);

// Define a lookup table for instruction handlers
InstructionHandler handlers[256] = {
    [add] = handle_add,
    [sub] = handle_sub,
    [xor] = handle_xor,
    [or] = handle_or,
    [and] = handle_and,
    [sll] = handle_sll,
    [srl] = handle_srl,
    [sra] = handle_sra,
    [slt] = handle_slt,
    [sltu] = handle_sltu,
    
    [addi] = handle_addi,
    [xori] = handle_xori,
    [ori] = handle_ori,
    [andi] = handle_andi,
    [slli] = handle_slli,
    [srli] = handle_srli,
    [srai] = handle_srai,
    [slti] = handle_slti,
    [sltiu] = handle_sltiu,
    
    [lb] = handle_lb,
    [lh] = handle_lh,
    [lw] = handle_lw,
    [lbu] = handle_lbu,
    [lhu] = handle_lhu,
    
    [sb] = handle_sb,
    [sh] = handle_sh,
    [sw] = handle_sw,
    
    [beq] = handle_beq,
    [bne] = handle_bne,
    [blt] = handle_blt,
    [bge] = handle_bge,
    [bltu] = handle_bltu,
    [bgeu] = handle_bgeu,
    
    [jal] = handle_jal,
    [jalr] = handle_jalr,
    
    [lui] = handle_lui,
    [auipc] = handle_auipc, 
};


int main(int argc, char* argv[]) {
    int data[][4] = {
        //{lw, x6, x2, 0b1},
        {lw, x1, x0, 0b1},
        {lw, x2, x0, 0b10},
        {add,x2,x1,x3},
        {blt,x3,x20,0b1111},
        {sw,x30,0b1,x2},
        {sw,x30,0b10,x3},
        {lw,x1,x0,0b1},
        {lw,x2,x0,0b10},
        {jalr,x30,0b1,x29}
    };

    char buff[9];
    for (int k = 0; k < sizeof(data) / sizeof(data[0]); k++) {
        // Use the opcode to look up the appropriate handler
        InstructionHandler handler = handlers[data[k][0]];
        if (handler) {
            uint32_t instruction = handler(data[k]);
            hex(instruction, buff);
            printf("%s\n", buff);
        } else {
            printf("Unknown instruction\n");
        }
    }

    return 0;
}