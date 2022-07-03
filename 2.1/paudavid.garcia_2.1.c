
/*
********************************************************************
*
* 
* @Proposit: Práctica 2.1 de Programació durant el curs 2021-22
* @Autor: Pau-David Garcia Rodriguez
* @Data de creacio: 20-03-2022
* @Data de l'ultima modificació: 26-05-2022
* 
* *****************************************************************/

#define MAX_STRING_LENGTH 70


#include <stdio.h>
#include <string.h>						//llibreries


typedef struct {
	int stock;
    float price;
    char product_name[MAX_STRING_LENGTH];	
} Product;								//Memoria Producte



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
    
    

/****************************************************************************************
*
* 
* @Finalitat: comprova  si ja existeix algun product per si afegir o be actualizar.
* @Parameters:  in : n
  		    in : product_name_com = cadena on guardem el nom del producte
			in : stock_com = int on guardem el stock del produce
			in : price_com = int del preu del producte
			in : Product struct memoria.
* @Retorn: retorna si existeix algun repetit.
* 
* ********************************************************************************************/
int comprovadorRepetit(char product_name_com[MAX_STRING_LENGTH], int stock_com, float price_com, Product m[200], int i){
    
    int fet=0;
    int count=0;
    
    while (count<=i){

        if (strcmp(product_name_com, m[count].product_name)==0){					//comparem si existeix
            fet=1;

            m[count].stock=m[count].stock+stock_com;					//sumeme mes stock del producte trobat
            
            if (m[count].price>price_com){								
                m[count].price=m[count].price;							//comparem preu i si es mes gran ho actualizem
            }else{	
                m[count].price=price_com;
            }
        }
        
        count++;				
    }

    return fet;
    
}


/****************************************************************************************
*
* @Finalitat: si el valor introduit conte un "@".
* @Parameters:  in : value = cadena on guardem el nom
*			in : trobat = int on guardem si sha trobat o no.
* @Retorn: retorna el valor en INT.
* 
* ********************************************************************************************/
int contieneArroba(char value[MAX_STRING_LENGTH]){
    int trobat=0;
    int i=0;
    
    for(i=0; i<strlen(value);i++){						//comprova si en cada nom llegit existeix algun valor amb "@". 
        
        if (value[i]=='@'){
            trobat=1;

        }
    }
    return trobat;								//retornem si ho hem trobat
    

}

/****************************************************************************************
*
* @Finalitat: treu espais.
* @Parameters:  in : value1 = cadena a modificar
*			in value2 = cadena modificada sense espais
*			in : i, j = variables auxiliars.
* @Retorn: null.
* 
********************************************************************************************/
void quitarEspacio(char value1[MAX_STRING_LENGTH], char value2[MAX_STRING_LENGTH]){
    int i=0, j=0;
    while (value1[i]!='\0') {
        if(value1[i]!=' '){
            value2[j]=value1[i];				//per eliminar el espai final
            j++;           
        }
        i++;
    }
    value2[j]='\0';
}

/****************************************************************************************
*
* @Finalitat: inicialitza tot el struct perque no hi hagin problemes.
* @Parameters:  in : Student struct
*			in : u = variables auxiliars.
* @Retorn: null.
* 
********************************************************************************************/
void inicializadoStruct(Product m[200]){
	int u=0;
    for (u=0; u<200; u++){
        m[u].stock = 0;                           //a totes les posicions del struct inciem en 0 o \0
        m[u].price = 0;
        m[u].product_name[0]='\0';
    }
    
}


/****************************************************************************************
*
* @Finalitat: carrega les dades del supplier 3
* @Parameters:  in : Product struct
*			in : u = variables auxiliars.
			in : FILE *b = punter al fitxer a obrir i guardar.
* @Retorn: retun i.
* 
********************************************************************************************/
int carregaDadesSupplier3(Product m[200], int i, FILE *b){
    
    int fet;
    int j=0;
    int contiene=0;
    
    Product p[50];
    

    fread(&p[j], sizeof(Product),1, b);						//llegim al ser binari tot un struct

    while (!feof(b)){
        
        contiene = contieneArroba(p[j].product_name);						//analitzem

        if (p[j].stock!=0 && contiene!=1){
                
            fet = comprovadorRepetit(p[j].product_name, p[j].stock, p[j].price, m, i);			//comprovem
                
            if (fet!=1){
                strcpy(m[i].product_name, p[j].product_name);
                m[i].stock=p[j].stock;								//si tot es correcte l'actualitzem
                m[i].price=p[j].price;
                i++;
            }
            j++;
                
        }
            fread(&p[j], sizeof(Product),1, b);					//seguim lleguint


    }
    fclose(b); 						//tanquem fitxer i fem return
    return i;
}


