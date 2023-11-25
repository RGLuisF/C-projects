#include<stdlib.h>
#include<string.h>
#include<curses.h>

#define WIDTH 30
#define HEIGHT 15

#define BUF_SIZE 1024

WINDOW *crearventana(int h, int w, int y0, int x0);
int numren(FILE *file);
void borrarventana(WINDOW *window);
void imprimir(WINDOW *window, FILE *file,int n, int t);

int main(int argc, char *argv){
  FILE* lista;
  WINDOW* menu;
  int my,mx,ch,h = 0,t = 0,r = 0;
  float x0,y0;

  lista = fopen("prueba.txt","r");
  
  if (lista == NULL){
    printf("No se pudo abrir el archivo");
    return 0;
  }
  
  initscr();
  if(has_colors() == FALSE){
    printf("La terminal no soporta color");
    endwin();
    return 0;
  }
  cbreak();
  noecho();
  keypad(stdscr,true);
  curs_set(0);

  use_default_colors();
  start_color();
  printw("Presione F1 para salir");
  getmaxyx(stdscr,mx,my);
  x0 = (my - WIDTH)/2;
  y0 = (mx - HEIGHT)/2;
  refresh();

  menu = crearventana(HEIGHT,WIDTH,y0,x0);
  imprimir(menu,lista,h,t);
  refresh();
  
  r = numren(lista)-1;

  while((ch = wgetch(menu)) != KEY_F(1)){
    switch(ch){
      case KEY_UP:
                  if(h > 0) h--;
                  if(h < t) t--;
                  borrarventana(menu);
                  menu = crearventana(HEIGHT,WIDTH,y0,x0);
                  imprimir(menu,lista,h,t); 
                  break;
      case KEY_DOWN:
                  if(h < r) h++;
                  if((HEIGHT-2)+t<=h) t++;
                  borrarventana(menu);
                  menu = crearventana(HEIGHT,WIDTH,y0,x0);
                  imprimir(menu,lista,h,t);
                  break;
      default: mvprintw(1, 0, "Tecla presionada es %3d Hopefully it can be printed as '%c' %d", ch, ch,r);
				       refresh();
				       break;
    }
  }

  borrarventana(menu);
  endwin();
  fclose(lista);
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

int numren(FILE* file)
{
    char buf[BUF_SIZE];
    int counter = 0;
    fseek(file,0,SEEK_SET);
    while(1)
    {
        size_t res = fread(buf, 1, BUF_SIZE, file);
        if (ferror(file))
            return -1;

        int i;
        for(i = 0; i < res; i++)
            if (buf[i] == '\n')
                counter++;

        if (feof(file))
            break;
    }

    return counter;
}
void borrarventana(WINDOW *window){
    wclear(window);
    wrefresh(window);
    delwin(window);
}
 
void imprimir(WINDOW *window,FILE *file,int h, int t){
  char s[20];
  int j;

  fseek(file,0,SEEK_SET);
  
  for(j = 0; j < t ; j++)
  fgets(s,20,file);

  for(j = t; j < (HEIGHT-2)+t; j++){
    if(fgets(s,20,file) != NULL){
    s[strcspn(s,"\n")] = 0; 
    if (j == h){
      wattron(window, A_REVERSE);
      mvwprintw(window, j-t+1, 1, s);
      wattroff(window, A_REVERSE);
    }
    else mvwprintw(window, j-t+1, 1, s);
  }
  wrefresh(window);
  }
}
