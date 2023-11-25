#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<ncurses.h>

typedef struct v2d{
  float x;
  float y;
}V2D;

typedef struct v3d{
  float x;
  float y;
  float z;
}V3D;

V2D rotarV2D(V2D v, V2D c, float A);
V3D rotarV3D(V3D v, V3D t, float A, float B, float C);
V2D calcularproy(V3D v, V2D c,int w, int h, int d);
void dibujarlinea(V2D v0,V2D vf);

/*void dibujarlineaxd(V2D v0,V2D vf);*/

int main(){

  initscr();

  if(has_colors() == FALSE){
    endwin();
    return 0;
  }
  use_default_colors();
  start_color();
  noecho();
  cbreak;

  float mx=0.0, my=0.0, A=0.0, B=0.0, C=0.0, l=20, pm=0.0;
  int dp=40,d=70,a=7,ch;
  V2D v1, v2, v3, v4, v5, v6, v7, v8, c;
  V3D w1, w2, w3, w4, w5, w6, w7, w8, t;

  getmaxyx(stdscr,mx,my);
  c.x = mx/2;
  c.y = my/2;
  
  printw("Presione 1 para cuadrado, 2 para el cubo");
  ch = getch();
  if (ch == '1'){

  v1.x = mx/2+a;
  v1.y = my/2+a;

  v2.x = mx/2-a;
  v2.y = my/2+a;

  v3.x = mx/2-a;
  v3.y = my/2-a;
  
  v4.x = mx/2+a;
  v4.y = my/2-a;
  
  while(1){
  clear();
  dibujarlinea(rotarV2D(v1,c,A),rotarV2D(v2,c,A));
  dibujarlinea(rotarV2D(v2,c,A),rotarV2D(v3,c,A));
  dibujarlinea(rotarV2D(v3,c,A),rotarV2D(v4,c,A));
  dibujarlinea(rotarV2D(v4,c,A),rotarV2D(v1,c,A));
  A += 0.05;
  refresh();
  usleep(50000);
  }
  }
  else if(ch == '2'){

  w1.x = 0*l+d;
  w1.y = 0*l+d;
  w1.z = 0*l+d;

  w2.x = 1*l+d;
  w2.y = 0*l+d;
  w2.z = 0*l+d;

  w3.x = 1*l+d;
  w3.y = 1*l+d;
  w3.z = 0*l+d;

  w4.x = 0*l+d;
  w4.y = 1*l+d;
  w4.z = 0*l+d;

  w5.x = 0*l+d;
  w5.y = 1*l+d;
  w5.z = 1*l+d;

  w6.x = 0*l+d;
  w6.y = 0*l+d;
  w6.z = 1*l+d;

  w7.x = 1*l+d;
  w7.y = 0*l+d;
  w7.z = 1*l+d;

  w8.x = 1*l+d;
  w8.y = 1*l+d;
  w8.z = 1*l+d;
  
  t.x = (w1.x + w8.x)/2;
  t.y = (w1.y + w8.y)/2;
  t.z = (w1.z + w8.z)/2;

 while(1){

  clear();
  v1 = calcularproy(rotarV3D(w1,t,A,B,C),c,mx,my,dp);
  v2 = calcularproy(rotarV3D(w2,t,A,B,C),c,mx,my,dp);
  v3 = calcularproy(rotarV3D(w3,t,A,B,C),c,mx,my,dp);
  v4 = calcularproy(rotarV3D(w4,t,A,B,C),c,mx,my,dp);
  v5 = calcularproy(rotarV3D(w5,t,A,B,C),c,mx,my,dp);
  v6 = calcularproy(rotarV3D(w6,t,A,B,C),c,mx,my,dp);
  v7 = calcularproy(rotarV3D(w7,t,A,B,C),c,mx,my,dp);
  v8 = calcularproy(rotarV3D(w8,t,A,B,C),c,mx,my,dp);

  /*
  move(v1.x,v1.y);
  addch(ACS_LARROW);
  move(v2.x,v2.y);
  addch(ACS_PLUS);
  move(v3.x,v3.y);
  addch(ACS_VLINE);
  move(v4.x,v4.y);
  addch(ACS_HLINE);
  move(v5.x,v5.y);
  addch(ACS_BULLET);
  move(v6.x,v6.y);
  addch(ACS_UARROW);
  move(v7.x,v7.y);
  addch(ACS_DARROW);
  move(v8.x,v8.y);
  addch(ACS_BLOCK);
  */
  
  dibujarlinea(v1,v2);
  dibujarlinea(v2,v3);
  dibujarlinea(v3,v4);
  dibujarlinea(v4,v1);
  dibujarlinea(v1,v6);
  dibujarlinea(v2,v7);
  dibujarlinea(v3,v8);
  dibujarlinea(v4,v5);
  dibujarlinea(v6,v7);
  dibujarlinea(v7,v8);
  dibujarlinea(v8,v5);
  dibujarlinea(v5,v6);
 
  A += 0.05;  /*x fijo*/
  B += 0.05;  /*y fijo*/
  C += 0.00;  /*z fijo*/
  usleep(50000);
  refresh();
 }
 }
 else{
  clear();
  printw("Opcion invalida, se cerrara el programa");
  refresh();
  getch();
 }
  endwin();
  return 0;
}

