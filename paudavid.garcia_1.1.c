/********************************************************************
*
* 
* @Proposit: Práctica 1.1 de Programació durant el curs 2021-22
* @Autor: Pau-David Garcia Rodriguez
* @Data de creacio: 12-11-2021
* @Data de l'ultima modificació: 12-11-2021
* 
* *****************************************************************/



#include <stdio.h>


void banknotes(int retirar) {                                                                                       //esta funcion nos proporciona que billetes son necessarios de mayor a menor.

/****************************************************************************************************
*
* 
* @Finalitat: Mostrar visualment el numero de billets/monedes per a una determinada quantiat.
* @Parameters:  in: entero50 = resultado de dividir retirar entre 50
*               in: residuo50 = residuo de la division retirar entre 50
*               in: entero20 = resultado de dividir residuo50 entre 20
*               in: residuo20 = residuo de la division residuo50 entre 20
*               in: entero10 = resultado de dividir residuo20 entre 10
*               in: residuo10 = residuo de la division residuo20 entre 10
*               in: entero5 = resultado de dividir residuo10 entre 5
*               in: residuo5 = residuo de la division residuo10 entre 5
*               in: entero1 = resultado de dividir residuo5 entre 1
*               in: residuo1 = residuo de la division residuo5 entre 1
*        
* @Retorn: null
* 
* **************************************************************************************************/


    
    int entero50, residuo50, entero20, residuo20, entero10, residuo10, entero5, residuo5, entero1, residuo1;    //declaracion de varibales
    printf ("\nBanknotes handed:");
    
    entero50 = retirar/50;                                                                                      //dividimos lo que se desea retirar entre el billete mas grande, 50. Con ello obtenemos el numero de billetes de 50 que podemos asumir.
    residuo50 = retirar%50;                                                                                     // el resto que no puede asumir el billete de 50, se calcula mediante el modulo, es el residuo y nos proporciona el siguiente valor a dividr, en este caso el siguiente sera 20.
    
    if (residuo50==0) {                                                                                         //si el residuo da 0 ya tenemos el numero de billetes necessarios de 50.
        if (entero50!=0) {
            printf("\n\t50€ - %d", entero50);
        }
    }else {                                                                                                     //Sino debemos seguir hasta que de residuo 0, ahora con billetes de 20.
        entero20 = residuo50/20;
        residuo20 = residuo50%20;
            if (residuo20==0) {
                if (entero50!=0) {
                    printf("\n\t50€ - %d", entero50);
                }
                    if (entero20!=0) {
                        printf("\n\t20€ - %d", entero20);                                                               //printamos los valores que ha podido coger el billete de 50 y 20
                    }
            }else {
                entero10 = residuo20/10;
                residuo10 =residuo20%10;
                if(residuo10==0) {
                    if (entero50!=0) {
                        printf("\n\t50€ - %d", entero50);
                    }
                    if (entero20!=0) {
                        printf("\n\t20€ - %d", entero20);                                                               
                    }
                    if (entero10!=0) {
                        printf("\n\t10€ - %d", entero10);                                                       //printamos los valores que ha podido coger el billete de 50, 20, y 10
                    }

                }else {
                    entero5= residuo10/5;
                    residuo5= residuo10%5;
                    if (residuo5==0) {
                        if (entero50!=0) {
                            printf("\n\t50€ - %d", entero50);
                        }
                        if (entero20!=0) {
                            printf("\n\t20€ - %d", entero20);                                                               
                        }
                        if (entero10!=0) {
                            printf("\n\t10€ - %d", entero10);                                                       
                        }
                        if (entero5!=0) {
                            printf("\n\t5€ - %d", entero5);                                                     //printamos los valores que ha podido coger el billete de 50, 20, 10, 5
                        }
                    }else {
                        entero1=residuo5/1;
                        residuo1=residuo5%1;
                        if (residuo1==0) {
                            if (entero50!=0) {
                                printf("\n\t50€ - %d", entero50);
                            }
                            if (entero20!=0) {
                                printf("\n\t20€ - %d", entero20);                                                               
                            }
                            if (entero10!=0) {
                                printf("\n\t10€ - %d", entero10);                                                       
                            }
                            if (entero5!=0) {
                                printf("\n\t5€ - %d", entero5);                                                     
                            }
                            if (entero1!=0) {
                                printf("\n\t1€ - %d", entero1);                                                 //printamos los valores que ha podido coger el billete de 50, 20, 10, 5, 1
                            }
                        }
                    }
                        
                }   
            }
    }  
 
}

