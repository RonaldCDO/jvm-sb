#ifndef FRAME
#define FRAME

#include "data_class_format.h"
#include "methods.h"


class StackOp{
    protected:
    u2 op;
    
    public:
    inline u2 GetOp(){return op;};
};

class Frame{
    protected:
        std::vector<StackOp*> op;
    public:
};

#endif