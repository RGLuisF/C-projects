#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Operador{
char op;
struct Operador *sig;
}Operador;

typedef struct Operando{
char var;
double val;
struct Operando *sig;
}Operando;

typedef Operador *Pilaoperador;

typedef Operando *Pilaoperando;

int imprimepop(Pilaoperador *Pila);
int imprimepvar(Pilaoperando *Pila);

Pilaoperando buscavar(char var, Pilaoperando *Pila);
int insertaop(char op, Pilaoperador *Pila);
int insertavar(char var, double val, Pilaoperando *Pila);
int leervalores(char* s, Pilaoperando *pvar);
int leercadena(char* s, int e, Pilaoperador *pop, Pilaoperando *pvar, Pilaoperando *aux);
int evalua(char *s, Pilaoperador *pop, Pilaoperando *pvar, Pilaoperando *aux);
int opera(Pilaoperador *pop, Pilaoperando *pvar);
int precedencia(char op);
int esop(char op);

int main(int argc, char *argv[]){
Pilaoperando pvar=NULL, aux=NULL;
Pilaoperador pop=NULL;
char s[128];
printf("Este programa evalua una expresion dada\n");
printf("Constantes y funciones disponibles:\n"
       "P=pi\tE=e\tL=ln\n"
       "S=sin\tC=cos\tT=tan\n"
       "Expresion a leer:");
scanf("%[^\n]%*c",&s);
leervalores(s,&aux);
evalua(s,&pop, &pvar, &aux);
printf("\n");
system("PAUSE");
return 0;
}

int imprimepop(Pilaoperador *Pila){
    Pilaoperador aux;
    aux=*Pila;
    
    if(aux==NULL){
    printf("Sin operadores\n");
    return 0;
    }

    while(aux!=NULL){
        printf("%c\n",aux->op);
        aux = aux->sig; 
    }
    return 0;
}

int imprimevar(Pilaoperando *Pila){
    Pilaoperando aux;
    aux=*Pila;
    
    if(aux==NULL){
    printf("Sin operandos\n");
    return 0;
    }

    while(aux!=NULL){
        printf("%c=%g\n",aux->var, aux->val);
        aux = aux->sig; 
    }
    return 0;
}

int insertaop(char op, Pilaoperador *Pila){
    Operador *aux;
    Pilaoperador aux1;
    
    aux=(Operador*)malloc(sizeof(Operador));
    if(aux!=NULL){
    aux->op=op;
    aux->sig=NULL;
    }
    else return -1;
    
    if(*Pila==NULL){
      *Pila=aux;
      return 0;
    }
    else{
      aux1=*Pila;
      aux->sig=aux1;
      *Pila=aux;
    }
    return 0;
}

int insertavar(char var, double val, Pilaoperando *Pila){
    Operando *aux;
    Pilaoperando aux1;
    
    aux=(Operando*)malloc(sizeof(Operando));
    if(aux!=NULL){
    aux->var = var;
    aux->val = val;
    aux->sig = NULL;
    }
    else return -1;
    
    if(*Pila==NULL){
      *Pila=aux;
      return 0;
    }
    else{
      aux1=*Pila;
      aux->sig=aux1;
      *Pila=aux;
    }
    return 0;
}

Pilaoperando buscavar(char var, Pilaoperando *Pila){
    Pilaoperando aux;
    aux=*Pila;
    
    if(aux==NULL) return aux;
    while(aux!=NULL){
      if(aux->var == var){
        return aux;
      }
      aux = aux->sig; 
   }
   aux = NULL;
   return aux;
}

int leervalores(char* s, Pilaoperando *pvar){
    Operando *aux;
    double val;
    int i;
    
    for(i=0; i<strlen(s); i++){
       if(!esop(s[i]) && s[i] != '(' && s[i] != ')' && s[i] != 'P' && s[i] != 'E' && s[i] != 'x'){
          if(buscavar(s[i], pvar)!= NULL){
                 aux = buscavar(s[i], pvar);
                 insertavar(s[i],aux->val,pvar);
          }
          else{
          printf("\nDigite el valor de %c: ", s[i]);
          scanf("%lg",&val);
          insertavar(s[i],val,pvar);
          }
       }
    }
    return 0;
}

