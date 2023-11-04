#include <stdlib.h>
#include <stdio.h>

#include "op_gaussianos.h"

G leerG(void){
	G a;
	
	printf("\nEscriba la parte real e imaginaria del Gaussiano:");
	scanf("%d%d",&a.re,&a.im);
	
	return a;
}

int escG(G a){
     
     if(a.re==0&&a.im==0) printf("0");
     else{
     	if(a.re==0);
     	else printf("%d",a.re);
     	if (a.im==0);
     	else{
     		if(a.im==1) printf("+i");
     		else{
     			if(a.im==-1) printf("-i");
     		    else printf("%+di",a.im);	
			 }
     		
		 }
	 }
	 return 0;
}

int fescG(FILE *f, G a){
     
     if(a.re==0&&a.im==0) fprintf(f,"0");
     else{
     	if(a.re==0);
     	else fprintf(f,"%d",a.re);
     	if (a.im==0);
     	else{
     		if(a.im==1) fprintf(f,"+i");
     		else{
     			if(a.im==-1) fprintf(f,"-i");
     		    else fprintf(f,"%+di",a.im);	
			 }
     		
		 }
	 }
	 return 0;
}

G fleerG(FILE *f){
	G a;

	fscanf(f,"%d%d",&a.re,&a.im);
	
	return a;
}

G sumaG(G a,G b){	
	G c;
	
	c.re=a.re+b.re;
	c.im=a.im+b.im;
	
	return c;	
}

G restaG(G a,G b){		
	G c;
	
	c.re=a.re-b.re;
	c.im=a.im-b.im;
	
	return c;
}

G prodG(G a,G b){	
	G c;
	
	c.re=a.re*b.re-a.im*b.im;
	c.im=a.re*b.im+a.im*b.re;
	
	return c;
}


G expG(G a,int e){
	G ret={re:a.re,im:a.im};
    int i;
    
    for(i=0;i<e-1;i++) ret=prodG(ret,a);
}
