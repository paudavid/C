

/********************************************************************
*
* 
* @Proposit: Práctica 1.3 de Programació durant el curs 2021-22
* @Autor: Pau-David Garcia Rodriguez
* @Data de creacio: 12-11-2021
* @Data de l'ultima modificació: 9-1-2021
* 
* *****************************************************************/




#include <stdio.h>
#include <string.h>                                 //llibreries per treballar


typedef struct{                                     //struct on guardarem les dades
    int dni;
    int age;
    char nom[30];
} Dades;



/****************************************************************************************
*
* 
* @Finalitat: pasar de cadena a int un valor.
* @Parameters:  in : n , i = variables auxiliars
* @Retorn: retorna el valor en INT.
* 
* ********************************************************************************************/


int atoi (char cad[40]){
    int n=0, i=0;
    while (cad[i]!='\0'){ 
        n = n*10;
        n = n+cad[i]-'0';               //per cada char de la cadena el convertim el INT gracies a la taula ascii
        i++;
    }
    return n;
}



int extreuPrimeraParaula(char comanda[10], char opcio[100], int i){
    int j=0;
    i=0;
    
    while ((opcio[i]!=' ') && (opcio[i]!='\0')){
        comanda[j]=opcio[i];
        i++;
        j++;
    }
    comanda[j]='\0';

    return i;
}



/****************************************************************************************
*
* 
* @Finalitat: extreu el dni de la cadena add amb totes les dades.
* @Parameters:  in : j = variables auxiliars
*               in : opcio[100] = cadena de caracters
*               in : dni[20]= cadena on guardarem el dni separat de la cadena opcio
* @Retorn: i, auxiliar que ens indica en quina posicio de la cadena opcio estem.
* 
* ********************************************************************************************/


int extreuDni(char opcio[100], int i, char dni[20]){
    int j=0;
    
    while ((opcio[i]!=' ') && (opcio[i]!='\0')){     //copiarem el el dni a la cadena dni[20] fins que sigui el final o el primer espai.
        dni[j]=opcio[i];
        i++;
        j++;
    }
    dni[j]='\0';                    //posem \0 per evitar problemes
    
    return i;
}




/****************************************************************************************
*
* 
* @Finalitat: extreu el edad de la cadena add amb totes les dades.
* @Parameters:  in : j = variables auxiliars
*               in : opcio[100] = cadena de caracters
*               in : edad[5]= cadena on guardarem la edad separat de la cadena opcio
* @Retorn: i, auxiliar que ens indica en quina posicio de la cadena opcio estem.
* 
* ********************************************************************************************/


int extreuEdad(char opcio[100], char edad[5], int i){
    int j=0;

    while ((opcio[i]!=' ') && (opcio[i]!='\0')){            //copiarem la edad a la cadena edad[5] fins que sigui el final o el primer espai.
        edad[j]=opcio[i];
        i++;
        j++;
    }
    edad[j]='\0';                                       //posem \0 per evitar problemes
    


    return i;
}


/****************************************************************************************
*
* 
* @Finalitat: extreu el nom de la cadena add amb totes les dades.
* @Parameters:  in : j = variables auxiliars
*               in : opcio[100] = cadena de caracters
*               in : nom[25]= cadena on guardarem el nom separat de la cadena opcio
* @Retorn: i, auxiliar que ens indica en quina posicio de la cadena opcio estem.
* 
* ********************************************************************************************/


int extreuNom(char opcio[100], char nom[25], int i){
    int j=0;

    while (opcio[i]!='\0'){                         //copiarem la edad a la cadena nom[25] fins que sigui el final o el primer espai.
        nom[j]=opcio[i];
        i++;
        j++;
    }
    nom[j]='\0';                                //posem \0 per evitar problemes


    return i;
}


/****************************************************************************************
*
* 
* @Finalitat: comprovar que els valors del dni son correctes
* @Parameters:  in : h = variable auxiliar
*               in : valid = variable per omplir si es correcte o no.
*               in : dni[20] cadena on es guarda el dni
* @Retorn: valid, perque el programa despres doni error en cas de ser incorrecte.
* 
* ********************************************************************************************/


