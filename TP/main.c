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

#define mf 500

typedef struct
{
	int cod;
	char titulo[30];
	int tracks;
	float precio;
}	strEstructura; 


//------------------------------ CARGA ----------------------------------------------//
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
	printf ("\n Ingrese un codigo entre 1000 y 8000 para el disco numero %d: ", i+1);
	scanf("%d", &vector[i].cod);
	
	while (vector[i].cod<1000 || vector[i].cod>8000)
	{
		printf ("\n El codigo no estaba en el rango indicado. Por favor, ingrese un codigo entre 1000 y 8000 para el disco numero %d: ", i+1);
		scanf("%d", &vector[i].cod);
	}
	
	return;
}
	
	
void ingreso_titulo(strEstructura vector[], int i)
{	
	fflush(stdin);
	printf("\n Ingrese el titulo del disco numero %d, recuerde que el mismo debe tener un maximo de 30 caracteres : ", i+1);
	fgets (vector[i].titulo, 30, stdin);
	
	fflush(stdin);
	
	while (strlen(vector[i].titulo)>30)
	{
		printf("\n Lo ingresado no cumplió con los requisitos pedidos. Por favor, ingrese el titulo del disco numero %d: ", i+1);
		fgets (vector[i].titulo, 30, stdin);
		fflush(stdin);
	}
	
	return;	
}
	

void ingreso_tracks(strEstructura vector[], int i)
{
	printf("\n Ingrese el numero de tracks que tendra el disco numero, recuerde que un disco puede tener como maximo 25 tracks. %d: ", i);
	scanf("%d", &vector[i].tracks);
	
	while ((vector[i].tracks)>25)
	{
		printf("\n El numero ingresado no cumple con las condiciones. Por favor, ingrese el numero de tracks que tendra el disco numero %d, recuerde que elmaximo de tracks es de 25: ", i+1);
		scanf("%d", &vector[i].tracks);	
	}
	return;
}
	

int carga(strEstructura vector[]) 
/*funcion que hace la carga pero ademas devuelve el largo del vector (maximo logico)
esto lo hacemos para aprovechar y recorrer el vector una sola vez */
{
	int i=0;
	int largo_vector;
	bool salida=false;

	while (!salida || i<mf)
	{
		ingreso_cod(vector, i);
		salida=chequeo_salida(vector, i);
		
		if (!salida || i<mf)
		{
			ingreso_titulo(vector, i);
		
			ingreso_tracks(vector, i);
		
			printf("\n Ingrese el precio para el disco numero %d: ", i+1);
			scanf ("\n%d", &vector[i].precio);	
		
		}
		
		i++;
	}
	
	largo_vector=i;
	
	return largo_vector;

}
	
//------------------------------ CARGA ----------------------------------------------//

//------------------------------ PRECIO MINIMO  ----------------------------------------------//

int precio_promedio(int largo_vector, strEstructura vector[] )
{
	int precio_total, res, i;
	
	for (i=0; i<=largo_vector; i++)
	{
		precio_total+=vector[i].precio;
	
	}
	
	res= (precio_total)/(largo_vector);
	
	
	return res;
}

//------------------------------ PRECIO MINIMO --------------------//
int pos_minimo(strEstructura vector[], int largo_vector)
{
	float min=vector[0].precio;
	int pos_minimo=0;
	int i;
	
	for (i=0; i<=largo_vector; i++)
	{
		if (vector[i].precio<min)
		{
			min=vector[i].precio;
			pos_minimo=i;
		}
	}

	return pos_minimo;
				
}	
//------------------------------ PRECIO MINIMO  ----------------------------------------------//
	
//------------------------------PRECIO MAXIMO  ----------------------------------------------//	
int pos_maximo (strEstructura vector[], int largo_vector)
{
	float max=vector[0].precio;
	int pos_maximo =0;
	int i;	
		
	for (i=0; i<=largo_vector; i++)
	{
		if (vector[i].precio>max)
		{
			max=vector[i].precio;
			pos_maximo =i;
		}
	}

	return pos_maximo ;

}	
//------------------------------ PRECIO MAXIMO  ----------------------------------------------//	

//------------------------------MOSTRAR  ----------------------------------------------// 	
void mostrar_datos(strEstructura vector[], int pos, char mensaje[40])
{
	//codigo
	printf("\n El codigo del disco %s es : %d \n", mensaje[40], vector[pos].cod);
	//posicion
	printf("\nEl %s se encontraba en la posicion %d del vector. \n", mensaje[40], pos);
	//titulo
	printf("\n El titulo del disco es: %s. \n", vector[pos].titulo);
	//tracks	
	printf ("\n El numero de tracks del disco de %s es : %d .", mensaje[40], vector[pos].tracks);
	//precio
	printf("\n El precio del disco %s es :%d .\n", mensaje[40], vector[pos].precio);
	return;
}
//------------------------------MOSTRAR  ----------------------------------------------//}


//------------------------------ ORDENAMIENTO  ----------------------------------------------//
void ordenar_vector(strEstructura vector[], int largo_vector)
{
	
	int i=0;
	int j,aux ;
	bool cambio=true;
	
	while (i<=largo_vector-1 && cambio)
	{	
		cambio=false;
		
		for (j=0; j<=largo_vector-i; j++)
			{
			if (vector[j].cod < vector[j+1].cod)
				{	
					cambio=true;
					aux= vector[j].cod ;
					vector[j].cod=vector[j+1].cod;
					vector[j+1].cod= aux;
				}		
			
			}	
	i++;
	}
	
	return; 	
}

void mostrar_datos_vector_ordenado(strEstructura vector, int largo_vector)
{
	int i;
	for (i=0; i<=mf; i++)
	{
		mostrar_datos (vector, i, "ordenado");
		
	}
	
	return;
}
//------------------------------ ORDENAMIENTO  ----------------------------------------------//

//------------------------------ BUSQUEDA BINARIA ----------------------------------------------//
int ingreso_busqueda_binaria(strEstructura vector[], int largo_vector)
{
	int inf=1;
	int max=largo_vector;
	int centro= (inf+max)/2;
	int dato;
	
	printf("Por favor, ingrese el numero a buscar: \n");
	scanf("%d", dato);
	
	
	while (inf <= sup)
	{
		if (vector[centro]==dato)
		{	
			printf ("\n El dato fue encontrado y su informacion es:  \n");
			mostrar_datos(vector[], centro, "solicitado" );
			return centro;
		}
		else
		{
			if (dato<vector[centro])
				sup=centro-1;
			else 
				inf=centro+1;
		}
		
	}
	
	printf("El valor no fue encontrado");
	return 0;
}


//------------------------------BUSQUEDA BINARIA  ----------------------------------------------//


//------------------------------ MAIN ----------------------------------------------//
int main()
{	int largoVector, posMaximo, posMinimo, precioPromedio;
	
	strEstructura vector[500];
	
	largoVector=carga(vector);	
	
	precioPromedio= precio_promedio(largoVector, vector);
	
	posMaximo= pos_maximo(vector, largoVector);
 	
	posMinimo= pos_minimo(vector, largoVector);
	
	//muestra los datos del precio maximo
	mostrar_datos(vector, posMaximo, "de precio maximo");	
	
	//muestra los datos del precio minimo
	mostrar_datos(vector, posMinimo, "de precio minimo"); 	
	
	ordenar_vector (vector, largoVector);
	
 	mostrar_datos_vector_ordenado(vector, largoVector);
	
	ingreso_busqueda_binaria(vector, largoVector);
	
	
	return 0;
}
