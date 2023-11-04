#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Suma(n) n*(n+1)/2
#define Suma1(n) (n*(n+1)*(2*n+1)/6)
#define Suma2(n) (Suma(n)*Suma(n))

#define Ap(a,l) l/(2*tan(a/2))
#define Peri(l,nl) l*nl
#define Area(l,a,nl) Peri(l,nl)*a/2

#define det(a,b,c,d,e,f,g,h,i) (a*e*i)+(d*h*c)+(g*b*f)-(g*e*c)-(d*b*i)-(a*h*f)
#define in(X,fmt) printf("Ingrese la entrada %s de la matriz 3x3:",#X);\
                scanf(#fmt,&(X));
#define ig(X,fmt) printf("Ingrese la entrada %s:",#X);\
                scanf(#fmt,&(X));

int main(int argc, char *argv[]) {
	
	int n,nl,opc,r;
	double V,A,l,h,ap,res,a11,a12,a13,a21,a22,a23,a31,a32,a33,x,y,z,det0,det1,det2,det3,a,b,c;
	
	printf("Elija una opcion:\n");
	printf("\t1) Suma de los primero n numeros\n"
	       "\t2) Suma de los primeros n cuadrados\n"
		   "\t3) Suma de los primeros n cubos\n"
		   "\t4) Area de un poligono regular de n lados\n"
		   "\t5) Volumen de un poliedro de base regular\n"
		   "\t6) Resolucion de un sistema de ecuaciones lineales 3x3\n"
		   "Su opcion:"); 
	scanf("%d",&opc);
	switch(opc){
	case 1: printf("Introducir un numero entero:");
	         scanf("%d",&n);
	         n=n<0?-n:n;
             r=Suma(n);
	        printf("La suma de los primeros %d numeros es %d \n",n,r);
	        
	break;	   
	case 2: printf("Introducir un numero entero:");
	         scanf("%d",&n);
	         n=n>=0?n:-n;
	         r=Suma1(n);
	         printf("La suma de los primeros %d cuadrados es %d \n",n,r);
	break;
	case 3: printf("Introducir un numero entero:");
	        scanf("%d",&n);
	        n=n>=0?n:-n;
	        r=Suma2(n);
	        printf("La suma de los primeros %d cubos es %d \n",n,r);
	break;	
	case 4: printf("Introduce el numero de lados del poligono regular:\n");
	         scanf("%d",&nl);
	        printf("Introduce la longitud de los lados del poligono regular:\n");
	         scanf("%lg",&l);
	         ap=(360/nl);
			A=Area(l,ap,nl);
			printf("El area del poligono regular de %d lados con longitud %lg es %lg\n",nl,l,A);
	break;
	case 5: printf("Introduce el numero de lados del poliedro:\n");
	         scanf("%d",&nl);
	        printf("Introduce la longitud de los lados del poliedro:\n");
	         scanf("%lg",&l);
	        printf("Introduce la altura del poliedro:\n");
	         scanf("%lg",&h);
	         ap=(360/nl);
			 A=Area(l,ap,nl);
			 V=A*h;
			printf("El volumen del poliedro de %d lados de lado %lg y altura %lg es %lg\n",nl,l,h,V); 
	break;
	case 6: in(a11,%lg)
	        in(a12,%lg)
	        in(a13,%lg)
	        in(a21,%lg)
	        in(a22,%lg)
	        in(a23,%lg)
	        in(a31,%lg)
	        in(a32,%lg)
	        in(a33,%lg)
	        ig(a,%lg)
	        ig(b,%lg)
	        ig(c,%lg)
	        
	        det0=det(a11,a12,a13,a21,a22,a23,a31,a32,a33);
	        if(det0!=0){
	        	
	        	det1=det(a,b,c,a21,a22,a23,a31,a32,a33);
                det2=det(a11,a12,a13,a,b,c,a31,a32,a33);
                det3=det(a11,a12,a13,a21,a22,a23,a,b,c);
                
                  x=det1/det0;
                  y=det2/det0;
                  z=det3/det0;
               
			    printf("La solucion del sistema de ecuaciones es\n x=%lg \n y=%lg \n z=%lg \n",x,y,z);
                
	        }
            
            else printf("El sistema de ecuaciones lineales no tiene solucion unica\n");
	break;	 
	default: printf("Unknown option");	 	
		 }
	system("PAUSE");
	return 0;
}
