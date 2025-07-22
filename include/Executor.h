#ifndef EXECUTOR_H
#define EXECUTOR_H
#include "Memory.h"
#include "Instruction.h"
extern Memory memo;
extern Register regs;
unsigned int pc = 0;

inline void ExecuteSingle(const Instruction& ins) {
    switch (ins.type) {
        case InstructionType::LUI: {
            auto val = ins.imm;
            regs.PutValue(ins.rd, val);
            pc += 4;
            break;
        }
        case InstructionType::AUIPC: {
            auto val = ins.imm;
            regs.PutValue(ins.rd, val + pc);
            pc += 4;
            break;
        }
        case InstructionType::JAL: {
            regs.PutValue(ins.rd, pc + 4);
            int offset = static_cast<int>(ins.imm << 12) >> 12;
            pc = pc + offset;
            break;
        }
        case InstructionType::JALR: {
            regs.PutValue(ins.rd, pc + 4);
            pc = regs.GetValue(ins.rs1) + ins.imm;
            break;
        }
        case InstructionType::BEQ: {
            if (regs.GetValue(ins.rs1) == regs.GetValue(ins.rs2)) {
                pc = pc + ins.imm;
            } else {
                pc += 4;
            }
            break;
        }
        case InstructionType::BGE: {
            if (regs.GetSignedValue(ins.rs1) >= regs.GetSignedValue(ins.rs2)) {
                pc = pc + ins.imm;
            } else {
                pc += 4;
            }
            break;
        }
        case InstructionType::BGEU: {
            if (regs.GetValue(ins.rs1) >= regs.GetValue(ins.rs2)) {
                pc = pc + ins.imm;
            } else {
                pc += 4;
            }
            break;
        }
        case InstructionType::BLT: {
            if (regs.GetSignedValue(ins.rs1) < regs.GetSignedValue(ins.rs2)) {
                pc = pc + ins.imm;
            } else {
                pc += 4;
            }
            break;
        }
        case InstructionType::BLTU: {
            if (regs.GetValue(ins.rs1) < regs.GetValue(ins.rs2)) {
                pc = pc + ins.imm;
            } else {
                pc += 4;
            }
            break;
        }
        case InstructionType::BNE: {
            if (regs.GetValue(ins.rs1) != regs.GetValue(ins.rs2)) {
                pc = pc + ins.imm;
            } else {
                pc += 4;
            }
            break;
        }
        case InstructionType::LB: {
            unsigned int index = regs.GetValue(ins.rs1) + ins.imm;
            regs.PutValue(ins.rd, memo.LoadByte(index, true));
            pc += 4;
            break;
        }
        case InstructionType::LBU: {
            unsigned int index = regs.GetValue(ins.rs1) + ins.imm;
            regs.PutValue(ins.rd, memo.LoadByte(index, false));
            pc += 4;
            break;
        }
        case InstructionType::LH: {
            unsigned int index = regs.GetValue(ins.rs1) + ins.imm;
            regs.PutValue(ins.rd, memo.LoadHalf(index, true));
            pc += 4;
            break;
        }
        case InstructionType::LHU: {
            unsigned int index = regs.GetValue(ins.rs1) + ins.imm;
            regs.PutValue(ins.rd, memo.LoadHalf(index, false));
            pc += 4;
            break;
        }
        case InstructionType::LW: {
            unsigned int index = regs.GetValue(ins.rs1) + ins.imm;
            regs.PutValue(ins.rd, memo.LoadWord(index));
            pc += 4;
            break;
        }
        case InstructionType::SB: {
            unsigned int index = regs.GetValue(ins.rs1) + ins.imm;
            memo.StoreByte(index, regs.GetValue(ins.rs2));
            pc += 4;
            break;
        }
        case InstructionType::SH: {
            unsigned int index = regs.GetValue(ins.rs1) + ins.imm;
            memo.StoreHalf(index, regs.GetValue(ins.rs2));
            pc += 4;
            break;
        }
        case InstructionType::SW: {
            unsigned int index = regs.GetValue(ins.rs1) + ins.imm;
            memo.StoreByte(index, regs.GetValue(ins.rs2));
            pc += 4;
            break;
        }
        case InstructionType::ADD: {
            regs.PutValue(ins.rd, regs.GetValue(ins.rs1) + regs.GetValue(ins.rs2));
            pc += 4;
            break;
        }
        case InstructionType::SUB: {
            regs.PutValue(ins.rd, regs.GetValue(ins.rs1) - regs.GetValue(ins.rs2));
            pc += 4;
            break;
        }
        case InstructionType::AND: {
            regs.PutValue(ins.rd, regs.GetValue(ins.rs1) & regs.GetValue(ins.rs2));
            pc += 4;
            break;
        }
        case InstructionType::OR: {
            regs.PutValue(ins.rd, regs.GetValue(ins.rs1) | regs.GetValue(ins.rs2));
            pc += 4;
            break;
        }
        case InstructionType::XOR: {
            regs.PutValue(ins.rd, regs.GetValue(ins.rs1) ^ regs.GetValue(ins.rs2));
            pc += 4;
            break;
        }
        case InstructionType::SLL: {
            regs.PutValue(ins.rd, regs.GetValue(ins.rs1) << regs.GetValue(ins.rs2));
            pc += 4;
            break;
        }
        case InstructionType::SRL: {
            regs.PutValue(ins.rd, regs.GetValue(ins.rs1) >> regs.GetValue(ins.rs2));
            pc += 4;
            break;
        }
        case InstructionType::SRA: {
            regs.PutValue(ins.rd, regs.GetSignedValue(ins.rs1) >> regs.GetValue(ins.rs2));
            pc += 4;
            break;
        }
        case InstructionType::SLT: {
            if (regs.GetSignedValue(ins.rs1) < regs.GetSignedValue(ins.rs2)) {
                regs.PutValue(ins.rd, 1);
            } else {
                regs.PutValue(ins.rd, 0);
            }
            pc += 4;
            break;
        }
        case InstructionType::SLTU: {
            if (regs.GetValue(ins.rs1) < regs.GetValue(ins.rs2)) {
                regs.PutValue(ins.rd, 1);
            } else {
                regs.PutValue(ins.rd, 0);
            }
            pc += 4;
            break;
        }
        case InstructionType::ADDI: {
            regs.PutValue(ins.rd, regs.GetValue(ins.rs1) + ins.imm);
            pc += 4;
            break;
        }
        case InstructionType::ANDI: {
            regs.PutValue(ins.rd, regs.GetValue(ins.rs1) & ins.imm);
            pc += 4;
            break;
        }
        case InstructionType::ORI: {
            regs.PutValue(ins.rd, regs.GetValue(ins.rs1) | ins.imm);
            pc += 4;
            break;
        }
        case InstructionType::XORI: {
            regs.PutValue(ins.rd, regs.GetValue(ins.rs1) ^ ins.imm);
            pc += 4;
            break;
        }
        case InstructionType::SLLI: {
            regs.PutValue(ins.rd, regs.GetValue(ins.rs1) << ins.imm);
            pc += 4;
            break;
        }
        case InstructionType::SRLI: {
            regs.PutValue(ins.rd, regs.GetValue(ins.rs1) >> ins.imm);
            pc += 4;
            break;
        }
        case InstructionType::SRAI: {
            regs.PutValue(ins.rd, regs.GetSignedValue(ins.rs1) >> ins.imm);
            pc += 4;
            break;
        }
        case InstructionType::SLTI: {
            if (regs.GetValue(ins.rs1) < ins.imm) {
                regs.PutValue(ins.rd, 1);
            } else {
                regs.PutValue(ins.rd, 0);
            }
            pc += 4;
            break;
        }
        case InstructionType::SLTIU: {
            if (regs.GetSignedValue(ins.rs1) < static_cast<int>(ins.imm)) {
                regs.PutValue(ins.rd, 1);
            } else {
                regs.PutValue(ins.rd, 0);
            }
            pc += 4;
            break;
        }
        default:;
    }
}

inline unsigned int Execute() {
    while (true) {
        std::cout << pc << '\n';
        unsigned int code = memo.GetInstructionCode(pc);
        if (code == 0x0ff00513) {
            return regs.GetValue(10) % 256;
        }
        Instruction ins{code};
        ExecuteSingle(ins);
    }
}
#endif //EXECUTOR_H
