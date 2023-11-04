#ifndef MatZp
#define MatZp

#ifdef __cplusplus
extern "C" {
#endif

#include "Zp.h"

typedef struct MatR{
	int m,n;
	Zp **ent;
}matZp;

matZp creamatZp(int m, int n, int p);
matZp leematZp(FILE *f, int p);
int escmatZp(FILE *f, matZp A);
matZp sumamatZp(matZp A, matZp B);
matZp restamatZp(matZp A, matZp B);
matZp prodmatZp(matZp A, matZp B);
int limpiamatZp(matZp *A);

#ifdef __cplusplus
}
#endif

#endif