/****************************************************************************************
*
* @Finalitat: coloca be la cadena per evitar mes espais de devant.
* @Parameters:  in : input = cadena a modificar
*			in : input_bine = cadena modificada
*			in : k, i = variables auxiliares.
* @Retorn: null.
* 
********************************************************************************************/
void moverCadena(char input[40], char input_bien[40]){
    int k=0;
    int i;
    
    for (i=1; input[i]!='\0';i++){
        input_bien[k]=input[i];					//mover la cadena para eliminar qualquier espacio inecessario
        k++;
    }
    input_bien[k]='\0';
    
}

/****************************************************************************************
*
* @Finalitat: carrega les dades del supplier 1
* @Parameters:  in : Student struct = memoria
*			in : FILE *f = punter del fitxer
*			in : k, i = variables auxiliares.
* @Retorn: return i.
* 
********************************************************************************************/
int carregaDadesSupplier1(Product m[200], int i, FILE *f){
    

    int fet;
    int stock_local;
    float price_local;
    int contiene;
    char product_name_local[40];
    char product_name_local_sin[40];


   
    fscanf(f, "%d %f", &stock_local, &price_local);
    while(feof(f)==0){
        fgets(product_name_local, 40, f);
        product_name_local[strlen(product_name_local)-1]='\0';
        moverCadena(product_name_local, product_name_local_sin);						//llegim dades i fem tot els arreglos possibles
        contiene = contieneArroba(product_name_local);
        
        if (stock_local!=0 && contiene!=1){
            fet = comprovadorRepetit(product_name_local_sin, stock_local, price_local, m, i);				//comprovar
                
            if (fet!=1){
                m[i].stock=stock_local;
                m[i].price=price_local;
                strcpy(m[i].product_name, product_name_local_sin);					//ho coloquem a la memoria.
                i++;		
            }
        }
        fscanf(f, "%d %f", &stock_local, &price_local);
    }
    fclose(f);
								//tanquem i fem return
    return i;						

}


/****************************************************************************************
*
* @Finalitat: carrega les dades del supplier 2
* @Parameters:  in : Student struct = memoria
*			in : FILE *l = punter del fitxer
*			in : k, i = variables auxiliares.
* @Retorn: return i.
* 
********************************************************************************************/
int carregaDadesSupplier2(Product m[200], int i, FILE *l){
    

    

    char basura[400];
    
    char product_n_local[40];
    char product_n_local_sin[40];

    float price_n;
    int stock_n;
    int fet;
    int contiene;
    
    

    fscanf(l, "%s %s", basura, basura); 				//cache del programa

    while (feof(l)==0){
        fgets(product_n_local, 40, l);
        product_n_local[strlen(product_n_local)-1]='\0';
        moverCadena(product_n_local, product_n_local_sin);						//arreglos
           
        fscanf(l, "%s", basura);
        fscanf(l, "%f", &price_n);
        fgets(basura, 400, l);
        fscanf(l, "%s", basura);
        fscanf(l, "%d", &stock_n);									//lleguim dades
        
        contiene = contieneArroba(product_n_local);						//comprovem

            if (stock_n!=0 && contiene!=1){
            
                fet = comprovadorRepetit(product_n_local_sin, stock_n, price_n, m, i);				//comprovem
                    
                if (fet!=1){
                   strcpy(m[i].product_name, product_n_local_sin);
                    m[i].price=price_n;
                    m[i].stock=stock_n; 									//guardem a la memoria
                    i++;
                }
                
            }
            fscanf(l, "%s %s", basura, basura);
        } 
    fclose(l);												//tanquem i fem return

    return i;											
}

/****************************************************************************************
*
* @Finalitat: mostra tots els valors de la memoria
* @Parameters:  in : Student struct = memoria
*			in : n = variables auxiliares.
* @Retorn: null.
* 
********************************************************************************************/
void mostrarValores(Product m[200], int n){
    

    int i, j;
    Product temp;
    
    
    if (n<1){
        printf("There are 0 products in the store\n");
    }else{
        for (i=0; i<n-1;i++){
            for (j=i+1;j<n;j++){
                if (m[i].stock>m[j].stock){
                    temp = m[i];
                    m[i] = m[j];
                    m[j] = temp;								//d'aquesta forma els ordenem de forma deescendent
                } 
            }
        }

        for(i=0; i<n;i++){
            printf("Product #%d:\n", i+1);
            printf("Name: %s\n", m[i].product_name);
            printf("Stock: %d units\n", m[i].stock);						//un cop ordenats els mostrem
            printf("Price: %.2f euros\n", m[i].price);
            printf("---\n");
        }  
    }


    

}

/****************************************************************************************
*
* @Finalitat: busca un producte en concret de la memoria i mostral
* @Parameters:  in : Student struct = memoria
*			in : i = variables auxiliares.
			in : value = cadena on guardar el nom a buscar
* @Retorn: null.
* 
********************************************************************************************/
void buscarValor(char value[40], Product m[200], int i){
    
    int k;
    
    
    for (int u=0; u<i; u++){
        if(strcmp(value,m[u].product_name)==0){
            printf("\nProduct found!");
            printf("\nName: %s", m[u].product_name);
            printf("\nStock: %d units", m[u].stock);
            printf("\nPrice: %.2f euros\n", m[u].price);						//busquem un valor concret amb un strcmp de la memoria i si el trobem el mostrem
            k=1;
            
        }
    }
    
    if (k!=1){
        printf("\nERROR: Product not found\n");					// o mostrem un error de que no es troba el producte seleccionat.
        
    }
    
    
}

