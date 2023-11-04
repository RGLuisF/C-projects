#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>     
#include <time.h>

#include "op_cuaternios.h"
#include "MatH.h"

/*int fescribeH(FILE *f, H a){
    char str[128], r[32]="\0", i[32]="\0", j[32]="\0", k[32]="\0";	
    
    if(a.r==0.0&&a.i==0.0&&a.j==0.0&&a.k==0.0) sprintf(str,"0");
	else{
        if(a.r==0.0);
	    else sprintf(r,"%lg",a.r);
        if(a.i==0.0);
        else {
    	    if(a.i==1) sprintf(i,"+i");
    	    else{
    	    	if(a.i==-1) sprintf(i,"-i");
    	        else sprintf(i,"%+lgi",a.i);
			  }
	        }
        if(a.j==0.0);
	    else {
    	    if(a.j==1) sprintf(j,"+j");
    	    else{
    	        if(a.j==-1) sprintf(j,"-j");
    	        else sprintf(j,"%+lgj",a.j);
    	        }
	        }
        if(a.k==0.0);
        else{
    	     if(a.k==1) sprintf(k,"+k");
    	     else{
			    if(a.k==-1) printf(k,"-k");
    	        else sprintf(k,"%+lgk",a.k);
			     } 
	        }
	    sprintf(str,"%s%s%s%s",r,i,j,k);
   }
    fprintf(f,"%40s",str);
    return 0;
}*/

int fescribeH(FILE *f, H a)
{ 
  char str[128], r[32]="\0", i[32]="\0", j[32]="\0", k[32]="\0";
  
  if (a.r != 0.0) sprintf(r,"%lg", a.r);
  
  if (a.i != 0.0) {
    if (a.i != 1.0 && a.i != -1.0) sprintf(i,"%+lgi", a.i);
    else sprintf(i,"%ci", a.i<0?'-':'+');
  }
  
  if (a.j != 0.0) {
    if (a.j != 1.0 && a.j != -1.0) sprintf(j,"%+lgj", a.j);
    else sprintf(j,"%cj", a.j<0?'-':'+');
  }
  
  if (a.k != 0.0) {
    if (a.k != 1.0 && a.k != -1.0) sprintf(k,"%+lgk", a.k);
    else sprintf(k,"%ck", a.k<0?'-':'+');
  }
  
  if (a.r==0.0&&a.i==0.0&&a.j==0.0&&a.k==0.0) sprintf(str,"0");
  else sprintf(str,"%s%s%s%s",r,i,j,k);
  
  fprintf(f,"%25s",str);
  return 0;
}

matH creamatH (int m, int n){
	matH ret={m:m, n:n, ent:NULL};
	int i,j;
	
	ret.ent = (H **)malloc(m*sizeof(H*));
    if(ret.ent==NULL) return ret;
    for(i=0; i<m; i++){
    ret.ent[i]=(H*)malloc(n*sizeof(H));
    if(ret.ent[i]==NULL){
      while(--i>=0) free(ret.ent[i]);
      free(ret.ent);
      ret.ent=NULL;
      break;
	  }
		for(j=0;j<n;j++){
			ret.ent[i][j].r=0.0;
			ret.ent[i][j].i=0.0;
			ret.ent[i][j].j=0.0;
			ret.ent[i][j].k=0.0;
		}
    }
    return ret;
}

matH leematH(FILE *f){
    int m,n,i,j;
    matH ret;

    fscanf(f, "%d%d", &m, &n);
    ret = creamatH(m, n);
    for(i=0; i<m; i++)
    for(j=0; j<n; j++)
      ret.ent[i][j]=fleerH(f);
      
    return ret;
}

int escmatH(FILE *f, matH A){
	int i, j;

    fprintf(f, "%d %d\n", A.m, A.n);
    for(i=0; i<A.m; i++){
    for(j=0; j<A.n; j++)
      fescribeH(f, A.ent[i][j]);
    fprintf(f, "\n");
  }

  return 0;
}

matH sumamatH(matH A, matH B){
	matH ret;
	int i,j;

	ret.m=ret.n=0;
	ret.ent=NULL;
	if(A.m!=B.m || A.n!=B.n) printf("\nNo se puede realizar la suma");
	else{
	ret=creamatH(A.m, A.n);
	for(i=0;i<A.m;i++)
		for(j=0;j<A.n;j++){
			ret.ent[i][j]=sumaH(A.ent[i][j], B.ent[i][j]);
		}
	}	
	return ret;
}

matH restamatH(matH A, matH B){
    matH ret;
	int i,j;

	ret.m=ret.n=0;
	ret.ent=NULL;
	if(A.m!=B.m || A.n!=B.n) printf("\nNo se puede realizar la resta");
	else{
	ret=creamatH(A.m, A.n);
	for(i=0;i<A.m;i++)
		for(j=0;j<A.n;j++){
			ret.ent[i][j]=restaH(A.ent[i][j], B.ent[i][j]);
		}
	}	
	return ret;
}

matH prodmatH(matH A, matH B){
	matH ret={m:0, n:0, ent:NULL};
    int i, j, k;

    if (A.n!=B.m) return ret;
    ret=creamatH(A.m, B.n);
    for(i=0; i<ret.m; i++)
    for(j=0; j<ret.n; j++)
      for(k=0; k<A.n; k++)
	ret.ent[i][j]=sumaH(ret.ent[i][j], prodH(A.ent[i][k], B.ent[k][j]));

  return ret;
}

int limpiamatH(matH *A){
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
