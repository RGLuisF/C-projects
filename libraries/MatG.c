#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>     
#include <time.h>

#include "op_gaussianos.h"
#include "MatG.h"

int fescribeG(FILE *f, G a){
   char str[128];
   	
   	if(a.re!=0.0){
      if(a.im==0.0) sprintf(str, "%d", a.re);
	  else{
		if(a.im==1.0) sprintf(str, "%d+i", a.re);
		else{
			if(a.im==-1.0) sprintf(str, "%d-i", a.re);
			else{
				sprintf(str, "%d%+di",a.re,a.im);
			}
		   }
	      }
		 }
		 
	else {
	  if(a.im==1.0) sprintf(str, "i");
		else{
			if(a.im==-1.0) sprintf(str, "-i");
			else{
				sprintf(str, "%+di",a.im);	
	       }
       }
   }
	 fprintf(f,"%23s", str);
	 return 0;
}

matG creamatG (int m, int n){
	matG ret={m:m, n:n, ent:NULL};
	int i,j;
	
	ret.ent = (G **)malloc(m*sizeof(G*));
    if(ret.ent==NULL) return ret;
    for(i=0; i<m; i++){
    ret.ent[i]=(G*)malloc(n*sizeof(G));
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

matG leematG(FILE *f){
    int m,n,i,j;
    matG ret;

    fscanf(f, "%d%d", &m, &n);
    ret = creamatG(m, n);
    for(i=0; i<m; i++)
    for(j=0; j<n; j++)
      ret.ent[i][j]=fleerG(f);
      
    return ret;
}

int escmatG(FILE *f, matG A){
	int i, j;

    fprintf(f, "%d %d\n", A.m, A.n);
    for(i=0; i<A.m; i++){
    for(j=0; j<A.n; j++)
      fescribeG(f, A.ent[i][j]);
    fprintf(f, "\n");
  }

  return 0;
}

matG sumamatG(matG A, matG B){
	matG ret;
	int i,j;

	ret.m=ret.n=0;
	ret.ent=NULL;
	if(A.m!=B.m || A.n!=B.n) printf("\nNo se puede realizar la suma");
	else{
	ret=creamatG(A.m, A.n);
	for(i=0;i<A.m;i++)
		for(j=0;j<A.n;j++){
			ret.ent[i][j]=sumaG(A.ent[i][j], B.ent[i][j]);
		}
	}	
	return ret;
}

matG restamatG(matG A, matG B){
    matG ret;
	int i,j;

	ret.m=ret.n=0;
	ret.ent=NULL;
	if(A.m!=B.m || A.n!=B.n) printf("\nNo se puede realizar la resta");
	else{
	ret=creamatG(A.m, A.n);
	for(i=0;i<A.m;i++)
		for(j=0;j<A.n;j++){
			ret.ent[i][j]=restaG(A.ent[i][j], B.ent[i][j]);
		}
	}	
	return ret;
}

matG prodmatG(matG A, matG B){
	matG ret={m:0, n:0, ent:NULL};
    int i, j, k;

    if (A.n!=B.m) return ret;
    ret=creamatG(A.m, B.n);
    for(i=0; i<ret.m; i++)
    for(j=0; j<ret.n; j++)
      for(k=0; k<A.n; k++)
	ret.ent[i][j]=sumaG(ret.ent[i][j], prodG(A.ent[i][k], B.ent[k][j]));

  return ret;
}

int limpiamatG(matG *A){
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
