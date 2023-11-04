#include <stdio.h>    
#include <stdlib.h>   
#include <string.h>

enum pronombres {YO, TU, EL, NOSOTROS, USTEDES, ELLOS, TotalPronombres};
enum tiemposSimples {PRESENTE, FUTURO, PRETERITO_IMPERFECTO, CONDICIONAL, PRETERITO,  TotalTiemposSimples};                                                             
enum tiemposComplejos {PRETERITO_PERFECTO, PRETERITO_ANTERIOR, FUTURO_PERFECTO, PLUSCUAMPERFECTO, CONDICIONAL_PERFECTO, TotalTiemposCompuestos}; 
#define LONGMAX 128

typedef char enBasePronombres[TotalPronombres*(TotalTiemposSimples+4)][LONGMAX];


char *ModoIndicativoSimple[]={"Presente", "Futuro", "Pret�rito imperfecto",
                              "Condicional", "Pret�rito" };
                              
char *ModoIndicativoCompuesto[]={"Pret�rito perfecto", "Pret�rito anterior", "Futuro perfecto", 
                                 "Pret�tiro pluscuamperfecto", "Condicional perfecto"};

char *ModoSubjuntivoSimple[]={"Presente", "Futuro", "Pret�rito imperfecto"};
							  
char *ModoSubjuntivoCompuesto[]={"Pret�tiro pluscuamperfecto", "Futuro perfecto", "Pret�rito perfecto"};							                       

char *ModoExtras[]={"Imperativo","Gerundio","Participio"};
                             
enBasePronombres DesidenciaSimpleAR = {"o        ","as       ","a        ","amos     ","an       ","an       ",
                                       "ar�      ","ar�s     ","ar�      ","aremos   ","ar�n     ","ar�n     ",
                                       "aba      ","abas     ","aba      ","�bamos   ","aban     ","aban     ",
									   "ar�a     ","ar�as    ","ar�a     ","ar�amos  ","ar�an    ","ar�an    ",
									   "�        ","aste     ","�        ","amos     ","aron     ","aron     ",
									   "e        ","es       ","e        ","emos     ","en       ","en       ",
									   "are      ","ares     ","are      ","aremos   ","aren     ","ren      ",
									   "ara      ","aras     ","ara      ","aramos   ","aran     ","aran     ",
									   "         ","a        ","e        ","emos     ","en       ","en       "};
									                                                                              
enBasePronombres DesidenciaSimpleER = {"o        ","es       ","e        ","emos     ","en       ","en       ",
									   "er�      ","er�s     ","er�      ","eremos   ","er�n     ","er�n     ",
									   "�a       ","�as      ","�a       ","�amos    ","�an      ","�an      ",
									   "er�a     ","er�as    ","er�a     ","er�amos  ","er�an    ","er�an    ",
									   "�        ","iste     ","i�       ","imos     ","ieron    ","ieron    ",
									   "a        ","as       ","a        ","amos     ","an       ","an       ",
									   "iere     ","ieres    ","iere     ","i�remos  ","ieren    ","ieren    ",
									   "iera     ","ieras    ","iera     ","i�ramos  ","ieran    ","ieran    ",
									   "         ","e        ","a        ","amos     ","an       ","an       "}; 

enBasePronombres DesidenciaSimpleIR = {"o        ","es       ","e        ","emos     ","en       ","en       ",
                                       "ir�      ","ir�s     ","ir�      ","iremos   ","ir�n     ","ir�n     ",
									   "�a       ","�as      ","�a       ","�amos    ","�an      ","�an      ",
									   "ir�a     ","ir�as    ","ir�a     ","ir�amos  ","ir�an    ","ir�an    ",
									   "�        ","iste     ","i�       ","imos     ","ieron    ","ieron    ",
									   "a        ","as       ","a        ","amos     ","an       ","an       ",
									   "iere     ","ieres    ","iere     ","i�remos  ","ieren    ","ieren    ",
									   "iera     ","ieras    ","iera     ","i�ramos  ","ieran    ","ieran    ",
									   "         ","e        ","a        ","amos     ","an       ","an       "}; 	
									   
enBasePronombres ConjugacionIHaber  = {"he        ","has       ","ha        ","hemos     ","han       ","han       ",
									   "hube      ","hubiste   ","hubo      ","hubimos   ","hubieron  ","hubieron  ",
								       "habr�     ","habr�s    ","habr�     ","habremos  ","habr�n    ","habr�n    ",
								       "hab�a     ","hab�as    ","hab�a     ","hab�amos  ","hab�an    ","hab�an    ",
									   "habr�a    ","habr�as   ","habr�a    ","habr�amos ","habr�an   ","habr�an   "}; 									  

enBasePronombres ConjugacionSHaber  = {"hubiera    ","hubieras   ","hubiera    ","hubi�ramos ","hubieran   ","hubieran   ",
									   "hubiere    ","hubieres   ","hubiere    ","hubi�remos ","hubieren   ","hubieren   ",
								       "haya       ","hayas      ","haya       ","hayamos    ","hayan      ","hayan      "};
	      								  									   									  								   
enBasePronombres Pronombres = {"yo", "t�", "�l", "nosotros", "ustedes", "ellos"};

