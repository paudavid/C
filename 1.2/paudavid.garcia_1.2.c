/********************************************************************
*
* 
* @Proposit: Práctica 1.2 de Programació durant el curs 2021-22
* @Autor: Pau-David Garcia Rodriguez
* @Data de creacio: 03-11-2021
* @Data de l'ultima modificació: 05-11-2021
* 
* *****************************************************************/






#include <stdio.h>
#include <string.h>  //para trabajar string





int insertCreditCard(int orden){
    
/****************************************************************************************
*
* 
* @Finalitat: inertar una serie de 4 numeros que seran pasado por controles de errores antes de ser aceptados.
* @Parameters:  in : input[5] = variable on es posen els 4 numeros.
*               in : resultat = donde guardaremos el resultado final en atoi en caso de ser todo correcto.
*               in : correcte = variable que nos libera del while en caso de pasar los controles.
*               in : valor_per_comprovar = per calcular que no posi un numero inferior de 4 digits, faig un atoi perque el control d'error pugui verificar.
*               in : h, j = variables auxiliares. 
*               in : orden = variable que nos dice el orden que toca por cada grupo de digitos.
* @Retorn: devuelve resultat, los numeros introducidos pero con contol de error y un atoi.
* 
* ********************************************************************************************/
    char input[5];
    int resultat=0;
    int correcte=0;
    int valor_per_comprovar=0;
    
    
    
    while(correcte!=1){ 								//Iniciamos while 
        printf("Input credit card digit group #%d: ", orden);      			//preguntamos los 4 digitos y los guardamos en una cadena llamada input[5]
        scanf("%s", input);
        
        for(int h=0; input[h]!='\0';h++){                         			 //atoi para comprovar que no pongo valores inferiores a 4 cifras.
            valor_per_comprovar=valor_per_comprovar*10+(input[h]-'0');
        }
            
        if (input[0]=='0' || input[4]!='\0' || valor_per_comprovar<1000 ){  		//comprovamos que el primer valor no es 0, que en la casilla 4 se acabe la informacion (para no mayores de 4 cifras) y que no sea inferior de estas 4 mediante el atoi.
            printf("ERROR: Digit groups must have 4 digits\n\n");
            valor_per_comprovar=0;               
            correcte=0;
        }else{
            correcte=1;
        }
    }   
    
    for(int j=0; input[j]!='\0';j++){                 					//si pasa todos los controles hacer un atoi con el input correcto.
        resultat=resultat*10+(input[j]-'0');
    }

    return resultat;                 							//devolvemso resultado para poder trabajarlo en otros puntos.
}

int insertPin(){
    
/****************************************************************************************
*
* 
* @Finalitat: inertar una serie de 4 numeros que seran pasado por controles de errores antes de ser aceptados.
* @Parameters:  in : pin[5] = variable que almacena los 4 valores, hace una funcion similar a los 4 digitos de la tarjeta.
*               in : valorpin_per_comprovar = guarda el valor de un atoi de pin.
*               in : pinInt = valor donde guardamos en atoi el pin[5] si ha pasado los controles.
*               in : j = variable auxiliar;
*        
* @Retorn: devuelve pinInt, donde hemos guardado en Int el valor de pin[5] tras los controles.
* 
* ********************************************************************************************/
    
    char pin[5];
    int valorpin_per_comprovar=0;
    int pinInt=0;


    printf("\nInput PIN: ");                   						 //preguntamos el pin y lo guardamos en pin[5]
    scanf("%s", pin);
    for (int g=0; pin[g]!='\0';g++){                   					 //atoi que nos servira para el contol de errores, veremos que no sea un valor inferior a 4 cifras.
            valorpin_per_comprovar=valorpin_per_comprovar*10+(pin[g]-'0');
    }
    
    while (pin[0]=='0' || pin[4]!='\0' || valorpin_per_comprovar<1000){ 		//miraremos que el no empiece por 0, que acabe en la 4 casilla y finalmente que no sea inferior a 4 digitos.
        printf("ERROR: The PIN must have 4 digits");         				//notificamos el error en ese caso y volevemos a preguntar.
        printf("\n\nInput PIN: ");
        scanf("%s", pin);
        valorpin_per_comprovar=0;
        
        for (int g=0; pin[g]!='\0';g++){                                   		 //finalmente en este while iremos preguntando de nuevo y con ello atois hasta que introduzca valores correctos.
            valorpin_per_comprovar=valorpin_per_comprovar*10+(pin[g]-'0');
        }
    }
    
    for (int j=0; pin[j]!='\0';j++){                    				//atoi final donde guardamos el valor en pinInt, de cadena a int.
            pinInt=pinInt*10+(pin[j]-'0');
    }
    
    return pinInt;               							//devolvemos pinInt;
}


