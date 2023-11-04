/**************************
 * Includes
 *
 **********************q* ***/

#include <windows.h>
#include <gl/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**************************
 * Function Declarations
 *
 **************************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);

/**************
 *Declaraciones
 **************/
 
//LOGO
typedef int (*misFractales)(void);

typedef struct _logo_{
  double x, y;
  char pluma;
  int grados;
  void (*dibujaSegmento)(double, double, double, double);
}LOGO;

#define ARRIBA 0
#define ABAJO !(ARRIBA)
#define G2R (M_PI/180.0)
#define GSEGMENT (1/sqrt(7))
#define escX 0.125
#define escY 0.125
#define MX 0.0
#define MY 0.0

#define pi 3.14159265
//LOGO
int asignaModoDibujarSegmento(void (*dibujaSegmento)(double, double, double, double), LOGO* tortuga);
int inicia(double x, double y, int grados, char pluma, LOGO* tortuga);
int der(int g, LOGO* tortuga);
int izq(int g, LOGO* tortuga);
int avanza(double l, LOGO* tortuga);
int retrocede(double l, LOGO* tortuga);

//CORNER
int iniciaCorner(double s, int a, double l, double x, double y, LOGO *tortuga);
int dibujaCorner(void);
int anguloCorner;
double longitudCorner;
double limiteCorner;
double miX0Corner;
double miY0Corner;
LOGO *tortugaAuxCorner;

int CornerPoly(int a, double l, int tt, LOGO *tortuga);
int CornerPolystep(int a, double l, LOGO *tortuga);

//CURVAA
int iniciaCurvaA(int n, double l, double x, double y, LOGO *tortuga);
int dibujaCurvaA(void);
int nivelRecursionCurvaA;
double longitudCurvaA;
double miX0CurvaA;
double miY0CurvaA;
LOGO *tortugaAuxCurvaA;

int CurvaA(int n, double l, LOGO *tortuga);

//TRIANGLES
int iniciaTriangulos(int n, double l, double x, double y, LOGO *tortuga);
int dibujaTriangulos(void);
int nivelRecursionTriangulos;
double longitudTriangulos;
double miX0Triangulos;
double miY0Triangulos;
LOGO *tortugaAuxTriangulos;

int TriangulosEncajonados(int n, double l, LOGO *tortuga);

//SQRSNOW
int iniciaSquaresnow(int n, double l, double x, double y, LOGO *tortuga);
int dibujaSquaresnow(void);
int nivelRecursionSquaresnow;
double longitudSquaresnow;
double miX0Squaresnow;
double miY0Squaresnow;
LOGO *tortugaAuxSquaresnow;

int EDGE(int n, double l, LOGO *tortuga);

//KOCH
int iniciaKoch(int n, double l, double x, double y, LOGO *tortuga);
int dibujaKoch(void);
int dibujaKochI(void);
int dibujaKochII(void);
int nivelRecursionKoch;
double longitudKoch;
double miX0Koch;
double miY0Koch;
LOGO *tortugaAuxKoch;

int KochRecursivo(int n, double l, LOGO *tortuga);

//CURVAH
int iniciaCurvaH(int n, double l, int p, double x, double y, LOGO *tortuga);
int dibujaCurvaH(void);
int nivelRecursionCurvaH;
int paridadCurvaH;
double longitudCurvaH;
double miX0CurvaH;
double miY0CurvaH;
LOGO *tortugaAuxCurvaH;

int Hilbert(int n, double l, int p, LOGO *tortuga);

//CURVAS
int iniciaCurvaS(int n, double l, double x, double y, LOGO *tortuga);
int dibujaCurvaS(void);
int nivelRecursionCurvaS;
double longitudCurvaS;
double miX0CurvaS;
double miY0CurvaS;
LOGO *tortugaAuxCurvaS;

int Oneside(int n, double l, LOGO *tortuga);
int AuxdibujaCurvaS(int n, double l, LOGO *tortuga);


//CrewDRAGON
int iniciaDragon(int n, double l, double x, double y, LOGO *tortuga);
int dibujaDragon(void);
int nivelRecursionDragon;
double longitudDragon;
double miX0Dragon;
double miY0Dragon;
LOGO *tortugaAuxDragon;