enBasePronombres DesidenciaSimpleMover = {"uevo      ","ueves     ","ueve      ","ovemos    ","ueven     ","ueven     ",
									      "over�     ","over�s    ","over�     ","overemos  ","over�n    ","over�n    ",
									      "ov�a      ","ov�as     ","ov�a      ","ov�amos   ","ov�an     ","ov�an     ",
									      "over�a    ","over�as   ","over�a    ","over�amos ","over�an   ","over�an   ",
									      "ov�       ","oviste    ","ovi�      ","ovimos    ","ovieron   ","ovieron   ",
									      "ueva      ","uevas     ","ueva      ","ovamos    ","uevan     ","uevan     ",
									      "oviere    ","ovieres   ","oviere    ","ovi�remos ","ovieren   ","ovieren   ",
									      "oviera    ","ovieras   ","oviera    ","ovi�ramos ","ovieran   ","ovieran   ",
									      "          ","ueve      ","ueva      ","ovamos    ","uevan     ","uevan     "};
										  
enBasePronombres DesidenciaSimplePoder = {"uedo      ","uedes     ","uede      ","odemos    ","ueden     ","ueden     ",
									      "odr�      ","odr�s     ","odr�      ","odremos   ","odr�n     ","odr�n     ",
									      "od�a      ","od�as     ","od�a      ","od�amos   ","od�an     ","od�an     ",
									      "odr�a     ","odr�as    ","odr�a     ","odr�amos  ","odr�an    ","odr�an    ",
									      "ude       ","udiste    ","udo       ","udimos    ","udieron   ","udieron   ",
									      "ueda      ","uedas     ","ueda      ","odamos    ","uedan     ","uedan     ",
									      "udiere    ","udieres   ","udiere    ","udi�remos ","udieren   ","udieren   ",
									      "udiera    ","udieras   ","udiera    ","udi�ramos ","udieran   ","udieran   ",
									      "          ","uede      ","ueda      ","odamos    ","uedan     ","uedan     "};
										  
enBasePronombres DesidenciaSimpleSentir = {"iento      ","ientes     ","iente      ","entimos    ","ienten     ","ienten     ",
									       "entir�     ","entir�s    ","entir�     ","entiremos  ","entir�n    ","entir�n    ",
									       "ent�a      ","ent�as     ","ent�a      ","ent�amos   ","ent�an     ","ent�an     ",
									       "entir�a    ","entir�as   ","entir�a    ","entir�amos ","entir�an   ","entir�an   ",
									       "ent�       ","entiste    ","inti�      ","entimos    ","intieron   ","intieron   ",
									       "ienta      ","ientas     ","ienta      ","intamos    ","ientan     ","ientan     ",
									       "intiere    ","intieres   ","intiere    ","inti�remos ","intieren   ","intieren   ",
									       "intiera    ","intieras   ","intiera    ","inti�ramos ","intieran   ","intieran   ",
									       "           ","iente      ","ienta      ","intamos    ","ientan     ","ientan     "};										                                                                                 

enBasePronombres DesidenciaSimpleErguir = {"irgo        ","irgues      ","irgue       ","erguimos    ","irguen      ","irguen      ",
									       "erguir�     ","erguir�s    ","erguir�     ","erguiremos  ","erguir�n    ","erguir�n    ",
									       "ergu�a      ","ergu�as     ","ergu�a      ","ergu�amos   ","ergu�an     ","ergu�an     ",
									       "erguir�a    ","erguir�as   ","erguir�a    ","erguir�amos ","erguir�an   ","erguir�an   ",
									       "ergu�       ","erguiste    ","irgui�      ","erguimos    ","irguieron   ","irguieron   ",
									       "irga        ","irgas       ","irga        ","irgamos     ","irgan       ","irgan       ",
									       "irguiere    ","irguieres   ","irguiere    ","irgui�remos ","irguieren   ","irguieren   ",
									       "irguiera    ","irguieras   ","irguiera    ","irgui�ramos ","irguieran   ","irguieran   ",
									       "            ","irgue       ","irga        ","irgamos     ","irgan       ","irgan       "};

enBasePronombres DesidenciaSimpleDormir = {"uermo      ","uermes     ","uerme      ","ormimos    ","uermen     ","uermen     ",
									       "ormir�     ","ormir�s    ","ormir�     ","ormiremos  ","ormir�n    ","ormir�n    ",
									       "orm�a      ","oirm�as    ","orm�a      ","orm�amos   ","orm�an     ","orm�an     ",
									       "ormir�a    ","ormirias   ","ormir�a    ","ormir�amos ","ormir�an   ","ormir�an   ",
									       "orm�       ","ormiste    ","urmi�      ","ormimos    ","urmieron   ","urmieron   ", 
									       "uerma      ","uermas     ","uerma      ","urmamos    ","uerman     ","uerman     ",
									       "urmiere    ","urmieres   ","urmiere    ","urmi�remos ","urmieren   ","urmieren   ",
									       "urmiera    ","urmieras   ","urmiera    ","urmi�ramos ","urmieran   ","urmieran   ",
									       "           ","uerme      ","uerma      ","urmamos    ","uerman     ","uerman     "};

enBasePronombres DesidenciaSimpleAdquirir = {"ero       ","eres      ","ere       ","rimos     ","eren      ","eren      ",
									         "rir�      ","rir�s     ","rir�      ","riremos   ","rir�n     ","rir�n     ",
									         "r�a       ","r�as      ","r�a       ","r�amos    ","r�an      ","r�an      ",
									         "rir�a     ","rir�as    ","rir�a     ","rir�amos  ","rir�an    ","rir�an    ",
									         "r�        ","riste     ","ri�       ","rimos     ","rieron    ","rieron    ",
									         "era       ","eras      ","era       ","ramos     ","eran      ","eran      ",
									         "riere     ","rieres    ","riere     ","iri�remos ","rieren    ","rieren    ",
									         "riera     ","rieras    ","riera     ","ri�ramos  ","rieran    ","rieran    ",
									         "          ","ere       ","era       ","ramos     ","eran      ","eran      "};