void showStatistics(int entrades, int num_joven, int num_adulto){
    
 /****************************************************************************************
*
* 
* @Finalitat: inertar una serie de 4 numeros que seran pasado por controles de errores antes de ser aceptados.
* @Parameters:  in : joven = almacena el porcentaje calculado por sus ventas correspondientes.
*               in : adulto = almacena el porcentaje calculado por sus ventas correspondientes.
*               in : vendidas = calculo realiado entre las entrades disponibles (15) menos las entradas perdidas.
*               in : entrades = entrades disponibles que quedan tras los diferentes calculos, o ninguno.
*               in : num_joven = numero de entradas compradas por jovenes.
*               in : num_adulto = numero de entradas compradas por adultos.        
* @Retorn: null.
* 
* ********************************************************************************************/
    
    float joven=0;
    float adulto=0;
    float vendidas=15-entrades;
    
    
    printf ("\nSTATISTICS:");
    printf ("\nRemaining tickets: %d", entrades);         					  //mostramos los tiquets restantes.
    
    if(num_joven!=0 || num_joven!=0){           						//con este if comprovamos que las entradas de los jovenes y los adultos no sea 0 para que no numero que no cuadren con los calculos.
        
      joven=(num_joven/vendidas)*100;                 					      //calculamos el tanto por ciento y lo guardamos en las variables joven y adulto.
      adulto=(num_adulto/vendidas)*100;
      
      printf ("\nTickets sold for children (percentage): %.2f", joven);         		//si es correcto mostramos el porcentaje para cada uno.
      printf ("\nTickets sold for adults (percentage): %.2f\n", adulto);
    }else{
      printf ("\nTickets sold for children (percentage): 0.00");               			 //sino hay entradas printamos 0 y ya esta.
      printf ("\nTickets sold for adults (percentage): 0.00\n");
    }
}


