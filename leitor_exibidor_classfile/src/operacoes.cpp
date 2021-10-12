#include "operacoes.h"
#include "frame.h"

frame *Operacoes::f = nullptr;
std::stack<struct frame_s*> *Operacoes::threads = nullptr;
Frame *Operacoes::fs = nullptr;

const fun Operacoes::functions[] ={
        &Operacoes::nop,
	    &Operacoes::aconst_null,
	    &Operacoes::iconst_m1,
	    &Operacoes::iconst_0,
    	&Operacoes::iconst_1,
	    &Operacoes::iconst_2,
	    &Operacoes::iconst_3,
	    &Operacoes::iconst_4,
	    &Operacoes::iconst_5,
	    &Operacoes::lconst_0,
	    &Operacoes::lconst_1,
	    &Operacoes::fconst_0,
	    &Operacoes::fconst_1,
	    &Operacoes::fconst_2,
	    &Operacoes::dconst_0,
	    &Operacoes::dconst_1,    

};

void Operacoes::setFrame(struct frame_s *NewF)
{
	f = NewF;
}

void Operacoes::setThreads(std::stack<struct frame_s*> *t){
	threads = t;
}

void Operacoes::setFrameStack(Frame* newFS){
	fs = newFS;
}

void Operacoes::run(int opcode){
    functions[opcode]();
}

void Operacoes::nop (Frame &frame){
    //0x00
}

void Operacoes::aconst_null (Frame &frame){
    //0x01
	frame.operandsStack.push(0);
	// f->operandsStack->push((int*)(nullptr));
}

void Operacoes::iconst_m1 (Frame &frame){
    //0x02
    frame.operandsStack.push(-1);
	// operandsStack->push(int(-1));
}

void Operacoes::iconst_0 (Frame &frame){
    //0x03
    frame.operandsStack.push(0);
	// operandsStack->push(int(0));
}

void Operacoes::iconst_1 (Frame &frame){
    //0x04
    frame.operandsStack.push(1);
	// operandsStack->push(int(1));
}

void Operacoes::iconst_2 (Frame &frame){
    //0x05
    frame.operandsStack.push(2);
	// operandsStack->push(int(2));
}

void Operacoes::iconst_3 (Frame &frame){
    //0x06
    frame.operandsStack.push(3);
	// operandsStack->push(int(3));
}

void Operacoes::iconst_4 (Frame &frame){
    //0x07
    frame.operandsStack.push(4);
	// operandsStack->push(int(4));
}

void Operacoes::iconst_5 (Frame &frame){
    //0x08
    frame.operandsStack.push(5);
	// operandsStack->push(int(5));
}

void Operacoes::lconst_0 (Frame &frame){
    //0x09
    frame.operandsStack.push(0);
    frame.operandsStack.push(0);
	// operandsStack->push(int(0));
}

void Operacoes::lconst_1 (Frame &frame){
    //0x0a
    frame.operandsStack.push(0);
    frame.operandsStack.push(1);
	// operandsStack->push(int(1));
}

void Operacoes::fconst_0 (Frame &frame){
    //0x0b
	// operandsStack->push(float(0.0f));
}

void Operacoes::fconst_1 (Frame &frame){
    //0x0c
	// operandsStack->push(float(1.0f));
}

void Operacoes::fconst_2 (Frame &frame){
    //0x0d
	// operandsStack->push(float(2.0f));
}

void Operacoes::dconst_0 (Frame &frame){
    //0x0e
	// operandsStack->push(double(0.0d));
}

void Operacoes::dconst_1 (Frame &frame){
    //0x0f
	// operandsStack->push(double(1.0d));
}

//testes double_aritmetica.class

double get_double(Frame &frame)
{
    double xd;
    uint64_t x = frame.operandsStack.top();
    frame.operandsStack.pop();
    x += ((uint64_t)frame.operandsStack.top() << 32);
    frame.operandsStack.pop();
    memcpy(&xd, &x, sizeof(double));
    return xd;
}

void dload_1(Frame &frame)
{
    frame.operandsStack.push(frame.variablesVector[1]);
    frame.operandsStack.push(frame.variablesVector[2]);
}

void dload_3(Frame &frame)
{
    frame.operandsStack.push(frame.variablesVector[3]);
    frame.operandsStack.push(frame.variablesVector[4]);
}

void dstore_3(Frame &frame)
{
    frame.variablesVector[4] = frame.operandsStack.top();
    frame.operandsStack.pop();
    frame.variablesVector[3] = frame.operandsStack.top();
    frame.operandsStack.pop();
}

void dadd(Frame &frame)
{
    double xd = get_double(frame);
    double yd = get_double(frame);
    uint64_t x;
    xd += yd;
    memcpy(&x, &xd, sizeof(double));
    frame.operandsStack.push(x >> 32);
    frame.operandsStack.push(x);
}