enBasePronombres DesidenciaSimplePodrir = {"udro       ","udres      ","udre       ","udrimos    ","udren      ","udren      ",
									       "udrir�     ","idrir�s    ","udrir�     ","udriremos  ","udrir�n    ","udrir�n    ",
									       "udr�a      ","udr�as     ","udr�a      ","udr�amos   ","udri�n     ","udr�an     ",
									       "udrir�a    ","udrir�as   ","udrir�a    ","udrir�amos ","udrir�an   ","udrir�an   ",
									       "udr�       ","udriste    ","udri�      ","udrimos    ","udrieron   ","udrieron   ",//odrir udriendo odrido//
									       "udra       ","udras      ","udra       ","udramos    ","udran      ","udran      ",
									       "udriere    ","udrieres   ","udriere    ","udri�remos ","udrieren   ","udrieren   ",
									       "udriera    ","udrieras   ","udriera    ","udri�ramos ","udrieran   ","udrieran   ",
									       "           ","udre       ","udra       ","udramos    ","udrid      ","udran      "};
										   									       
int conjugacionRegularAR(FILE *archivo, char raizVerboAR[]);
int conjugacionRegularER(FILE *archivo, char raizVerboER[]);  
int conjugacionRegularIR(FILE *archivo, char raizVerboIR[]);
int conjugacionMOVER(FILE *archivo, char raizVerboIR[]);
int conjugacionPODER(FILE *archivo, char raizVerboIR[]);  
int conjugacionSENTIR(FILE *archivo, char raizVerboIR[]);  
int conjugacionERGUIR(FILE *archivo, char raizVerboIR[]);
int conjugacionDORMIR(FILE *archivo, char raizVerboIR[]);
int conjugacionADQUIRIR(FILE *archivo, char raizVerboIR[]);
int conjugacionPODRIR(FILE *archivo, char raizVerboIR[]);                                                                           

