#include <stdio.h>
#include <stdlib.h>

#include "op_cuaternios.h"
#include "Hx.h"


void limpiaHx(Hx *a){
  if(a->c!=NULL) free(a->c);
  a->g=-1;
  a->c=NULL;
}

int escero(Hx a){
  return a.g<0;	
}

int escHx(FILE *f, Hx a){
	int i;
	
	if(escero(a)) fprintf(f,"0");
	
	for(i=a.g;i>1;i--){	
	if(a.c[i].r==0.0 && a.c[i].i==0.0 && a.c[i].j==0.0 && a.c[i].k==0.0);
	else{
	  if(a.c[i].r==1.0 && a.c[i].i==0.0 && a.c[i].j==0.0 && a.c[i].k==0.0) fprintf(f,"+x^%d",i);
	  else{
	  	if(a.c[i].r==-1.0 && a.c[i].i==0.0 && a.c[i].j==0.0 && a.c[i].k==0.0) fprintf(f,"-x^%d",i);
	    else{
	  	fprintf(f,"+(");
	  	fescH(f,a.c[i]);
	  	fprintf(f,")");
	    fprintf(f,"x^%d",i);
	    }
       }
     }
   }
	
	if(a.c[1].r==0.0 && a.c[1].i==0.0 && a.c[1].j==0.0 && a.c[1].k==0.0);
	else{
	  if(a.c[1].r==1.0 && a.c[1].i==0.0 && a.c[1].j==0.0 && a.c[1].k==0.0) fprintf(f,"+x");
	  else{
	  	if(a.c[1].r==-1.0 && a.c[1].i==0.0 && a.c[1].j==0.0 && a.c[1].k==0.0) fprintf(f,"-x");
	    else{
	  	fprintf(f,"+(");
	  	fescH(f,a.c[1]);
	  	fprintf(f,")");
	    fprintf(f,"x");
	    }
       }
     }
   
	
    
    if(a.c[0].r!=0.0 || a.c[0].i!=0.0 || a.c[0].j!=0.0 || a.c[0].k!=0.0){
      fprintf(f,"+(");
	  fescH(f,a.c[0]);
	  fprintf(f,")");	
	} 
	fprintf(f,"\n");
    fflush(f);
	return 0;
}

Hx leeHx(FILE *f){
	Hx ret;
	int i;

    fscanf(f,"%d",&(ret.g));
	
	if((ret.c=(H*)malloc((ret.g+1)*sizeof(H)))==NULL){
    printf("error al generar espacio.\n");
    ret.g=-1;
    return ret;
    }
	
	for(i=0;i<=ret.g;i++){
		ret.c[i]=fleerH(f);
	}
	
    while(ret.g>=0 && ret.c[ret.g].r==0.0 && ret.c[ret.g].i==0.0 && ret.c[ret.g].j==0.0 && ret.c[ret.g].k==0.0) ret.g--;
    if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
	}	
  return ret;
}

