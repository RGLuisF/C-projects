#ifndef MatQ
#define MatQ

#ifdef __cplusplus
extern "C" {
#endif

#include "op_racionales.h"

typedef struct MatQ{
	int m,n;
	Q **ent;
}matQ;

matQ creamatQ(int m, int n);
matQ leematQ(FILE *f);
int escmatQ(FILE *f, matQ A);
matQ sumamatQ(matQ A, matQ B);
matQ restamatQ(matQ A, matQ B);
matQ prodmatQ(matQ A, matQ B);
int limpiamatQ(matQ *A);

#ifdef __cplusplus
}
#endif

#endif
