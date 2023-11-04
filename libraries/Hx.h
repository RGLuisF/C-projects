#ifndef Hx
#define Hx

#ifdef __cplusplus
extern "C" {
#endif

#include "op_cuaternios.h"

typedef struct Hx{
int g;
H *c;	
}Hx;

void limpiaHx(Hx *a);
int escero(Hx a);
int escHx(FILE *f, Hx a);
Hx leeHx(FILE *f);
Hx copiaHx(Hx a);
Hx copiamenosHx(Hx a);

Hx sumaHx(Hx a, Hx b);
Hx restaHx(Hx a, Hx b);
Hx prodHx(Hx a, Hx b);
Hx monoHx(Hx a, H b, int e);
Hx divHx(Hx a, Hx b, Hx *res);
Hx mcdHx(Hx a, Hx b);
Hx derivaHx(Hx a);
Hx integraHx(Hx a);
H evaluaHx(Hx a, H e);

#ifdef __cplusplus
}
#endif

#endif
