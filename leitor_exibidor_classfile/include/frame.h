#ifndef FRAME
#define FRAME

#include "data_class_format.h"
#include "classfile.h"
#include "methods.h"
#include "constant_pool.h"
#include <vector>
#include <sstream>
#include <stack>

class StackOp{
    protected:
    u2 op;
    
    public:
    inline u2 GetOp(){return op;};
};

typedef struct frame_s{
	unsigned char *pc;
    ConstantPoolInfo *cp;
    // std::stack<StackOp*> operandsStack;
    // std::vector<Variable*> variablesVector;
	MethodsInfo m;
} frame;


class Frame{
    protected:
        // std::stack<StackOp*> operandsStack;
        // std::vector<Variable*> variablesVector;
        // std::stack<frame*> framestack;
        // u4 pc;
        // CodeAtt* code;
        // ClassFile *class_file;
        // MethodsInfo* method;
        
        int opcode;
        bool nextInstruction();
        
    public:
        std::stack<uint32_t> operandsStack;
        std::vector<uint32_t> variablesVector;
        std::stack<frame*> framestack;
        uint32_t pc;
        CodeAtt* code;
        ClassFile *class_file;
        MethodsInfo* method;

        // Frame (ClassFile*);
        Frame (ClassFile*, MethodsInfo&);

        void execute();
        static void setopcode();

        // Frame(ClassFile*, ConstantPool*, u2);
    
};

#endif