int LDragon(int n, double l, LOGO *tortuga);
int RDragon(int n, double l, LOGO *tortuga);


//HSNOW
int iniciaHookSnow(int n, double l, double x, double y, LOGO *tortuga);
int dibujaHookSnow(void);
int RSNOW(int n, double l, LOGO *tortuga);
int LSNOW(int n, double l, LOGO *tortuga);
int nivelRecursionHookSnow;
double longitudHookSnow;
double miX0HookSnow;
double miY0HookSnow;
LOGO *tortugaAuxHookSnow;

//GOSPER
int iniciaGosper(int n, double l, double x, double y, LOGO *tortuga);
int dibujaGosper(void);
int nivelRecursionGosper;
double longitudGosper;
double miX0Gosper;
double miY0Gosper;
LOGO *tortugaAuxGosper;

int LGosper(int n, double l, LOGO *tortuga);
int RGosper(int n, double l, LOGO *tortuga);

//HMAZEC
int iniciaMalmberg(int p, int n, double l, double x, double y, LOGO *tortuga);
int dibujaMaze(void);
int nivelRecursionMaze;
int paridadMaze;
double longitudMaze;
double miX0Maze;
double miY0Maze;
LOGO *tortugaAuxMaze;

int INTERIOR(double l, LOGO *tortuga);
int Maze(int n, double l, LOGO *tortuga);