V2D rotarV2D(V2D v, V2D c, float A){
  V2D aux;

  aux.x = c.x + (v.x - c.x) * cos(A) - (v.y - c.y) * sin(A);
  aux.y = c.y + (v.x - c.x) * sin(A) + (v.y - c.y) * cos(A);

  return aux;
}

V3D rotarV3D(V3D v, V3D t ,float A, float B, float C){
  V3D aux;

  aux.x = t.x + (v.y-t.y) * sin(A) * sin(B) * cos(C) - (v.z-t.z) * cos(A) * sin(B) * cos(C) +
          (v.y-t.y) * cos(A) * sin(C) * (v.z-t.z) * sin(A) * sin(C) + (v.x-t.x) * cos(B) * cos(C);

  aux.y = t.y + (v.y-t.y) * cos(A) * cos(C) + (v.z-t.z) * sin(A) * cos(C) -
          (v.y-t.y) * sin(A) * sin(B) * sin(C) + (v.z-t.z) * cos(A) * sin(B) * sin(C) -
          (v.x-t.x) * cos(B) * sin(C);

  aux.z = t.z + (v.z-t.z) * cos(A) * cos(B) - (v.y-t.y) * sin(A) * cos(B) + (v.x-t.x) * sin(B);

  return aux;
}

V2D calcularproy(V3D v, V2D c,int w, int h, int d){  
  float coef = d/(v.z);
  V2D p;
  
  p.x = coef * v.x - 28;
  p.y = coef * v.y + 7;

  return p;
}

void dibujarlinea(V2D v0, V2D vf){
  
  float dx, dy, err, e2;
  int sx, sy;
  V2D aux = v0;

  dx = abs(vf.x - v0.x);
  dy = -abs(vf.y - v0.y);

  sx = v0.x < vf.x ? 1 : -1;
  sy = v0.y < vf.y ? 1 : -1;

  err = dx + dy;

  while(floor(aux.x) != floor(vf.x)+sx && floor(aux.y) != floor(vf.y)+sy){
    move(aux.x,aux.y);
    addch(ACS_BLOCK);
    e2 = 2 * err;
    if(e2 >= dy) {err += dy; aux.x += sx;}
    if(e2 <= dx) {err += dx; aux.y += sy;}
  }
}

/*void dibujarlineaxd(V2D v0,V2D vf){
  int i=0,j=0;
  bool dx,dy;
  float m=0.0,d=0.0;
  V2D aux;
  
  (v0.y-vf.y)<abs(v0.x-vf.x) ? (d=abs(v0.x-vf.x)) : (d=abs(v0.y-vf.y));
  (v0.y-vf.y<=0) ? (dy=FALSE) : (dy=TRUE); True vf arriba de v0, False vf abajo o igual de v0
  
  if(v0.x-vf.x!=0){
    m=abs(v0.y-vf.y)/abs(v0.x-vf.x);
    (v0.x-vf.x<0) ? (dx=TRUE) : (dx=FALSE); True vf a la derecha de v0, False vf a la izquierda de v0
  }
  else{
    m=0.0;
    dx=FALSE; vf igual que v0
  }
}

  while(1){ 
  getmaxyx(stdscr,mx,my);
  c.x=mx/2;
  c.y=my/2;
  clear();
  for(i=0;i<5;i++)
  {
    v1.x=c.x+i;
    v1.y=c.y;
    v1=rotarV2D(v1,c,j);
    move(v1.x,v1.y);
    addch(ACS_BLOCK);
  }
  j+=0.2;
  refresh();
  usleep(90000);
  }
*/
