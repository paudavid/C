/*

********************************************************************
*
* 
* @Proposit: Práctica 2.3 de Programació durant el curs 2021-22
* @Autor: Pau-David Garcia Rodriguez
* @Data de creacio: 20-05-2022
* @Data de l'ultima modificació: 24-05-2022
* 
* *****************************************************************/



#include <stdio.h>
#include <string.h>                                 //llibreries
#include <stdlib.h>

#define MAX_STRING_LENGTH 70                        //el maxim string possible, aplicat per tots.

#include "linkedlist.h"



/*
typedef struct {
    char name[MAX_STRING_LENGTH];
    char login[MAX_STRING_LENGTH];
}Student;*/

typedef struct {
 char name[MAX_STRING_LENGTH];
 int current_capacity;
 LinkedList students;
} Classroom;

typedef struct {
    char name[MAX_STRING_LENGTH];
    int num_classrooms;
    Classroom *classrooms;
} Degree;

typedef struct {
    int num_degrees;
    Degree *elements;
} Degrees;


/****************************************************************************************
*
* 
* @Finalitat: moure la cadena per tal de no deixar espais.
* @Parameters:  in : k = variables auxiliars
* @Retorn: null.
* 
* ********************************************************************************************/
void moverCadena(char input[MAX_STRING_LENGTH], char input_bien[MAX_STRING_LENGTH]){
    int k=0;
    int i;
    
    for (i=1; input[i]!='\0';i++){
        input_bien[k]=input[i];                             //moure la cadena bé
        k++;
    }
    input_bien[k]='\0';
}



/****************************************************************************************
*
* 
* @Finalitat: exteure les dades dels estudiants (stus_X)
* @Parameters:  in : nombre_clase_estudiante, nombre_clase_estudiante_bien, nombre_estudiante, nombre_login = variables donde guardamos localmente la informacion antes de ponerla en la memoria dinamica.
*               in : j = variables auxiliar,
*               in : *g = on guardem el FILE de stus
*               in : **d = punter a punter a memoria a les estructures.
* @Retorn: null.
* 
* ********************************************************************************************/
void extreureDades2(FILE *g, Degrees **d, Student s){
    int i;
    char nombre_clase_estudiante[MAX_STRING_LENGTH];
    char nombre_estudiante[MAX_STRING_LENGTH];
    char nombre_clase_estudiante_bien[MAX_STRING_LENGTH];
    char nombre_login[MAX_STRING_LENGTH];

    fscanf(g, "%s", nombre_estudiante);
    nombre_estudiante[strlen(nombre_estudiante)-1]='\0';                //guardem el nom de l'estudiant
		for (int i=0; i<(*d)->num_degrees; i++){
			for(int j=0; j<(*d)->elements[i].num_classrooms; j++){
				(*d)->elements[i].classrooms[j].students = LINKEDLIST_create();
			}
		}
 	while(!feof(g)){
    
        fgets(nombre_clase_estudiante, MAX_STRING_LENGTH, g);                       //guardem el nom de la clase.
        nombre_clase_estudiante[strlen(nombre_clase_estudiante)-1]='\0';
        
        moverCadena(nombre_clase_estudiante, nombre_clase_estudiante_bien);    //treiem espais.

        fscanf(g, "%s", nombre_login);                          //guardem el login del estudiant 

		strcpy(s.name, nombre_estudiante);
		strcpy(s.login, nombre_login);

    for (i=0; i<(*d)->num_degrees; i++){//per començar a crear la estructura dinamica i saber quan espai necessitem
  
	   if(strcmp((*d)->elements[i].name, nombre_clase_estudiante_bien)==0){  //si el nom esta ben escrit

			LINKEDLIST_add((*d)->elements[i].classrooms[0].students, s);
			(*d)->elements[i].classrooms[0].current_capacity++;		
			s.name[0]='\0';
			s.login[0]='\0';
     	}
             
    }
    fscanf(g, "%s", nombre_estudiante);
    nombre_estudiante[strlen(nombre_estudiante)-1]='\0';

    }

}

