#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
{	int largo_vector;

	int vector[500];
	
	largo_vector=carga(vector);	
 	
 	
	return 0;
}

//------------------------------ CARGA --------------------//

bool chequeo_salida(strEstructura vector[], int i)  //Funcion usada para chequear el ingreso del usuario
{	
	bool salida;
	
	if ((vector[i].cod)=9999)
		salida=true;
	else 
		salida=false;
	
	return salida;
}

void ingreso_cod(strEstructura vector[], int i)
{	
	printf ("Ingrese un codigo entre 1000 y 8000 para el disco numero %d: ", i);
	scanf("%d", vector[i].cod);
	
	while (vector[i].cod>1000 || vector[i].cod<8000)
	{
		printf ("Ingrese un codigo entre 1000 y 8000 para el disco numero %d: ", i);
		scanf("%d", vector[i].cod);
		
		return;	
	}
	
}
	
	
void ingreso_titulo(strEstructura vec[], int i)
{	
	printf("Ingrese el titulo del disco numero %d: ", i);
	fgets (vector[i].titulo, 30, stdin);
	
	
	
	while (strlen(vector[i].titulo)>30)
	{
		printf("Ingrese el titulo del disco numero %d: ", i);
		fgets (vector[i].titulo, 30, stdin);
	}
	
	return;	
}
	

void ingreso_tracks(strEstructura vec[], int i)
{
	printf("\nIngrese el numero de tracks que tendra el disco numero %d: ", i);
	scanf("%d", vector[i].tracks);
	
	while ((vector[i].tracks)>25)
	{
		printf("\n Ingresne el numero de tracks que tendra el disco numero %d, recuerde que elmaximo de tracks es de 25: ", i);
		scanf("%d", vector[i].tracks);	
	}
	return;
}
	

int carga(strEstructura vector[]) 
/*funcion que hace la carga pero ademas devuelve el largo del vector (maximo logico)
esto lo hacemos para que aprovechar y recorrer el vector una sola vez */
{
	int i=0;
	int largo_vector;
	bool salida=false;

	while (salida || i<ml)
	{
		ingreso_cod(vector, i);
		salida=chequeo_salida(vector, i);
		
		while (salida || i<ml)
		{
			ingreso_titulo(vector, i);
		
			ingreso_tracks(vector, i);
		
			printf(" Ingrese el precio para el disco numero %d: ", i);
			scanf ("%d", vector[i].precio);	
		
		}
		
		i++;
	}
	
	largo_vector=i;
	
	return largo_vector;

}
	
//------------------------------ CARGA --------------------//

//------------------------------ PRECIO PROMEDIO  --------------------//
