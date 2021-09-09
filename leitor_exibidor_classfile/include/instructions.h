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

/**
typedef enum Opcodes {
    
// Constants
OC_nop = 0x00,
OC_aconst_null = 0x01,
OC_iconst_ml = 0x02,
OC_iconst_0 = 0x03,
OC_iconst_1 = 0x04,
OC_iconst_2 = 0x05,
OC_iconst_3 = 0x06,
OC_iconst_4 = 0x07,
OC_iconst_5 = 0x08,
OC_lconst_0 = 0x09,
OC_lconst_1 = 0x0a,
OC_fconst_0 = 0x0b,
OC_fconst_1 = 0x0c,
OC_fconst_2 = 0x0d,
OC_dconst_0 = 0x0e,
OC_dconst_1 = 0x0f,
OC_bipush = 0x10,
OC_sipush = 0x11,
OC_ldc = 0x12,
OC_ldc_w = 0x13,
OC_ldc2_w = 0x14,

//Loads

OC_iload = 0x15,
OC_lload = 0x16,
OC_fload = 0x17,
OC_dload = 0x18,
OC_aload = 0x19,
OC_iload_0 = 0x1a,
OC_iload_1 = 0x1b,
OC_iload_2 = 0x1c,
OC_iload_3 = 0x1d,
OC_lload_0 = 0x1e,
OC_lload_1 = 0x1f,
OC_lload_2 = 0x20,
OC_lload_3 = 0x21,
OC_fload_0 = 0x22,
OC_fload_1 = 0x23,
OC_fload_2 = 0x24,
OC_fload_3 = 0x25,
OC_dload_0 = 0x26,
OC_dload_1 = 0x27,
OC_dload_2 = 0x28,
OC_dload_3 = 0x29,
OC_aload_0 = 0x2a,
OC_aload_1 = 0x2b,
OC_aload_2 = 0x2c,
OC_aload_3 = 0x2d,
OC_iaload = 0x2e,
OC_laload = 0x2f,
OC_faload = 0x30,
OC_daload = 0x31,
OC_aaload = 0x32,
OC_baload = 0x33,
OC_caload = 0x34,
OC_sload = 0x35,

// Stores

OC_istore = 0x36,
OC_lsotre = 0x37,
OC_fsotre = 0x38,
OC_dsotre = 0x30,
OC_asotre = 0x3a,
OC_istore_0 = 0x3b,
OC_istore_1 = 0x3c,
OC_istore_2 = 0x3d,
OC_istore_3 = 0x3e,
OC_lstore_0 = 0x3f,
OC_lstore_1 = 0x40,
OC_lstore_2 = 0x41,
OC_lstore_3 = 0x42,
OC_fstore_0 = 0x43,
OC_fstore_1 = 0x44,
OC_fstore_2 = 0x45,
OC_fstore_3 = 0x46,
OC_dstore_0 = 0x47,
OC_dstore_1 = 0x48,
OC_dstore_2 = 0x49,
OC_dstore_3 = 0x4a,
OC_astore_0 = 0x4b,
OC_astore_1 = 0x4c,
OC_astore_2 = 0x4d,
OC_astore_3 = 0x4e,
OC_iastore = 0x4f,
OC_lastore = 0x50,
OC_fastore = 0x51,
OC_dastore = 0x52,
OC_aastore = 0x53,
OC_bastore = 0x54,
OC_castore = 0x55,
OC_sastore = 0x56,

//Stack

OC_pop = 0x57,
OC_pop2 = 0x58,
OC_dup = 0x59,
OC_dup_x1 = 0x5a,
OC_dup_x2 = 0x5b,
OC_dup2 = 0x5c,
OC_dup2_x1 = 0x5d,
OC_dup2_x2 = 0x5e,
OC_swap = 0x5f,

//Math

OC_iadd = 0x60,
OC_ladd = 0x61,
OC_fadd = 0x62,
OC_dadd = 0x63,
OC_isub = 0x64,
OC_lsub = 0x65,
OC_fsub = 0x66,
OC_dsub = 0x67,
OC_imul = 0x68,
OC_lmul = 0x69,
OC_fmul = 0x6a,
OC_dmul = 0x6b,
OC_idiv = 0x6c,
OC_ldiv = 0x6d,
OC_fdiv = 0x6e,
OC_ddiv = 0x6f,
OC_irem = 0x70,
OC_lrem = 0x71,
OC_frem = 0x72,
OC_drem = 0x73,
OC_ineg = 0x74,
OC_lneg = 0x75,
OC_fneg = 0x76,
OC_dneg = 0x77,
OC_ishl = 0x78,
OC_lshl = 0x79,
OC_ishr = 0x7a,
OC_lshr = 0x7b,
OC_iushr = 0x7c,
OC_lushr = 0x7d,
OC_iand = 0x7e,
OC_land = 0x7f,
OC_ior = 0x80,
OC_lor = 0x81,
OC_ixor = 0x82,
OC_lxor = 0x83,
OC_iinc = 0x84,

//Conversions

OC_i2l = 0x85,
OC_i2f = 0x86,
OC_i2d = 0x87,
OC_l2i = 0x88,
OC_l2f = 0x89,
OC_l2d = 0x8a,
OC_f2i = 0x8b,
OC_f2l = 0x8c,
OC_f2d = 0x8d,
OC_d2i = 0x8e,
OC_d2f = 0x8f,
OC_d2l = 0x90,
OC_i2b = 0x91,
OC_i2c = 0x92,
OC_i2s = 0x93,

//Comparisons

OC_lcmp = 0x94,
OC_fcmpl = 0x95,
OC_fcmpg = 0x96,
OC_dcmpl = 0x97,
OC_dcmpg = 0x98,
OC_ifeq = 0x99,
OC_ifne = 0x9a,
OC_iflt = 0x9b,
OC_ifge = 0x9c,
OC_ifgt = 0x9d,
OC_ifle = 0x9e,
OC_if_icmpeq = 0x9f,
OC_if_icmpne = 0xa0,
OC_if_icmplt = 0xa1,
OC_if_icmpge = 0xa2,
OC_if_icmpgt = 0xa3,
OC_if_icmple = 0xa4,
OC_if_acmpeq = 0xa5,
OC_if_acmpne = 0xa6,

//Control

OC_goto = 0xa7,
OC_jsr = 0xa8,
OC_ret = 0xa9,
OC_tableswitch = 0xaa,
OC_lookupswitch = 0xab,
OC_ireturn = 0xac,
OC_lreturn = 0xad,
OC_freturn = 0xae,
OC_dreturn = 0xaf,
OC_areturn = 0xb0,
OC_return = 0xb1,

//References

OC_getstatic = 0xb2,
OC_putstatic = 0xb3,
OC_getfield = 0xb4,
OC_putfield = 0xb5,
OC_invokevirtual = 0xb6,
OC_invokespecial = 0xb7,
OC_invokestatic = 0xb8,
OC_invokeinterface = 0xb9,
OC_invokedynamic = 0xba,
OC_new = 0xbb,
OC_newarray = 0xbc,
OC_anewarray = 0xbd,
OC_arraylenght = 0xbe,
OC_athrow = 0xbf,
OC_checkcast = 0xc0,
OC_instanceof = 0xc1,
OC_monitorenter = 0xc2,
OC_monitorexit = 0xc3,

//Extended

OC_wide = 0xc4,
OC_multinewarray = 0xc5,
OC_ifnull = 0xc6,
OC_ifnonnull = 0xc7,
OC_goto_w = 0xc8,
OC_jsr_w = 0xc9,

//Reserved

OC_breakpoint = 0xca,
OC_impdep1 = 0xfe,
OC_impdep2 = 0xff

};

**/

#endif