/****************************************************************************************
*
* @Finalitat: busca un producte en concret de la memoria i mostral
*
* @Retorn: null.
* 
********************************************************************************************/
int main()
{
    
    FILE *f;
    FILE *g;
    FILE *d;
    
    
    
    Product m[200];
    
    inicializadoStruct(m);					//incialitzem
    	
    char opcion_principal[20];
    
    char extensionTXT[5]=".txt";
    char extensionBIN[5]=".bin";				//extensions
    
    char nombre_supplier1[20];
    char nombre_supplier2[20];				//cadenes dels suppliers
    char nombre_supplier3[20];
    
    char opcion_principal_int=0;				
    int i;		
    char buscador[40];						//variables auxiliars
    char cache[20];
    
    //while para repetir el menu hasta que opcion_principal==4 (sortir)
    
    printf("Welcome!\n");

    while (opcion_principal_int!=4){
        opcion_principal_int=0;
        printf("\n1. Load products from supplier | 2. List products | 3. Show product | 4. Exit\n");
        printf("Select option: ");
        scanf("%s", opcion_principal);
        
        opcion_principal_int=atoi(opcion_principal);
        while (opcion_principal_int<1 || opcion_principal_int>4){  
            printf("\nERROR: Wrong option number\n\n");
            printf("1. Load products from supplier | 2. List products | 3. Show product | 4. Exit\n");			//si no compleix els rquisits tornem a preguntar
            printf("Select option: ");
            scanf("%s", opcion_principal);
            opcion_principal_int=atoi(opcion_principal);
        
        }
        
        char opcion_supplier[10];
        int opcion_supplier_int=0;

        switch(opcion_principal_int){					//switch per definir les diferentes opcions del menu
            
            
            case 1:
            
            printf ("\n1. Supplier 1 | 2. Supplier 2 | 3. Supplier 3");
            printf ("\nChoose one to load from: ");
            scanf("%s", opcion_supplier);
            opcion_supplier_int=atoi(opcion_supplier);


            while (opcion_supplier_int<1 || opcion_supplier_int>3){
                printf("\nERROR: Wrong option number\n");
                printf ("\n1. Supplier 1 | 2. Supplier 2 | 3. Supplier 3");				//control de erros de la opcio del supplier
                printf ("\nChoose one to load from: ");
                scanf("%s", opcion_supplier);
                opcion_supplier_int=atoi(opcion_supplier);

            }
            
            if (opcion_supplier_int==1){
                printf ("\nType the name of the file (without '.txt'): ");
                scanf("%s",  nombre_supplier1);
                strcat(nombre_supplier1, extensionTXT);
                
                f = fopen(nombre_supplier1, "r");									//si es correcte obrim i comprovem possibles erros.
                
                if (f==NULL){
                    printf("\nERROR: Can't open file '%s'\n", nombre_supplier1);
                }else{
                    i = carregaDadesSupplier1(m, i, f);
                    
                }
                
                
            }
            
            if(opcion_supplier_int==2){
                
                printf ("\nType the name of the file (without '.txt'): ");
                scanf("%s",  nombre_supplier2);
                strcat(nombre_supplier2, extensionTXT);
                g = fopen(nombre_supplier2, "r");
                
                if (g==NULL){													//si es correcte obrim i comprovem possibles erros.
                    printf("\nERROR: Can't open file '%s'\n", nombre_supplier2);
                }else{
                    i = carregaDadesSupplier2(m, i, g);
                    
                }
            }
            
            if(opcion_supplier_int==3){
                
                printf ("\nType the name of the file (without '.bin'): ");
                scanf("%s",  nombre_supplier3);

                strcat(nombre_supplier3, extensionBIN);									//si es correcte obrim i comprovem possibles erros.
                															
                d = fopen(nombre_supplier3, "rb");
                
                if (d==NULL){
                    printf("\nERROR: Can't open file '%s'\n", nombre_supplier3);
                }else{
                    i = carregaDadesSupplier3(m, i, d);
                    
                }
            }
    
            break;
            
            
            case 2:
                printf("\n");
                mostrarValores(m, i);							//cridem a la funcio per mostrar tots els valors de la memoria
               
            break;
            
            
            case 3:
                fgets(cache, 20, stdin);
                printf("\nProduct name?: ");
                fgets(buscador, 40, stdin);
                buscador[strlen(buscador)-1]='\0';								//abans li demenarem quin producte vol buscar
                buscarValor(buscador, m, i);
        }
    

    }
    
    printf("\nBye!");									//ens despedim
        
        return 0;
    
}

