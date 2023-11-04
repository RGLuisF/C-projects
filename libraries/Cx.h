#ifndef Cx
#define Cx

#include "op_complejos.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Cx{
   int g;
   C *c;
}Cx;

void limpiaCx(Cx *a);
int escero(Cx a);
int escCx(FILE *f, Cx a);
Cx leeCx(FILE *f);
Cx copiaCx(Cx a);
Cx copiamenosCx(Cx a);

Cx sumaCx(Cx a, Cx b);
Cx restaCx(Cx a, Cx b);
Cx prodCx(Cx a, Cx b);
Cx monoCx(Cx a, C b, int e);
Cx divCx(Cx a, Cx b, Cx *res);
Cx mcdCx(Cx a, Cx b);
Cx derivaCx(Cx a);
Cx integraCx(Cx a);
C evaluaCx(Cx a, C e);

#ifdef __cplusplus
}
#endif

#endif