/****************************************************************************************
*
* 
* @Finalitat: exteure les dades de les classes (class_1)
* @Parameters:  in : numero_total = numero total de assignaturas
*               in : numerocla = numero de clases por assig.
*               in : nombre_clase, nombre_clase_bien, num_class, capacitat (de cada clase) = variables locales donde guardamos la informacion extraida antes de la memoria dinamia
*               in : i = variable auxiliar
* @Retorn: null.
* 
* ********************************************************************************************/ 
void extreureDades(FILE *f, Degrees **d){
    
    int numero_total;
    int numerocla;
    char nombre_clase[MAX_STRING_LENGTH];
	char nombre_clase_bien[MAX_STRING_LENGTH];
    char num_class[MAX_STRING_LENGTH];
	int i=0;	

    fscanf(f, "%d", &numero_total);                         // guardem el numero total de degrees
	(*d)->num_degrees=numero_total;                         // ho guardem desde ja a Degrees.num_degrees
	(*d)->elements=(Degree *) malloc(sizeof(Degree)*numero_total); //	creem el primer malloc per crear la primera estructura amb el numero de Degrees
	
	fscanf(f, "%d", &numerocla);                          //guardem el numero de clases de la asignatura
	fgets(nombre_clase, MAX_STRING_LENGTH,f);              //guardem el nom de la assignatura
    nombre_clase[strlen(nombre_clase)-1]='\0';

	moverCadena(nombre_clase,nombre_clase_bien);                // treiem espais

    for (i=0; feof(f)==0; i++){
        
        strcpy((*d)->elements[i].name, nombre_clase_bien);          //guardem el nom de la assignatura a la memoria dinamica
        (*d)->elements[i].num_classrooms=numerocla;                 // guardem el numero de clases
        (*d)->elements[i].classrooms=(Classroom *)malloc(sizeof(Classroom)*numerocla);      //fem un malloc per poder guardar de forma dinamica les clases a les assginatures
        
        for (int j=0; j<numerocla; j++){
            fscanf(f, "%s", num_class);                         //bucle per guardar al mateix slot de la assginatura les diferentes clases que hi hagin
            strcpy((*d)->elements[i].classrooms[j].name, num_class);            //guardem el valors llegits        
            (*d)->elements[i].classrooms[j].current_capacity=0;  //a 0 perque de moment no hi haura ningu.
        }
		fscanf(f, "%d", &numerocla);
		fgets(nombre_clase, MAX_STRING_LENGTH,f);               
		nombre_clase[strlen(nombre_clase)-1]='\0';
		moverCadena(nombre_clase, nombre_clase_bien);
    }
        
}

/****************************************************************************************
*
* 
* @Finalitat: comprova si el "degree" existeix
* @Parameters:  in : trobat = on guardem amb 1 si la trobat i amb 0 sino es el cas.
* @Retorn: trobat.
* 
* ********************************************************************************************/ 
int comprovaDegree(Degrees **d, char which_degree[MAX_STRING_LENGTH]){
    int trobat=0;
    int i=0;
    for (i=0; i<(*d)->num_degrees; i++){
        if(strcmp((*d)->elements[i].name, which_degree)==0){                //si trobem el grau a la memoria retornem un 1, sino un 0
           trobat=1;
        }
    }
    return trobat;
}


/****************************************************************************************
*
* 
* @Finalitat: funcio per mostrar la informacio d'un grau concret a la memoria dinamica.
* @Parameters:  in : **d = estructura dinamica.
*               in : degre_to_show = grau que volem la informacio
*               in : brosa = cache.
*               int degree_trobat = si em trobat el grau (1), sino es el cas (0)
* @Retorn: trobat.
* 
* ********************************************************************************************/
void degreToShow (Degrees **d, Student s){
    char degre_to_show[MAX_STRING_LENGTH];
    char brosa[MAX_STRING_LENGTH];
    int degree_trobat=0;
    int i=0;
    
    fgets(brosa, MAX_STRING_LENGTH, stdin);             //tenia un problema de espais, i aixo m'ho soluciona.

    printf("\nDegree to show? ");
    fgets(degre_to_show, MAX_STRING_LENGTH, stdin);             //el grau que volem buscar
    degre_to_show[strlen(degre_to_show)-1]='\0';
    
    degree_trobat = comprovaDegree(d, degre_to_show);           //comprovem que existeix.
    printf("\n");

    
    if(degree_trobat!=1){
        printf("ERROR: Can't find degree\n");               //error sino el trobem
    }else{

        for (i=0; i<(*d)->num_degrees; i++){
            if(strcmp((*d)->elements[i].name, degre_to_show)==0){
			
                for(int j=0;j<(*d)->elements[i].num_classrooms; j++){
					LINKEDLIST_goToHead((*d)->elements[i].classrooms[j].students);
				   if ((*d)->elements[i].classrooms[j].current_capacity){
    				   while(!LINKEDLIST_isAtEnd((*d)->elements[i].classrooms[j].students)){
    						s = LINKEDLIST_get((*d)->elements[i].classrooms[j].students);
    
    						printf("%s (%s): %s\n",s.name, s.login, (*d)->elements[i].classrooms[j].name);
    
    						LINKEDLIST_next((*d)->elements[i].classrooms[j].students);
                        }
					}
                }   
            }
        }
    }
}

