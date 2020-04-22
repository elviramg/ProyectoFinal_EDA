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
            case 2:
            	numero_Imp = eliminar_Imp(&primero, &ultimo, numero_Imp);
                system("pause");
                break;
            case 3:
                impresoras_Conectadas(&primero, &DocPrim, &ultimoUS, &mandado, numero_Imp);
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
	 Imp *nodo, *temp;
    nodo = *primero; //nodo tiene la direccion de la primera (estructura) impresora
    temp = *primero;//se creo un apuntador temporal para no perder las direcciones
    char conf;

    if(!nodo){ //si el *primero estaba en NULL noy hay impresoras
		printf("\n\nNo hay impresoras conectadas. No se puede eliminar\n");
		return 0;
	}
	else{
		printf("\nHay %d impresora(s) conectadas\n\n", numero_Imp);
		printf("Se eliminara la impresora %s (%d) con %d documentos\n",nodo->nombreImp, nodo->cta, nodo->ultimaImpre->cta);
		printf("¿Estas seguro de eliminar (desconectar) la impresora? (s/n): ");
		fflush(stdin);
		scanf("%c", &conf);
		if(conf == 's' || conf == 'S'){
            int i;
			for(i=0; i<(numero_Imp-1); i++){
				nodo = nodo->sig;//recorremos nodos
				(nodo->cta)--;//la impresora 2 ahora es la 1...
			}
			*primero = temp->sig;//ahora el primero apunta a la estructura siguiente
			free(temp);//liberamos la estructura a la que apuntaba "temp"
			printf("\nSe ha eliminado impresora \n");
			numero_Imp--;//hay una impresora menos, contador disminuye
		}
        if(!*primero)//si ya no hay impresoras
            *ultimo = NULL;

        return numero_Imp;
}
}

int impresoras_Conectadas(Imp **primero, Nodo **DocPrim, Usuario **ultimoUS, Nodo **mandado, int numero_Imp){
	Imp *nodo; //Apuntador de tipo impresora

Nodo *docum;
docum= *DocPrim;
	int i;
	nodo = *primero; //el apuntador esta en la primera (estructura) impresora
	printf("Hay %d impresora(s) conectadas\n\n", numero_Imp);
	printf("Los documentos en la cola son: \n");
	for(i=0; i<numero_Imp; i++){
		do
        {
            printf("Documento %s enviado por el usuario %s en impresora %s de prioridad %d\n", docum->docu, docum->usuario, docum->mandado_a_imprimir->nombreImp, docum->prioridad);
            if(docum->siguiente){
            docum=docum->siguiente;
            }
            }
            while(docum->siguiente!=NULL);
		nodo = nodo->sig;  //recorremos el apuntador a la (estructura) impresora siguient
	}
}

Imp* Imprimir(Imp **primero, Imp **ultimo, int numero_Imp){
	char n[10];
    char confirmacion = '\0';
	Imp *mando, *visualizar;
	Nodo *DocPrim, *DocUlt;

	if(numero_Imp != 0){
		mando = *primero;
		system("cls");
		printf("\n***Menú de impresión***\n");
		printf("Conectado a %d impresora(s)\n", numero_Imp);
			printf("Ingrese el nombre de impresora a la que desea mandar a imprimir su archivo: ");
			fflush(stdin);
			gets(n);
                {
                while(strcmp(mando->nombreImp,n)!=0){
				//while(nodo->cta != n){
					mando = mando->sig;
				}
				printf("\nConfirmar impresión (s/n): ");
				fflush(stdin);
				scanf("%c", &confirmacion);
				if(confirmacion=='s' || confirmacion=='S'){
                        printf("Se ha seleccionado la impresora %s\n",mando->nombreImp);
				}

				else
					printf("\nSe ha cancelado la impresion\n");
			}
	}
	
	else{
		printf("\nNo hay impresoras conectadas, no se puede mandar a imprimir.\n");
		printf("Revise la conexión a impresoras.\n");
		return 0;
	}
	return (mando);
}

int AgregarDoc(Nodo **DocPrim, Nodo **DocUlt, Usuario **ultimoUS, Imp **mando){
	Nodo *NewDoc; //Apuntador de tipo nodo que apunta a nuevos documentos
    Usuario *actualUs;
    actualUs=*ultimoUS;
    
    if((NewDoc=(Nodo *)malloc(sizeof(Nodo)))==NULL){  //Necesito apartar memoria para los nuevos documentos
		printf("\nNo puede almacenar memoria\n Reinicie el programa");
		return -1;
	}
	
	NewDoc->siguiente=NULL; //Mandamos el apuntar siguiente a null por ser la ultima estructura creada
	
	Usuario *UsActual;
	UsActual=*ultimoUS;
	
	
	
	
}

int ingresar_Usuario(Usuario **primerUS, Usuario **ultimoUS){
	
}



}