void menu(int fin){
    
 /****************************************************************************************
*
* 
* @Finalitat: mostrar el menu con unas de las opciones (2).
* @Parameters:  in : option = variable para la opcion del menu
*               in : entrades = incializada a 15, son las entradas disponibles.
*               in : no_more_1 = para contar las veces que accede a comprar (opcion1).
*               in : optionCA = variable donde se guarda la opcion sobre si quiere children o adult.
*               in : aux = variable auxiliar.
*               in : num_buy = numero de entradas solicitadas.
*               in : num_adulto = entradas compradas con la opcion adulto.
*               in : num_joven = entradas compradas con  las opcion children.
*               in : fin = vairable para terminar el programa.
* @Retorn: null.
* 
* ********************************************************************************************/
    
    int option=0;
    int entrades=15;
    int no_more_1=0;
    char optionCA;
    char aux;
    int num_buy=0;
    int num_adulto=0;
    int num_joven=0;
    
    
    while(fin!=1){                                      
        printf("\n1. Buy | 2. Show statistics | 3. Exit");      				//preguntamos al usuario que opcio que opcion quiere.
        printf("\nSelect option: ");
        scanf("%d", &option);
    

        
        while (option<1 || option>3){                          					 //solo permitimos valores 1, 2 y 3.
           printf("ERROR: Invalid option");                    					//notificamos error y volvemos a preguntar
            printf("\n\n1. Buy | 2. Show statistics | 3. Exit");
            printf("\nSelect option: ");
            scanf("%d", &option);
        }
        
        switch(option){                                 					//abrimos switch para organizar las opciones mucho mejor.
            case 1:  
                no_more_1++;
                if (no_more_1<3){                       					//solo podemos comprar un maximo de 2 veces, lo controlamos con un contador i un if.
                               
                    scanf("%c", &aux);                 						 //auxiliar
                    printf("\n(c)hildren or (a)dult? (case insensitive) "); 			//preguntamos que tipo de entrada quiere.
                    scanf ("%c", &optionCA);
                    scanf("%c", &aux);                 						 //auxiliar 

                    while ((optionCA!='C' && optionCA!='c') && (optionCA!='A' && optionCA!='a')){ //lo haremos case insenstive pero debemos comprovar que solo introducen la c o la a.
                        printf("ERROR: You must choose between (c)hildren or (a)dult ");        //damos error y volvemos a preguntar
                        printf("\n\n(c)hildren or (a)dult? (case insensitive) ");
                        scanf ("%c", &optionCA);
                         scanf("%c", &aux); //auxiliar
                    }
                    
                    printf ("Remaining tickets: %d", entrades);                         	//tickets disponibles
                    printf ("\nHow many tickets do you want to buy? ");                         //le preguntamos cuantos quiere.
                    scanf ("%d", &num_buy);
                    
                    while (num_buy>10 || num_buy>entrades){                                     //preguntaremos de nuevo hasta que no pida >10 y no pida mas de las diponibles.
                        if (num_buy>10 && num_buy<entrades){
                            printf ("ERROR: You cannot buy more than 10 tickets at once");      //si solo ha puesto mas entradas de 10 le damos un error concreto.
                        }
                        if(num_buy>entrades && num_buy<10){
                            printf("ERROR: You cannot buy more tickets than available");        //si solo ha superado las entras disponibles le damos un error concreto.
                
                        }
                        if (num_buy>entrades && num_buy>10){
                            printf ("ERROR: You cannot buy more than 10 tickets at once");      //si ha hecho las 2, mostraremos los 2 tipos de errores.
                            printf("\nERROR: You cannot buy more tickets than available");
                        }
                        printf ("\n\nRemaining tickets: %d", entrades);
                        printf ("\nHow many tickets do you want to buy? ");                     //preguntamos de nuevo
                        scanf ("%d", &num_buy);  
                    }
                
                    
                    if (optionCA=='C' || optionCA=='c'){
                        num_joven=num_joven+num_buy;               				 //guardamos las entradas vendidas a childrens
                    }
                    
                    if(optionCA=='A' || optionCA=='a'){
                        num_adulto=num_adulto+num_buy;              				//guarda las entradas vendidas a adults.
                    }
                    entrades=entrades-num_buy;             					 //entradas restantes


        
                }
                else{
                    printf("\nERROR: You cannot buy more tickets today\n");  		       //En el caso de que haya comprado 2 veces, le mostramos un error de que no puede comprar mas.
                }
            
            break;
            
            case 2:

                showStatistics(entrades, num_joven, num_adulto);         		      //la opcion 2 mostramos un menu de estadisticas donde le pasamos las diferentes ventas y las entradas disponibles.
            
            break;
            
            case 3:
                printf("\nHave a nice day!");                   				//nos despedimos del usuario y acabamos el programa.
                fin=1;
            
        }    
    }
}