/****************************************************************************************
*
* 
* @Finalitat: comprova si el login existeix a la estructura dinamica.
* @Parameters:  in : **d = estructura dinamica
*               in : which_degree = cadena de caracters del grau seleccionat
*               in : login_to_move = cadena de caracters de login que es vol moure.
*               int trobat = si el troba (1), sino (0).
* @Retorn: trobat.
* 
* ********************************************************************************************/
int buscarLogin(Degrees **d, char which_degree[MAX_STRING_LENGTH], char login_to_move[MAX_STRING_LENGTH], Student s){
   int trobat=0;
   int i=0;
   for (i=0; i<(*d)->num_degrees; i++){
        if(strcmp((*d)->elements[i].name, which_degree)==0){    //busquem un login saben un grau, aixi que buscarem dintre aquest grau
            for(int j=0;j<(*d)->elements[i].num_classrooms; j++){
				LINKEDLIST_goToHead((*d)->elements[i].classrooms[j].students);
    			while(!LINKEDLIST_isAtEnd((*d)->elements[i].classrooms[j].students)){
    				s = LINKEDLIST_get((*d)->elements[i].classrooms[j].students);
    				if(strcmp(s.login, login_to_move)==0){ //si trobem el login dintre el grau retornem un 1, sino un 0      
                        trobat=1;
                    }
    				LINKEDLIST_next((*d)->elements[i].classrooms[j].students);   
                }
            }
        }
    }
   return trobat;
}


/****************************************************************************************
*
* 
* @Finalitat: comprova si la clase a la que es vol aplicar el estudiant es valida.
* @Parameters:  in : **d = estructura dinamica
*               in : which_degree = cadena de caracters del grau seleccionat
*               in : login_to_move = cadena de caracters de login que es vol moure.
*               in : class_to_move = enter que ens indica la clase a la que volem moure l'estudiant
*               int trobat = si el troba (1), sino (0).
* @Retorn: trobat.
* 
* ********************************************************************************************/


int comprovaClase(Degrees **d, char which_degree[MAX_STRING_LENGTH], char login_to_move[MAX_STRING_LENGTH], int class_to_move, Student s){
    int trobat=0;
	int j=0;
	int save=0;
    int i=0;
    
    for (i=0; i<(*d)->num_degrees; i++){
        if(strcmp((*d)->elements[i].name, which_degree)==0){  //busquem en un grau en concret
		  for(j=0;j<(*d)->elements[i].num_classrooms;j++){
		  LINKEDLIST_goToHead((*d)->elements[i].classrooms[j].students);
				while(!LINKEDLIST_isAtEnd((*d)->elements[i].classrooms[j].students)){
					s = LINKEDLIST_get((*d)->elements[i].classrooms[j].students);

					if(strcmp(s.login, login_to_move)==0){ //si trobem el login dintre el grau retornem un 1, sino un 0      
						save=j;
                	}
					LINKEDLIST_next((*d)->elements[i].classrooms[j].students);  
            	}
			}
			if ((class_to_move<=(*d)->elements[i].num_classrooms) && (class_to_move!=save+1) && (class_to_move>0)){
				trobat=1;
			}
			else{
				trobat=0;
			}
        }
   }
   return trobat;
}


