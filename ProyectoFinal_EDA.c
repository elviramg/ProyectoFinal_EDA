//PROGRAMA QUE SIMULA LA GESTION DE UNA IMPRESORA
//ELVIRA VALENTINA MAGALLANES GARCÍA

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

//ESTRUCTURAS

typedef struct nodo {
	char docu[20];
	//Contador de documentos
	int cta;
	struct nodo *siguiente;
	//colas de prioridad, para los usuarios
	struct NewImp *mandado_a_imprimir;
	char usuario[20];
	int prioridad;

} Nodo;//Esta es la estructura para los documentos

typedef struct NewImp {
	//Contador de cantidad de impresoras
	int cta;
	char nombreImp[20];
	//Apuntadores a la estructura de documentos
	struct nodo *impresiones, *ultimaImpre;

	struct NewImp *sig;
} Imp; //Esta es la estructura para la impresora


int main(){
	setlocale(LC_CTYPE, "Spanish");
	
	 do
        {
            system("cls");
            printf("\n\t\t\t SIMULADORA DE UNA IMPRESORA")
            int opc;
            printf("\t\t\t BIENVENIDO \n\t");
            printf("\n\t\t\t¿Qué deseas hacer?");
            printf("\n\t\t\t1. Agregar impresora");
            printf("\n\t\t\t2. Eliminar impresora");
            printf("\n\t\t\t3. Visualizar colas de impresión");
            printf("\n\t\t\t4. Mandar a imprimir");
            printf("\n\t\t\t5. Añadir usuario");
            printf("\n\t\t\t6. Salir");
 
            fflush(stdin);
            scanf("%d", &opc);

            switch(opc){
            case 1:
               //agregar funcion
                system("pause");
                break;
            case 2:
            	//agregar función
                system("pause");
                break;
            case 3:
                //agregar funcion
                system("pause");
                break;
            case 4:
				//agregar funcion
                system("pause");
                break;
            case 5:
                //agregar funcion
                system("pause");
                break;
            case 6:
                printf("¡Adios!\n");
                return 0;
                break;
            default:
                printf("Opción no válida\n");
                }
                
        }
        while(1);

    return 0;
    }
    
    //FUNCIONES
}