int leercadena(char* s, int e, Pilaoperador *pop, Pilaoperando *pvar, Pilaoperando *pval){
    Operando *aux;
    double val;
    int i;
   
    for(i=0; i<strlen(s); i++){
       if(esop(s[i])){
         if(*pop!=NULL){
          if(precedencia(s[i])<precedencia((*pop)->op)){
             do{               
              opera(pop, pvar);
             }while(*pop!=NULL && (*pop)->op!='(');
             insertaop(s[i], pop);  
          }
          else insertaop(s[i], pop);
         }
         else insertaop(s[i], pop);
       }
       else if(s[i]== ')'){
         if(*pop!=NULL){
            do{
            opera(pop, pvar);
            }while(*pop!=NULL && (*pop)->op!='(');
            libpop(pop);
         }
       }
       else if(s[i] == '(')  insertaop(s[i], pop);
       else if(s[i] == 'P')  insertavar(s[i],M_PI,pvar);
       else if(s[i] == 'E')  insertavar(s[i],M_E,pvar);
       else if(s[i] == 'x')  insertavar(s[i],e,pvar);
       else{
            if(buscavar(s[i], pval)!= NULL){
                 aux = buscavar(s[i], pval);
                 insertavar(s[i],aux->val,pvar);
            }
            else{
                 printf("I AM ERROR");
                 printf("\nDigite el valor de %c: ", s[i]);
                 scanf("%lg",&val);
                 insertavar(s[i],val,pvar);
            }
      }
    }
    do{
       opera(pop, pvar);
    }while(*pop!=NULL);
    
    return 0;
}

int esop(char op){
    switch(op){
    case '+': return 1;
    case '-': return 1;
    case '*': return 1;
    case '/': return 1;
    case '%': return 1;
    case '^': return 1;
    case 'S': return 1;
    case 'C': return 1;
    case 'T': return 1;
    case 'L': return 1;
    default: return 0;
   }
}

int precedencia(char op){
    switch(op){
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    case '%': return 2;
    case '^': return 3;
    case 'S': return 4;
    case 'C': return 4;
    case 'T': return 4;
    case 'L': return 4;
    default: return 0;
    }
}

int opera(Pilaoperador *pop, Pilaoperando *pvar){
   double aux;
   
   if(*pop==NULL) return 0;
   if(*pvar==NULL) return 0;
   
   switch((*pop)->op){
    case '+': aux = (*pvar)->sig->val+(*pvar)->val;
              libpvar(pvar);
              libpvar(pvar);
              insertavar('+', aux, pvar);
              libpop(pop);
              break;
    case '-': aux = (*pvar)->sig->val-(*pvar)->val;
              libpvar(pvar);
              libpvar(pvar);
              insertavar('-', aux, pvar);
              libpop(pop);
              break; 
    case '*': aux = (*pvar)->sig->val*(*pvar)->val;
              libpvar(pvar);
              libpvar(pvar);
              insertavar('*', aux, pvar);
              libpop(pop);
              break;
    case '/': if((*pvar)->val!=0){
              aux = (*pvar)->sig->val/(*pvar)->val;
              libpvar(pvar);
              libpvar(pvar);
              insertavar('/', aux, pvar);
              libpop(pop);
              break;
              }else printf("No se puede dividir entre cero\n"); return -1;
    case '%': if((*pvar)->val!=0){
              aux = fmod((*pvar)->sig->val,(*pvar)->val);
              libpvar(pvar);
              libpvar(pvar);
              insertavar('%', aux, pvar);
              libpop(pop);
              break;
              }else printf("No se puede dividir entre cero\n"); return -1;
    case '^': aux = pow((*pvar)->sig->val,(*pvar)->val);
              libpvar(pvar);
              libpvar(pvar);
              insertavar('^', aux, pvar);
              libpop(pop);
              break;
    case 'S': aux = sin((*pvar)->val);
              libpvar(pvar);
              insertavar('S', aux, pvar);
              libpop(pop);
              break;
    case 'C': aux = cos((*pvar)->val);
              libpvar(pvar);
              insertavar('C', aux, pvar);
              libpop(pop);
              break;
    case 'T': aux = tan((*pvar)->val);
              libpvar(pvar);
              insertavar('T', aux, pvar);
              libpop(pop);
              break;
              
    case 'L': aux = log((*pvar)->val);
              libpvar(pvar);
              insertavar('L', aux, pvar);
              libpop(pop);
              break;   
   }
   return 0;
}

int evalua(char *s, Pilaoperador *pop, Pilaoperando *pvar, Pilaoperando *aux){
    double r;
    int e;
    
    for(e=-5; e<6; e++){
           leercadena(s,e,pop,pvar,aux);
           printf("\nLa expresion evaluada en %d es: %lg\n",e,(*pvar)->val);
    }
    return 0;
}

int libpvar(Pilaoperando *pvar){
    Operando *f;
    f = *pvar;
    *pvar = (*pvar)->sig;
    f->sig=NULL;
    free(f);
    return 0;
}

int libpop(Pilaoperador *pop){
    Operador *f;
    f = *pop;
    *pop = (*pop)->sig;
    f->sig=NULL;
    free(f);
    return 0;
}
