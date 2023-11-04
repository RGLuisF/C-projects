#ifndef op_racionales
#define op_racionales

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _Q_{
  int p, q;
}Q;

int mcd(int a, int b);
Q leeQ(void);
Q fleeQ(FILE *f);
int escribeQ(Q a);
int fescribeQ(FILE *f, Q a);
Q creaQ(int num, int den);
Q simplificaQ(Q a);

Q sumaQ(Q a, Q b);
Q restaQ(Q a, Q b);
Q prodQ(Q a, Q b);
Q expQ(Q a, int g);
Q divQ(Q a, Q b);

Q sumaQ(Q a, Q b);
Q multQ(Q a, Q b);

#ifdef __cplusplus
}
#endif

#endif
