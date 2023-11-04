#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>     
#include <time.h>

#include "op_racionales.h"
#include "MatQ.h"

matQ creamatQ (int m, int n){
	matQ ret={m:m, n:n, ent:NULL};
	int i,j;
	
	ret.ent = (Q **)malloc(m*sizeof(Q*));
    if(ret.ent==NULL) return ret;
    for(i=0; i<m; i++){
    ret.ent[i]=(Q*)malloc(n*sizeof(Q));
    if(ret.ent[i]==NULL){
      while(--i>=0) free(ret.ent[i]);
      free(ret.ent);
      ret.ent=NULL;
      break;
	  }
    for (j=0; j<n; j++) ret.ent[i][j]=creaQ(0,1);
    }
    return ret;
}

matQ leematQ(FILE *f){
    int m,n,i,j;
    matQ ret;

    fscanf(f, "%d%d", &m, &n);
    ret = creamatQ(m, n);
    for(i=0; i<m; i++)
    for(j=0; j<n; j++)
      ret.ent[i][j]=fleeQ(f);
      
    return ret;
}

int escmatQ(FILE *f, matQ A){
	int i, j;

    fprintf(f, "%d %d\n", A.m, A.n);
    for(i=0; i<A.m; i++){
    for(j=0; j<A.n; j++)
      fescribeQ(f, A.ent[i][j]);
    fprintf(f, "\n");
  }

  return 0;
}

matQ sumamatQ(matQ A, matQ B){
	matQ ret;
	int i,j;

	ret.m=ret.n=0;
	ret.ent=NULL;
	if(A.m!=B.m || A.n!=B.n) printf("\nNo se puede realizar la suma");
	else{
	ret=creamatQ(A.m, A.n);
	for(i=0;i<A.m;i++)
		for(j=0;j<A.n;j++){
			ret.ent[i][j]=sumaQ(A.ent[i][j], B.ent[i][j]);
		}
	}	
	return ret;
}

matQ restamatQ(matQ A, matQ B){
    matQ ret;
	int i,j;

	ret.m=ret.n=0;
	ret.ent=NULL;
	if(A.m!=B.m || A.n!=B.n) printf("\nNo se puede realizar la resta");
	else{
	ret=creamatQ(A.m, A.n);
	for(i=0;i<A.m;i++)
		for(j=0;j<A.n;j++){
			ret.ent[i][j]=restaQ(A.ent[i][j], B.ent[i][j]);
		}
	}	
	return ret;
}

matQ prodmatQ(matQ A, matQ B){
	matQ ret={m:0, n:0, ent:NULL};
    int i, j, k;

    if (A.n!=B.m) return ret;
    ret=creamatQ(A.m, B.n);
    for(i=0; i<ret.m; i++)
    for(j=0; j<ret.n; j++)
      for(k=0; k<A.n; k++)
	ret.ent[i][j]=sumaQ(ret.ent[i][j], prodQ(A.ent[i][k], B.ent[k][j]));

  return ret;
}

int limpiamatQ(matQ *A){
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
