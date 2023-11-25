#include<ncurses.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
  initscr();
  if(has_colors() == FALSE)
  {
    endwin();
    printf("La terminal no soporta colores");
    return 0;
  }
  use_default_colors();
  start_color();
  cbreak();
  noecho();
  keypad(stdscr,TRUE);
  
  int i=0,j=0,mx=0,my=0;
  bool fx=FALSE,fy=FALSE;
  do{
    clear();
    move(i,j);
    printw("ESFM");
    usleep(70000);
    refresh();
    
    getmaxyx(stdscr,mx,my);
    if (i>=mx-1) fx=TRUE;
    else if (i<=0) fx=FALSE;
    if (j>=my-5) fy=TRUE;
    else if (j<=0) fy=FALSE;
    
    fx==TRUE ? i-- : i++;
    fy==TRUE ? j-- : j++;

  }while(mx>0);

  getch();
  endwin();
  return 0;
}
