//PROGRAMA QUE SIMULA LA GESTION DE UNA IMPRESORA
//ELVIRA VALENTINA MAGALLANES GARCÍA

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

//ESTRUCTURAS

typedef struct nodo { //ESTRUCTURA DE LOS DOCUMENTOS
	char docu[20];
	//Contador de documentos
	int cta;
	struct nodo *siguiente;
	//colas de prioridad, para los usuarios
	struct NewImp *mandado_a_imprimir;
	char usuario[20];
	int prioridad;

} Nodo;//Esta es la estructura para los documentos

typedef struct NewImp { //ESTRUCTURA NUEVA IMPRESORA
	//Contador de cantidad de impresoras
	int cta;
	char nombreImp[20];
	//Apuntadores a la estructura de documentos
	struct nodo *impresiones, *ultimaImpre;

	struct NewImp *sig;
} Imp; //Esta es la estructura para la impresora

typedef struct NewUs { //ESTRUCTURA NUEVO USUARIO
	char usuario[20];
	//Contador de la cantidad de usuarios
	int noUs;
	int prioridad;
	struct NewUs *siguiente;
} Usuario; // Esta es la estructura para usuarios

Nodo *DocPrim, *DocUlt;
Nodo *mandado;
Imp *mando;
int  numero_Imp=0;

char usua[20], claveUsuario[10];
int i=0;

//APUNTADORES
int agregar_Imp(Imp **primero, Imp **ultimo, int numero_Imp);
int eliminar_Imp(Imp **primero, Imp **ultimo, int numero_Imp);
int impresoras_Conectadas(Imp **primero, Nodo **DocPrim, Usuario **ultimoUS, Nodo **mandado_a_imprimir, int numero_Imp);
int AgregarDoc(Nodo **DocPrim, Nodo **DocUltimo, Usuario **ultimoUS, Imp **mando);
int ingresar_Usuario(Usuario **primerUS, Usuario **ultimoUS);
Imp* Imprimir(Imp **primero, Imp **ultimo, int numero_Imp);
Usuario *primerUS, *ultimoUS;

//Contraseña
    char claveSitema[10]= "hola"; 

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
				numero_Imp = agregar_Imp(&primero, &ultimo, numero_Imp);
                system("pause");
                break;
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
    
int agregar_Imp(Imp **primero, Imp **ultimo, int numero_Imp){
    printf("\n\t\t****AGREGAR IMPRESORA****\n");
    Imp *New; //APUNTADOR QUE APUNTA A ESTRUCTURA IMP
	if((New=(Imp *)malloc(sizeof(Imp)))==NULL){
		printf("\n\nNo pude almacenar memoria\n");
		return -1;
	}
	
	numero_Imp++;
	printf("Usted está conectado a %d impresoras\n", (numero_Imp));
	New->cta=numero_Imp;
	New->sig=NULL;
	/*apartamos espacio*/
	if((New->ultimaImpre=(Nodo *)malloc(sizeof(Nodo)))==NULL){
		printf("\n\nNo pude almacenar memoria\n");
		return -1;
	}
	
	if((New->impresiones=(Nodo *)malloc(sizeof(Nodo)))==NULL){
		printf("\n\nNo pude almacenar memoria\n");
		return -1;
	}
	
	printf("Ingrese el nombre de la impresora: ");
	fflush(stdin);
    gets(New->nombreImp);

	New->ultimaImpre->cta = 0;
	New->impresiones->cta = 0;

	if(*ultimo)
		(*ultimo)->sig = New; //el apuntador siguiente de la estructura que estaba al ultimo guarda la direccion de la nueva estructura
		*ultimo = New; //ahora el ultimo es el nueevo
	
	if(!*primero) //si primero == NULL entonces es la primera estructura impresora en agregarse
		*primero = New;

		return numero_Imp;
}

int eliminar_Imp(Imp **primero, Imp **ultimo, int numero_Imp){

}

int impresoras_Conectadas(Imp **primero, Nodo **DocPrim, Usuario **ultimoUS, Nodo **mandado, int numero_Imp){
	
}

Imp* Imprimir(Imp **primero, Imp **ultimo, int numero_Imp){
	
}

int AgregarDoc(Nodo **DocPrim, Nodo **DocUlt, Usuario **ultimoUS, Imp **mando){
	
}

int ingresar_Usuario(Usuario **primerUS, Usuario **ultimoUS){
	
}



}

