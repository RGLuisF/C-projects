#include <stdio.h>
#include <stdlib.h>

#include "op_complejos.h"
#include "Cx.h"

void limpiaCx(Cx *a){
	 if(a->c!=NULL) free(a->c);
     a->g=-1;
     a->c=NULL;
}

int escero(Cx a){
	return a.g<0;
}

int escCx(FILE *f, Cx a){
	int i;
	
	if(escero(a)) fprintf(f,"0");
	
	for(i=a.g;i>1;i--){	
	if(a.c[i].re==0.0 && a.c[i].im==0.0);
	else{
	  if(a.c[i].re==1.0 && a.c[i].im==0.0) fprintf(f,"+x^%d",i);
	  else{
	  	if(a.c[i].re==-1.0 && a.c[i].im==0.0) fprintf(f,"-x^%d",i);
	    else{
	  	fprintf(f,"+(");
	  	fescC(f,a.c[i]);
	  	fprintf(f,")");
	    fprintf(f,"x^%d",i);
	    }
      }
    }
   }
	
	if(a.c[1].re==0.0 && a.c[1].im==0.0);
	else{
	  if(a.c[i].re==1.0 && a.c[i].im==0.0 && a.g>=1) fprintf(f,"+x");
	  else{
	  	if(a.c[i].re==-1.0 && a.c[i].im==0.0 && a.g>=1) fprintf(f,"-x");
	    else{
	    fprintf(f,"+(");
	  	fescC(f,a.c[1]);
	  	fprintf(f,")");
	    fprintf(f,"x");
	    }
      }
    }
    
    if(a.c[0].re!=0.0 || a.c[0].im!=0.0){
      fprintf(f,"+(");
	  fescC(f,a.c[0]);
	  fprintf(f,")");	
	} 
	fprintf(f,"\n");
	fflush(f);
	return 0;
}

Cx leeCx(FILE *f){
	Cx ret;
	int i;

	fscanf(f,"%d",&(ret.g));
	
	if((ret.c=(C*)malloc((ret.g+1)*sizeof(C)))==NULL){
    printf("error al generar espacio.\n");
    ret.g=-1;
    return ret;
    }
	
	for(i=0;i<=ret.g;i++){
		ret.c[i]=fleerC(f);
	}
	
    while(ret.g>=0 && ret.c[ret.g].re==0.0 && ret.c[ret.g].im==0.0) ret.g--;
    if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
    }
	
	return ret;
}

