#include <stdlib.h>
#include <stdio.h>

#include "Zp.h"
#include "Zpx.h"

void limpiaZx(Zx *a){
  if(a->c!=NULL) free(a->c);
  a->g=-1;
  a->c=NULL;
}

int escero(Zx a){
  return a.g<0;
}

int escZx(FILE *f, Zx a){
	int i;
	
	if(escero(a)) fprintf(f,"0");
	
	for(i=a.g;i>1;i--){	
	if(a.c[i].n!=0){
	  if(a.c[i].n!=1){
	    if(a.c[i].n!=-1){
	      fescZP(f,a.c[i]);
	      fprintf(f,"x^%d",i);	
		}
	    else fprintf(f,"-x^%d",i);
	  } 	
	  else fprintf(f,"+x^%d",i);
      }	
	}
	
    if(a.c[1].n!=0 && a.g>=1){
      if(a.c[1].n!=1){
	    if(a.c[1].n!=-1){
	    	fescZP(f,a.c[1]);
			fprintf(f,"x",a.c[1]);
		}
	    else fprintf(f,"-x");
	    } 	
	  else fprintf(f,"+x");
      }	
      
    if(a.c[0].n!=0){
		fescZP(f,a.c[0]); 
	 }
	 fprintf(f,"\n");
	 return 0;
}

Zx leeZx(FILE *f, int p){
	Zx ret;
	int i;

	fscanf(f,"%d",&(ret.g));
	
	if((ret.c=(Zp*)malloc((ret.g+1)*sizeof(Zp)))==NULL){
    printf("Error al generar espacio.\n");
    ret.g=-1;
    return ret;
    }
	
	for(i=0;i<=ret.g;i++){
		ret.c[i]=fleeZP(f,p);
	}
	
    while(ret.g>=0 && ret.c[ret.g].n==0) ret.g--;
    if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
    }
	return ret;
}

