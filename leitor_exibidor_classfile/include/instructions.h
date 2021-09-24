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
        inline void SetSize(u1 padding){size = size + padding;};
        inline std::string GetMnemonic(){return mnemonic;};
        void Show();
};

class InstructionVector{
    protected:
        std::vector<Instruction*> instructions;
    public:
        void CreateInstructionVector();
        Instruction* GetInstruction(int position);
        int GetSize();
        int ShowInstruction(u1 opcode, int prefix);
        int ShowTableswitch();
};

extern InstructionVector instructionVector;

#endif