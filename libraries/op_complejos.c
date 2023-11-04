#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "op_complejos.h"

#define EPSILON 1e-5

C leerC(void){
	C a;
	
	printf("\nEscriba la parte real e imaginaria del complejo:");
	scanf("%lg%lg",&a.re,&a.im);
	
	return a;
}

int escC(C a){
     
     if(a.re==0&&a.im==0) printf("0");
     else{
     	if(a.re==0);
     	else printf("%lg",a.re);
     	if (a.im==0);
     	else{
     		if(a.im==1) printf("+i");
     		else{
     			if(a.im==-1) printf("-i");
     		    else printf("%+lgi",a.im);	
			 }
     		
		 }
	 }
	 return 0;
}

C fleerC(FILE *f){
	C a;
	fscanf(f,"%lg%lg",&a.re,&a.im);	
	return a;
}

int fescC(FILE *f, C a){
     
     if(a.re==0&&a.im==0) fprintf(f,"0");
     else{
     	if(a.re==0);
		     fprintf(f,"%+lg",a.re);	
		 }
     	if (a.im==0);
     	else{
    
     		if(a.im==1) fprintf(f,"%+i");
     		else{
     			if(a.im==-1) fprintf(f,"%-i");
     		    else fprintf(f,"%+lgi",a.im);	
			 }
     		
		 }
		 return 0;
	 }


C sumaC(C a,C b){	
	C c;
	
	c.re=a.re+b.re;
	c.im=a.im+b.im;
	
	return c;	
}

C restaC(C a,C b){		
	C c;
	
	c.re=a.re-b.re;
	c.im=a.im-b.im;
	
	return c;
}

C prodC(C a,C b){	
	C c;
	
	c.re=a.re*b.re-a.im*b.im;
	c.im=a.re*b.im+a.im*b.re;
	
	return c;
}

C invC(C a){
	C c; 
	double n;
	
	n=sqrt(a.re*a.re+a.im*a.im);
	c.re=a.re/(n*n);
	c.im=-a.im/(n*n);
	
	if(-EPSILON<=c.re && c.re<EPSILON) c.re=0;
	if(-EPSILON<=c.im && c.im<EPSILON) c.im=0;
	
	return c;
	 
}

C divC(C a,C b){	
	C c;
	
	b=invC(b);
	c=prodC(a,b);
	
	return c;
}

C expC(C a,int e){
    C ret={re:a.re,im:a.im};
    int i;

    for(i=0;i<e-1;i++) ret=prodC(ret,a);
    
    return ret;
}
