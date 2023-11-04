#ifndef MatG
#define MatG

#ifdef __cplusplus
extern "G" {
#endif

#include "op_gaussianos.h"

typedef struct MatG{
	int m,n;
	G **ent;
}matG;

int fescribeG(FILE *f, G a);

matG creamatG(int m, int n);
matG leematG(FILE *f);
int escmatG(FILE *f, matG A);
matG sumamatG(matG A, matG B);
matG restamatG(matG A, matG B);
matG prodmatG(matG A, matG B);
int limpiamatG(matG *A);

#ifdef __cplusplus
}
#endif

#endif