Cx copiaCx(Cx a){
	 Cx ret={g:a.g,c:NULL};
     int i;
  
    if (ret.g<0){
    ret.c=NULL;
    return ret;
    }
  
    if((ret.c=(C*)malloc((ret.g+1)*sizeof(C)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
  
    for(i=0;i<=ret.g;i++) ret.c[i]=a.c[i];
  
    return ret;
}

Cx copiamenosCx(Cx a){
	Cx ret={g:a.g,c:NULL};
    int i;
  
    if((ret.c=(C*)malloc((ret.g+1)*sizeof(C)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
  
   for(i=0;i<=ret.g;i++){
   	ret.c[i].re=-a.c[i].re;
   	ret.c[i].im=-a.c[i].im;
   } 
  
   return ret;
}

Cx sumaCx(Cx a, Cx b){
	Cx ret;
    int i, min;

    if (a.g<0){
    return copiaCx(b);
    }
    if (b.g<0){
    return copiaCx(a);
    }
    if (a.g<b.g){
    min = a.g;
    ret.g = b.g;
    } else{
    min = b.g;
    ret.g = a.g;
    }
  
  if((ret.c=(C*)malloc((ret.g+1)*sizeof(C)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
  
  for (i=0; i<=min; i++) ret.c[i]=sumaC(a.c[i],b.c[i]);
  if (a.g==min){
    for (; i<=ret.g; i++) ret.c[i]=b.c[i];
  }
  if (b.g==min){
    for (; i<=ret.g; i++) ret.c[i]=a.c[i];
  }
  
  while(ret.g>=0 && ret.c[ret.g].re==0.0 && ret.c[ret.g].im==0.0) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
  }
  return ret;
}

Cx restaCx(Cx a, Cx b){
  Cx ret;
  int i, min;

  if (a.g<0){
    return copiamenosCx(b);
  }
  if (b.g<0){
    return copiaCx(a);
  }
  if (a.g<b.g){
    min = a.g;
    ret.g = b.g;
  } else{
    min = b.g;
    ret.g = a.g;
  }
  
  if((ret.c=(C*)malloc((ret.g+1)*sizeof(C)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  
  for (i=0; i<=min; i++) ret.c[i]=restaC(a.c[i],b.c[i]);
  if (a.g==min){
    for (; i<=ret.g; i++){
    	ret.c[i].re=-b.c[i].re;
    	ret.c[i].im=-b.c[i].im;
	}
  }
  if (b.g==min){
    for (; i<=ret.g; i++) ret.c[i]=a.c[i];
  }
  
  while(ret.g>=0 && ret.c[ret.g].re==0.0 && ret.c[ret.g].im==0.0) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
  }
  return ret;
}

Cx prodCx(Cx a, Cx b){
  Cx ret;
  int i,j;
  
    if (a.g<0 || b.g<0){
  	ret.g=-1;	
    return ret;
    }
  
    ret.g=a.g+b.g; 
   
    if((ret.c=(C*)malloc((ret.g+1)*sizeof(C)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
    
    for(i=0;i<=ret.g;i++){
     ret.c[i].re=0.0;
	 ret.c[i].im=0.0;	
	}
  
      for(i=0;i<=a.g;i++)
       for(j=0;j<=b.g; j++)	
    	ret.c[i+j]=sumaC(ret.c[i+j],prodC(a.c[i],b.c[j]));
	
    return ret;
}

Cx monoCx(Cx a, C b, int e){
	Cx ret;
	int i;
	
	ret.g=a.g+e;
	
	if((ret.c=(C*)malloc((ret.g+1)*sizeof(C)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }

    for(i=0;i<=ret.g;i++){
    ret.c[i].re=0.0;	
    ret.c[i].im=0.0;	
	} 
    for(i=e;i<=ret.g;i++) ret.c[i]=prodC(a.c[i-e],b);
    
	return ret;  
}

Cx divCx(Cx a, Cx b, Cx *res){
	Cx ret,aux,aaux;
	int grad,i;
	
	aaux=copiaCx(a);
	a=aaux; 
	
	ret.g=a.g-b.g;
    if((ret.c=(C*)malloc((ret.g+1)*sizeof(C)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }

  for (i=0; i<=ret.g; i++){
  	ret.c[i].re=0.0;
  	ret.c[i].im=0.0;
  } 

  do{
    grad=a.g-b.g;
    ret.c[grad] =divC(a.c[a.g],b.c[b.g]);
    aux=monoCx(b, ret.c[grad], grad);
    aaux=restaCx(a,aux);
    limpiaCx(&a);
    limpiaCx(&aux);
    a=aaux;
    limpiaCx(res);
    *res=copiaCx(a);
  }while(!escero(*res) && (res->g>=b.g));
	
   return ret;	
}

Cx mcdCx(Cx a, Cx b){
	Cx aaux,baux,r={g:-1,c:NULL};
	
	if(escero(b)){
		return a;
	}
	
	aaux=copiaCx(a);
	a=aaux;
	
	baux=copiaCx(b);
	b=baux;
	
	divCx(a,b,&r);

	while(!escero(r)){
	   divCx(a,b,&r);
	   limpiaCx(&a);
	   a=copiaCx(b);
	   limpiaCx(&b);
	   b=copiaCx(r);
	   limpiaCx(&r);}

	return b;
}

Cx derivaCx(Cx a){
	Cx ret={g:a.g-1,c:NULL};
	int i;
	
	if((ret.c=(C*)malloc((ret.g+1)*sizeof(C)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
	
	for(i=0;i<=ret.g;i++){
	  ret.c[i].re=(i+1)*a.c[i+1].re;
	  ret.c[i].im=(i+1)*a.c[i+1].im;	
	} 
	
	return ret;
}

Cx integraCx(Cx a){
	Cx ret={g:a.g+1,c:NULL};
	int i;
	
	if((ret.c=(C*)malloc((ret.g+1)*sizeof(C)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
    
    ret.c[0].re=0.0;
    ret.c[0].im=0.0;
    
    for(i=1;i<=ret.g;i++){
     ret.c[i].re=(a.c[i-1].re/i);
	 ret.c[i].im=(a.c[i-1].im/i);	
	} 
	
	return ret;
}

C evaluaCx(Cx a, C e){
	C r={re:0.0,im:0.0};
	int i;
	   
	for(i=0;i<=a.g;i++) r=sumaC(r,prodC(a.c[i],expC(e,i))); 	
	
	return r;
}