int main(int argc, char *argv[]){                               
  FILE *miArchivo;              
  char buffer[128],t;             
  int lbuffer;                  

  miArchivo = fopen("misVerbos.txt", "a");

  if (miArchivo == NULL){
    fprintf(stderr, "No se pudo abrir el archivo \"misVerbos.txt\"\n");
    return 0;                                                          
  }                                                                    
  printf("Este programa conjuga verbos regulares o de los siguientes modelos\n\n");
  printf(" Sentir      \tAdquirir  \tMover   \tDormir   \tPoder      \tPodir   \tErguir\n"
         " mentir      \treadquirir\tconmover\tadormir  \tcontrapoder\trepodrir\n"
		 " disentir    \tinquirir  \tamover  \tmaldormir\n"
		 " arrepentirse\tperquirir \tpromover\n"
		 " resentirse  \tpesquirir \tremover\n"
		 " desmentir   \tcoadquirir\n"
		 " consentir   \n" 
		 " presentir   \n" 
		 " asentir     \n" 
		 " repentirse  \n" 
		 " desconsentir\n"); 
  printf("\nEscribir el verbo en infinitivo a conjugar:");
  scanf("%s", buffer);
  lbuffer = strlen(buffer);
 
  if(strcmp(buffer+strlen(buffer)-4,"over")==0){
  	
  	if(strcmp(buffer,"mover")==0) fprintf(miArchivo,"\nMover: Hacer que un cuerpo o una parte de �l cambie de lugar f�sico.\n");
  	if(strcmp(buffer,"conmover")==0) fprintf(miArchivo,"\nConmover: Perturbar, inquietar, alterar, mover fuertemente o con eficacia a alguien o algo.\n");
	if(strcmp(buffer,"amover")==0) fprintf(miArchivo,"\nAmover: Anular, derogar, revocar.\n");
	if(strcmp(buffer,"promover")==0) fprintf(miArchivo,"\nPromover: Impulsar el desarrollo o la realizaci�n de algo.\n");
	if(strcmp(buffer,"remover")==0) fprintf(miArchivo,"\nRemover: Pasar o mudar algo de un lugar a otro.\n"); 
  	buffer[lbuffer-4]= '\0';
  	printf("Por conjugar verbo\n");
    conjugacionMOVER(miArchivo, buffer);
    printf("Verbo Conjugado\n");
    fclose(miArchivo);
    printf("FIN\n");
    return 0;
  }
  
  if(strcmp(buffer+strlen(buffer)-4,"oder")==0){
  	if(strcmp(buffer,"poder")==0) fprintf(miArchivo,"\nPoder: Tener la capacidad o facultad de hacer determinada cosa.\n");
  	if(strcmp(buffer,"contrapoder")==0) fprintf(miArchivo,"\nContrapoder: Poder que intenta contrarrestar al poder establecido.\n"); 
  	buffer[lbuffer-4]= '\0';
  	printf("Por conjugar verbo\n");
    conjugacionPODER(miArchivo, buffer);
    printf("Verbo Conjugado\n");
    fclose(miArchivo);
    printf("FIN\n");
    return 0;
  }
  
  if(strcmp(buffer+strlen(buffer)-5,"entir")==0){
  	
  	if(strcmp(buffer,"sentir")==0) fprintf(miArchivo,"\nSentir: Percibir una sensaci�n proveniente de un est�mulo externo o del propio cuerpo.\n");
  	if(strcmp(buffer,"mentir")==0) fprintf(miArchivo,"\nMentir: Decir o manifestar lo contrario de lo que se sabe, cree o piensa.\n");
	if(strcmp(buffer,"disentir")==0) fprintf(miArchivo,"\nDisentir: No ajustarse al sentir o parecer de alguien.\n");
	if(strcmp(buffer,"desmentir")==0) fprintf(miArchivo,"\nDesmentir: Sostener o demostrar que un dicho o hecho es falso.\n");
	if(strcmp(buffer,"consentir")==0) fprintf(miArchivo,"\nConsentir: Permitir algo o condescender en que se haga.\n");
	if(strcmp(buffer,"presentir")==0) fprintf(miArchivo,"\nPresentir: Intuir o tener la impresi�n de que algo va a suceder.\n");
	if(strcmp(buffer,"asentir")==0) fprintf(miArchivo,"\nAsentir: Admitir como cierto o conveniente lo que otra persona ha afirmado o propuesto antes.\n");
	if(strcmp(buffer,"desconsentir")==0) fprintf(miArchivo,"\nDesconsentir: No consentir, dejar de consentir.\n");
  	buffer[lbuffer-5]= '\0';
  	printf("Por conjugar verbo\n");
    conjugacionSENTIR(miArchivo, buffer);
    printf("Verbo Conjugado\n");
    fclose(miArchivo);
    printf("FIN\n");
    return 0;
  }
  
  if(strcmp(buffer+strlen(buffer)-7,"entirse")==0){
    if(strcmp(buffer,"arrepentirse")==0) fprintf(miArchivo,"\nArrepentirse: Sentir pesar por haber hecho o haber dejado de hacer algo.\n");
    if(strcmp(buffer,"resentirse")==0) fprintf(miArchivo,"\nResentirse: Tener sentimiento, pesar o enojo por algo.\n");
	if(strcmp(buffer,"repentirse")==0) fprintf(miArchivo,"\nRepentirse: Arrepentirse.\n");  	 
  	buffer[lbuffer-7]= '\0';
  	printf("Por conjugar verbo\n");
    conjugacionSENTIR(miArchivo, buffer);
    printf("Verbo Conjugado\n");
    fclose(miArchivo);
    printf("FIN\n");
    return 0;
  }
  
  if(strcmp(buffer,"erguir")==0){
  	
  	fprintf(miArchivo,"\nErguir: Poner una cosa en posici�n vertical.\n");
  	 
  	buffer[lbuffer-6]= '\0';
  	printf("Por conjugar verbo\n");
    conjugacionERGUIR(miArchivo, buffer);
    printf("Verbo Conjugado\n");
    fclose(miArchivo);
    printf("FIN\n");
    return 0;
  }
  
  if(strcmp(buffer+strlen(buffer)-5,"ormir")==0){
  	
  	if(strcmp(buffer,"dormir")==0) fprintf(miArchivo,"\nDormir: Reposar, con los ojos cerrados, en un estado inconsciente en el que se produce la suspensi�n de las funciones sensoriales y de los movimientos voluntarios.\n");
  	if(strcmp(buffer,"adormir")==0) fprintf(miArchivo,"\nAdormir: Adormecer.\n");
	if(strcmp(buffer,"maldormir")==0) fprintf(miArchivo,"\nMaldormir: To sleep badly. (No hay definici�n en espa�ol de la RAE)\n"); 
  	buffer[lbuffer-5]= '\0';
  	printf("Por conjugar verbo\n");
    conjugacionDORMIR(miArchivo, buffer);
    printf("Verbo Conjugado\n");
    fclose(miArchivo);
    printf("FIN\n");
    return 0;
  }
  
  if(strcmp(buffer+strlen(buffer)-3,"rir")==0 && strcmp(buffer+strlen(buffer)-5,"odrir")!=0){
  	
  	if(strcmp(buffer,"adquirir")==0) fprintf(miArchivo,"\nAdquirir: Llegar a tener o conseguir una cualidad, un conocimiento, un h�bito o una habilidad, de forma natural o tras un proceso.\n");
  	if(strcmp(buffer,"readquirir")==0) fprintf(miArchivo,"\nReadquirir: Volver a adquirir.\n");
	if(strcmp(buffer,"inquirir")==0) fprintf(miArchivo,"\nInquirir: Indagar, averiguar o examinar cuidadosamente algo.\n");
	if(strcmp(buffer,"perquirir")==0) fprintf(miArchivo,"\nPerquirir: Investigar, buscar algo con cuidado y diligencia.\n");
	if(strcmp(buffer,"perquirir")==0) fprintf(miArchivo,"\nPesquirir: Perquirir.\n");
	if(strcmp(buffer,"coadquirir")==0) fprintf(miArchivo,"\nCoadquirir: Adquirir dos o m�s personas una cosa.\n");   
  	buffer[lbuffer-3]= '\0';
  	printf("Por conjugar verbo\n");
    conjugacionADQUIRIR(miArchivo, buffer);
    printf("Verbo Conjugado\n");
    fclose(miArchivo);
    printf("FIN\n");
    return 0;
  }
  
  if(strcmp(buffer+strlen(buffer)-5,"odrir")==0){
  	
  	if(strcmp(buffer,"podrir")==0) fprintf(miArchivo,"\nPodrir: Descomponer o corromper una materia o una sustancia por la acci�n de diversos factores y de determinados microorganismos.\n");
  	if(strcmp(buffer,"repodrir")==0) fprintf(miArchivo,"\nRepodrir: Pudrir mucho.\n"); 
  	buffer[lbuffer-5]= '\0';
  	printf("Por conjugar verbo\n");
    conjugacionPODRIR(miArchivo, buffer);
    printf("Verbo Conjugado\n");
    fclose(miArchivo);
    printf("FIN\n");
    return 0;
  }
  
  t=buffer[lbuffer-2];                                   
  buffer[lbuffer-2]= '\0';
  switch(t){
  	case 'a': printf("Por conjugar verbo\n");
              conjugacionRegularAR(miArchivo, buffer);
              printf("Verbo Conjugado\n");
              break;
    case 'e': printf("Por conjugar verbo\n");
              conjugacionRegularER(miArchivo, buffer);
              printf("Verbo Conjugado\n");
              break;
  	case 'i': printf("Por conjugar verbo\n");
              conjugacionRegularIR(miArchivo, buffer);
              printf("Verbo Conjugado\n");
              break;			
  }

  fclose(miArchivo);
  printf("FIN\n");

  return 0;
}         