/****************************************************************************************
*
* 
* @Finalitat: funcio per moure el estudiant.
* @Parameters:  in : **d = estructura dinamica
*               in : which_degree = cadena de caracters del grau seleccionat
*               in : login_to_move = cadena de caracters de login que es vol moure.
*               in : class_to_move = enter que ens indica la clase a la que volem moure l'estudiant
*               in : trobat = si el troba (1), sino (0).
*               in : brosa = cache
*               in : login_trobat = int, on guardem el valor retornat per buscarLogin.
*               in : clase_verificada = int, on guardem el valor retornat per comprovaClase.
*               in : degree_trobat = int, on guarden el valor retornat per comprovaDegree.
* @Retorn: null.
* 
* ********************************************************************************************/
void moveStudent(Degrees **d, Student s){
    
    char which_degree[MAX_STRING_LENGTH];
    which_degree[0]='\0';
    char brosa[MAX_STRING_LENGTH];
    char login_to_move[MAX_STRING_LENGTH];
    int class_to_move=0;
    int login_trobat=0;
    int clase_verificada=0;
    int degree_trobat=0;
    int i=0;
    int j=0;

    fgets(brosa, MAX_STRING_LENGTH, stdin);         //cache
    
    
    printf("\nDegree? ");
    fgets(which_degree, MAX_STRING_LENGTH, stdin);          //preguntem quin grau vol per moure estudiants. 
    which_degree[strlen(which_degree)-1]='\0';
    
    degree_trobat = comprovaDegree(d, which_degree);            //comprovem que existeix
    
    if(degree_trobat!=1){
        printf("\nERROR: Can't move student\n");            //error sino el trovem el grau.
    }else{
        printf("\nClassrooms and capacity:\n");
        for (int i=0; i<(*d)->num_degrees; i++){
            if(strcmp((*d)->elements[i].name, which_degree)==0){        //busquem en el grau demanat i mostrem tota la informacio d'aquest grau.
                for(int j=0;j<(*d)->elements[i].num_classrooms; j++){
					LINKEDLIST_goToHead((*d)->elements[i].classrooms[j].students);
					printf("%d. %s %d/inf\n", j+1, (*d)->elements[i].classrooms[j].name, (*d)->elements[i].classrooms[j].current_capacity);
					while (!LINKEDLIST_isAtEnd((*d)->elements[i].classrooms[j].students)){
						s = LINKEDLIST_get((*d)->elements[i].classrooms[j].students);
						printf("%s\n", s.login);
						LINKEDLIST_next((*d)->elements[i].classrooms[j].students);
					}
				}

            }
        }   
    
	
          
        printf("\nWho do you want to move (login)? ");              //un cop amb les dades exposades, preguntem quin login vol moure,
        scanf("%s", login_to_move); 
        login_trobat = buscarLogin(d, which_degree, login_to_move, s);         //comprovem que existeix.
       
        if(login_trobat!=1){
            printf("\nERROR: Can't move student\n");                        //error a mostrar
        }else{
            printf("\nTo which classroom (index)? ");                   //si es correcte, preguntem a quina clase vol moure.
            scanf("%d", &class_to_move);
     		clase_verificada = comprovaClase(d, which_degree, login_to_move, class_to_move, s);            //verifiquem si es pot la clase desitjada.
    	

			
            if (clase_verificada!=1){
                printf("\nERROR: Can't move student\n");                //error sino es pot.
            }else{
			for (i=0; i<(*d)->num_degrees; i++){
                  	if(strcmp((*d)->elements[i].name, which_degree)==0){
            			for(j=0;j<(*d)->elements[i].num_classrooms; j++){
							LINKEDLIST_goToHead((*d)->elements[i].classrooms[j].students);
							while(!LINKEDLIST_isAtEnd((*d)->elements[i].classrooms[j].students)){
								s = LINKEDLIST_get((*d)->elements[i].classrooms[j].students);
								if(strcmp(s.login, login_to_move)==0){ //si trobem el login dintre el grau retornem un 1, sino un 0     
                							LINKEDLIST_add((*d)->elements[i].classrooms[class_to_move-1].students, s);
									(*d)->elements[i].classrooms[class_to_move-1].current_capacity++;
									(*d)->elements[i].classrooms[j].current_capacity--,
									LINKEDLIST_remove((*d)->elements[i].classrooms[j].students);
                				}
								LINKEDLIST_next((*d)->elements[i].classrooms[j].students);   
            			    }
					    }	
				    }
		        }
		    }
        }    
        
    }
    
        
}

