#include <stdio.h>    
#include <stdlib.h>   
#include <math.h> 
#include <string.h>

#include "op_racionales.h" 

int mcd(int a, int b); 

int mcd(int a, int b) 
{                     
  int r;              

  if (a < 0) a=-a;
  if (b < 0) b=-b;
  if (b == 0) return a;

  while ((r=a%b) != 0){
    a = b;             
    b = r;             
  }                    

  return b;
}   

Q leeQ(void)
{
  Q f;
  do{
   printf("\nIntroduzca el numerador y el denominador");
   scanf("%d%d",&f.p,&f.q);
   f=simplificaQ(f);	
  }
  while(f.q==0);
  return f;
}   

Q fleeQ(FILE *f){
  Q ret;
  do{
   fscanf(f,"%d%d",&ret.p,&ret.q);
   ret=simplificaQ(ret);	
  }
  while(ret.q==0);
  return ret;	
}    

int escribeQ(Q a)
{
  char buferTemporal[128];
  int l;

  sprintf(buferTemporal, "%d", a.p);
  l = strlen(buferTemporal);
  if (a.q!= 1) sprintf(buferTemporal+l, "/%d", a.q);
  printf("%8s", buferTemporal);
  return 0;
}

int fescribeQ(FILE *f, Q a)
{
  char buferTemporal[128];
  int l;

  sprintf(buferTemporal, "%d", a.p);
  l = strlen(buferTemporal);
  if (a.q!= 1) sprintf(buferTemporal+l, "/%d", a.q);
  fprintf(f,"%8s", buferTemporal);
  return 0;
}

Q creaQ(int num, int den)
{
  Q r = {num, den};

  return simplificaQ(r);
}

Q simplificaQ(Q a)
{                     
  int d;              
  Q regreso;          

  regreso = a;
  d = mcd (a.p, a.q);
  if (d>1){
    regreso.p /= d;
    regreso.q /= d;
  }
  if (regreso.q < 0){
    regreso.p *= -1;
    regreso.q *= -1;
  }

  return regreso;
}

Q sumaQ(Q a, Q b)
{               
  Q r;           

  r.p = a.p*b.q + a.q*b.p;
  r.q = a.q*b.q;
  r=simplificaQ(r);

  return r;
}

Q restaQ(Q a, Q b)
{
  Q r;           

  r.p = a.p*b.q - a.q*b.p;
  r.q = a.q*b.q;
  r=simplificaQ(r);

  return r;
}

Q prodQ(Q a, Q b)
{
  Q r;           

  r.p = a.p*b.p;
  r.q = a.q*b.q;
  
  r=simplificaQ(r);

  return r;	
} 

Q expQ(Q a, int g){
  Q ret;
  
  ret.p=pow(a.p,g);
  ret.q=pow(a.q,g);
  simplificaQ(ret);
  
  return ret;
}

Q divQ(Q a, Q b)
{
  Q r;           
  r.p = a.p*b.q;
  r.q = a.q*b.p;
  r=simplificaQ(r);

  return r;
}

