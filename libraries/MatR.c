#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>     

#include "MatR.h"

matR creamatR (int m, int n){
	matR ret={m:m, n:n, ent:NULL};
	int i,j;
	
	ret.ent = (double **)malloc(m*sizeof(double*));
    if(ret.ent==NULL) return ret;
    for(i=0; i<m; i++){
    ret.ent[i]=(double*)malloc(n*sizeof(double));
    if(ret.ent[i]==NULL){
      while(--i>=0) free(ret.ent[i]);
      free(ret.ent);
      ret.ent=NULL;
      break;
	  }
    for (j=0; j<n; j++) ret.ent[i][j]=0.0;
    }
    return ret;
}

matR leematR(FILE *f){
    int m,n,i,j;
    matR ret;

    fscanf(f, "%d%d", &m, &n);
    ret = creamatR(m, n);
    for(i=0; i<m; i++)
    for(j=0; j<n; j++)
    fscanf(f,"%lf",&ret.ent[i][j]);
      
    return ret;
}

int escmatR(FILE *f, matR A){
	int i, j;

    fprintf(f, "%d %d\n", A.m, A.n);
    for(i=0; i<A.m; i++){
    for(j=0; j<A.n; j++)
      fprintf(f,"%8lg ", A.ent[i][j]);
    fprintf(f, "\n");
  }

  return 0;
}

matR sumamatR(matR A, matR B){
	matR ret;
	int i,j;

	ret.m=ret.n=0;
	ret.ent=NULL;
	if(A.m!=B.m || A.n!=B.n) printf("\nNo se puede realizar la suma");
	else{
	ret=creamatR(A.m, A.n);
	for(i=0;i<A.m;i++)
		for(j=0;j<A.n;j++){
			ret.ent[i][j]=A.ent[i][j]+B.ent[i][j];
		}
	}	
	return ret;
}

matR restamatR(matR A, matR B){
    matR ret;
	int i,j;

	ret.m=ret.n=0;
	ret.ent=NULL;
	if(A.m!=B.m || A.n!=B.n) printf("\nNo se puede realizar la resta");
	else{
	ret=creamatR(A.m, A.n);
	for(i=0;i<A.m;i++)
		for(j=0;j<A.n;j++){
			ret.ent[i][j]=A.ent[i][j]-B.ent[i][j];
		}
	}	
	return ret;
}

matR prodmatR(matR A, matR B){
	matR ret={m:0, n:0, ent:NULL};
    int i, j, k;

    if (A.n!=B.m) return ret;
    ret=creamatR(A.m, B.n);
    for(i=0; i<ret.m; i++)
    for(j=0; j<ret.n; j++)
      for(k=0; k<A.n; k++)
	ret.ent[i][j]+=A.ent[i][k]*B.ent[k][j];

  return ret;
}

int limpiamatR(matR *A){
	int i;
	for(i=0;i<A->m;i++){
		free(A->ent[i]);
		A->ent[i]=NULL;
	}
	free(A->ent);
	A->ent=NULL;
	A->m=A->n=0;
	return 0;
}
