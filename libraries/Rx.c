#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "Rx.h"

void limpiaRx(Rx *a){
  if(a->c!=NULL) free(a->c);
  a->g=-1;
  a->c=NULL;
}

int escero(Rx a){
  return a.g<0;
}

int escRx(FILE *f,Rx a){
	int i;
	
	if(escero(a)) fprintf(f,"0");
	
	for(i=a.g;i>1;i--){	
	if(a.c[i]!=0){
	  if(a.c[i]!=1){
	    if(a.c[i]!=-1) fprintf(f,"%+lgx^%d",a.c[i],i);
	    else fprintf(f,"-x^%d",i);
	    } 	
	  else fprintf(f,"+x^%d",i);
      }	
	}
	
    if(a.c[1]!=0 && a.g>=1){
      if(a.c[1]!=1){
	    if(a.c[1]!=-1) fprintf(f,"%+lgx",a.c[1]);
	    else fprintf(f,"-x");
	    } 	
	  else fprintf(f,"+x");
      }	
      
    if(a.c[0]!=0) fprintf(f,"%+lg",a.c[0]); 
    
    fprintf(f,"\n");
    return 0;
	}

Rx leeRx(FILE *f){
	Rx ret;
	int i;
	
	fscanf(f,"%d",&ret.g);
	
	if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    ret.g=-1;
    return ret;
    }
	
	for(i=0;i<=ret.g;i++){
		fscanf(f,"%lf",&(ret.c[i]));
	}
	
    while(ret.g>=0 && ret.c[ret.g]==0.0) ret.g--;
    if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
    }
	
	return ret;
}

Rx copiaRx(Rx a){
  Rx ret={g:a.g,c:NULL};
  int i;
  
  if (ret.g<0){
    ret.c=NULL;
    return ret;
  }
  
  if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
  
  for(i=0;i<=ret.g;i++) ret.c[i]=a.c[i];
  
  return ret;
}

Rx copiamenosRx(Rx a){
  Rx ret={g:a.g,c:NULL};
  int i;
  
  if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
  
  for(i=0;i<=ret.g;i++) ret.c[i]=-a.c[i];
  
  return ret;
}

Rx sumaRx(Rx a, Rx b){
  Rx ret;
  int i, min;

  if (a.g<0){
    return copiaRx(b);
  }
  if (b.g<0){
    return copiaRx(a);
  }
  if (a.g<b.g){
    min = a.g;
    ret.g = b.g;
  } else{
    min = b.g;
    ret.g = a.g;
  }
  
  if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  
  for (i=0; i<=min; i++) ret.c[i]=a.c[i]+b.c[i];
  if (a.g==min){
    for (; i<=ret.g; i++) ret.c[i]=b.c[i];
  }
  if (b.g==min){
    for (; i<=ret.g; i++) ret.c[i]=a.c[i];
  }
  
  while(ret.g>=0 && ret.c[ret.g]==0.0) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
  }
  return ret;
}

Rx restaRx(Rx a, Rx b){
  Rx ret;
  int i, min;

  if (a.g<0){
    return copiamenosRx(b);
  }
  if (b.g<0){
    return copiaRx(a);
  }
  if (a.g<b.g){
    min = a.g;
    ret.g = b.g;
  } else{
    min = b.g;
    ret.g = a.g;
  }
  
  if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  
  for (i=0; i<=min; i++) ret.c[i]=a.c[i]-b.c[i];
  if (a.g==min){
    for (; i<=ret.g; i++) ret.c[i]=-b.c[i];
  }
  if (b.g==min){
    for (; i<=ret.g; i++) ret.c[i]=a.c[i];
  }
  
  while(ret.g>=0 && ret.c[ret.g]==0.0) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
  }
  return ret;
}

Rx prodRx(Rx a, Rx b){
  Rx ret;
  int i,j;
  
  if (a.g<0 || b.g<0){
  	ret.g=-1;	
    return ret;
  }
  
   ret.g=a.g+b.g; 
   
   if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
   }
    
    for(i=0;i<=ret.g;i++) ret.c[i]=0.0;
  
      for(i=0;i<=a.g;i++)
       for(j=0;j<=b.g; j++)	
    	ret.c[i+j]+=a.c[i]*b.c[j];
	
    return ret;
}

Rx monoRx(Rx a, double b, int e){
	Rx ret;
	int i;
	
	ret.g=a.g+e;
	
	if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }

    for(i=0;i<=ret.g;i++) ret.c[i]=0.0;
    for(i=e;i<=ret.g;i++) ret.c[i]=a.c[i-e]*b;
    
	return ret;  
}

Rx divRx(Rx a, Rx b, Rx *res){
	Rx ret,aux,aaux;
	int grad,i;
	
	aaux=copiaRx(a);
	a=aaux; 
	
	ret.g=a.g-b.g;
    if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
    
  for (i=0; i<=ret.g; i++) ret.c[i]=0.0;

  do{
    grad=a.g-b.g;
    ret.c[grad] =a.c[a.g]/b.c[b.g];
    aux=monoRx(b, ret.c[grad], grad);
    aaux=restaRx(a,aux);
    limpiaRx(&a);
    limpiaRx(&aux);
    a=aaux;
    limpiaRx(res);
    *res=copiaRx(a);
    }while(!escero(*res) && (res->g>=b.g));
	
   return ret;	
}

Rx mcdRx(Rx a, Rx b){
	Rx aaux,baux,r={g:-1,c:NULL};
	
	if(escero(b)){
		return a;
	}
	
	aaux=copiaRx(a);
	a=aaux;
	
	baux=copiaRx(b);
	b=baux;
	
	divRx(a,b,&r);

	while(!escero(r)){
	   divRx(a,b,&r);
	   limpiaRx(&a);
	   a=copiaRx(b);
	   limpiaRx(&b);
	   b=copiaRx(r);
	   limpiaRx(&r);}

	return b;
}

Rx derivaRx(Rx a){
	Rx ret={g:a.g-1,c:NULL};
	int i;
	
	if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
	
	for(i=0;i<=ret.g;i++) ret.c[i]=(i+1)*a.c[i+1];
	
	return ret;
}

Rx integraRx(Rx a){
	Rx ret={g:a.g+1,c:NULL};
	int i;
	
	if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
    
    ret.c[0]=0.0;
    for(i=1;i<=ret.g;i++) ret.c[i]=a.c[i-1]/i;
	
	return ret;
}

double evaluaRx(Rx a, double e){

	double r=0.0;
	int i;
	  
	for(i=0;i<=a.g;i++) r+=a.c[i]*pow(e,i);
	
	return r;
}

