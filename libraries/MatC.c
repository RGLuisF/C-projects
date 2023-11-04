#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>     
#include <time.h>

#include "op_complejos.h"
#include "MatC.h"

int fescribeC(FILE *f, C a){
   	char str[128];
   	
   	if(a.re!=0.0){
      if(a.im==0.0) sprintf(str, "%lg", a.re);
	  else{
		if(a.im==1.0) sprintf(str, "%lg+i", a.re);
		else{
			if(a.im==-1.0) sprintf(str, "%lg-i", a.re);
			else{
				sprintf(str, "%lg%+lgi",a.re,a.im);
			}
		   }
	      }
		 }
		 
	else{
	  if(a.im==1.0) sprintf(str, "i");
		else{
			if(a.im==-1.0) sprintf(str, "-i");
			else{
				sprintf(str, "%+lgi",a.im);	
	       }
       }
   }
	fprintf(f,"%23s", str);
	return 0;
}

matC creamatC (int m, int n){
	matC ret={m:m, n:n, ent:NULL};
	int i,j;
	
	ret.ent = (C **)malloc(m*sizeof(C*));
    if(ret.ent==NULL) return ret;
    for(i=0; i<m; i++){
    ret.ent[i]=(C*)malloc(n*sizeof(C));
    if(ret.ent[i]==NULL){
      while(--i>=0) free(ret.ent[i]);
      free(ret.ent);
      ret.ent=NULL;
      break;
	  }
		for(j=0;j<n;j++){
			ret.ent[i][j].re=0.0;
			ret.ent[i][j].im=0.0;
		}
    }
    return ret;
}

matC leematC(FILE *f){
    int m,n,i,j;
    matC ret;

    fscanf(f, "%d%d", &m, &n);
    ret = creamatC(m, n);
    for(i=0; i<m; i++)
    for(j=0; j<n; j++)
      ret.ent[i][j]=fleerC(f);
      
    return ret;
}

int escmatC(FILE *f, matC A){
	int i, j;

    fprintf(f, "%d %d\n", A.m, A.n);
    for(i=0; i<A.m; i++){
    for(j=0; j<A.n; j++)
      fescribeC(f, A.ent[i][j]);
    fprintf(f, "\n");
  }

  return 0;
}

matC sumamatC(matC A, matC B){
	matC ret;
	int i,j;

	ret.m=ret.n=0;
	ret.ent=NULL;
	if(A.m!=B.m || A.n!=B.n) printf("\nNo se puede realizar la suma");
	else{
	ret=creamatC(A.m, A.n);
	for(i=0;i<A.m;i++)
		for(j=0;j<A.n;j++){
			ret.ent[i][j]=sumaC(A.ent[i][j], B.ent[i][j]);
		}
	}	
	return ret;
}

matC restamatC(matC A, matC B){
    matC ret;
	int i,j;

	ret.m=ret.n=0;
	ret.ent=NULL;
	if(A.m!=B.m || A.n!=B.n) printf("\nNo se puede realizar la resta");
	else{
	ret=creamatC(A.m, A.n);
	for(i=0;i<A.m;i++)
		for(j=0;j<A.n;j++){
			ret.ent[i][j]=restaC(A.ent[i][j], B.ent[i][j]);
		}
	}	
	return ret;
}

matC prodmatC(matC A, matC B){
	matC ret={m:0, n:0, ent:NULL};
    int i, j, k;

    if (A.n!=B.m) return ret;
    ret=creamatC(A.m, B.n);
    for(i=0; i<ret.m; i++)
    for(j=0; j<ret.n; j++)
      for(k=0; k<A.n; k++)
	ret.ent[i][j]=sumaC(ret.ent[i][j], prodC(A.ent[i][k], B.ent[k][j]));

  return ret;
}

int limpiamatC(matC *A){
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
