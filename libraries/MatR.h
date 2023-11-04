#ifndef MatR
#define MatR

#ifdef __cplusplus
extern "C" {
#endif

typedef struct MatR{
	int m,n;
	double **ent;
}matR;

matR creamatR(int m, int n);
matR leematR(FILE *f);
int escmatR(FILE *f, matR A);
matR sumamatR(matR A, matR B);
matR restamatR(matR A, matR B);
matR prodmatR(matR A, matR B);
int limpiamatR(matR *A);

#ifdef __cplusplus
}
#endif

#endif
