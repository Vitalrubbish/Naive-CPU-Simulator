#ifndef INSTRUCTION_H
#define INSTRUCTION_H
enum class InstructionType {
    LUI, AUIPC, JAL, JALR, BEQ, BNE, BLT, BGE, BLTU, BGTU, LB, LH, LW,
    LBU, LHU, SB, SH, SW, ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI,
    SRAI, ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND
};

class Instruction {
    InstructionType type{};

};
#endif //INSTRUCTION_H