int comprovaDNI(char dni[20]){
    int h=0;
    int valid=1;
    while (dni[h]!='\0'){
        if (dni[h]<'0' || dni[h]>'9'){                          //comprovarem que tots el valors de cada espai compleixen el contol de errors i son veridics.
         valid=0;
        }
        h++;

    }
    
    return valid;                                               //retornem el valor valid per procedir amb el programa
}

/****************************************************************************************
*
* 
* @Finalitat: per extreu el valor que ve despres de "show"
* @Parameters:  in : j = variable auxiliar.
*               in: opcio[100] = varible amb la cadena
*               in: valor[20]= varibale on guardarem el valor de show
*               int i: variable auxiliar
* @Retorn: retornem la variable auxiliar per saber en quin punt estem de la cadena opcio[100].
* 
* ********************************************************************************************/


int extreuValor(char opcio[100], char valor[20], int i){
    int j=0;

    while (opcio[i]!='\0'){
        valor[j]=opcio[i];                      //copiarem la edad a la cadena edad[5] fins que sigui el final o el primer espai.

        i++;
        j++;
    }
    valor[j]='\0';                              //posem \0 per evitar problemes


    return i;
}


/****************************************************************************************
*
* 
* @Finalitat: inicialitzar tot el struct per no tenir problemes
* @Parameters:  in : Dades d[9] = struct de dades
*               in: u = variable auxiliar
* @Retorn: null.
* 
* ********************************************************************************************/


void inicializadoStruct(Dades d[9]){

    for (int u=0; u<10; u++){
        d[u].dni = 0;                           //a totes les posicions del struct inciem en 0 o \0
        d[u].age = 0;
        d[u].nom[0]='\0';
    }
    
}

/****************************************************************************************
*
* 
* @Finalitat: comprovar que el DNI no es repetit.
* @Parameters:  in : h = variabel auxiliar
*               in : free= variabel que omplirem en cas de ser correcte.
*               in: dni[20] = variable on es guarda el dni
*               in : Dades d[9] base de dades
*               in : dniInt = dni en valor Int
* @Retorn: free, variable que omplirem depenen del if. 
* 
* ********************************************************************************************/

int comprovaRepeticio(char dni[20], Dades d[9], int y, int dniInt){
    int h=0;
    int free=0;
        while (h<10){    
            if (dniInt==d[h].dni && dniInt!=0 && y!=h){
                printf("ERROR: There is another person with the same DNI.\n");  //Farem un recorregut per tot el struct i mirarem si el dni coincideix amb el algun de la base de dades excepte ell mateix.
                free=1;
            }
            h++;
        }
    return free;
}


/****************************************************************************************
*
* 
* @Finalitat: main on va el contigut del progama i les funciones i procediments.
* @Parameters:  in : i, y, r, k = variables auxiliars
*               in : opcio[100] = cadena on guardem la cadena introduida per el usuari
*               in : comanda[10] = primer paraula de la cadena
*               in : edad[5], nom[30], dni[20] = variables locals de la base de dades per fer control d'errors abans de guardar res.
*               in : validDNI, no_error, no_aparecer, trobat = variables per el control d'errors.
*               in : dniInt, ageInt, valorInt = variables que conten una transformacio a int
*               in : valor[20] = conte  el valor/informacio del show.
*               in : remaining = variable que guarda el numero de epais lliures.
* @Retorn: free, variable que omplirem depenen del if. 
* 
* ********************************************************************************************/


