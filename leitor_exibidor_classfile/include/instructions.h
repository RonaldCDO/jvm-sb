#ifndef INSTRUCTIONS
#define INSTRUCTIONS

#include "data_class_format.h"

#define MNEMONIC_SIZE 20

class Instruction {
    protected:
        u1 opcode;
        std::string mnemonic;
        int size;
    public:
        Instruction(u1 opcode, const std::string mnemonic, int size);
        inline u1 GetOpcode(){return opcode;};
        inline int GetSize(){return size;};
        inline std::string GetMnemonic(){return mnemonic;};
};

class InstructionVector{
    protected:
        std::vector<Instruction*> instructions;
    public:
        std::vector<Instruction*> CreateInstructionVector();
        Instruction* GetInstruction(int position);
        int GetSize();
        int ShowInstruction(u1 opcode, int prefix);
};


#endif