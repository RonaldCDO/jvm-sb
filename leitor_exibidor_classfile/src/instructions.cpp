#include "instructions.h"


Instruction::Instruction(u1 opcode, const std::string mnemonic, int size) {
    this->opcode = opcode;
    this->mnemonic = mnemonic;
    this->size = size;
}

std::vector<Instruction*> InstructionVector::CreateInstructionVector() {
    
    //CONSTANTS

    instructions.push_back(new Instruction(0x00, "nop", 0));
    instructions.push_back(new Instruction(0x01, "aconst_null", 0));
    instructions.push_back(new Instruction(0x02, "iconst_ml", 0));
    instructions.push_back(new Instruction(0x03, "iconst_0", 0));
    instructions.push_back(new Instruction(0x04, "iconst_1", 0));
    instructions.push_back(new Instruction(0x05, "iconst_2", 0));
    instructions.push_back(new Instruction(0x06, "iconst_3", 0));
    instructions.push_back(new Instruction(0x07, "iconst_4", 0));
    instructions.push_back(new Instruction(0x08, "iconst_5", 0));
    instructions.push_back(new Instruction(0x09, "lconst_0", 0));
    instructions.push_back(new Instruction(0x0a, "lconst_1", 0));
    instructions.push_back(new Instruction(0x0b, "fconst_0", 0));
    instructions.push_back(new Instruction(0x0c, "fconst_1", 0));
    instructions.push_back(new Instruction(0x0d, "fconst_2", 0));
    instructions.push_back(new Instruction(0x0e, "dconst_0", 0));
    instructions.push_back(new Instruction(0x0f, "dconst_1", 0));
    instructions.push_back(new Instruction(0x10, "bipush", 1));
    instructions.push_back(new Instruction(0x11, "sipush", 2));
    instructions.push_back(new Instruction(0x12, "ldc", 1));
    instructions.push_back(new Instruction(0x13, "ldc_w", 2));
    instructions.push_back(new Instruction(0x14, "ldc2_w", 2));
    
    //LOADS

    instructions.push_back(new Instruction(0x15, "iload", 1));
    instructions.push_back(new Instruction(0x16, "lload", 1));
    instructions.push_back(new Instruction(0x17, "fload", 1));
    instructions.push_back(new Instruction(0x18, "dload", 1));
    instructions.push_back(new Instruction(0x19, "aload", 1));     
    instructions.push_back(new Instruction(0x1a, "iload_0", 0));
    instructions.push_back(new Instruction(0x1b, "iload_1", 0));
    instructions.push_back(new Instruction(0x1c, "iload_2", 0));
    instructions.push_back(new Instruction(0x1d, "iload_3", 0));
    instructions.push_back(new Instruction(0x1e, "lload_0", 0));
    instructions.push_back(new Instruction(0x1f, "lload_1", 0));
    instructions.push_back(new Instruction(0x20, "lload_2", 0));
    instructions.push_back(new Instruction(0x21, "lload_3", 0));
    instructions.push_back(new Instruction(0x22, "fload_0", 0));
    instructions.push_back(new Instruction(0x23, "fload_1", 0));
    instructions.push_back(new Instruction(0x24, "fload_2", 0));
    instructions.push_back(new Instruction(0x25, "fload_3", 0));
    instructions.push_back(new Instruction(0x26, "dload_0", 0));
    instructions.push_back(new Instruction(0x27, "dload_1", 0));
    instructions.push_back(new Instruction(0x28, "dload_2", 0));
    instructions.push_back(new Instruction(0x29, "dload_3", 0));
    instructions.push_back(new Instruction(0x2a, "aload_0", 0));
    instructions.push_back(new Instruction(0x2b, "aload_1", 0));
    instructions.push_back(new Instruction(0x2c, "aload_2", 0));
    instructions.push_back(new Instruction(0x2d, "aload_3", 0));
    instructions.push_back(new Instruction(0x2e, "iaload", 0));
    instructions.push_back(new Instruction(0x2f, "laload", 0));
    instructions.push_back(new Instruction(0x30, "faload", 0));
    instructions.push_back(new Instruction(0x31, "daload", 0));
    instructions.push_back(new Instruction(0x32, "aaload", 0));    
    instructions.push_back(new Instruction(0x33, "baload", 0));
    instructions.push_back(new Instruction(0x34, "caload", 0));
    instructions.push_back(new Instruction(0x35, "sload", 0));
    
    //STORES

    instructions.push_back(new Instruction(0x36, "istore", 0));
    instructions.push_back(new Instruction(0x37, "lstore", 0));
    instructions.push_back(new Instruction(0x38, "fstore", 0));
    instructions.push_back(new Instruction(0x30, "dstore", 0));    
    instructions.push_back(new Instruction(0x3a, "astore", 0));
    instructions.push_back(new Instruction(0x36, "istore", 1));
    instructions.push_back(new Instruction(0x37, "lstore", 1));
    instructions.push_back(new Instruction(0x38, "fstore", 1));
    instructions.push_back(new Instruction(0x30, "dstore", 1));    
    instructions.push_back(new Instruction(0x3a, "astore", 1));
    instructions.push_back(new Instruction(0x3b, "istore_0", 0));
    instructions.push_back(new Instruction(0x3c, "istore_1", 0));
    instructions.push_back(new Instruction(0x3d, "istore_2", 0));
    instructions.push_back(new Instruction(0x3e, "istore_3", 0));    
    instructions.push_back(new Instruction(0x3f, "lstore_0", 0));
    instructions.push_back(new Instruction(0x40, "lstore_1", 0));
    instructions.push_back(new Instruction(0x41, "lstore_2", 0));
    instructions.push_back(new Instruction(0x42, "lstore_3", 0));
    instructions.push_back(new Instruction(0x43, "fstore_0", 0));    
    instructions.push_back(new Instruction(0x44, "fstore_1", 0));
    instructions.push_back(new Instruction(0x45, "fstore_2", 0));
    instructions.push_back(new Instruction(0x46, "fstore_3", 0));
    instructions.push_back(new Instruction(0x47, "dstore_0", 0));
    instructions.push_back(new Instruction(0x48, "dstore_1", 0));    
    instructions.push_back(new Instruction(0x49, "dstore_2", 0));
    instructions.push_back(new Instruction(0x4a, "dstore_3", 0));
    instructions.push_back(new Instruction(0x4b, "astore_0", 0));
    instructions.push_back(new Instruction(0x4c, "astore_1", 0));
    instructions.push_back(new Instruction(0x4d, "astore_2", 0));    
    instructions.push_back(new Instruction(0x4e, "astore_3", 0));    
    instructions.push_back(new Instruction(0x4f, "iastore", 0));
    instructions.push_back(new Instruction(0x50, "lastore", 0));    
    instructions.push_back(new Instruction(0x51, "fastore", 0));
    instructions.push_back(new Instruction(0x52, "dastore", 0));
    instructions.push_back(new Instruction(0x53, "aastore", 0));
    instructions.push_back(new Instruction(0x54, "bastore", 0));
    instructions.push_back(new Instruction(0x55, "castore", 0));    
    instructions.push_back(new Instruction(0x56, "sastore", 0));    
    
    //STACK
    
    instructions.push_back(new Instruction(0x57, "pop", 0));   
    instructions.push_back(new Instruction(0x58, "pop2", 0));    
    instructions.push_back(new Instruction(0x59, "dup", 0));    
    instructions.push_back(new Instruction(0x5a, "dup_x1", 0));    
    instructions.push_back(new Instruction(0x5b, "dup_x2", 0));
    instructions.push_back(new Instruction(0x5c, "dup2", 0));
    instructions.push_back(new Instruction(0x5d, "dup2_x1", 0));
    instructions.push_back(new Instruction(0x5e, "dup2_x2", 0));
    instructions.push_back(new Instruction(0x5f, "swap", 0));
             

    
    // MATH

    instructions.push_back(new Instruction(0x60, "iadd", 0));
    instructions.push_back(new Instruction(0x61, "ladd", 0));
    instructions.push_back(new Instruction(0x62, "fadd", 0));
    instructions.push_back(new Instruction(0x63, "dadd", 0));
	instructions.push_back(new Instruction(0x64, "isub", 0));
    instructions.push_back(new Instruction(0x65, "lsub", 0));
    instructions.push_back(new Instruction(0x66, "fsub", 0));
    instructions.push_back(new Instruction(0x67, "dsub", 0));
    instructions.push_back(new Instruction(0x68, "imul", 0));
    instructions.push_back(new Instruction(0x69, "lmul", 0));
    instructions.push_back(new Instruction(0x6a, "fmul", 0));
    instructions.push_back(new Instruction(0x6b, "dmul", 0));
    instructions.push_back(new Instruction(0x6c, "idiv", 0));
    instructions.push_back(new Instruction(0x6d, "ldiv", 0));
    instructions.push_back(new Instruction(0x6e, "fdiv", 0));
    instructions.push_back(new Instruction(0x6f, "ddiv", 0));
    instructions.push_back(new Instruction(0x70, "irem", 0));
    instructions.push_back(new Instruction(0x71, "lrem", 0));
    instructions.push_back(new Instruction(0x72, "frem", 0));
    instructions.push_back(new Instruction(0x73, "drem", 0));
    instructions.push_back(new Instruction(0x74, "ineg", 0));
    instructions.push_back(new Instruction(0x75, "lneg", 0));
    instructions.push_back(new Instruction(0x76, "fneg", 0));
    instructions.push_back(new Instruction(0x77, "dneg", 0));
    instructions.push_back(new Instruction(0x78, "ishl", 0));
    instructions.push_back(new Instruction(0x79, "lshl", 0));
    instructions.push_back(new Instruction(0x7a, "ishr", 0));
    instructions.push_back(new Instruction(0x7b, "lshr", 0));
    instructions.push_back(new Instruction(0x7c, "iushr", 0));
    instructions.push_back(new Instruction(0x7d, "lushr", 0));
    instructions.push_back(new Instruction(0x7e, "iand", 0));
    instructions.push_back(new Instruction(0x7f, "land", 0));
    instructions.push_back(new Instruction(0x80, "ior", 0));
    instructions.push_back(new Instruction(0x81, "lor", 0));
    instructions.push_back(new Instruction(0x82, "ixor", 0));
    instructions.push_back(new Instruction(0x83, "lxor", 0));
    instructions.push_back(new Instruction(0x84, "iinc", 2));
    
    // CONVERSIONS

    instructions.push_back(new Instruction(0x85, "i2l", 0));
    instructions.push_back(new Instruction(0x86, "i2f", 0));
    instructions.push_back(new Instruction(0x87, "i2d", 0));
    instructions.push_back(new Instruction(0x88, "l2i", 0));
    instructions.push_back(new Instruction(0x89, "l2f", 0));
    instructions.push_back(new Instruction(0x8a, "l2d", 0));
    instructions.push_back(new Instruction(0x8b, "f2i", 0));
    instructions.push_back(new Instruction(0x8c, "f2l", 0));
    instructions.push_back(new Instruction(0x8d, "f2d", 0));
    instructions.push_back(new Instruction(0x8e, "d2i", 0));
    instructions.push_back(new Instruction(0x8f, "d2l", 0));
    instructions.push_back(new Instruction(0x90, "d2f", 0));
    instructions.push_back(new Instruction(0x91, "i2b", 0));
    instructions.push_back(new Instruction(0x92, "i2c", 0));
    instructions.push_back(new Instruction(0x93, "i2s", 0));
    
    //COMPARISONS

    instructions.push_back(new Instruction(0x94, "lcmp", 0));
    instructions.push_back(new Instruction(0x95, "fcmpl", 0));
    instructions.push_back(new Instruction(0x96, "fcmpg", 0));
    instructions.push_back(new Instruction(0x97, "dcmpl", 0));
    instructions.push_back(new Instruction(0x98, "dcmpg", 0));
    instructions.push_back(new Instruction(0x99, "ifeq", 2));
    instructions.push_back(new Instruction(0x9a, "ifne", 2));
    instructions.push_back(new Instruction(0x9b, "iflt", 2));
    instructions.push_back(new Instruction(0x9c, "ifge", 2));
    instructions.push_back(new Instruction(0x9d, "ifgt", 2));
    instructions.push_back(new Instruction(0x9e, "ifle", 2));
    instructions.push_back(new Instruction(0x9f, "if_icmpeq", 2));
    instructions.push_back(new Instruction(0xa0, "if_icmpne", 2));
    instructions.push_back(new Instruction(0xa1, "if_icmplt", 0));
    instructions.push_back(new Instruction(0xa2, "if_icmpge", 0));
    instructions.push_back(new Instruction(0xa3, "if_icmpgt", 0));
    instructions.push_back(new Instruction(0xa4, "if_icmple", 0));
    instructions.push_back(new Instruction(0xa5, "if_acmpeq", 2));
    instructions.push_back(new Instruction(0xa6, "if_acmpne", 2));
    
    //CONTROL

    instructions.push_back(new Instruction(0xa7, "goto", 2));
    instructions.push_back(new Instruction(0xa8, "jsr", 2));
    instructions.push_back(new Instruction(0xa9, "ret", 1));
    instructions.push_back(new Instruction(0xaa, "tableswitch", 14));
    instructions.push_back(new Instruction(0xab, "lookupswitch", 10));
    instructions.push_back(new Instruction(0xac, "ireturn", 0));
    instructions.push_back(new Instruction(0xad, "lreturn", 0));
    instructions.push_back(new Instruction(0xae, "freturn", 0));
    instructions.push_back(new Instruction(0xaf, "dreturn", 0));
    instructions.push_back(new Instruction(0xb0, "areturn", 0));
    instructions.push_back(new Instruction(0xb1, "return", 0));
    
    //REFERENCES

    instructions.push_back(new Instruction(0xb2, "getstatic", 2));
    instructions.push_back(new Instruction(0xb3, "putstatic", 2));
    instructions.push_back(new Instruction(0xb4, "getfield", 2));
    instructions.push_back(new Instruction(0xb5, "putfield", 2));
    instructions.push_back(new Instruction(0xb6, "invokevirtual", 2));
    instructions.push_back(new Instruction(0xb7, "invokespecial", 2));
    instructions.push_back(new Instruction(0xb8, "invokestatic", 2));
    instructions.push_back(new Instruction(0xb9, "invokeinterface", 4));
    instructions.push_back(new Instruction(0xba, "invokedynamic", 4));
    instructions.push_back(new Instruction(0xbb, "new", 2));
    instructions.push_back(new Instruction(0xbc, "newarray", 1));
    instructions.push_back(new Instruction(0xbd, "anewarray", 2));
    instructions.push_back(new Instruction(0xbe, "arraylength", 0));
    instructions.push_back(new Instruction(0xbf, "athrow", 0));
    instructions.push_back(new Instruction(0xc0, "checkcast", 2));
    instructions.push_back(new Instruction(0xc1, "instanceof", 2));
    instructions.push_back(new Instruction(0xc2, "monitorenter", 0));
    instructions.push_back(new Instruction(0xc3, "monitorexit", 0));
    
    //EXTENDED
    
    instructions.push_back(new Instruction(0xc4, "wide", 3));
    instructions.push_back(new Instruction(0xc5, "multinewarray", 3));
    instructions.push_back(new Instruction(0xc6, "ifnull", 2));
    instructions.push_back(new Instruction(0xc7, "ifnonnull", 2));
    instructions.push_back(new Instruction(0xc8, "goto_w", 4));
    instructions.push_back(new Instruction(0xc9, "jsr_w", 4));
    instructions.push_back(new Instruction(0xca, "breakpoint", 0));
    instructions.push_back(new Instruction(0xfe, "impdep1", 0));
    instructions.push_back(new Instruction(0xff, "impdep2", 0));

    return instructions;    
}

Instruction* InstructionVector::GetInstruction(int position) {
    return instructions.at(position);
}


int InstructionVector::GetSize() {
    return instructions.size();
}

int InstructionVector::ShowInstruction(u1 opcode) {

    Instruction* inst;

    for (int i = 0; i < (int) instructions.size(); i++) {
        inst = instructions.at(i);
        if (opcode == inst->GetOpcode()) {
            std::cout << "\t\t" << inst->GetMnemonic();
            if (inst->GetSize()) {
                /**
                for (int i = 0; i < inst->GetSize(); i++) {
                    std::cout << operands[i] << " "; 
                }
                **/
            }
            std::cout << std::endl;
            return inst->GetSize();
        }
    }
    return -1;
}