int conjugacionRegularAR(FILE *archivo, char raizVerboAR[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=6,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerboAR)+2;
  
  fprintf(archivo,"\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerboAR, DesidenciaSimpleAR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                         
   
   fprintf(archivo,"\n");
   ldesidencia=10;
   for(tiempo=0; tiempo<=4; tiempo++){
   	  titulo=strlen(ModoIndicativoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+3)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoIndicativoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*TotalTiemposCompuestos; tiempo+=6){
   		fprintf(archivo, "%8s %s%sado   ", Pronombres[persona], ConjugacionIHaber[tiempo], raizVerboAR);
	   }
	 fprintf(archivo,"\n");  
   }
   
   fprintf(archivo,"\n");
   ldesidencia=6;
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");   
   }
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoExtras[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoExtras[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
	
   for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<6*TotalPronombres;tiempo+=6)
			switch(tiempo){
		    case 18: sprintf(formato, "%%%ds %%%ds",8,strlen(raizVerboAR)+10);
			         fprintf(archivo, formato, Pronombres[persona]," "," ");
		             break;
		    case 24: if(strlen(raizVerboAR)%2==0) fprintf(archivo,"   %sando",raizVerboAR);
		             else{ sprintf(formato, "%%%ds%%sando", strlen(raizVerboAR));
	                       fprintf(archivo,formato," ",raizVerboAR);	} 
		             break;
		    case 30: fprintf(archivo,"%11s %sado "," ",raizVerboAR);
					 break;
		    default: if(tiempo<25) fprintf(archivo, "%8s %s%s", Pronombres[persona], raizVerboAR, DesidenciaSimpleAR[tiempo+30]); 
		             break;   
            }
            fprintf(archivo, "\n");
   }
   
   fprintf(archivo,"\n");
   ldesidencia=11;
   for(tiempo=0; tiempo<=2; tiempo++){
   	  titulo=strlen(ModoSubjuntivoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+3)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoSubjuntivoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*3; tiempo+=6){
   		fprintf(archivo, "%8s %s%sado   ", Pronombres[persona], ConjugacionSHaber[tiempo], raizVerboAR);
	   }
	 fprintf(archivo,"\n");  
   }
   
   return 0;  
}            

int conjugacionRegularER(FILE *archivo, char raizVerboER[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=6,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerboER)+2;
  
  fprintf(archivo,"\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerboER, DesidenciaSimpleER[tiempo]); 
        fprintf(archivo, "\n");
   }                                                         
   
   fprintf(archivo,"\n");
   ldesidencia=10;
   for(tiempo=0; tiempo<=4; tiempo++){
   	  titulo=strlen(ModoIndicativoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+3)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoIndicativoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*TotalTiemposCompuestos; tiempo+=6){
   		fprintf(archivo, "%8s %s%sido   ", Pronombres[persona], ConjugacionIHaber[tiempo], raizVerboER);
	   }
	 fprintf(archivo,"\n");  
   }
   
   fprintf(archivo,"\n");
   ldesidencia=6;
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");   
   }
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoExtras[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoExtras[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
	
   for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<6*TotalPronombres;tiempo+=6)
			switch(tiempo){
		    case 18: sprintf(formato, "%%%ds %%%ds",8,strlen(raizVerboER)+10);
			         fprintf(archivo, formato, Pronombres[persona]," "," ");
		             break;
		    case 24: if(strlen(raizVerboER)%2==0) fprintf(archivo,"   %siendo",raizVerboER);
		             else{ sprintf(formato, "%%%ds%%siendo", strlen(raizVerboER)+3);
	                       fprintf(archivo,formato," ",raizVerboER);	} 
		             break;
		    case 30: fprintf(archivo,"%11s %sido "," ",raizVerboER);
					 break;
		    default: if(tiempo<25) fprintf(archivo, "%8s %s%s", Pronombres[persona], raizVerboER, DesidenciaSimpleER[tiempo+30]); 
		             break;   
            }
            fprintf(archivo, "\n");
   }
   
   fprintf(archivo,"\n");
   ldesidencia=11;
   for(tiempo=0; tiempo<=2; tiempo++){
   	  titulo=strlen(ModoSubjuntivoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+3)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoSubjuntivoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*3; tiempo+=6){
   		fprintf(archivo, "%8s %s%sido   ", Pronombres[persona], ConjugacionSHaber[tiempo], raizVerboER);
	   }
	 fprintf(archivo,"\n");  
   }
   
   return 0;  
}

