#ifndef FRAME
#define FRAME

#include "data_class_format.h"
#include "classfile.h"
#include "methods.h"
#include "constant_pool.h"
#include <vector>
#include <sstream>
#include <stack>

typedef struct frame_s{
	unsigned char *pc;
    ConstantPool cp;
    std::stack<StackOp*> operandsStack;
    std::vector<Variable*> variablesVector;
	// methodsinfo;
} frame;

class StackOp{
    protected:
    u2 op;
    
    public:
    inline u2 GetOp(){return op;};
};


class Frame{
    protected:
        std::stack<StackOp*> operandsStack;
        std::vector<Variable*> variablesVector;
        u4 pc;
        
    public:

        Frame (ClassFile*);

        void execute();
        static void setopcode();

        // Frame(ClassFile*, ConstantPool*, u2);
    
};

#endif