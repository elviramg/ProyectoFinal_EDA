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
}