int conjugacionRegularIR(FILE *archivo, char raizVerboIR[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=6,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerboIR)+2;
  
  fprintf(archivo,"\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerboIR, DesidenciaSimpleIR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                         
   
   fprintf(archivo,"\n");
   ldesidencia=10;
   for(tiempo=0; tiempo<=4; tiempo++){
   	  titulo=strlen(ModoIndicativoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+3)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoIndicativoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*TotalTiemposCompuestos; tiempo+=6){
   		fprintf(archivo, "%8s %s%sido   ", Pronombres[persona], ConjugacionIHaber[tiempo], raizVerboIR);
	   }
	 fprintf(archivo,"\n");  
   }
   
   fprintf(archivo,"\n");
   ldesidencia=6;
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");   
   }
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoExtras[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoExtras[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
	
   for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<6*TotalPronombres;tiempo+=6)
			switch(tiempo){
		    case 18: sprintf(formato, "%%%ds %%%ds",8,strlen(raizVerboIR)+10);
			         fprintf(archivo, formato, Pronombres[persona]," "," ");
		             break;
		    case 24: if(strlen(raizVerboIR)%2==0) fprintf(archivo,"  %siendo",raizVerboIR);
		             else{ sprintf(formato, "%%%ds%%siendo", strlen(raizVerboIR)+2);
	                       fprintf(archivo,formato," ",raizVerboIR);	} 
		             break;
		    case 30: fprintf(archivo,"%11s %sido "," ",raizVerboIR);
					 break;
		    default: if(tiempo<25) fprintf(archivo, "%8s %s%s", Pronombres[persona], raizVerboIR, DesidenciaSimpleIR[tiempo+30]); 
		             break;   
            }
            fprintf(archivo, "\n");
   }
   
   fprintf(archivo,"\n");
   ldesidencia=11;
   for(tiempo=0; tiempo<=2; tiempo++){
   	  titulo=strlen(ModoSubjuntivoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+3)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoSubjuntivoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*3; tiempo+=6){
   		fprintf(archivo, "%8s %s%sido   ", Pronombres[persona], ConjugacionSHaber[tiempo], raizVerboIR);
	   }
	 fprintf(archivo,"\n");  
   }
   
   return 0;  
}

int conjugacionMOVER(FILE *archivo, char raizVerboIR[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=6,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerboIR)+2;
  
  fprintf(archivo,"\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerboIR, DesidenciaSimpleMover[tiempo]); 
        fprintf(archivo, "\n");
   }                                                         
   
   fprintf(archivo,"\n");
   ldesidencia=10;
   for(tiempo=0; tiempo<=4; tiempo++){
   	  titulo=strlen(ModoIndicativoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+5)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoIndicativoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*TotalTiemposCompuestos; tiempo+=6){
   		fprintf(archivo, "%8s %s%sovido   ", Pronombres[persona], ConjugacionIHaber[tiempo], raizVerboIR);
	   }
	 fprintf(archivo,"\n");  
   }
   
   fprintf(archivo,"\n");
   ldesidencia=7;
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");   
   }
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoExtras[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+1, centrado+1);
	    fprintf(archivo, formato, " ", ModoExtras[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
	
   for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<6*TotalPronombres;tiempo+=6)
			switch(tiempo){
		    case 18: sprintf(formato, "%%%ds %%%ds",8,strlen(raizVerboIR)+10);
			         fprintf(archivo, formato, Pronombres[persona]," "," ");
		             break;
		    case 24: if(strlen(raizVerboIR)%2==0) fprintf(archivo,"        %soviendo",raizVerboIR);
		             else{ sprintf(formato, "%%%ds%%soviendo", strlen(raizVerboIR)+3);
	                       fprintf(archivo,formato," ",raizVerboIR);	} 
		             break;
		    case 30: fprintf(archivo,"%12s %sovido "," ",raizVerboIR);
					 break;
		    default: if(tiempo<25) fprintf(archivo, "%8s %s%s", Pronombres[persona], raizVerboIR, DesidenciaSimpleMover[tiempo+30]); 
		             break;   
            }
            fprintf(archivo, "\n");
   }
   
   fprintf(archivo,"\n");
   ldesidencia=11;
   for(tiempo=0; tiempo<=2; tiempo++){
   	  titulo=strlen(ModoSubjuntivoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+5)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoSubjuntivoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*3; tiempo+=6){
   		fprintf(archivo, "%8s %s%sovido   ", Pronombres[persona], ConjugacionSHaber[tiempo], raizVerboIR);
	   }
	 fprintf(archivo,"\n");  
   }
   
   return 0;  
}

int conjugacionPODER(FILE *archivo, char raizVerboIR[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=6,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerboIR)+2;
  
  fprintf(archivo,"\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerboIR, DesidenciaSimplePoder[tiempo]); 
        fprintf(archivo, "\n");
   }                                                         
   
   fprintf(archivo,"\n");
   ldesidencia=10;
   for(tiempo=0; tiempo<=4; tiempo++){
   	  titulo=strlen(ModoIndicativoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+5)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoIndicativoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*TotalTiemposCompuestos; tiempo+=6){
   		fprintf(archivo, "%8s %s%sodido   ", Pronombres[persona], ConjugacionIHaber[tiempo], raizVerboIR);
	   }
	 fprintf(archivo,"\n");  
   }
   
   fprintf(archivo,"\n");
   ldesidencia=6;
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");   
   }
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoExtras[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoExtras[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
	
   for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<6*TotalPronombres;tiempo+=6)
			switch(tiempo){
		    case 18: sprintf(formato, "%%%ds %%%ds",8,strlen(raizVerboIR)+10);
			         fprintf(archivo, formato, Pronombres[persona]," "," ");
		             break;
		    case 24: fprintf(archivo,"    %sudiendo",raizVerboIR);
		             break;
		    case 30: fprintf(archivo,"%9s %sodido "," ",raizVerboIR);
					 break;
		    default: if(tiempo<25) fprintf(archivo, "%8s %s%s", Pronombres[persona], raizVerboIR, DesidenciaSimplePoder[tiempo+30]); 
		             break;   
            }
            fprintf(archivo, "\n");
   }
   
   fprintf(archivo,"\n");
   ldesidencia=11;
   for(tiempo=0; tiempo<=2; tiempo++){
   	  titulo=strlen(ModoSubjuntivoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+5)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoSubjuntivoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*3; tiempo+=6){
   		fprintf(archivo, "%8s %s%sodido   ", Pronombres[persona], ConjugacionSHaber[tiempo], raizVerboIR);
	   }
	 fprintf(archivo,"\n");  
   }
   
   return 0;  
}