int depositar(int banco) {                                                                                      //funcion int para dipositar dinero.
    
/****************************************************************************************
*
* 
* @Finalitat: Mostrar visualment el numero de billets/monedes per a una determinada quantiat.
* @Parameters:  in: dinero = variable para guardar el dinero que se quiere introducir.
*               in: banco = vairable que nos dice y guarda el dinero total.
*               
*        
* @Retorn: Devuelve la cantidad de banco+dinero.
* 
* ********************************************************************************************/
    int dinero=0;
    
   printf ("\nEnter amount to deposit: ");                                                                    //dinero que queremos ingresar
        scanf ("%d", &dinero);
        
        
        while (dinero<=0 || dinero>5000) {                                                                      //si es menor o igual a 0 y superior a 5000 esta mal, volvemos a preguntar
            printf ("ERROR: Invalid amount");
            printf ("\n\nEnter amount to deposit: ");
             scanf ("%d", &dinero);
        }
        
        printf ("\n%d€ were added successfully to your account balance",  dinero);                            // ha salido bien
        printf ("\nPrevious balance: %d€", banco);                                                              //dinero antes del ingreso
        banco=banco+dinero;
        printf ("\nCurrent balance: %d€", banco);                                                               //dinero despues del ingreso

        
        
        return(banco);                                                                                          //devolvemos este dinero a la variable banco con el dinero actualizado.
    
}



int retirar(int banco) {                                                                                        //funcion para retir dinero del banco
    
/**************************************************************************************************
*
* 
* @Finalitat: Mostrar visualment el numero de billets/monedes per a una determinada quantiat.
* @Parameters:  in: retirar = variable para guardar el dinero a retirar
*               in: dinero_actualizado = variable que actualiza el dinero trasla retirada.
*               in: un_tercio = variable que guarda el dinero del banco/3.
*               in: banco = dinero total.
*              
*        
* @Retorn: dinero_actualizado = banco-retirar
* 
* ********************************************************************************************************/
    int retirar=0;                                                                                              //dinero que queremos retirar
    int dinero_actualizado=0;                                                                                   //dinero despues de retirar
    int un_tercio=0;                                                                                            //varibale utilizada para hacer el calculo del control de error (2/3 del total)
    printf ("\nEnter amount to withdraw: ");                                                                  //insertar cantidad
    scanf ("%d", &retirar);
    
    un_tercio=banco/3;                                                                                          //para calcular 2/3 he decidido cacular 1/3 primero.
    
    while (retirar<=0 || retirar>4000 || (un_tercio+un_tercio<retirar)) {                                       //no puede retirar 0 ni menor de 0, ni tampoco superior a 4000 o 2/3 de la cantidad del banco.
    
        if(retirar<=0) {
            printf ("\nERROR: You cannot withdraw a negative or below-zero amount");                           //error sobre retirar menos o igual a 0
        }
        if (retirar>4000 || (un_tercio+un_tercio<retirar)) {
            printf ("\nERROR: You cannot withdraw more than 4000€ or more than 2/3 of the balance in your bank account");//error sobre retirar mas de 4000 o los 2/3
        }
        
        printf ("\n\nEnter amount to withdraw: ");                                                              //volvemos a preguntar
        scanf ("%d", &retirar);
    
    }

    printf ("\nPrevious balance: %d€", banco );                                                                 //antes de retirar
    dinero_actualizado=banco-retirar;
    printf ("\nCurrent balance: %d€", dinero_actualizado);                                                       //despues de retirar
    
    
    banknotes(retirar);                                                                                         //cargamos la funcion que nos permite calcular los billetes y monedas necessarios
    
    return (dinero_actualizado);                                                                                //actualizamos el dinero del banco

}






int main()
{
    
    int opcion=0;
    int banco=0;
    int end=0;
    printf("Welcome to LS ATM!"); //saludamo, inicio del programa
    
    while (end!=1){ //este while nos permite volver a pregunar el menu tantas veces como haga falta.
    
        printf ("\n\n1. Deposit | 2. Withdraw | 3. Exit"); //menu con las 3 opciones
        printf ("\nSelect option: ");
        scanf ("%d", &opcion);
    
        
        while (opcion!=1 && opcion!=2 && opcion!=3) { //solo se pueden seleccionar el 1, el 2 y el 3.
    
            printf ("ERROR: Invalid option");
            printf ("\n\n1. Deposit | 2. Withdraw | 3. Exit");
            printf ("\nSelect option: ");
            scanf ("%d", &opcion);
        }
        
            switch (opcion) { //con este switch en funcion de valor seleccionador podremos ejecutar una funcion o la otra, o bien acabar el programa.
                
                case 1: banco = depositar(banco); break; //depositar
                
                case 2: banco=retirar(banco); break; //retirar
                
                case 3: printf("\nHave a nice day!"); end=1; break; //salir
                
            }
    }
        
   
}
