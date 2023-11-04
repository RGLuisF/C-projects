#ifndef Gx
#define Gx

#ifdef _cplusplus
extern "C"{
#endif

#include "op_gaussianos.h"

typedef struct Gx{
int g;
G *c;	
}Gx;

void limpiaGx(Gx *a);
int escero(Gx a);

int escGx(FILE *f,Gx a);
Gx leeGx(FILE *f);

Gx copiaGx(Gx a);
Gx copiamenosGx(Gx a);
Gx sumaGx(Gx a, Gx b);
Gx restaGx(Gx a, Gx b);
Gx prodGx(Gx a, Gx b);
Gx monoGx(Gx a, G b, int e);
Gx derivaGx(Gx a);
G evaluaGx(Gx a, G e);

#ifdef __cplusplus
}
#endif

#endif