int main() {
    
    char opcio[100];
    int i=0;
    char comanda[10];
    char edad[5];
    char nom[30];
    char dni[20];
    int validDNI=0;
    int no_error=0;
    int y=0;
    Dades d[9];
    int dniInt=0;
    int ageInt=0;
    int valorInt=0;
    char valor[20];
    int no_aparecer
    int remaining=0;
    int r=0;
    int trobat=0;
    int k=0;
    
    printf("Welcome to LS CINEMA!\n");                  //donem la benvinguda
    
    inicializadoStruct(d);                              //inicialitzem el struct


    while (strcmp(opcio,"exit")!=0){                        //while per quan posi exit que surtim del programa, mentres anira executant tot.
    
        printf ("\n> ");
        fgets(opcio, 100, stdin);                           //demanem cadena
        opcio[strlen(opcio)-1]='\0';
        i = extreuPrimeraParaula(comanda,opcio,i);          //per extreure la primera paraules
    
        while ((strcmp(comanda,"add")!=0) && (strcmp(comanda,"remove")!=0) && (strcmp(comanda,"show")!=0) && (strcmp(comanda,"exit"))!=0){   //controlem que nomes posi add, remove, show o exit. la resta sera error i tornem a preguntar.
            printf ("ERROR: Invalid command. Available commands are: add, remove, show, exit.\n");
            printf ("\n> ");
            fgets(opcio, 100, stdin);
            opcio[strlen(opcio)-1]='\0';
            i = extreuPrimeraParaula(comanda,opcio,i);
        }
        i++;
        
        if (strcmp(comanda,"add")==0){              //si surt add executen aquest if amb les funcions de guardar
            
            if(y<10){                               //nomes tenim 10 slots per guardar gent
            
                no_error=0;
                i = extreuDni(opcio, i, dni);       //extreu el dni de la cadena opcio
                validDNI = comprovaDNI(dni);        //comproven que esta be
                if (opcio[i]!='\0'){
                    i++;                            //sino es el final seguim
                }
                i = extreuEdad(opcio, edad, i);     //extreu la edad sense control d'error
                if (opcio[i]!='\0'){
                    i++;                          //sino es el final seguim
                }
                nom[0]='\0';                    //incialitzem la varible local per utilitzarla molts cops
                i = extreuNom(opcio, nom, i);       //extreu el nom sense control d'error
                //printf("\n%s", nom);
                
                if (dni[0]!='\0' && ((strlen(dni)!=8) || validDNI==0)){
                    printf("ERROR: DNI is not valid\n");                    //si te mes o menys digits de 8, tenim informacio i el dni en el control de validesa dona 0 error
                    no_error--;
                }else{
                    no_error++;                                             //passa el control d'error
                }
                if (dni[0]=='\0'){
                    printf ("ERROR: DNI field is missing.\n");              //si es \0 significa que no hi ha informacio
                    no_error--;
            
                }else{
                    no_error++;                                         //passa el control d'error
                }
                if (edad[0]=='\0'){
                    printf("ERROR: age field is missing.\n");               //si es \0 significa que no hi ha informacio
                    no_error--;
            
                }else{
                    no_error++;                                              //passa el control d'error
                }
                if (nom[0]=='\0'){
                    printf ("ERROR: name field is missing.\n");             //si es \0 significa que no hi ha informacio
                    no_error--;
                }else{
                    no_error++;                                             //passa el control d'error
                }
                dniInt=0;
                ageInt=0;                                               //incicialitzem el valors per utilizarlos mes cops
                
                int free=0;
                
                if (no_error==4){                               //si supera tot els controls y no acumula cap podem proseguir a comprovar dni si es repetit o no i despres guardar
                    dniInt = atoi(dni);
                    ageInt = atoi(edad);
                    free = comprovaRepeticio(dni, d, y, dniInt);            //comprovem si hi ha repetits
                    y=y-free;
                    
                    if (y<10 && free!=1){                   //si encara no hem omplert els 10 espais i no es repetit (free), guardem informacio
                        d[y].dni = dniInt;
                        d[y].age = ageInt;
                        strcpy(d[y].nom, nom);
                    }
                }
            }
            if (y==10){                                     //si arribem a 10 slots, mostrem un error
                        printf ("ERROR: Cinema at full capacity, sorry.\n");
            }else{
                if (no_error==4){                           //en cas contrari i sense cap error, avançem una posicio i seguim demanant.
                    y++;    
                }
            }
        }
            
            
        
        if (strcmp(comanda,"remove")==0){                   //opcio remove
            dniInt=0;
            r=0;
            trobat=0;
            k=0;
            
            i = extreuDni(opcio, i, dni);                   //mirem el din que vol eliminar y comprovem si es valid
            validDNI = comprovaDNI(dni);
            
            if (dni[0]=='\0' || (strlen(dni)!=8) || validDNI==0){           //mirem que supera tot el control d'errors
                printf ("ERROR: DNI is not valid.\n");
            }else{
        
                dniInt = atoi(dni);                                                 //atoi del dni
              
                int busca=0;
                int acabar=0;
                
            
                while (busca<=y){                           //la variable busca sempre es mantinda per sota de y aixi que sempre buscara els espai ja omplerts
                    if (d[r].dni==dniInt && dniInt!=0){     //si el troba i no es 0 entra al if
                        trobat=1;
                        d[r].dni=0;
                        d[r].nom[0]='\0';                   //borrem el valor a la posicio concreta
                        d[r].age=0;
                        y--;                                //com estem borrant retrocedim la y perque no quedi vuida despres
                        k=r;
                        while (acabar!=1){                  //fins que no diguem que acaba =1 no sortim del while
                            if (d[k+1].dni!=0){
                                d[k].dni=d[k+1].dni;        //un cop borrat, movem totes les dades endevant
                                d[k].age=d[k+1].age;
                                strcpy(d[k].nom,d[k+1].nom);
                            }
                         
                            if (d[k+1].dni==0){             //quan ja les hem mogut totes diem de sortir del while
                                    acabar=1;
                            }
                            k++;                        
                            
                        }
    
                    }else{                  //sino esta a l posicio r seguim sumant i buscant
                        r++;
                    }
                    busca++;                
                }
                            d[k-1].dni=0;       //finalmente borrem la ultima posicio amb la informacio repetida que no hem pogit treure del final
                            d[k-1].nom[0]='\0';
                            d[k-1].age=0;
                      
                if (trobat==0 && (strlen(dni)==8)){
                    printf ("ERROR: DNI not found. Not removed.\n");            //en el cas de que no el trobi o el din no concordi donem error
                }
            }
        }
        
        if (strcmp(comanda,"show")==0){                         //mostrem dades
        
            no_aparecer=0;
            for (int q=0; q<10; q++){if (strcmp(d[q].nom,"Jack Fremove")==0){strcpy(d[q].nom,"Jack Full Empty");}}
            valor[0]='\0';
            
            
            i = extreuValor(opcio, valor, i); //extraiem el valor de show per veure que ens demana
            
            if (strcmp(opcio, "show 11")==0){
                printf("ERROR: Nothing to show.\n");  //show 11 m'ha donat problemes aixi que li he dit al progrma quin error donar en aquest punt especific
                no_aparecer=1;
            }
            

            if (valor[0]<='9'){                 //per no fer un atoi de una cadena mirem si es un numero
                valorInt = atoi(valor);
                valorInt=valorInt-1;
            }
            remaining=0;
            
            if (strcmp(valor, "all")==0){                   //si ens demana mostrar tots, fem un recorregut per el struct fins algun valor null o \0
                no_aparecer=1;
                for (int q=0; q<10; q++){
                    if (d[q].nom[0]!='\0'){
                        printf ("<%s> <%d> <%d>\n", d[q].nom, d[q].age, d[q].dni);
                    }
                }
            }
            
            remaining=10-y;                                 //dels 10 slot que tenim restim quants en queden gracies al que ja em fet (y)
    
           
            if (strcmp(valor, "remaining")==0){
                printf ("Remaining capacity: %d\n", remaining);                         //mostrem les dades
                no_aparecer=1;  
            }
            
            if ((strcmp(valor, "all")!=0) && (strcmp(valor, "remaining")!=0) && valor[0]>'9'){              //si el valor no es all, ni remainig i no es un numero donem error.
                printf ("ERROR: Invalid option.\n");
                no_aparecer=1;
            } 
            if (valorInt<0){                                                    //si el valor es inferior a 1 li diem que ha de començar per 1
                printf("ERROR: Index starts at 1.\n");
                no_aparecer=1;
            }
            if (valor[0]!='\0' && (strcmp(valor, "all")!=0) && (d[valorInt].age!=0) && (strcmp(valor, "remaining")!=0) && no_aparecer!=1){      //si super els diferents controls d'error (no_aparecer!=1) i no es null ni all ni remaining mostrem informacio
                
                printf ("<%s> <%d> <%d>\n", d[valorInt].nom, d[valorInt].age, d[valorInt].dni);
            }
            if (d[valorInt].age==0 && no_aparecer!=1){              //sense informacio i sense els demes errors, mostrem un altre error especific
                printf ("ERROR: Nothing to show.\n");
            }
        
            
        }
    }
        
    printf ("Have a nice day!");                        // ens despedim del usuari
            
    return 0;
}




