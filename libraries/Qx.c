#include <stdio.h>
#include <stdlib.h>

#include "op_racionales.h"
#include "Qx.h"

void limpiaQx(Qx *a){
  if(a->c!=NULL) free(a->c);
  a->g=-1;
  a->c=NULL;
}

int escero(Qx a){
  return a.g<0;
}

int escQx(FILE *f,Qx a){
	int i;
	
	if(escero(a)) fprintf(f,"0");
	
	for(i=a.g;i>1;i--){	
	if(a.c[i].p!=0){
	  if(a.c[i].p!=a.c[i].q){
	    if(a.c[i].p!=-a.c[i].q){
	      fescribeQ(f, a.c[i]);
	      fprintf(f,"x^%d",i);	
		}
	    else fprintf(f,"-x^%d",i);
	  } 	
	  else fprintf(f,"+x^%d",i);
      }	
	}
	
    if(a.c[1].p!=0 && a.g>=1){
      if(a.c[1].p!=a.c[1].q){
	    if(a.c[1].p!=-a.c[1].q){
	    	fescribeQ(f,a.c[1]);
			fprintf(f,"x",a.c[1]);
		}
	    else fprintf(f,"-x");
	    } 	
	  else fprintf(f,"+x");
      }	
      
    if(a.c[0].p!=0){
		fescribeQ(f,a.c[0]); 
	 }
	 fprintf(f, "\n");
	 fflush(f);
	return 0;
	}

Qx leeQx(FILE *f){
	Qx ret;
	int i;

	fscanf(f,"%d",&(ret.g));
	
	if((ret.c=(Q*)malloc((ret.g+1)*sizeof(Q)))==NULL){
    printf("error al generar espacio.\n");
    ret.g=-1;
    return ret;
    }
	
	for(i=0;i<=ret.g;i++){
		ret.c[i]=fleeQ(f);
	}
	
    while(ret.g>=0 && ret.c[ret.g].p==0.0) ret.g--;
    if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
  }
	
	return ret;
}