Hx copiaHx(Hx a){
  Hx ret={g:a.g,c:NULL};
  int i;
  
  if (ret.g<0){
    ret.c=NULL;
    return ret;
  }
  
  if((ret.c=(H*)malloc((ret.g+1)*sizeof(H)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
  
  for(i=0;i<=ret.g;i++) ret.c[i]=a.c[i];
  
  return ret;	
}

Hx copiamenosHx(Hx a){
  Hx ret={g:a.g,c:NULL};
  int i;
  
  if((ret.c=(H*)malloc((ret.g+1)*sizeof(H)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
  
  for(i=0;i<=ret.g;i++){
  	ret.c[i].r=-a.c[i].r;
  	ret.c[i].i=-a.c[i].i;
  	ret.c[i].j=-a.c[i].j;
  	ret.c[i].k=-a.c[i].k;
  } 
  
  return ret;	
}

Hx sumaHx(Hx a, Hx b){
  Hx ret;
  int i, min;

  if (a.g<0){
    return copiaHx(b);
  }
  if (b.g<0){
    return copiaHx(a);
  }
  if (a.g<b.g){
    min = a.g;
    ret.g = b.g;
  } else{
    min = b.g;
    ret.g = a.g;
  }
  
  if((ret.c=(H*)malloc((ret.g+1)*sizeof(H)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  
  for (i=0; i<=min; i++) ret.c[i]=sumaH(a.c[i],b.c[i]);
  if (a.g==min){
    for (; i<=ret.g; i++) ret.c[i]=b.c[i];
  }
  if (b.g==min){
    for (; i<=ret.g; i++) ret.c[i]=a.c[i];
  }
  
  while(ret.g>=0 && ret.c[ret.g].r==0.0 && ret.c[ret.g].i==0.0 && ret.c[ret.g].j==0.0 && ret.c[ret.g].k==0.0) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
  }
  return ret;	
}

Hx restaHx(Hx a, Hx b){
  Hx ret;
  int i, min;

  if (a.g<0){
    return copiamenosHx(b);
  }
  if (b.g<0){
    return copiaHx(a);
  }
  if (a.g<b.g){
    min = a.g;
    ret.g = b.g;
  } else{
    min = b.g;
    ret.g = a.g;
  }
  
  if((ret.c=(H*)malloc((ret.g+1)*sizeof(H)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  
  for (i=0; i<=min; i++) ret.c[i]=restaH(a.c[i],b.c[i]);
  if (a.g==min){
    for (; i<=ret.g; i++){
  	ret.c[i].r=-b.c[i].r;
  	ret.c[i].i=-b.c[i].i;
  	ret.c[i].j=-b.c[i].j;
  	ret.c[i].k=-b.c[i].k;
  } 
  }
  if (b.g==min){
    for (; i<=ret.g; i++) ret.c[i]=a.c[i];
  }
  
  while(ret.g>=0 && ret.c[ret.g].r==0.0 && ret.c[ret.g].i==0.0 && ret.c[ret.g].j==0.0 && ret.c[ret.g].k==0.0) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
  }
  return ret;
}
Hx prodHx(Hx a, Hx b){
  Hx ret;
  int i,j;
  
  if (a.g<0 || b.g<0){
  	ret.g=-1;	
    return ret;
  }
  
   ret.g=a.g+b.g; 
   
   if((ret.c=(H*)malloc((ret.g+1)*sizeof(H)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
   }
    
    for(i=0;i<=ret.g;i++){
      ret.c[i].r=0.0;
	  ret.c[i].i=0.0;
	  ret.c[i].j=0.0;
	  ret.c[i].k=0.0;	
	} 
  
      for(i=0;i<=a.g;i++)
       for(j=0;j<=b.g; j++)	
    	ret.c[i+j]=sumaH(ret.c[i+j],prodH(a.c[i],b.c[j]));
	
    return ret;
}

Hx monoHx(Hx a, H b, int e){
	Hx ret;
	int i;
	
	ret.g=a.g+e;
	
	if((ret.c=(H*)malloc((ret.g+1)*sizeof(H)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }

    for(i=0;i<=ret.g;i++){
      ret.c[i].r=0.0;
	  ret.c[i].i=0.0;
	  ret.c[i].j=0.0;
	  ret.c[i].k=0.0;	
	} 
    for(i=e;i<=ret.g;i++) ret.c[i]=prodH(b,a.c[i-e]);
    
	return ret;  
}

Hx divHx(Hx a, Hx b, Hx *res){
	Hx ret,aux,aaux;
	int grad,i;
	
	aaux=copiaHx(a);
	a=aaux; 
	
	ret.g=a.g-b.g;
    if((ret.c=(H*)malloc((ret.g+1)*sizeof(H)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
    
  for (i=0; i<=ret.g; i++){
  	ret.c[i].r=0.0;
  	ret.c[i].i=0.0;
  	ret.c[i].j=0.0;
  	ret.c[i].k=0.0;
  } 

  do{
    grad=a.g-b.g;
    ret.c[grad]=divH(a.c[a.g],b.c[b.g]);
    aux=monoHx(b, ret.c[grad], grad);
    aaux=restaHx(a,aux);
    limpiaHx(&a);
    limpiaHx(&aux);
    a=aaux;
    limpiaHx(res);
    *res=copiaHx(a);
  }while(!escero(*res) && (res->g>=b.g));
	
   return ret;	
}

Hx mcdHx(Hx a, Hx b){
	Hx aaux,baux,r={g:-1,c:NULL};
	
	if(escero(b)){
		return a;
	}
	
	aaux=copiaHx(a);
	a=aaux;
	
	baux=copiaHx(b);
	b=baux;
	
	divHx(a,b,&r);

	while(!escero(r)){
	   divHx(a,b,&r);
	   limpiaHx(&a);
	   a=copiaHx(b);
	   limpiaHx(&b);
	   b=copiaHx(r);
	   limpiaHx(&r);}
	return b;
}

Hx derivaHx(Hx a){
	Hx ret={g:a.g-1,c:NULL};
	int i;
	
	if((ret.c=(H*)malloc((ret.g+1)*sizeof(H)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
	
	for(i=0;i<=ret.g;i++){
	  ret.c[i].r=(i+1.0)*a.c[i+1].r;
	  ret.c[i].i=(i+1.0)*a.c[i+1].i;
	  ret.c[i].j=(i+1.0)*a.c[i+1].j;	
	  ret.c[i].k=(i+1.0)*a.c[i+1].k;			
	} 
	
	return ret;
}

Hx integraHx(Hx a){
	Hx ret={g:a.g+1,c:NULL};
	int i;
	
	if((ret.c=(H*)malloc((ret.g+1)*sizeof(H)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
    
    ret.c[0].r=0.0;
    ret.c[0].i=0.0;
    ret.c[0].j=0.0;
    ret.c[0].k=0.0;
    
    for(i=1;i<=ret.g;i++){
     ret.c[i].r=a.c[i-1].r/(i+0.0);
	 ret.c[i].i=a.c[i-1].i/(i+0.0);
	 ret.c[i].j=a.c[i-1].j/(i+0.0);
	 ret.c[i].k=a.c[i-1].k/(i+0.0);	
	} 
	
	return ret;
}

H evaluaHx(Hx a, H e){
	H r={r:0,i:0,j:0,k:0};
	int i;
	
	for(i=0;i<=a.g;i++) r=sumaH(r,prodH(a.c[i],expH(e,i)));

	return r;
}

