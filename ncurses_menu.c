#include<stdio.h>
#include<stdlib.h>
#include<curses.h>

WINDOW *crearventana(int h, int w, int y0, int x0);
void borrarventana(WINDOW *window);
WINDOW * moverventana(WINDOW *window, int h, int w, int *y0, int *x0);

int main(){
  initscr();
  if(has_colors()==FALSE){
    endwin();
    printf("La terminal no soporta color");
    return 0;
  }
  cbreak();
  noecho();
  keypad(stdscr,true);

  use_default_colors();
  start_color();  

  int mx,my,w,h,x0,y0,ch,i,hl;
  WINDOW *menuwin;

  getmaxyx(stdscr,mx,my);
  w = 90;
  h = 28;
  x0 = (my - w)/2;
  y0 = (mx - h)/2;
  refresh();

  menuwin = crearventana(h,w,y0,x0);
  
  char opciones[3][20] = {"Color de ventana","Mover ventana", "Cerrar"};
  hl = 0;

  while(1){

    for(i=0; i<3; i++){
      if(i==hl) wattron(menuwin , A_REVERSE);
      mvwprintw(menuwin, i+1, 1, opciones[i]);
      wattroff(menuwin, A_REVERSE);
    }

    ch = wgetch(menuwin);
    
    switch (ch) {
      case KEY_UP:
        hl--;
        if(hl == -1) hl = 0;
        break;
      case KEY_DOWN:
        hl++;
        if(hl==3) hl=2;
        break;
      default:
        break;
    }

    if(ch == 10 && hl==2) break;
    if(ch == 10){
      switch(hl){
        case 0: borrarventana(menuwin);
                menuwin = crearventana(h,w,y0,x0);
                mvwprintw(menuwin,1,1,"Falta implementar cambio de color");
                wrefresh(menuwin);
                getch();
                borrarventana(menuwin);
                menuwin = crearventana(h,w,y0,x0);
                break;
        case 1: menuwin = moverventana(menuwin,h,w,&(y0),&(x0));
                break;
      }
    }
  }
  
  endwin();
  return 0;
}

WINDOW *crearventana(int h, int w, int y0, int x0){
  WINDOW *ventana;
  ventana = newwin(h,w,y0,x0);
  keypad(ventana, TRUE);
  box(ventana,0,0);
  wrefresh(ventana);
  return ventana;
}

void borrarventana(WINDOW *window){
    wclear(window);
    wrefresh(window);
    delwin(window);
}

WINDOW *moverventana(WINDOW *window, int h, int w, int *y0, int *x0){
  int ch;
  wclear(window);
  box(window,0,0);
  mvwprintw(window,1,1,"Para mover la ventana presione las flechas direccionales");
  mvwprintw(window,2,1,"Al terminar presione la tecla Enter"); 
  wrefresh(window);
  while((ch = getch()) != 10){
    switch(ch){
      case KEY_LEFT:
        borrarventana(window);
        window = crearventana(h,w,*y0,--*x0);
      break;
      case KEY_RIGHT:
        borrarventana(window);
        window = crearventana(h,w,*y0,++*x0);
      break;
      case KEY_UP:
        borrarventana(window);
        window = crearventana(h,w,--*y0,*x0);
      break;
      case KEY_DOWN:
        borrarventana(window);
        window = crearventana(h,w,++*y0,*x0);
     break;
    }
  }
  borrarventana(window);
  window = crearventana(h,w,*y0,*x0);
  return window;
}
