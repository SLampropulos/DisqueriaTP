#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*Aca van los datos que me dan 
1. 500 discos como maximo
2. Cada disco contiene: 
.Codigo (entre 1000 y 8000
.Titulo: maximo de 30 caracteres
.Track: cada titulo puede tener 25 tracks como maximo
.Precio: real



*/

#define ml 500

typedef struct
{
	int cod;
	char titulo[30];
	int tracks;
	float precio;
}	strEstructura; 


strEstructura vector[500];






int carga();
int calculo_precio_promedio();
int busqueda_minimo_precio();
int busqueda_maximo_precio();
void mostrar_datos();


int main()
{	
	int vector[500];
	
 	
 	
	return 0;
}

void chequeoCod(strEstructura vector[])
{	
	int i;
	
	while (vector[i].cod>=1000 || vector[i].cod<=8000 && vector[i].cod!=9999)
	{
		printf ("Ingrese un codigo entre 1000 y 8000 para el disco numero %d: ", i);
		scanf("%d", vector[i].cod);
		
		return;
		
	}
	
}
int carga(strEstructura vector[])
{
	int i=0;
	bool condicion=false;

	while not condicion || i<ml)
	{
		chequeoCod();
		
		printf("Ingrese el titulo del disco numero %d: ", d);
		scanf("%d", vector[i].titulo);
		
		printf(" Ingrese el numero de tracks que tendra el disco numero %d: ", i);
		scanf("%d", vector[i].tracks);
		
		printf(" Ingrese el precio para el disco numero %d: ", i)
		scanf ("%d", vector[i].precio)	
	
		i++;
	}	
	
	
	
	
	
	
	
}
