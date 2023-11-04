#ifndef Zpx
#define Zpx

#ifdef __cplusplus
extern "C"{
#endif

#include "Zp.h"

typedef struct ZPx{
  int g;
  Zp *c;
 }Zx;

void limpiaZx(Zx *a);
int escero(Zx a);

int escZx(FILE *f, Zx a);
Zx leeZx(FILE *f, int p);
Zx copiaZx(Zx a);
Zx copiamenosZx(Zx a);

Zx sumaZx(Zx a, Zx b);
Zx restaZx(Zx a, Zx b);
Zx prodZx(Zx a, Zx b);
Zx monoZx(Zx a, Zp b, int e);
Zx divZx(Zx a, Zx b, Zx *res);
Zx mcdZx(Zx a, Zx b);
Zx derivaZx(Zx a);
Zx integraZx(Zx a);
Zp evaluaZx(Zx a,Zp e);

#ifdef __cplusplus
}
#endif

#endif