/****************************************************************************************
*
* 
* @Finalitat: allibera la memoria amb free alla on hem fet malloc.
* @Parameters:  in : **d = estructura dinamica
* @Retorn: trobat.
* 
* ********************************************************************************************/
void alliberacioMemoria(Degrees **d){
    int i=0;
    
    for (i=0; i<(*d)->num_degrees; i++){
        for(int j=0;j<(*d)->elements[i].num_classrooms; j++){
		LINKEDLIST_destroy(&(*d)->elements[i].classrooms[j].students);
        }
         free((*d)->elements[i].classrooms);
    }
    free((*d)->elements);
}

/****************************************************************************************
*
* 
* @Finalitat: funcio main, on parteixes gairebe totes les funcions del programa.
* @Parameters:  in : Degrees *d = estructura dinamica
*               in : filename1, filename1 on guardem el nom del fixers
*               in pass1, pass2 = pero controlar els errors del fixers.
*               in option = opcion del menu principal.
*               in end = marca el final del programa i el bucle del main.
*               in FILE *f, FILE *g = punters al fitxers
* @Retorn: trobat.
* 
* ********************************************************************************************/
int main()
{
    



    Degrees *d; 
   	Student s;
    char filename1[MAX_STRING_LENGTH] , filename2[MAX_STRING_LENGTH];
    int pass1=0, pass2=0;
    int option;
    int end=0;                      
    
    FILE *f;
    FILE *g;
    
    
    
    printf("Welcome!\n");                       //donem benvinguda
    while(pass1!=1){
        printf("\nType the name of the 'classrooms' file: ");                   //preguntem nom
        scanf("%s", filename1);
        f = fopen(filename1, "r");
        
        if (f==NULL){
            pass1=0;
            printf("\nERROR: Can't open file '%s'\n", filename1);               //error sino es pot obrir.
        }else{
            Degrees *d = (Degrees *) malloc(sizeof(Degrees));                   //creem el primer malloc de Degrees que apuntara i ens ajudara a accedir a la estructura amb les dades mes importants.
            extreureDades(f, &d);                                               //extreiem class_X
            pass1=1;
        }   
    }
    
    while(pass1==1 && pass2!=1){                            //si hem superat el primer FILE
        printf("\nType the name of the 'students' file: ");
        scanf("%s", filename2);
        g = fopen(filename2, "r");
        
        if (g==NULL){
            pass2=0;
            printf("\nERROR: Can't open file '%s'\n", filename2);           //error sino es pot obrir
        }else{
            extreureDades2(g, &d, s);                                          //extraiem i guardem els students.
            pass2=1;
        }   
    }
    
    while (end!=1){
        printf("\n1. Summary | 2. Show degree students | 3. Move student | 4. Exit");           //menu amb la informacio
        printf("\nSelect option: ");
        scanf("%d", &option);
        
        while (option<1 || option>4){
            printf("\nERROR: Wrong option number\n");                                           //en cas d'error seguirem preguntant.
            printf("\n1. Summary | 2. Show degree students | 3. Move student | 4. Exit");
            printf("\nSelect option: ");
            scanf("%d", &option);
        }
        
        
        switch(option){                 //switch amb totes les opcions del menu.
            
            case 1: 
                for (int i=0; i<(d->num_degrees); i++){
                 printf("\n%s\n", d->elements[i].name);
                    for (int j=0; j<d->elements[i].num_classrooms;j++){
                        printf("%s", d->elements[i].classrooms[j].name);
                        printf(" %d/inf\n", d->elements[i].classrooms[j].current_capacity);   //summary de tot.
                    }
                }
            break;
            
            case 2:
            
                degreToShow(&d,s);                //buscar un grau concret
            break;
            
            case 3:
            
                moveStudent(&d, s);                //moure estudiant
            
            break;
            
            case 4:
            
                alliberacioMemoria(&d);             //alliberar memoria.
            	free(d);
                fclose(f);                  //tancar FILES
                fclose(g);
				printf("\nBye!");           //ens despedim
                
                end=1;                  //acabem programa
            break;
        }  
    }
    
    return 0;
}