Qx copiaQx(Qx a){
  Qx ret={g:a.g,c:NULL};
  int i;
  
  if (ret.g<0){
    ret.c=NULL;
    return ret;
  }
  
  if((ret.c=(Q*)malloc((ret.g+1)*sizeof(Q)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
  
  for(i=0;i<=ret.g;i++) ret.c[i]=a.c[i];
  
  return ret;
}

Qx copiamenosQx(Qx a){
  Qx ret={g:a.g,c:NULL};
  int i;
  
  if((ret.c=(Q*)malloc((ret.g+1)*sizeof(Q)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
  
  for(i=0;i<=ret.g;i++){
    ret.c[i].p=-a.c[i].p;
    ret.c[i].q=a.c[i].q;
  }
  
  return ret;
}

Qx sumaQx(Qx a, Qx b){
  Qx ret;
  int i, min;

  if (a.g<0){
    return copiaQx(b);
  }
  if (b.g<0){
    return copiaQx(a);
  }
  if (a.g<b.g){
    min = a.g;
    ret.g = b.g;
  } else{
    min = b.g;
    ret.g = a.g;
  }
  
  if((ret.c=(Q*)malloc((ret.g+1)*sizeof(Q)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  
  for (i=0; i<=min; i++) ret.c[i]=sumaQ(a.c[i],b.c[i]);
  if (a.g==min){
    for (; i<=ret.g; i++) ret.c[i]=b.c[i];
  }
  if (b.g==min){
    for (; i<=ret.g; i++) ret.c[i]=a.c[i];
  }
  
  while(ret.g>=0 && ret.c[ret.g].p==0.0) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
  }
  return ret;
}

Qx restaQx(Qx a, Qx b){
  Qx ret;
  int i, min;

  if (a.g<0){
    return copiamenosQx(b);
  }
  if (b.g<0){
    return copiaQx(a);
  }
  if (a.g<b.g){
    min = a.g;
    ret.g = b.g;
  } else{
    min = b.g;
    ret.g = a.g;
  }
  
  if((ret.c=(Q*)malloc((ret.g+1)*sizeof(Q)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  
  for (i=0; i<=min; i++) ret.c[i]=restaQ(a.c[i],b.c[i]);
  if (a.g==min){
    for (; i<=ret.g; i++){
     ret.c[i].p=-b.c[i].p;	
     ret.c[i].q=b.c[i].q;
	}
  }
  if (b.g==min){
    for (; i<=ret.g; i++) ret.c[i]=a.c[i];
  }
  
  while(ret.g>=0 && ret.c[ret.g].p==0.0) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
  }
  return ret;
}

Qx prodQx(Qx a, Qx b){
  Qx ret;
  int i,j;
  
  if (a.g<0 || b.g<0){
  	ret.g=-1;	
    return ret;
  }
  
   ret.g=a.g+b.g; 
   
   if((ret.c=(Q*)malloc((ret.g+1)*sizeof(Q)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
   }
    
    for(i=0;i<=ret.g;i++) ret.c[i]=creaQ(0,1);
  
      for(i=0;i<=a.g;i++)
       for(j=0;j<=b.g; j++)	
    	ret.c[i+j]=sumaQ(ret.c[i+j],prodQ(a.c[i],b.c[j]));
	
    return ret;
}

Qx monoQx(Qx a, Q b, int e){
	Qx ret;
	int i;
	
	ret.g=a.g+e;
	
	if((ret.c=(Q*)malloc((ret.g+1)*sizeof(Q)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }

    for(i=0;i<=ret.g;i++) ret.c[i]=creaQ(0,1);
    for(i=e;i<=ret.g;i++) ret.c[i]=prodQ(a.c[i-e],b);
    
	return ret;  
}

Qx divQx(Qx a, Qx b, Qx *res){
	Qx ret,aux,aaux;
	int grad,i;
	
	aaux=copiaQx(a);
	a=aaux; 
	
	ret.g=a.g-b.g;
    if((ret.c=(Q*)malloc((ret.g+1)*sizeof(Q)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
    
  for (i=0; i<=ret.g; i++) ret.c[i]=creaQ(0,1);

  do{
    grad=a.g-b.g;
    ret.c[grad] = divQ(a.c[a.g],b.c[b.g]);
    aux=monoQx(b,ret.c[grad], grad);
    aaux=restaQx(a,aux);
    limpiaQx(&a);
    limpiaQx(&aux);
    a=aaux;
    limpiaQx(res);
    *res=copiaQx(a);
  }while(!escero(*res) && (res->g>=b.g));
	
   return ret;	
}

Qx mcdQx(Qx a, Qx b){
	Qx aaux,baux,r={g:-1,c:NULL};
	
	if(escero(b)){
		return a;
	}
	
	aaux=copiaQx(a);
	a=aaux;
	
	baux=copiaQx(b);
	b=baux;
	
	divQx(a,b,&r);

	while(!escero(r)){
	   divQx(a,b,&r);
	   limpiaQx(&a);
	   a=copiaQx(b);
	   limpiaQx(&b);
	   b=copiaQx(r);
	   limpiaQx(&r);
	   }

	return b;
}

Qx derivaQx(Qx a){
	Qx ret={g:a.g-1,c:NULL};
	int i;
	
	if((ret.c=(Q*)malloc((ret.g+1)*sizeof(Q)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
	
	for(i=0;i<=ret.g;i++) ret.c[i]=prodQ(creaQ(i+1,1),a.c[i+1]);
	
	return ret;
}

Qx integraQx(Qx a){
	Qx ret={g:a.g+1,c:NULL};
	int i;
	
	if((ret.c=(Q*)malloc((ret.g+1)*sizeof(Q)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
    
    ret.c[0]=creaQ(0,1);
    for(i=1;i<=ret.g;i++){
    	ret.c[i].p=a.c[i-1].p;
    	ret.c[i].q=a.c[i-1].q*i;
    	simplificaQ(ret.c[i]);
	} 
	
	return ret;
}

Q evaluaQx(Qx a,Q e){
	Q r={p:0,q:1};
	int i;

	for(i=0;i<=a.g;i++) r=sumaQ(r,prodQ(a.c[i],expQ(e,i)));	
	return r;
}
