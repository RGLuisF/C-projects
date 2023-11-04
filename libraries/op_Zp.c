#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include"op_Zp.h"

Zp leeZP(int p){
  Zp a;
  a.p=p;
  printf("Introduzca un numero entero\n");
  scanf("%d",&a.n);
  a.n=simpZP(a);
  return a;
}

int escZP(Zp a){
  printf("%+d",a.n);
  return 0;
}

Zp fleeZP(FILE *f, int p){
  Zp a;
  a.p=p;
  fscanf(f,"%d",&a.n);
  a.n=simpZP(a);
  return a;
}

int fescZP(FILE *f, Zp a){
  fprintf(f,"%5d",a.n);
  return 0;
}

int simpZP(Zp d){	
 d.n=((d.n%d.p)+d.p)%d.p;
 return d.n;	
}

Zp creaZP(int n, int p){
	Zp a={p:p,n:n};
	
	a.n=simpZP(a);
	
	return a;
}

Zp sumaZP(Zp a, Zp b){	
  Zp r;
  r.p=a.p;
  r.n=a.n+b.n;
  
  r.n=simpZP(r);
  return r;	
}

Zp restaZP(Zp a, Zp b){	
  Zp r;
  r.p=a.p;
  r.n=a.n-b.n;
  
  r.n=simpZP(r);
  return r;	
}

Zp prodZP(Zp a, Zp b){	
  Zp r;
  r.p=a.p;
  r.n=a.n*b.n;
  r.n=simpZP(r);
  return r;	
}

Zp expZP(Zp a, int g){	
  Zp ret={p:a.p};
  ret.n=pow(a.n,g);
  ret.n=simpZP(ret);
  return ret;
}

Zp invZP(Zp d){
   int r,q,s,s0,s1,a,b,p;	
    a=d.n;
    b=d.p;	
    s0=0;
    s1=1;
    while((r=a%b)!=0){
      q = a/b;
      a=b;
      b=r;
      s=s0;
      s0=s1-q*s0;
      s1=s;
    }
	d.n=s0;
    d.n=simpZP(d);
	
    return d;
}

Zp raizZP(Zp a){
	int i;
	Zp b;
	b.n=-1;
	for(i=0;i<a.p;i++){
		if(i*i%a.p==a.n){
			if(b.n==-1){
				b.n=i;
			}else{
				b.p=i;
			} 
		}
	}
return b;
}

Zp divZP(Zp a, Zp b){
  Zp r;
  r=invZP(b);
  r=prodZP(a,r);
  return r;		
}
