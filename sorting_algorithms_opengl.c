/**************************
 * Includes
 *
 **************************/

#include <windows.h>
#include <stdio.h>
#include <gl/gl.h>


#define escX 0.06
#define escY 0.033
#define MX -0.8
#define MY -1.0
#define pi 3.14159265
/**************************
 * Function Declarations
 *
 **************************/
LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);

void segmento(double, double, double, double);
void dibujaarreglo(int array[]);
void intercambio(int array[], int i, int j, HDC hDC);
void actualizar(int array[],HDC hDC);

void interdir(int array[],HDC hDC);
void selecdir(int array[],HDC hDC);
void inserdir(int array[],HDC hDC);
void shell(int array[], HDC hDC);

void heap(int array[],int n, int i, HDC hDC);
void heapsort(int array[], HDC hDC);

int  subconjunto(int array[], int min, int max, HDC hDC); 
void quicksort(int array[], int min, int max, HDC hDC);

void mergesort(int arr[], int l, int r,HDC hDC);
void combinar(int arr[], int l, int m, int r,HDC hDC);


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
    wc.lpszClassName = "Algoritmos";
    RegisterClass (&wc);
    
    ////DECLARACIONES////
    int ar[]={7,6,36,9,12,33,21,37,38,46,15,25,28,34,14,20,
              18,16,3,47,27,13,40,5,31,26,30,49,4,11,42,44,
              45,29,22,35,10,50,43,41,8,48,17,39,24,32,2,1,
              19,23}; 
    char *miParametro="";
    if (iCmdShow>1) miParametro = lpCmdLine;
    
    /* create main window */
    hWnd = CreateWindow (
      "Algoritmos", "Ordenamiento", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      100, 100, 640, 480,
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
            glPushMatrix ();
            glClear (GL_COLOR_BUFFER_BIT);
            glClearColor (1.0f, 1.0f, 1.0f, 0.0f);
            if (strlen(lpCmdLine)==0) miParametro="mergesort";    
            if(strncmp(miParametro, "intercambiodirecto", 10)==0){
             interdir(ar,hDC);
            }else if(strncmp(miParametro, "selecciondirecta", 10)==0){
             selecdir(ar,hDC);
            }else if(strncmp(miParametro, "inserciondirecta", 10)==0){
             inserdir(ar,hDC);
            }else if(strncmp(miParametro, "shellsort", 9)==0){
             shell(ar,hDC);
            }else if(strncmp(miParametro, "heapsort", 8)==0){
             heapsort(ar,hDC);
            }else if(strncmp(miParametro, "quicksort", 9)==0){
             quicksort(ar,0,49,hDC);
            }else if(strncmp(miParametro, "mergesort", 9)==0){
             mergesort(ar,0,49,hDC);
            }
            glPopMatrix ();

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
        PostQuitMessage (1);
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
{ glLineWidth(5.0);
  glBegin (GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d (MX+escX*x1, MY+escY*y1);
    glVertex2d (MX+escX*x2, MY+escY*y2);
  glEnd ();
}

void dibujaarreglo(int array[]){
  int i;
  for(i=0;i<=49;i++){
    segmento(0.0+0.5*i,0.0,0.0+0.5*i,array[i]);
  }
}


void intercambio(int array[], int  i, int j, HDC hDC){
int aux;
if(-1<i<50 && -1<j<50){
aux=array[i];
array[i]=array[j];
array[j]=aux;
}
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clean the screen and the depth buffer
glLoadIdentity();
dibujaarreglo(array);
Sleep(10);

SwapBuffers (hDC);
}

void interdir(int array[],HDC hDC){
int i,j;
dibujaarreglo(array);
 for(i=0;i<=49;i++){
    for(j=0;j<=48-i;j++){
       if(array[j]>array[j+1]){
            intercambio(array,j,j+1,hDC);
       }
    }
  }
}

void selecdir(int array[],HDC hDC){
int i,j,min;
dibujaarreglo(array);
    for(i=0;i<=49;i++){
        min=i;
        for(j=i;j<=49;j++){
          if(array[j]<array[min]) min=j;
        }
        intercambio(array,i,min,hDC);  
    }
}

void inserdir(int array[],HDC hDC){
int i;
dibujaarreglo(array);
for(i=1;i<=49;i++){
    while(i!=0 && array[i]<array[i-1]){
        intercambio(array,i-1,i,hDC);    
        i--;
    }
  }
}

void shell(int array[], HDC hDC){
int i,l=25;
dibujaarreglo(array);
while(l!=0){
    for(i=l;i<=49;i++){
         while(i-l>=0 && i>=0 &&array[i]<array[i-l]){
          intercambio(array,i-l,i,hDC);
          i=i-l;
        }
    }
    l=(int)(l/2);
   }
}


void heap(int array[],int n, int i, HDC hDC){
int aux, p=i, hd=2*i+1, hi=2*i+2;

if (hi <n  && array[hi] > array[p])
    p = hi;
if (hd <n  && array[hd] > array[p])
    p = hd;
if (p!=i){
    aux=array[i];
      array[i]=array[p];
      array[p]=aux;
      actualizar(array,hDC);
    heap(array,n,p,hDC);
    }
}

void heapsort(int array[],HDC hDC){
  int i,aux;
   dibujaarreglo(array);
   
   for(i=24;0<=i;i--){
     heap(array,50,i,hDC);
   }
   i=49;
   while(i>1){
      aux=array[i];
      array[i]=array[0];
      array[0]=aux;
      heap(array,i,0,hDC);
      i--;
   }
}


int subconjuntos(int array[], int min, int max, HDC hDC) 
{ 
    int pivote = array[max];
    int i = (min - 1);
    int j;
    
    for (j = min; j <= max - 1; j++) //checar hasta el pivote
    { 
        if (array[j] < pivote) 
        { 
            i++;
            intercambio(array,i,j,hDC);
            
        } 
    } 
    intercambio(array,i+1,max,hDC);
    return (i + 1); 
}

void quicksort(int array[], int min, int max, HDC hDC){   
    int p;
    if(min<max){ 
        p = subconjuntos(array, min, max, hDC); 
        quicksort(array, min, p - 1,hDC); 
        quicksort(array, p + 1, max,hDC); 
    }
    return; 
} 

void actualizar(int array[],HDC hDC){
    
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clean the screen and the depth buffer
glLoadIdentity();
dibujaarreglo(array);
Sleep(10);
SwapBuffers (hDC);

}

void combinar(int array[], int l, int m, int r,HDC hDC)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];
 
    i = 0;
    j = 0; 
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            actualizar(array,hDC);
            i++;
        }
        else {
            array[k] = R[j];
            actualizar(array,hDC);
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        array[k] = L[i];
        actualizar(array,hDC);
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        actualizar(array,hDC);
        j++;
        k++;
    }
}
 

void mergesort(int array[], int l, int r,HDC hDC)
{
    if(l < r){

        int m = l + (r - l) / 2;
 
        mergesort(array, l, m,hDC);
        mergesort(array, m + 1, r,hDC);

        combinar(array, l, m, r,hDC);

    }
    return;
}



