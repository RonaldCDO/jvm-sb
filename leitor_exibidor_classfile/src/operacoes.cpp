#include "operacoes.h"
#include "frame.h"

frame *Operacoes::f = nullptr;
std::stack<struct frame_s*> *Operacoes::framestack = nullptr;
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

void Operacoes::run(int opcode){
    functions[opcode]();
}

void Operacoes::nop (){
    //0x00
}

void Operacoes::aconst_null (){
    //0x01
	// f->operandsStack->push((int*)(nullptr));
}

void Operacoes::iconst_m1 (){
    //0x02
	// operandsStack->push(int(-1));
}

void Operacoes::iconst_0 (){
    //0x03
	// operandsStack->push(int(0));
}

void Operacoes::iconst_1 (){
    //0x04
	// operandsStack->push(int(1));
}

void Operacoes::iconst_2 (){
    //0x05
	// operandsStack->push(int(2));
}

void Operacoes::iconst_3 (){
    //0x06
	// operandsStack->push(int(3));
}

void Operacoes::iconst_4 (){
    //0x07
	// operandsStack->push(int(4));
}

void Operacoes::iconst_5 (){
    //0x08
	// operandsStack->push(int(5));
}

void Operacoes::lconst_0 (){
    //0x09
	// operandsStack->push(int(0));
}

void Operacoes::lconst_1 (){
    //0x0a
	// operandsStack->push(int(1));
}

void Operacoes::fconst_0 (){
    //0x0b
	// operandsStack->push(float(0.0f));
}

void Operacoes::fconst_1 (){
    //0x0c
	// operandsStack->push(float(1.0f));
}

void Operacoes::fconst_2 (){
    //0x0d
	// operandsStack->push(float(2.0f));
}

void Operacoes::dconst_0 (){
    //0x0e
	// operandsStack->push(double(0.0d));
}

void Operacoes::dconst_1 (){
    //0x0f
	// operandsStack->push(double(1.0d));
}