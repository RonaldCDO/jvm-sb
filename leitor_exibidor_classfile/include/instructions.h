#ifndef INSTRUCTIONS
#define INSTRUCTIONS

#include "data_class_format.h"

#define MNEMONIC_SIZE 20


// Modelo de classe base para as instrucoes utilizadas na JVM
class Instruction {
    protected:
        u1 opcode;
        std::string mnemonic;
        int size;
    public:
        Instruction();
        Instruction(u1 opcode, const std::string mnemonic, int size);
        inline u1 GetOpcode(){return opcode;};
        inline int GetSize(){return size;};
        inline std::string GetMnemonic(){return mnemonic;};
        virtual void Show();
        virtual void Execute();
};

// Modelo de instrucao especifica do tipo "Tableswitch"
class TableswitchInst : public Instruction {
    protected:
        int padding;
        u4 default_bytes;
        u4 high_bytes;
        u4 low_bytes;
        std::vector<u4> jump_offsets;
        u2 jump_offsets_length;
        bool padding_set;
    public:
        TableswitchInst(u1 opcode, const std::string mnemonic);
        void SetPadding(int padding);
        void SetBytes(u4 default_bytes, u4 high_bytes, u4 low_bytes);
        void SetJumpOffsets(u4* jump_offsets);
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