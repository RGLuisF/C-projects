#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>     

#include "Zp.h"
#include "MatZp.h"

matZp creamatZp (int m, int n, int p){
	matZp ret={m:m, n:n, ent:NULL};
	int i,j;
	
	ret.ent = (Zp **)malloc(m*sizeof(Zp*));
    if(ret.ent==NULL) return ret;
    for(i=0; i<m; i++){
        ret.ent[i]=(Zp*)malloc(n*sizeof(Zp));
      if(ret.ent[i]==NULL){
        while(--i>=0) free(ret.ent[i]);
        free(ret.ent);
        ret.ent=NULL;
        break;
	    }
      for (j=0; j<n; j++){
        ret.ent[i][j].p=p;
        ret.ent[i][j].n=0.0;
	   } 
    }
    return ret;
}

matZp leematZp(FILE *f, int p){
    int m,n,i,j;
    matZp ret;

    fscanf(f, "%d%d", &m, &n);
    ret = creamatZp(m, n, p);
    
    for(i=0; i<m; i++)
      for(j=0; j<n; j++) ret.ent[i][j]=fleeZP(f,p);
      
    return ret;
}

int escmatZp(FILE *f, matZp A){
	int i, j;

    fprintf(f, "%d %d\n", A.m, A.n);
    for(i=0; i<A.m; i++){
    for(j=0; j<A.n; j++)
      fescZP(f,A.ent[i][j]);
    fprintf(f, "\n");
  }

  return 0;
}

matZp sumamatZp(matZp A, matZp B){
	matZp ret;
	int i,j;

	ret.m=ret.n=0;
	ret.ent=NULL;
	if(A.m!=B.m || A.n!=B.n) printf("\nNo se puede realizar la suma");
	else{
	ret=creamatZp(A.m, A.n,A.ent[0][0].p);
	for(i=0;i<A.m;i++)
		for(j=0;j<A.n;j++){
			ret.ent[i][j]=sumaZP(A.ent[i][j], B.ent[i][j]);
		}
	}	
	return ret;
}

matZp restamatZp(matZp A, matZp B){
    matZp ret;
	int i,j;

	ret.m=ret.n=0;
	ret.ent=NULL;
	if(A.m!=B.m || A.n!=B.n) printf("\nNo se puede realizar la resta");
	else{
	ret=creamatZp(A.m, A.n, A.ent[0][0].p);
	for(i=0;i<A.m;i++)
		for(j=0;j<A.n;j++){
			ret.ent[i][j]=restaZP(A.ent[i][j], B.ent[i][j]);
		}
	}	
	return ret;
}

matZp prodmatZp(matZp A, matZp B){
	matZp ret={m:0, n:0, ent:NULL};
    int i, j, k;

    if (A.n!=B.m) return ret;
    ret=creamatZp(A.m, B.n, A.ent[0][0].p);
    for(i=0; i<ret.m; i++)
    for(j=0; j<ret.n; j++)
      for(k=0; k<A.n; k++)
	ret.ent[i][j]=sumaZP(ret.ent[i][j], prodZP(A.ent[i][k], B.ent[k][j]));

  return ret;
}

int limpiamatZp(matZp *A){
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