Zx copiaZx(Zx a){
  Zx ret={g:a.g,c:NULL};
  int i;
  
  if (ret.g<0){
    ret.c=NULL;
    return ret;
  }
  
  if((ret.c=(Zp*)malloc((ret.g+1)*sizeof(Zp)))==NULL){
    printf("Error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
  
  for(i=0;i<=ret.g;i++) ret.c[i]=a.c[i];
  
  return ret;
}

Zx copiamenosZx(Zx a){
  Zx ret={g:a.g,c:NULL};
  int i;
  
  if((ret.c=(Zp*)malloc((ret.g+1)*sizeof(Zp)))==NULL){
    printf("Error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
  
  for(i=0;i<=ret.g;i++) ret.c[i]=creaZP(-a.c[i].n,a.c[i].p);
  
  return ret;
}

Zx sumaZx(Zx a, Zx b){
  Zx ret;
  int i, min;

  if (a.g<0){
    return copiaZx(b);
  }
  if (b.g<0){
    return copiaZx(a);
  }
  if (a.g<b.g){
    min = a.g;
    ret.g = b.g;
  }else{
    min = b.g;
    ret.g = a.g;
  }
  
  if((ret.c=(Zp*)malloc((ret.g+1)*sizeof(Zp)))==NULL){
    printf("Error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  
  for (i=0; i<=min; i++) ret.c[i]=sumaZP(a.c[i],b.c[i]);
  if (a.g==min){
    for (; i<=ret.g; i++) ret.c[i]=b.c[i];
  }
  if (b.g==min){
    for (; i<=ret.g; i++) ret.c[i]=a.c[i];
  }
  
  while(ret.g>=0 && ret.c[ret.g].n==0) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
  }
  return ret;
}

Zx restaZx(Zx a, Zx b){
  Zx ret;
  int i, min;

  if (a.g<0){
    return copiamenosZx(b);
  }
  if (b.g<0){
    return copiaZx(a);
  }
  if (a.g<b.g){
    min = a.g;
    ret.g = b.g;
  } else{
    min = b.g;
    ret.g = a.g;
  }
  
  if((ret.c=(Zp*)malloc((ret.g+1)*sizeof(Zp)))==NULL){
    printf("Error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  
  for (i=0; i<=min; i++) ret.c[i]=restaZP(a.c[i],b.c[i]);
  if (a.g==min){
    for (; i<=ret.g; i++) ret.c[i]=creaZP(-b.c[i].n,b.c[i].p);
  }
  if (b.g==min){
    for (; i<=ret.g; i++) ret.c[i]=a.c[i];
  }
  
  while(ret.g>=0 && ret.c[ret.g].n==0) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
  }
  return ret;
}

Zx prodZx(Zx a, Zx b){
  Zx ret;
  int i,j;
  
  if (a.g<0 || b.g<0){
  	ret.g=-1;	
    return ret;
  }
  
   ret.g=a.g+b.g; 
   
   if((ret.c=(Zp*)malloc((ret.g+1)*sizeof(Zp)))==NULL){
    printf("Error al generar espacio.\n");
    ret.g = -1;
    return ret;
   }
    
    for(i=0;i<=ret.g;i++) ret.c[i]=creaZP(0,a.c[0].p);
  
      for(i=0;i<=a.g;i++)
       for(j=0;j<=b.g; j++)	
    	ret.c[i+j]=sumaZP(ret.c[i+j],prodZP(a.c[i],b.c[j]));
	
    return ret;
}

Zx monoZx(Zx a, Zp b, int e){
	Zx ret;
	int i;
	
	ret.g=a.g+e;
	
	if((ret.c=(Zp*)malloc((ret.g+1)*sizeof(Zp)))==NULL){
    printf("Error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }

    for(i=0;i<=ret.g;i++) ret.c[i]=creaZP(0,a.c[i].p);
    for(i=e;i<=ret.g;i++) ret.c[i]=prodZP(a.c[i-e],b);
    
	return ret;  
}

Zx divZx(Zx a, Zx b, Zx *res){
	Zx ret,aux,aaux;
	int grad,i;
	
	aaux=copiaZx(a);
	a=aaux; 
	
	ret.g=a.g-b.g;
    if((ret.c=(Zp*)malloc((ret.g+1)*sizeof(Zp)))==NULL){
    printf("Error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
    
  for (i=0; i<=ret.g; i++) ret.c[i]=creaZP(0,a.c[i].p);

  do{
    grad=a.g-b.g;
    ret.c[grad] = divZP(a.c[a.g],b.c[b.g]);
    aux=monoZx(b,ret.c[grad], grad);
    aaux=restaZx(a,aux);
    limpiaZx(&a);
    limpiaZx(&aux);
    a=aaux;
    limpiaZx(res);
    *res=copiaZx(a);
  }while(!escero(*res) && (res->g>=b.g));
	
   return ret;	
}

Zx mcdZx(Zx a, Zx b){
	Zx aaux,baux,r={g:-1,c:NULL};
	
	if(escero(b)){
		return a;
	}
	
	aaux=copiaZx(a);
	a=aaux;
	
	baux=copiaZx(b);
	b=baux;
	
	divZx(a,b,&r);

	while(!escero(r)){
	   divZx(a,b,&r);
	   limpiaZx(&a);
	   a=copiaZx(b);
	   limpiaZx(&b);
	   b=copiaZx(r);
	   limpiaZx(&r);
	   }

	return b;
}

Zx derivaZx(Zx a){
	Zx ret={g:a.g-1,c:NULL};
	int i;
	
	if((ret.c=(Zp*)malloc((ret.g+1)*sizeof(Zp)))==NULL){
    printf("Error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }

	for(i=0;i<=ret.g;i++) ret.c[i]=creaZP((i+1)*a.c[i+1].n,a.c[1].p);	

	return ret;
}

Zx integraZx(Zx a){
	Zx ret={g:a.g+1,c:NULL};
	int i;
	
	if((ret.c=(Zp*)malloc((ret.g+1)*sizeof(Zp)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
    
    ret.c[0]=creaZP(0,a.c[0].p);
    for(i=1;i<=ret.g;i++) ret.c[i]=divZP(a.c[i-1],creaZP(i,a.c[1].p));
	
	return ret;
}

Zp evaluaZx(Zx a, Zp e){
	Zp r;
	int i;
	
	r=creaZP(0,a.c[i].p);

	for(i=0;i<=a.g;i++) r=sumaZP(r,prodZP(a.c[i],expZP(e,i)));
	
    return r;
}
