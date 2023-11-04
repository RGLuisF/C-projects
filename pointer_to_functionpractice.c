#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <string.h>

#include "H_RACIONAL.h"
#include "H_COMPLEJOS.h"
#include "H_ZP.h"
#include "H_CUATERNIOS.h"
#include "H_GAUSSIANOS.h"

enum tipoCoeficiente {RACIONALES, REALES, CUATERNIOS, GAUSSIANOS, ZP, COMPLEJOS, TOTAL};

typedef union coef{
  Q unRacional;
  double unReal;
  C unComplejo;
  Zp unZp;
  H  unH;
  G  unG;
}Coeficiente;

Coeficiente leerCoef(FILE *f, enum tipoCoeficiente tipo, int p);
Coeficiente opera(Coeficiente a, Coeficiente b, void *suma, enum tipoCoeficiente tipo);
int esccoef(FILE *f, Coeficiente a,enum tipoCoeficiente tipo);

int main(int argc, char *argv[]){
	
  FILE *in, *out;
  char *namein="Entrada.txt", *nameout="Resultado.txt";
 
  void *fs[]={sumaQ, sumaR, sumaH, sumaG, sumaZP, sumaC };
  void *fr[]={restaQ, restaR, restaH, restaG, restaZP, restaC};
  void *fp[]={prodQ, prodR, prodH, prodG, prodZP, prodC};
  void *fd[]={divQ, divR, divH, divZP, divZP, divC};

  int tipocoef,p=0;
  Coeficiente a,b,c;
  
   printf("Por abrir y leer el archivo %s",namein);
	in=fopen(namein,"rt");
	if(in==NULL){
    int my_error=errno; 
    printf("\nHubo un error en la lectura del archivo. Codigo: %d. Mensaje: <<%s>>\nPor finalizar la ejecucion del programa.\n", 
	       my_error, strerror(my_error));
    return -1;
    }
	   
   do{
   	fscanf(in,"%d",&tipocoef);
     }
   while(tipocoef<0 || 5<tipocoef);
   
   if(tipocoef==4) fscanf(in,"%d",&p);
   
   a=leerCoef(in,tipocoef,p);
   b=leerCoef(in,tipocoef,p);
   
   printf("\nPor realizar operacion y escribir el resultado en %s", nameout);
   
   out=fopen(nameout,"wt");
    
    if(out==NULL){
    	int my_error=errno;
    	printf("Hubo un error en la escritura del archivo: %d <<%s>>\nPor finalizar la ejecucion del programa.\n", my_error, strerror(my_error));
    	fclose(in);
    	return -1;
	}
	
    if(tipocoef==4) fprintf(out,"p=%d\n",p);
   
   fprintf(out,"a=");
   esccoef(out,a,tipocoef);
   fprintf(out,"\nb=");
   esccoef(out,b,tipocoef);
   c=opera(a,b,fs[tipocoef],tipocoef);
   fprintf(out,"\nsuma=");
   esccoef(out,c,tipocoef);
   c=opera(a,b,fr[tipocoef],tipocoef);
   fprintf(out,"\nresta=");
   esccoef(out,c,tipocoef);
   c=opera(a,b,fp[tipocoef],tipocoef);
   fprintf(out,"\nproducto=");
   esccoef(out,c,tipocoef);
   
   if(tipocoef==3) fprintf(out,"\nNo es posible dividir");
   else{
        c=opera(a,b,fd[tipocoef],tipocoef);
        fprintf(out,"\ndivisi n=");
        esccoef(out, c, tipocoef);
    }
   
  return 0;
}

Coeficiente leerCoef(FILE *f,enum tipoCoeficiente tipo, int p){

  Coeficiente ret;
  
    if (tipo==RACIONALES){
        ret.unRacional=fleeQ(f);
  } else if (tipo==REALES){
		fscanf(f,"%lf",&ret.unReal);
  } else if (tipo==CUATERNIOS){
        ret.unH=fleerH(f);
  } else if (tipo==GAUSSIANOS){
  	    ret.unG=fleerG(f);
  } else if (tipo==ZP){
        ret.unZp=fleeZP(f,p);
  } else if (tipo==COMPLEJOS){
        ret.unComplejo=fleerC(f);
  }
  
  return ret;
}

Coeficiente opera(Coeficiente a, Coeficiente  b, void *operacion, enum tipoCoeficiente tipo)
{
  Q (*fRacional)(Q, Q);
  double (*fReal)(double, double);
  C (*fCompleja)(C, C);
  Zp (*fZp)(Zp, Zp);
  H (*fH)(H, H);
  G (*fG)(G, G);
  Coeficiente ret;

    if (tipo==RACIONALES){
    fRacional = operacion;
    ret.unRacional = fRacional(a.unRacional, b.unRacional);
  } else if (tipo==REALES){
    fReal = operacion;
    ret.unReal=fReal(a.unReal, b.unReal);
  } else if (tipo==COMPLEJOS){
    fCompleja = operacion;
    ret.unComplejo = fCompleja(a.unComplejo, b.unComplejo);
  } else if (tipo==ZP){
    fZp = operacion;
    ret.unZp =fZp(a.unZp, b.unZp);
  } else if (tipo==CUATERNIOS){
  	fH = operacion;
  	ret.unH=fH(a.unH, b.unH);
  } else if (tipo==GAUSSIANOS){
  	fG = operacion;
  	ret.unG=fG(a.unG, b.unG);
  }

  return ret;
}

int esccoef(FILE *f, Coeficiente a, enum tipoCoeficiente tipo){
    if (tipo==RACIONALES){
    fescribeQ(f,a.unRacional);
  } else if (tipo==REALES){
    fprintf(f,"%lg", a.unReal);
  } else if (tipo==COMPLEJOS){
    fescC(f,a.unComplejo);
  } else if (tipo==ZP){
    fprintf(f,"%d", a.unZp.n);
  } else if (tipo==CUATERNIOS){
    fescH(f,a.unH);
  } else if (tipo==GAUSSIANOS){
    fescG(f,a.unG);
  } 

  return 0;	
}
