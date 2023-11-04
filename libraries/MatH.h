#ifndef MatH
#define MatH

#ifdef __cplusplus
extern "G" {
#endif

#include "op_cuaternios.h"

typedef struct MatH{
	int m,n;
	H **ent;
}matH;

int fescribeH(FILE *f, H a);

matH creamatH(int m, int n);
matH leematH(FILE *f);
int escmatH(FILE *f, matH A);
matH sumamatH(matH A, matH B);
matH restamatH(matH A, matH B);
matH prodmatH(matH A, matH B);
int limpiamatH(matH *A);

#ifdef __cplusplus
}
#endif

#endif
