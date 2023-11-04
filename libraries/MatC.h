#ifndef MatC
#define MatC

#ifdef __cplusplus
extern "C" {
#endif

#include "op_complejos.h"

typedef struct MatC{
	int m,n;
	C **ent;
}matC;

int fescribeC(FILE *f, C a);

matC creamatC(int m, int n);
matC leematC(FILE *f);
int escmatC(FILE *f, matC A);
matC sumamatC(matC A, matC B);
matC restamatC(matC A, matC B);
matC prodmatC(matC A, matC B);
int limpiamatC(matC *A);

#ifdef __cplusplus
}
#endif

#endif
