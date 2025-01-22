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
    output jump,

    output datapath[10:0]
);

always @(*) begin

    assign opcode = instrcution[6:0];
    assign rd = instrcution[11:7];
    assign rs1 = instrcution[19:15];
    assign rs2 = instrcution[24:20];
    assign func3 = instrcution[14:12];
    assign func7 = instrcution[31:25];

    case(opcode)
        `OP_TYPE_R:
            begin
                case(func3)
                    `funct3_add:
                        case(func7)
                            `funct7_add: datapath <= `DP_add;
                            `funct7_sub: datapath <= `DP_sub;
                        endcase
                    `funct3_xor: datapath <= `DP_xor;
                    `funct3_or:  datapath <= `DP_or;
                    `funct3_and: datapath <= `DP_and;
                    `funct3_sll: datapath <= `DP_sll;
                    `funct3_srl:
                        begin
                            case(func7)
                                `funct7_srl: datapath <= `DP_srl;
                                `funct7_sra: datapath <= `DP_sra;
                            endcase
                        end
                    `funct3_sra:  datapath <= `DP_sra;
                    `funct3_slt:  datapath <= `DP_slt;
                    `funct3_sltu: datapath <= `DP_sltu;
                endcase
            end

        `OP_TYPE_I:
            case(func3)
                `funct3_addi:  datapath <= `DP_addi;
                `funct3_xori:  datapath <= `DP_xori;
                `funct3_ori:   datapath <= `DP_ori;
                `funct3_andi:  datapath <= `DP_andi;
                `funct3_slli:  datapath <= `DP_slli;
                `funct3_srli:  datapath <= `DP_srli;
                `funct3_srai:  datapath <= `DP_srai;
                `funct3_slti:  datapath <= `DP_slti;
                `funct3_sltiu: datapath <= `DP_sltiu;
            endcase

        `OP_TYPE_I2:
        `OP_TYPE_I3:
        `OP_TYPE_I4:
        `OP_TYPE_S:
        `OP_TYPE_B:
        `OP_TYPE_J:
        `OP_TYPE_U:
        `OP_TYPE_U2:
    endcase

end

endmodule
    
    