void segmento(double, double, double, double);
/**************************
 * WinMain
 *
 **************************/

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{
    WNDCLASS wc;
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;        
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "graficos";
    RegisterClass (&wc);

    char fractales=0, funciones=0;
    misFractales miFractal;
    int nRecursion = 5;
    LOGO miTortuga;
    char *miParametro="";

    if (iCmdShow>1) miParametro = lpCmdLine;
    if (strlen(lpCmdLine)==0) miParametro="triforce";

    if((strncmp(miParametro, "corner", 6)==0)||
       (strncmp(miParametro, "curvaA", 6)==0)||
       (strncmp(miParametro, "curvaH", 6)==0)||
       (strncmp(miParametro, "curvaS", 6)==0)||
       (strncmp(miParametro, "dragon", 6)==0)||
       (strncmp(miParametro, "gosper", 6)==0)||
       (strncmp(miParametro, "maze", 4)==0)||
	   (strncmp(miParametro, "weave", 5)==0)|| 
	   (strncmp(miParametro, "hooksnow", 8)==0)||
	   (strncmp(miParametro, "koch", 5)==0)||
	   (strncmp(miParametro, "squaresnow", 10)==0)||
	   (strncmp(miParametro, "triforce", 10)==0)){
       fractales=1;
      asignaModoDibujarSegmento(segmento, &miTortuga);
      if(strncmp(miParametro, "corner", 6)==0){
      	iniciaCorner(5.3, 144, 0.05, -2.7,0.5, &miTortuga);
        miFractal=dibujaCorner;
      } else if(strncmp(miParametro, "curvaA", 6)==0){
      	iniciaCurvaA(21, 0.005, 4.0, -1.0, &miTortuga);
        miFractal=dibujaCurvaA;
      } else if(strncmp(miParametro, "curvaH", 6)==0){
      	iniciaCurvaH(7, 0.40, 1, -7.8, 7.8, &miTortuga);
        miFractal=dibujaCurvaH;
      } else if(strncmp(miParametro, "curvaS", 6)==0){
      	iniciaCurvaS(5, 0.25, -7.8, 7.8, &miTortuga);
        miFractal=dibujaCurvaS;
      } else if(strncmp(miParametro, "dragon", 6)==0){
      	iniciaDragon(17, 0.025, -3.0, -2.0, &miTortuga);
        miFractal=dibujaDragon;
      } else if(strncmp(miParametro, "gosper", 6)==0){
        iniciaGosper(5, 13.3, -7.5, 1.0, &miTortuga);
        miFractal=dibujaGosper;
      } else if(strncmp(miParametro, "maze", 4)==0){
        iniciaMalmberg(-1,2, 12.2, -7.7, -1.0, &miTortuga);
        miFractal=dibujaMaze;
      } else if(strncmp(miParametro, "weave", 5)==0){
        iniciaMalmberg(1,2, 15, -7.7, -0.3, &miTortuga);
      miFractal=dibujaMaze;
      } else if(strncmp(miParametro, "hooksnow", 8)==0){
        iniciaHookSnow(6, 13.7, -7.0, -4.0, &miTortuga);
        miFractal = dibujaHookSnow;
      } else if(strncmp(miParametro, "koch", 5)==0){
        iniciaKoch(10, 13.3, -7.0, 3.8, &miTortuga);
        miFractal = dibujaKochI;
      } else if (strncmp(miParametro, "squaresnow", 10)==0){
        iniciaSquaresnow(6, 9.4, -4.7, 4.6, &miTortuga);
        miFractal=dibujaSquaresnow;
      } else if (strncmp(miParametro, "triforce", 10)==0){
        iniciaTriangulos(13, 15.0, -7.4, 6.4, &miTortuga);
        miFractal=dibujaTriangulos;
      }
    
    }

    /* create main window */
    hWnd = CreateWindow (
      "graficos", 
      "Fractals and other diabolical designs", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      0, 0, 2*480, 2*480,
      NULL, NULL, hInstance, NULL);

    /* enable OpenGL for the window */
    EnableOpenGL (hWnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */

            glClearColor (1.0f, 1.0f, 1.0f, 0.5f);
            glClear (GL_COLOR_BUFFER_BIT);

            glPushMatrix ();
            glRotatef (theta, 0.0f, 0.0f, 1.0f);
            glColor3d(0.8, 0.4, 0.5);

            if(fractales==1){
              miFractal();
            } 
            glPopMatrix ();

            SwapBuffers (hDC);

            //theta += 1.0f;
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL (hWnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow (hWnd);

    return msg.wParam;
}


/********************
 * Window Procedure
 *
 ********************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
                          WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
        return 0;
    case WM_CLOSE:
        PostQuitMessage (0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        }
        return 0;

    default:
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
}


/*******************
 * Enable OpenGL
 *
 *******************/

void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC)
{
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC (hWnd);

    /* set the pixel format for the DC */
    ZeroMemory (&pfd, sizeof (pfd));
    pfd.nSize = sizeof (pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | 
      PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat (*hDC, &pfd);
    SetPixelFormat (*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext( *hDC );
    wglMakeCurrent( *hDC, *hRC );

}


/******************
 * Disable OpenGL
 *
 ******************/

void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent (NULL, NULL);
    wglDeleteContext (hRC);
    ReleaseDC (hWnd, hDC);
}

void segmento(double x1, double y1, double x2, double y2)
{
  glBegin (GL_LINES);
    glVertex2d (MX+escX*x1, MY+escY*y1);
    glVertex2d (MX+escX*x2, MY+escY*y2);
  glEnd ();
}

//LOGO
int inicia(double x, double y, int grados, char pluma, LOGO* tortuga)
{
  tortuga->x=x;
  tortuga->y=y;
  tortuga->pluma = pluma;
  tortuga->grados = grados;
  
  return 0;
}

int asignaModoDibujarSegmento(void (*dibujaSegmento)(double, double, double, double), LOGO *tortuga)
{
  return (tortuga->dibujaSegmento = dibujaSegmento)!=NULL;
}

int der(int g, LOGO* tortuga)
{
  tortuga->grados = (((tortuga->grados-g)%360)+360)%360;
  
  return 0;
}

int izq(int g, LOGO* tortuga)
{
  return der(-g, tortuga);
}

int avanza(double l, LOGO* tortuga)
{
  double x=tortuga->x, y=tortuga->y;
  
  tortuga->x += l*cos(tortuga->grados*G2R);
  tortuga->y += l*sin(tortuga->grados*G2R);
  if (tortuga->pluma == ABAJO)
    tortuga->dibujaSegmento(x, y, tortuga->x, tortuga->y);

  return 0;
}

int retrocede(double l, LOGO* tortuga)
{
  return avanza(-l, tortuga);
}

int coloca(double x, double y, int grados, char pluma, LOGO* tortuga)
{
  tortuga->x=x;
  tortuga->y=y;
  tortuga->pluma = pluma;
  tortuga->grados = grados;

  return 0;
}

//CORNER
int iniciaCorner(double s, int a, double l, double x, double y, LOGO *tortuga){
  anguloCorner=a;
  longitudCorner = s;
  limiteCorner=l;
  miX0Corner=x;
  miY0Corner=y;
  tortugaAuxCorner = tortuga;
  
  return 0;
}

int dibujaCorner(void){
  inicia(miX0Corner, miY0Corner, 0, ABAJO, tortugaAuxCorner);

  return CornerPoly(anguloCorner, longitudCorner, 0, tortugaAuxCorner);
}

int CornerPoly(int a, double l, int tt, LOGO *tortuga){
  
  if (l<limiteCorner) return 0;
  
  CornerPolystep(a, l, tortuga);
  tt+=a;
  
  if(tt%360!=0)
  CornerPoly(a, l, tt, tortuga);
  
  return 0;
}

int CornerPolystep(int a, double l, LOGO *tortuga){
  avanza(l, tortuga);
  CornerPoly(-a, l/2, 0, tortuga);
  der(a, tortuga);
  return 0;
}

//CURVAA
int iniciaCurvaA(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionCurvaA=n;
  longitudCurvaA = l;
  miX0CurvaA=x;
  miY0CurvaA=y;
  tortugaAuxCurvaA = tortuga;
  
  return 0;
}

int dibujaCurvaA(void){
  inicia(miX0CurvaA, miY0CurvaA, 0, ABAJO, tortugaAuxCurvaA);

  return CurvaA(nivelRecursionCurvaA,longitudCurvaA,tortugaAuxCurvaA);
}

int CurvaA(int n, double l, LOGO *tortuga){
	if(n<=0){
		avanza(l,tortuga);
		return 0;
	}
	
	CurvaA(n-1,l,tortuga);
	der(90,tortuga);
	CurvaA(n-1,l,tortuga);
	izq(90,tortuga);
	
	return 0;
}

//TRAINGLES upsidupsi
int iniciaTriangulos(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionTriangulos=n;
  longitudTriangulos = l;
  miX0Triangulos=x;
  miY0Triangulos=y;
  tortugaAuxTriangulos = tortuga;
  
  return 0;
}

int dibujaTriangulos(void){
  inicia(miX0Triangulos, miY0Triangulos, 0, ABAJO, tortugaAuxTriangulos);

  return TriangulosEncajonados(nivelRecursionTriangulos, longitudTriangulos, tortugaAuxTriangulos);
}

int TriangulosEncajonados(int n, double l, LOGO *tortuga){
	int i;
	if(n<=0) return 0;
    for(i=0;i<3;i++){
    	TriangulosEncajonados(n-1, l/2, tortuga);
    	avanza(l,tortuga);
    	der(120,tortuga);
	}
	
	return 0; 
}

//SQRSNOW
int iniciaSquaresnow(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionSquaresnow=n;
  longitudSquaresnow = l;
  miX0Squaresnow=x;
  miY0Squaresnow=y;
  tortugaAuxSquaresnow = tortuga;
  
  return 0;
}

int dibujaSquaresnow(void){
  
  int i;	
  inicia(miX0Squaresnow, miY0Squaresnow, 0, ABAJO, tortugaAuxSquaresnow);

  for(i=0;i<4;i++){
  	EDGE(nivelRecursionSquaresnow,longitudSquaresnow,tortugaAuxSquaresnow);
  	der(90,tortugaAuxSquaresnow);
  }

  return 0;
}

int EDGE(int n, double l, LOGO *tortuga){
    double unit;
    if(n<=0){
    	avanza(l,tortuga);
    	return 0;
	}
    unit=l/4;
    
    EDGE(n-1,unit,tortuga);
    izq(90,tortuga);
    EDGE(n-1,unit,tortuga);
    der(90,tortuga);
    EDGE(n-1,unit,tortuga);
    der(90,tortuga);
    EDGE(n-1,unit,tortuga);
    EDGE(n-1,unit,tortuga);
    izq(90,tortuga);
    EDGE(n-1,unit,tortuga);
    izq(90,tortuga);
    EDGE(n-1,unit,tortuga);
    der(90,tortuga);
    EDGE(n-1,unit,tortuga);
    
    return 0;

}

//KOCH
int iniciaKoch(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionKoch=n;
  longitudKoch = l;
  miX0Koch=x;
  miY0Koch=y;
  tortugaAuxKoch = tortuga;
  
  return 0;
}

int dibujaKoch(void){
  inicia(miX0Koch, miY0Koch, 0, ABAJO, tortugaAuxKoch);

  return KochRecursivo(nivelRecursionKoch, longitudKoch, tortugaAuxKoch);
}

int dibujaKochI(void){
  int i;
  inicia(miX0Koch, miY0Koch, 0, ABAJO, tortugaAuxKoch);

  for (i=0; i<3; i++){
    KochRecursivo(nivelRecursionKoch, longitudKoch, tortugaAuxKoch);
    der(120, tortugaAuxKoch);
  }
  return 0;
}

int dibujaKochII(void){
  int i;
  inicia(miX0Koch, miY0Koch, 0, ABAJO, tortugaAuxKoch);

  for (i=0; i<3; i++){
    KochRecursivo(nivelRecursionKoch, longitudKoch, tortugaAuxKoch);
    izq(120, tortugaAuxKoch);
  }
  return 0;
}

int KochRecursivo(int n, double l, LOGO *tortuga)
{
  double l3;
  if (n<=0){
    avanza(l, tortuga);
    return 0;
  }
  l3=l/3.0;
  KochRecursivo(n-1, l3, tortuga);
  izq(60, tortuga);
  KochRecursivo(n-1, l3, tortuga);
  der(120, tortuga);
  KochRecursivo(n-1, l3, tortuga);
  izq(60, tortuga);
  KochRecursivo(n-1, l3, tortuga);
  
  return 0;
}

//CURVAH
int iniciaCurvaH(int n, double l, int p, double x, double y, LOGO *tortuga)
{
  nivelRecursionCurvaH=n;
  longitudCurvaH = l;
  paridadCurvaH=n;
  miX0CurvaH=x;
  miY0CurvaH=y;
  tortugaAuxCurvaH = tortuga;
  
  return 0;
}

int dibujaCurvaH(void){
  inicia(miX0CurvaH, miY0CurvaH, 0, ABAJO, tortugaAuxCurvaH);

  return Hilbert(nivelRecursionCurvaH, longitudCurvaH, paridadCurvaH, tortugaAuxCurvaH);
}

int Hilbert(int n, double l, int p, LOGO *tortuga){
	
	if(n<=0) return 0;
	
	izq(p*90,tortuga);
	Hilbert(n-1,l,-p,tortuga);
	avanza(l,tortuga);
	der(p*90,tortuga);
	Hilbert(n-1,l,p,tortuga);
	avanza(l,tortuga);
	Hilbert(n-1,l,p,tortuga);
	der(p*90,tortuga);
	avanza(l,tortuga);
	Hilbert(n-1,l,-p,tortuga);
	izq(p*90,tortuga);
	
	return 0;
}

//CURVAS
int iniciaCurvaS(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionCurvaS=n;
  longitudCurvaS = l;
  miX0CurvaS=x;
  miY0CurvaS=y;
  tortugaAuxCurvaS = tortuga;
  
  return 0;
}

int dibujaCurvaS(void){
  inicia(miX0CurvaS, miY0CurvaS, 0, ABAJO, tortugaAuxCurvaS);
    
  return AuxdibujaCurvaS(nivelRecursionCurvaS, longitudCurvaS, tortugaAuxCurvaS);
}

int AuxdibujaCurvaS(int n, double l, LOGO *tortuga){
	int i;
	double diag=l/sqrt(2);
	
	for(i=0;i<4;i++){
    	Oneside(n, l, tortuga);
    	der(45,tortuga);
    	avanza(diag,tortuga);
    	der(45,tortuga);
	}
	
	return 0;
}

int Oneside(int n, double l, LOGO *tortuga){
	
	double diag=l/sqrt(2);
	
	if(n<=0) return 0;
	
	Oneside(n-1, l,tortuga);
	der(45,tortuga);
	avanza(diag,tortuga);
	der(45,tortuga);
	Oneside(n-1, l,tortuga);
	izq(90,tortuga);
	avanza(l,tortuga);
	izq(90,tortuga);
	Oneside(n-1, l,tortuga);
	der(45,tortuga);
	avanza(diag,tortuga);
	der(45,tortuga);
	Oneside(n-1, l,tortuga);
	
	return 0;
}

//CrewDRAGON
int iniciaDragon(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionDragon=n;
  longitudDragon = l;
  miX0Dragon=x;
  miY0Dragon=y;
  tortugaAuxDragon = tortuga;
  
  return 0;
}

int dibujaDragon(void){
  inicia(miX0Dragon, miY0Dragon, 0, ABAJO, tortugaAuxDragon);

  return LDragon(nivelRecursionDragon, longitudDragon, tortugaAuxDragon);
}

int LDragon(int n, double l, LOGO *tortuga){
	if(n<=0){
		avanza(l,tortuga);
		return 0;
	}
	
	LDragon(n-1,l,tortuga);
	izq(90,tortuga);
	RDragon(n-1,l,tortuga);
	
	return 0;	
}

int RDragon(int n, double l, LOGO *tortuga){
	if(n<=0){
		avanza(l,tortuga);
		return 0;
	}
	LDragon(n-1, l, tortuga);
	der(90, tortuga);
	RDragon(n-1,l,tortuga);
	
	return 0;
}

//HSNOW
int iniciaHookSnow(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionHookSnow=n;
  longitudHookSnow = l;
  miX0HookSnow=x;
  miY0HookSnow=y;
  tortugaAuxHookSnow = tortuga;
  
  return 0;
}

int dibujaHookSnow(void){
  inicia(miX0HookSnow, miY0HookSnow, 0, ABAJO, tortugaAuxHookSnow);

  return RSNOW(nivelRecursionHookSnow,longitudHookSnow,tortugaAuxHookSnow);
}

int RSNOW(int n, double l, LOGO *tortuga){
    double unit,sunit;
    
    if(n<=0){
    	avanza(l,tortuga);
    	return 0;
	}
	
	unit=l/3;
	sunit=(l*2*sin(pi/3))/9;
	
	izq(60,tortuga);
	LSNOW(n-1,unit,tortuga);
	RSNOW(n-1,unit,tortuga);
	der(60,tortuga);
	RSNOW(n-1,unit,tortuga);
	der(60,tortuga);
	RSNOW(n-1,unit,tortuga);
	der(150,tortuga);
	RSNOW(n-1,sunit,tortuga);
	LSNOW(n-1,sunit,tortuga);
	izq(60,tortuga);
	RSNOW(n-1,sunit,tortuga);
	izq(60,tortuga);
	LSNOW(n-1,sunit,tortuga);
	RSNOW(n-1,sunit,tortuga);
	izq(90,tortuga);
	LSNOW(n-1,unit,tortuga);
	RSNOW(n-1,unit,tortuga);
	
	return 0;
}

int LSNOW(int n, double l, LOGO *tortuga){
    double unit,sunit;
    if(n<=0){
    	avanza(l,tortuga);
    	return 0;
	}
	
	unit=l/3;
	sunit=(l*2*sin(pi/3))/9;
	
	LSNOW(n-1,unit,tortuga);
	RSNOW(n-1,unit,tortuga);
	der(90,tortuga);
	LSNOW(n-1,sunit,tortuga);
	RSNOW(n-1,sunit,tortuga);
	der(60,tortuga);
	LSNOW(n-1,sunit,tortuga);
	der(60,tortuga);
	RSNOW(n-1,sunit,tortuga);
	LSNOW(n-1,sunit,tortuga);
	izq(150,tortuga);
	LSNOW(n-1,unit,tortuga);
	izq(60,tortuga);
	LSNOW(n-1,unit,tortuga);
	izq(60,tortuga);
	LSNOW(n-1,unit,tortuga);
	RSNOW(n-1,unit,tortuga);
	der(60,tortuga);
	
	return 0;
}

//GOSPER
int iniciaGosper(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionGosper=n;
  longitudGosper = l;
  miX0Gosper=x;
  miY0Gosper=y;
  tortugaAuxGosper = tortuga;
  
  return 0;
}

int dibujaGosper(void){
  inicia(miX0Gosper, miY0Gosper, 0, ABAJO, tortugaAuxGosper);

  return RGosper(nivelRecursionGosper, longitudGosper, tortugaAuxGosper) ;
}

int RGosper(int n, double l, LOGO *tortuga){
    
    double unit;
    
    if(n<=0){
    	avanza(l,tortuga);
    	return 0;
	}
	
	unit=l*GSEGMENT;
	der(75,tortuga);
	LGosper(n-1,unit,tortuga);
	izq(60,tortuga);
	RGosper(n-1,unit,tortuga);
	RGosper(n-1,unit,tortuga);
	izq(120,tortuga);
	RGosper(n-1,unit,tortuga);
	izq(60,tortuga);
	LGosper(n-1,unit,tortuga);
	der(120,tortuga);
	LGosper(n-1,unit,tortuga);
	der(60,tortuga);
	RGosper(n-1,unit,tortuga);
	izq(15,tortuga);

	return 0;
}
int LGosper(int n, double l, LOGO *tortuga){
    
    double unit;
    
    if(n<=0){
    	avanza(l,tortuga);
    	return 0;
	}
	
	unit=l*GSEGMENT;
	der(15,tortuga);
	LGosper(n-1,unit,tortuga);
	izq(60,tortuga);
	RGosper(n-1,unit,tortuga);
    izq(120,tortuga);
    RGosper(n-1,unit,tortuga);
    der(60,tortuga);
    LGosper(n-1,unit,tortuga);
    der(120,tortuga);
    LGosper(n-1,unit,tortuga);
    LGosper(n-1,unit,tortuga);
    der(60,tortuga);
    RGosper(n-1,unit,tortuga);
    izq(75,tortuga);
    
	return 0;	
}

//HMAZEC
int iniciaMalmberg(int p, int n, double l, double x, double y, LOGO *tortuga)
{ 
  paridadMaze=p;
  nivelRecursionMaze=n;
  longitudMaze = l;
  miX0Maze=x;
  miY0Maze=y;
  tortugaAuxMaze = tortuga;
  
  return 0;
}

int dibujaMaze(void){
	inicia(miX0Maze, miY0Maze, 0, ABAJO, tortugaAuxMaze);
	
	return Maze(nivelRecursionMaze,longitudMaze,tortugaAuxMaze);
}

int Maze(int n, double l, LOGO *tortuga){
  int i;
  double unit;
  if(n<=0){
  	INTERIOR(l,tortuga);
  	return 0;
  }
  unit=l/3;
  Maze(n-1,unit,tortuga);
  izq(90,tortuga);
  Maze(n-1,unit,tortuga);
  
  for(i=0;i<3;i++){
  	der(90,tortuga);
  	Maze(n-1,unit,tortuga);
  }
  
  for(i=0;i<3;i++){
  	izq(90,tortuga);
  	Maze(n-1,unit,tortuga);
  }
  
  der(90,tortuga);
  Maze(n-1,unit,tortuga);
  
  return 0;
}

int INTERIOR(double l, LOGO *tortuga){
  double unit=l/5;
  int p=-paridadMaze; 
  
  if(p>0){
  	p=1;
  	izq(45,tortuga);
  } 
  avanza(4*unit,tortuga);
  der(90*p,tortuga);
  avanza(3*unit,tortuga);
  der(90*p,tortuga);
  avanza(2*unit,tortuga);
  der(90*p,tortuga);
  avanza(unit,tortuga);
  der(90*p,tortuga);
  avanza(unit,tortuga);
  izq(90*p,tortuga);
  avanza(unit,tortuga);
  izq(90*p,tortuga);
  avanza(2*unit,tortuga);
  izq(90*p,tortuga);
  avanza(3*unit,tortuga);
  izq(90*p,tortuga);
  avanza(4*unit,tortuga);
  izq(90*p,tortuga);
  avanza(4*unit,tortuga);
  der(90*p,tortuga);
  if(p>0){
  	der(90,tortuga);
  	avanza(4*unit,tortuga);
  	izq(45,tortuga);
  }  
   
  return 0;
}
