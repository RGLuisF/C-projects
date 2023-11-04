#ifndef op_gaussianos
#define op_gaussianos

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _G_{
  int re,im;
}G;

int escG(G a);
G leerG(void);

int fescG(FILE *f, G a);
G fleerG(FILE *f);

G sumaG(G a,G b);
G restaG(G a,G b);
G prodG(G a,G b);
G expG(G a, int e);


#ifdef __cplusplus
}
#endif

#endif
