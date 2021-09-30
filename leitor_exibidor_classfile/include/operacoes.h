#include "frame.h"

class Operacoes {

private:

	static void nop();
	static void aconst_null();
	static void iconst_m1();
	static void iconst_0();
	static void iconst_1();
	static void iconst_2();
	static void iconst_3();
	static void iconst_4();
	static void iconst_5();
	static void lconst_0();
	static void lconst_1();
	static void fconst_0();
	static void fconst_1();
	static void fconst_2();
	static void dconst_0();
	static void dconst_1();

public:
    static void run(int);
};