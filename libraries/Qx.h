#ifndef Qx
#define Qx

#ifdef __cplusplus
extern "C" {
#endif

#include "op_racionales.h"

typedef struct Qx{
  int g;
  Q *c;
}Qx;

//funciones Qx//
void limpiaQx(Qx *a);
int escero(Qx a);
int escQx(FILE *f, Qx a);
Qx leeQx(FILE *f);
Qx copiaQx(Qx a);
Qx copiamenosQx(Qx a);


Qx sumaQx(Qx a, Qx b);
Qx restaQx(Qx a, Qx b);
Qx prodQx(Qx a, Qx b);
Qx monoQx(Qx a, Q b, int e);
Qx divQx(Qx a, Qx b, Qx *res);
Qx mcdQx(Qx a, Qx b);
Qx derivaQx(Qx a);
Qx integraQx(Qx a);
Q evaluaQx(Qx a, Q e);


#ifdef __cplusplus
}
#endif

#endif