int raiz_digital(int valor)   
{
/***********************************************************************************************  
* @Finalitat: esta funcion ha sido basada en fuentas de internet y mediante un solo calculo nos propociona la raiz digital.
* @Parameters:  in : valor = numero que queremos calcular la raiz digital.
* @Retorn: devuelve el siguiente calculo raiz_digital_rec2((valor%10) + raiz_digital_rec2(valor/10)), la raiz digital.
* 
***************************************************************************************************/
		return(raiz_digital((valor%10) + raiz_digital(valor/10)));
}

int comprovaPin(int pinInt, int primeros_c, int segundos_c, int terceros_c, int cuatro_c){
    
/***********************************************************************************************  
* @Finalitat: Comprovar que la tarjeta de credito es valida.
* @Parameters:  in : raiz_dig, raiz_dig2, raiz_dig3, raiz_dig4 = variables utilizadas para guardar el calculo de la raiz digital de los 4 grupos de 4 digitos.
*               in : raiz_total = donde guardamos las 4 raizes digitales juntas mediante una formula.
*               in : fin = variables que guarda si el programa debe terminar o no.
*               in : pinInt = donde guardamos los 4 valores del pin.
*               in : primeros_c, segundos_c, terceros_c, cuatro_c = donde guardamoslos 4 grupos de 4 digitos correctos.
* @Retorn: depende del funcionamiento tenemos dos retuns, si no se verifica se cierra el programa fin =1.
* 
***************************************************************************************************/
    
    int raiz_dig=0, raiz_dig2=0, raiz_dig3=0, raiz_dig4=0, raiz_total=0;
    int fin=0;

    raiz_dig = raiz_digital(primeros_c);
    raiz_dig2 = raiz_digital(segundos_c);           					//mediante la funcion anterior, calculas y guardamos.
    raiz_dig3 = raiz_digital(terceros_c);
    raiz_dig4 = raiz_digital(cuatro_c);
    
    raiz_total=raiz_dig*1000+raiz_dig2*100+raiz_dig3*10+raiz_dig4;     			 //juntamos las 4 raices digitales
    
    if ( raiz_total!=pinInt){                                   			// en el caso de que el pin y las raices no sean iguales, notificamos el error y finalizamos el programa.
        printf("ERROR: The credit card is not valid");
        printf("\n\nHave a nice day!");
        return (fin=1);

    }else{
        return(fin=0);              							//sino no.
    }
    
    
    
    
}



int main()
{
/***********************************************************************************************  
* @Finalitat: Ejecutar las funciones principales.
* @Parameters:  in : fin = variables que guarda si el programa debe terminar o no.
*               in : pinInt = donde guardamos los 4 valores del pin.
*               in : primeros_c, segundos_c, terceros_c, cuatro_c = donde guardamoslos 4 grupos de 4 digitos correctos.
*               in : orden = variable que guarda el numero/orden de los grupos de digitos.
* @Retorn: null.
***************************************************************************************************/
    int primeros_c=0;
    int segundos_c=0;
    int terceros_c=0;           
    int cuatro_c=0;
    int orden=1;
    int pinInt =0;
    int fin;
    
    printf ("Welcome to LS THEATRE!\n\n");                          			//damos la bienvenida

    
    primeros_c = insertCreditCard(orden);
    orden++;
    segundos_c = insertCreditCard(orden);
    orden++;
    terceros_c = insertCreditCard(orden);                         			//extramos los grupos de 4 digitos correctament tras los controles de error.
    orden++;                                                      			//a la vez vamos aumentando orden en funcion pasamos del grupo correcto.
    cuatro_c = insertCreditCard(orden);
    
    pinInt=insertPin();                                             			//mediante esta funcion pedimos el pin y lo pasamos por el control de error.
    
    fin = comprovaPin(pinInt,primeros_c, segundos_c, terceros_c, cuatro_c);   		  //con esta funcion comprovamos que la tarjeta es valida antes de pasar al menu.
     
    menu(fin);                                                 				 //ejecutamos el menu.
    
    
    return 0;
}
