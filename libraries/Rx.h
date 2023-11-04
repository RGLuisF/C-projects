#ifndef Rx	
#define Rx

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Rx{
int g;
double *c;	
}Rx;

void limpiaRx(Rx *a);
int escero(Rx a);
int escRx(FILE *f, Rx a);
Rx leeRx(FILE *f);
Rx copiaRx(Rx a);
Rx copiamenosRx(Rx a);

Rx sumaRx(Rx a, Rx b);
Rx restaRx(Rx a, Rx b);
Rx prodRx(Rx a, Rx b);
Rx monoRx(Rx a, double b, int e);
Rx divRx(Rx a, Rx b, Rx *res);
Rx mcdRx(Rx a, Rx b);
Rx derivaRx(Rx a);
Rx integraRx(Rx a);
double evaluaRx(Rx a, double e);

#ifdef __cplusplus
}
#endif

#endif