int conjugacionSENTIR(FILE *archivo, char raizVerboIR[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=8,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerboIR)+2;
  
  fprintf(archivo,"\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerboIR, DesidenciaSimpleSentir[tiempo]); 
        fprintf(archivo, "\n");
   }                                                         
   
   fprintf(archivo,"\n");
   ldesidencia=10;
   for(tiempo=0; tiempo<=4; tiempo++){
   	  titulo=strlen(ModoIndicativoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+5)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoIndicativoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*TotalTiemposCompuestos; tiempo+=6){
   		fprintf(archivo, "%8s %s%sentido   ", Pronombres[persona], ConjugacionIHaber[tiempo], raizVerboIR);
	   }
	 fprintf(archivo,"\n");  
   }
   
   fprintf(archivo,"\n");
   ldesidencia=7;
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+1, centrado+1);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");   
   }
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoExtras[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+1, centrado+1);
	    fprintf(archivo, formato, " ", ModoExtras[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
	
   for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<6*TotalPronombres;tiempo+=6)
			switch(tiempo){
		    case 18: sprintf(formato, "%%%ds %%%ds",8,strlen(raizVerboIR)+11);
			         fprintf(archivo, formato, Pronombres[persona]," "," ");
		             break;
		    case 24: fprintf(archivo,"     %sintiendo",raizVerboIR);
		             break;
		    case 30: fprintf(archivo,"%10s %sentido "," ",raizVerboIR);
					 break;
		    default: if(tiempo<25) fprintf(archivo, "%8s %s%s", Pronombres[persona], raizVerboIR, DesidenciaSimpleSentir[tiempo+30]); 
		             break;   
            }
            fprintf(archivo, "\n");
   }
   
   fprintf(archivo,"\n");
   ldesidencia=11;
   for(tiempo=0; tiempo<=2; tiempo++){
   	  titulo=strlen(ModoSubjuntivoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+5)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoSubjuntivoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*3; tiempo+=6){
   		fprintf(archivo, "%8s %s%sentido   ", Pronombres[persona], ConjugacionSHaber[tiempo], raizVerboIR);
	   }
	 fprintf(archivo,"\n");  
   }
   
   return 0;  
}

int conjugacionERGUIR(FILE *archivo, char raizVerboIR[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=11,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerboIR)+2;
  
  fprintf(archivo,"\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s  %s", Pronombres[persona], DesidenciaSimpleErguir[tiempo]); 
        fprintf(archivo, "\n");
   }                                                         
   
   fprintf(archivo,"\n");
   ldesidencia=13;
   for(tiempo=0; tiempo<=4; tiempo++){
   	  titulo=strlen(ModoIndicativoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+5)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoIndicativoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*TotalTiemposCompuestos; tiempo+=6){
   		fprintf(archivo, "%8s %serguido   ", Pronombres[persona], ConjugacionIHaber[tiempo]);
	   }
	 fprintf(archivo,"\n");  
   }
   
   fprintf(archivo,"\n");
   ldesidencia=10;
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+1, centrado+1);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");   
   }
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoExtras[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+1, centrado+1);
	    fprintf(archivo, formato, " ", ModoExtras[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
	
   for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<6*TotalPronombres;tiempo+=6)
			switch(tiempo){
		    case 18: sprintf(formato, "%%%ds %%%ds",8,strlen(raizVerboIR)+11);
			         fprintf(archivo, formato, Pronombres[persona]," "," ");
		             break;
		    case 24: fprintf(archivo,"        irguiendo");
		             break;
		    case 30: fprintf(archivo,"%12s erguido "," ");
					 break;
		    default: if(tiempo<25) fprintf(archivo, "%8s  %s", Pronombres[persona], DesidenciaSimpleErguir[tiempo+30]); 
		             break;   
            }
            fprintf(archivo, "\n");
   }
   
   fprintf(archivo,"\n");
   ldesidencia=13;
   for(tiempo=0; tiempo<=2; tiempo++){
   	  titulo=strlen(ModoSubjuntivoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+5)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoSubjuntivoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*3; tiempo+=6){
   		fprintf(archivo, "%8s %serguido   ", Pronombres[persona], ConjugacionSHaber[tiempo]);
	   }
	 fprintf(archivo,"\n");  
   }
   
   return 0;  
}

int conjugacionDORMIR(FILE *archivo, char raizVerboIR[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=8,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerboIR)+2;
  
  fprintf(archivo,"\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerboIR, DesidenciaSimpleDormir[tiempo]); 
        fprintf(archivo, "\n");
   }                                                         
   
   fprintf(archivo,"\n");
   ldesidencia=10;
   for(tiempo=0; tiempo<=4; tiempo++){
   	  titulo=strlen(ModoIndicativoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+5)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoIndicativoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*TotalTiemposCompuestos; tiempo+=6){
   		fprintf(archivo, "%8s %s%sormido   ", Pronombres[persona], ConjugacionIHaber[tiempo], raizVerboIR);
	   }
	 fprintf(archivo,"\n");  
   }
   
   fprintf(archivo,"\n");
   ldesidencia=7;
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+1, centrado+1);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");   
   }
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoExtras[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+1, centrado+1);
	    fprintf(archivo, formato, " ", ModoExtras[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
	
   for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<6*TotalPronombres;tiempo+=6)
			switch(tiempo){
		    case 18: sprintf(formato, "%%%ds %%%ds",8,strlen(raizVerboIR)+11);
			         fprintf(archivo, formato, Pronombres[persona]," "," ");
		             break;
		    case 24: fprintf(archivo,"      %surmiendo",raizVerboIR);
		             break;
		    case 30: fprintf(archivo,"%11s %sormido "," ",raizVerboIR);
					 break;
		    default: if(tiempo<25) fprintf(archivo, "%8s %s%s", Pronombres[persona], raizVerboIR, DesidenciaSimpleDormir[tiempo+30]); 
		             break;   
            }
            fprintf(archivo, "\n");
   }
   
   fprintf(archivo,"\n");
   ldesidencia=11;
   for(tiempo=0; tiempo<=2; tiempo++){
   	  titulo=strlen(ModoSubjuntivoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+5)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoSubjuntivoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*3; tiempo+=6){
   		fprintf(archivo, "%8s %s%sormido  ", Pronombres[persona], ConjugacionSHaber[tiempo], raizVerboIR);
	   }
	 fprintf(archivo,"\n");  
   }
   
   return 0;  
}

