#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define N 19                           

enum est{nuevo, enlistado, visitado};     

typedef struct nodo{
    int x;                                  
    int y;                                  
    int libre;                              
    int d;                                  
    int estado;                             
    struct nodo *ant;
}nodo;

int maze[N][N] =                     
{   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1 },
    { 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
    { 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1 },
    { 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1 },
    { 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
    { 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1 },
    { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
    { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
    { 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1 }};

nodo node[N][N];                 
nodo *lista[N*N];                  
int tl;              

void adyacente(nodo *cptr, int x, int y);
void Dijkstra(nodo *cptr, nodo *salida);
void dibujamaze(int x, int y, int n);
void dibujacamino(nodo *salida);
void caminomascorto(nodo *salida);
void mostrarlistaa();


int main(void)
{  
   int i,j;  
   nodo *aux, *salida;
   salida = &node[N-1][N-1];
   tl=0;
    
   for (j=0; j<N; j++) {
        for (i=0; i<N; i++) {
            aux = &node[j][i];           
            aux->libre = maze[j][i];     
            aux->x = i;                    
            aux->y = j;                  
            aux->d = 400;               
            aux->estado = nuevo;         
            aux->ant = NULL;
        }
    }
                                                   
    Dijkstra(aux,salida);                                      
    dibujacamino(salida);
    
    system("PAUSE");
    return 0;
}

void adyacente(nodo *aux, int a, int b)
{
    nodo *vecino;                           
    int d;                            
    int x = aux->x + a;                   
    int y = aux->y + b;                   
    if (x < 0 || x >= N || y < 0 || y >= N) 
        return;                               
    vecino = &node[y][x];                     
                          
    if (vecino->libre == 0)                 
        return;
    if (vecino->estado == visitado)         
        return;
    
    d = aux->d + 1;     
    if (d < vecino->d)                
        vecino->d = d;                          
    if (vecino->estado == nuevo) {           
        lista[tl++] = vecino;            
        vecino->estado = enlistado;          
    }
    vecino->ant=aux; 
}

void Dijkstra(nodo *aux, nodo *salida){
   int i, j, k, min;

    aux = &node[0][0];                 
    aux->d  = 0;                        

    while (aux != salida) {                
        aux->estado = visitado;            
        adyacente(aux,  0, -1); 
        adyacente(aux,  0, 1);             
        adyacente(aux, -1, 0);              
        adyacente(aux,  1, 0);             
                        
        min = 400;
        k = -1;             
        
        
        for (i=0; i<tl; i++) {
            if (min > lista[i]->d) { 
                min = lista[i]->d;   
                k = i;
            } 
        }
       
        if(k < 0) {              
            printf("No hay forma de llegar a la salida.\n");
            return;
        }
   
        dibujamaze(aux->x,aux->y,aux->d);
        mostrarlistaa();
        Sleep(10);
        aux = lista[k];
        if (tl>0)                      
           lista[k] = lista[--tl];
 
    }
      
}

void dibujamaze(int x, int y, int n){
    int i,j;
    Sleep(100);
    system("cls");
    for(i=0;i<N+2;i++) printf("M ");
    for(i=0;i<N;i++){
      printf("\nM ");
       for(j=0;j<N;j++){
         if(maze[i][j]==1){
              if (i==0 && j==0) printf("E ");
              else if (i==N-1 && j==N-1) printf("S ");
              else if (i==y && j==x) printf("%d ",n);
              else printf("  ",n);
            }
         else printf("M ");    
        }
        printf("M ");
    }
    printf("\n");
    for(i=0;i<N+2;i++) printf("M ");
    printf("\n");
    printf("\n");
}

void dibujacamino(nodo *salida){
   nodo *aux;
    
    int i,j,f=0;
    system("cls");
    for(i=0;i<N+2;i++) printf("M ");
    for(i=0;i<N;i++){
      printf("\nM ");
       for(j=0;j<N;j++){
         if(maze[i][j]==1){
              if (i==0 && j==0) printf("E ");
              else if (i==N-1 && j==N-1) printf("S ");
              else{
                   aux=salida; 
                   while(aux!=&node[0][0]){
                       if(i==aux->y && j==aux->x){
                             f=1;
                             break;
                       }
                       aux=aux->ant;
                   }
                   if(f==1) printf("1 ");
                   else  printf("  ");
                   f=0;
              } 
        }
        else printf("M ");    
        }
        printf("M ");
    }
    printf("\n");
    for(i=0;i<N+2;i++) printf("M ");
    printf("\n");
    printf("\n");
}

void caminomascorto(nodo *salida){
    nodo *aux;
    aux=salida;
    while(aux!=&node[0][0]){
         printf("(%d,%d)=%d\n",aux->x, aux->y, aux->d);
        aux=aux->ant;
    }
}

void mostrarlistaa(){
    int i;
    if (tl>0){
       printf("(x,y)=distancia\n");
       for(i=0;i<tl;i++){
          printf("(%d,%d)=%d\n",lista[i]->x, lista[i]->y,lista[i]->d);
       }
    }
}
