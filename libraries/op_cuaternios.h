#ifndef op_cuaternios
#define op_cuaternios

#ifdef __cplusplus
extern "C" {
#endif

#define EPSILON 1e-15

typedef struct _H_{
  double r,i,j,k;
}H;

int escH(H x);
H leerH(void);

int fescH(FILE *f, H x);
H fleerH(FILE *f);

H sumaH(H x,H y);
H restaH(H x,H y);
H prodH(H x,H y);
H expH(H a, int e);
H invH(H a);
H divH(H a,H b);

#ifdef __cplusplus
}
#endif

#endif
