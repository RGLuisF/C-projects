#include <stdio.h>
#include <stdlib.h>

#include "op_cuaternios.h"

H leerH(void){
	H x;
	
	printf("\nIntroduzca las entradas real, i, j y k del cuaternio\n");
	scanf("%lg%lg%lg%lg",&x.r,&x.i,&x.j,&x.k);
	
	return x;
}


int escH(H x){
	
  	if(x.r==0.0&&x.i==0.0&&x.j==0.0&&x.k==0.0) printf("0");
	else{
        if(x.r==0.0);
	    else printf("%lg",x.r);
        if(x.i==0.0);
        else {
    	    if(x.i==1) printf("+i");
    	    else{
    	    	if(x.i==-1) printf("-i");
    	        else printf("%+lgi",x.i);
			  }
	        }
        if(x.j==0.0);
	    else {
    	    if(x.j==1) printf("+j");
    	    else{
    	        if(x.j==-1) printf("-j");
    	        else printf("%+lgj",x.j);
    	        }
	        }
        if(x.k==0.0);
        else{
    	     if(x.k==1) printf("+k");
    	     else{
			    if(x.k==-1) printf("-k");
    	        else printf("%+lgk",x.k);
			  }
    	     
	        }
   }
   return 0;
}

int fescH(FILE *f, H x){
	
  	if(x.r==0.0&&x.i==0.0&&x.j==0.0&&x.k==0.0) fprintf(f,"0");
	else{
        if(x.r==0.0);
	    else fprintf(f,"%lg",x.r);
        if(x.i==0.0);
        else {
    	    if(x.i==1) fprintf(f,"+i");
    	    else{
    	    	if(x.i==-1) fprintf(f,"-i");
    	        else fprintf(f,"%+lgi",x.i);
			  }
	        }
        if(x.j==0.0);
	    else {
    	    if(x.j==1) fprintf(f,"+j");
    	    else{
    	        if(x.j==-1) fprintf(f,"-j");
    	        else fprintf(f,"%+lgj",x.j);
    	        }
	        }
        if(x.k==0.0);
        else{
    	     if(x.k==1) fprintf(f,"+k");
    	     else{
			    if(x.k==-1) fprintf(f,"-k");
    	        else fprintf(f,"%+lgk",x.k);
			  }
    	     
	        }
   }
   return 0;
}

H fleerH(FILE *f){
	H x;
	fscanf(f,"%lg%lg%lg%lg",&x.r,&x.i,&x.j,&x.k);	
	return x;
}


H sumaH(H x, H y){
	
 H r;
 
 r.r=x.r+y.r;
 r.i=x.i+y.i;
 r.j=x.j+y.j;
 r.k=x.k+y.k;

 return r;	
}

H restaH(H x, H y){
 
 H r;
 
 r.r=x.r-y.r;
 r.i=x.i-y.i;
 r.j=x.j-y.j;
 r.k=x.k-y.k;
 
 return r;	
}

H prodH(H a, H b)
{
  H ret={
    a.r*b.r - a.i*b.i - a.j*b.j - a.k*b.k,
    a.r*b.i + a.i*b.r + a.j*b.k - a.k*b.j,
    a.r*b.j - a.i*b.k + a.j*b.r + a.k*b.i,
    a.r*b.k + a.i*b.j - a.j*b.i + a.k*b.r
  };

  if (-EPSILON <= ret.r && ret.r <= EPSILON) ret.r = 0.0;
  if (-EPSILON <= ret.i && ret.i <= EPSILON) ret.i = 0.0;
  if (-EPSILON <= ret.j && ret.j <= EPSILON) ret.j = 0.0;
  if (-EPSILON <= ret.k && ret.k <= EPSILON) ret.k = 0.0;

  return ret;
}

H expH(H a, int e){
	
 H ret={r:a.r,i:a.i,j:a.j,k:a.k};
 int i;
 
 for(i=0;i<e-1;i++) ret=prodH(ret,a);
 
 return ret;
}

H invH(H h){
  double norma2=h.r*h.r+h.i*h.i+h.j*h.j+h.k*h.k;
  H ret={h.r, -h.i, -h.j, -h.k};

  if (norma2==0.0) return h;
  ret.r/=norma2;
  ret.i/=norma2;
  ret.j/=norma2;
  ret.k/=norma2;

  if (-EPSILON <= ret.r && ret.r <= EPSILON) ret.r = 0.0;
  if (-EPSILON <= ret.i && ret.i <= EPSILON) ret.i = 0.0;
  if (-EPSILON <= ret.j && ret.j <= EPSILON) ret.j = 0.0;
  if (-EPSILON <= ret.k && ret.k <= EPSILON) ret.k = 0.0;

  return ret;
}

H divH(H a, H b)
{
  return prodH(a, invH(b));
}
