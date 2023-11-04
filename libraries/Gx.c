#include <stdlib.h>
#include <stdio.h>

#include "op_gaussianos.h"
#include "Gx.h"

void limpiaGx(Gx *a){
  if(a->c!=NULL) free(a->c);
  a->g=-1;
  a->c=NULL;
}

int escero(Gx a){
  return a.g<0;	
}

int escGx(FILE *f, Gx a){
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
	  	fescG(f,a.c[i]);
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
	  	fescG(f,a.c[1]);
	  	fprintf(f,")");
	    fprintf(f,"x");
	    }
      }
    }
    
    if(a.c[0].re!=0.0 || a.c[0].im!=0.0){
      fprintf(f,"+(");
	  fescG(f,a.c[0]);
	  fprintf(f,")");	
	} 
	fprintf(f,"\n");
	
	fflush(f);
	return 0;
}

Gx leeGx(FILE *f){
	Gx ret;
	int i;

	fscanf(f,"%d",&(ret.g));
	
	if((ret.c=(G*)malloc((ret.g+1)*sizeof(G)))==NULL){
    printf("error al generar espacio.\n");
    ret.g=-1;
    return ret;
    }
	
	for(i=0;i<=ret.g;i++){
		ret.c[i]=fleerG(f);
	}
	
    while(ret.g>=0 && ret.c[ret.g].re==0 && ret.c[ret.g].im==0) ret.g--;
    if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
	}	
  return ret;
}

Gx copiaGx(Gx a){
  Gx ret={g:a.g,c:NULL};
  int i;
  
  if (ret.g<0){
    ret.c=NULL;
    return ret;
  }
  
  if((ret.c=(G*)malloc((ret.g+1)*sizeof(G)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }
  
  for(i=0;i<=ret.g;i++) ret.c[i]=a.c[i];
  
  return ret;	
}

Gx copiamenosGx(Gx a){
  Gx ret={g:a.g,c:NULL};
  int i;
  
  if((ret.c=(G*)malloc((ret.g+1)*sizeof(G)))==NULL){
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

Gx sumaGx(Gx a, Gx b){
  Gx ret;
  int i, min;

  if (a.g<0){
    return copiaGx(b);
  }
  if (b.g<0){
    return copiaGx(a);
  }
  if (a.g<b.g){
    min = a.g;
    ret.g = b.g;
  } else{
    min = b.g;
    ret.g = a.g;
  }
  
  if((ret.c=(G*)malloc((ret.g+1)*sizeof(G)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  
  for (i=0; i<=min; i++) ret.c[i]=sumaG(a.c[i],b.c[i]);
  if (a.g==min){
    for (; i<=ret.g; i++) ret.c[i]=b.c[i];
  }
  if (b.g==min){
    for (; i<=ret.g; i++) ret.c[i]=a.c[i];
  }
  
  while(ret.g>=0 && ret.c[ret.g].re==0 && ret.c[ret.g].im==0) ret.g--;
    if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
	}
  return ret;	
}

Gx restaGx(Gx a, Gx b){
  Gx ret;
  int i, min;

  if (a.g<0){
    return copiamenosGx(b);
  }
  if (b.g<0){
    return copiaGx(a);
  }
  if (a.g<b.g){
    min = a.g;
    ret.g = b.g;
  } else{
    min = b.g;
    ret.g = a.g;
  }
  
  if((ret.c=(G*)malloc((ret.g+1)*sizeof(G)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  
  for (i=0; i<=min; i++) ret.c[i]=restaG(a.c[i],b.c[i]);
  if (a.g==min){
    for (; i<=ret.g; i++){
  	ret.c[i].re=-b.c[i].re;
  	ret.c[i].im=-b.c[i].im;
    } 
  }
  if (b.g==min){
    for (; i<=ret.g; i++) ret.c[i]=a.c[i];
  }
  
  while(ret.g>=0 && ret.c[ret.g].re==0 && ret.c[ret.g].im==0) ret.g--;
    if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
	}
  return ret;
}

Gx prodGx(Gx a, Gx b){
  Gx ret;
  int i,j;
  
  if (a.g<0 || b.g<0){
  	ret.g=-1;	
    return ret;
  }
  
   ret.g=a.g+b.g; 
   
   if((ret.c=(G*)malloc((ret.g+1)*sizeof(G)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
   }
    
    for(i=0;i<=ret.g;i++){
      ret.c[i].re=0;
	  ret.c[i].im=0;
	} 
      for(i=0;i<=a.g;i++)
       for(j=0;j<=b.g; j++)	
    	ret.c[i+j]=sumaG(ret.c[i+j],prodG(a.c[i],b.c[j]));
	
    return ret;
}

Gx monoGx(Gx a, G b, int e){
	Gx ret;
	int i;
	
	ret.g=a.g+e;
	
	if((ret.c=(G*)malloc((ret.g+1)*sizeof(G)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
    }

    for(i=0;i<=ret.g;i++){
      ret.c[i].re=0;
	  ret.c[i].im=0;	
	} 
    for(i=e;i<=ret.g;i++) ret.c[i]=prodG(a.c[i-e],b);
    
	return ret;  
}

Gx derivaGx(Gx a){
	Gx ret={g:a.g-1,c:NULL};
	int i;
	
	if((ret.c=(G*)malloc((ret.g+1)*sizeof(G)))==NULL){
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

G evaluaGx(Gx a, G e){
	G r={re:0,im:0};
	int i;

	for(i=0;i<=a.g;i++) r=sumaG(r,prodG(a.c[i],expG(e,i)));
    return r;
}
