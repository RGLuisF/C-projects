#ifndef _op_complejos_
#define _op_complejos_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _C_{
  double re, im;
}C;

C leerC(void);
int escC(C a);

C fleerC(FILE *f);
int fescC(FILE *f, C a);

C sumaC(C a, C b);
C restaC(C a, C b);
C prodC(C a, C b);
C invC(C a);
C divC(C a, C b);
C expC(C a,int e);

#ifdef __cplusplus
}
#endif

#endif