int conjugacionADQUIRIR(FILE *archivo, char raizVerboIR[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=6,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerboIR)+2;
  
  fprintf(archivo,"\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerboIR, DesidenciaSimpleAdquirir[tiempo]); 
        fprintf(archivo, "\n");
   }                                                         
   
   fprintf(archivo,"\n");
   ldesidencia=10;
   for(tiempo=0; tiempo<=4; tiempo++){
   	  titulo=strlen(ModoIndicativoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+3)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoIndicativoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*TotalTiemposCompuestos; tiempo+=6){
   		fprintf(archivo, "%8s %s%srido   ", Pronombres[persona], ConjugacionIHaber[tiempo], raizVerboIR);
	   }
	 fprintf(archivo,"\n");  
   }
   
   fprintf(archivo,"\n");
   ldesidencia=6;
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");   
   }
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoExtras[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoExtras[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
	
   for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<6*TotalPronombres;tiempo+=6)
			switch(tiempo){
		    case 18: sprintf(formato, "%%%ds %%%ds",8,strlen(raizVerboIR)+10);
			         fprintf(archivo, formato, Pronombres[persona]," "," ");
		             break;
		    case 24: fprintf(archivo,"   %sriendo",raizVerboIR);
		             break;
		    case 30: fprintf(archivo,"%11s %srido "," ",raizVerboIR);
					 break;
		    default: if(tiempo<25) fprintf(archivo, "%8s %s%s", Pronombres[persona], raizVerboIR, DesidenciaSimpleAdquirir[tiempo+30]); 
		             break;   
            }
            fprintf(archivo, "\n");
   }
   
   fprintf(archivo,"\n");
   ldesidencia=11;
   for(tiempo=0; tiempo<=2; tiempo++){
   	  titulo=strlen(ModoSubjuntivoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+3)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoSubjuntivoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*3; tiempo+=6){
   		fprintf(archivo, "%8s %s%srido   ", Pronombres[persona], ConjugacionSHaber[tiempo], raizVerboIR);
	   }
	 fprintf(archivo,"\n");  
   }
   
   return 0;  
}

int conjugacionPODRIR(FILE *archivo, char raizVerboIR[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=8,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerboIR)+2;
  
  fprintf(archivo,"\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+1);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerboIR, DesidenciaSimplePodrir[tiempo]); 
        fprintf(archivo, "\n");
   }                                                         
   
   fprintf(archivo,"\n");
   ldesidencia=10;
   for(tiempo=0; tiempo<=4; tiempo++){
   	  titulo=strlen(ModoIndicativoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+5)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoIndicativoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*TotalTiemposCompuestos; tiempo+=6){
   		fprintf(archivo, "%8s %s%sodrido   ", Pronombres[persona], ConjugacionIHaber[tiempo], raizVerboIR);
	   }
	 fprintf(archivo,"\n");  
   }
   
   fprintf(archivo,"\n");
   ldesidencia=6;
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+1, centrado+1);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");   
   }
   for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoExtras[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+1, centrado+1);
	    fprintf(archivo, formato, " ", ModoExtras[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
	
   for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<6*TotalPronombres;tiempo+=6)
			switch(tiempo){
		    case 18: sprintf(formato, "%%%ds %%%ds",8,strlen(raizVerboIR)+11);
			         fprintf(archivo, formato, Pronombres[persona]," "," ");
		             break;
		    case 24: fprintf(archivo,"    %sudriendo",raizVerboIR);
		             break;
		    case 30: fprintf(archivo,"%10s %sodrido "," ",raizVerboIR);
					 break;
		    default: if(tiempo<25) fprintf(archivo, "%8s %s%s", Pronombres[persona], raizVerboIR, DesidenciaSimplePodrir[tiempo+30]); 
		             break;   
            }
            fprintf(archivo, "\n");
   }
   
   fprintf(archivo,"\n");
   ldesidencia=11;
   for(tiempo=0; tiempo<=2; tiempo++){
   	  titulo=strlen(ModoSubjuntivoCompuesto[tiempo])/2;
   	  centrado=(lverbo+lpronombre+ldesidencia+5)/2;
   	   if(centrado<=titulo) centrado=0;
   	     else centrado-= titulo;
   	  sprintf(formato,"%%%ds%%s%%%ds",centrado,centrado+2);
   	  fprintf(archivo, formato, " ", ModoSubjuntivoCompuesto[tiempo], " ");
   }
   fprintf(archivo,"\n\n");
   for(persona=0;persona<TotalPronombres; persona++){
   	for(tiempo=persona; tiempo<TotalPronombres*3; tiempo+=6){
   		fprintf(archivo, "%8s %s%sodrido  ", Pronombres[persona], ConjugacionSHaber[tiempo], raizVerboIR);
	   }
	 fprintf(archivo,"\n");  
   }
   
   return 0;  
}   
