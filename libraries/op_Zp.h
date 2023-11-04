#ifndef op_Zp
#define op_Zp

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ZP_{
  int p, n;
}Zp;

Zp leeZP(int p);
int escZP(Zp a);

Zp fleeZP(FILE *f, int p);
int fescZP(FILE *f, Zp a);

int simpZP(Zp d);
Zp creaZP(int n, int p);
Zp sumaZP(Zp a, Zp b);
Zp restaZP(Zp a, Zp b);
Zp prodZP(Zp a, Zp b);
Zp expZP(Zp a, int g);
Zp invZP(Zp d);
Zp divZP(Zp a, Zp b);
Zp raizZP(Zp a);

#ifdef __cplusplus
}
#endif

#endif
