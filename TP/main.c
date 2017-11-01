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
	int precio;
}	strEstructura; 

//------------------------------ CARGA ----------------------------------------------//
bool chequeo_salida(strEstructura vector[], int i)  //Funcion usada para chequear el ingreso del usuario
{	
	bool salida;
	
	if ((vector[i].cod)==9999)
		salida=true;
	else 
		salida=false;
	
	return salida;
}

void ingreso_cod(strEstructura vector[], int i)
{	
	printf ("\n Ingrese un codigo entre 1000 y 8000 para el disco numero %d.\nIngrese 9999 para finalizar: ", i+1);
	scanf("%i", &vector[i].cod);
	
		while (vector[i].cod<1000 || vector[i].cod>8000 && vector[i].cod!=9999) 
		{
			printf ("\n El codigo no estaba en el rango indicado. Por favor, ingrese un codigo entre 1000 y 8000 para el disco numero %d: ", i+1);
			scanf("%i", &vector[i].cod);
		
		}
	
	return;
}
	
	
void ingreso_titulo(strEstructura vector[], int i)
{	
	int longitud;
	fflush(stdin);
	printf("\n Ingrese el titulo del disco numero %d, recuerde que el mismo debe tener un maximo de 30 caracteres : ", i+1);
	fgets (vector[i].titulo, 30, stdin);
	fflush(stdin);
	longitud=strlen(vector[i].titulo);
	
	while (longitud>30)
	{
		printf("\n Lo ingresado no cumplió con los requisitos pedidos. Por favor, ingrese el titulo del disco numero %d: ", i+1);
		fgets (vector[i].titulo, 30, stdin);
		longitud=strlen(vector[i].titulo);
		fflush(stdin);
	}
	
	return;	
}
	

void ingreso_tracks(strEstructura vector[], int i)
{
	printf("\n Ingrese el numero de tracks que tendra el disco numero %d, recuerde que un disco puede tener como maximo 25 tracks: ", i+1);
	scanf("%d", &vector[i].tracks);
	
	while ((vector[i].tracks)>25)
	{
		printf("\n El numero ingresado no cumple con las condiciones. Por favor, ingrese el numero de tracks que tendra el disco numero %d, recuerde que elmaximo de tracks es de 25: ", i+1);
		scanf("%d", &vector[i].tracks);	
	}
	return;
}

void ingreso_precio(strEstructura vector[], int i)
{
	printf("\n Ingrese el precio para el disco numero %d: ", i+1);
	scanf ("\n %i", &vector[i].precio);	
	
	return;
}
	

int carga(strEstructura vector[]) 
/*funcion que hace la carga pero ademas devuelve el largo del vector (maximo logico)
esto lo hacemos para aprovechar y recorrer el vector una sola vez */
{
	int i=0;
	int largo_vector;
	bool salida=false;

	while (!salida && i<mf)
	{
		ingreso_cod(vector, i);
		salida=chequeo_salida(vector, i);
		
		if (!salida && i<mf)
		{
			ingreso_titulo(vector, i);
		
			ingreso_tracks(vector, i);
		
			ingreso_precio(vector, i);
		
		}
		
		i++;
	}
	
	largo_vector=i-1;
	
	printf("\n La carga ha finalizado!\n");
	
	return largo_vector;

}
	
//------------------------------ CARGA ----------------------------------------------//

//------------------------------ PRECIO MINIMO  ----------------------------------------------//

int precio_promedio(strEstructura vector[], int largo_vector)
{
	int precio_total=0;
	int res;
	int i;
	
	for (i=0; i<largo_vector; i++)
	{
		precio_total+=vector[i].precio;
	}
	
	res=precio_total/largo_vector;
	
	
	return res;
}


//------------------------------PRECIO MAXIMO  ----------------------------------------------//	
int pos_maximo (strEstructura vector[], int largo_vector)
{
	float max=vector[0].precio;
	int pos_maximo =0;
	int i;	
		
	for (i=0; i<largo_vector; i++)
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

//------------------------------ PRECIO MINIMO --------------------//
int pos_minimo(strEstructura vector[], int largo_vector)
{
	float min=vector[0].precio;
	int pos_minimo=0;
	int i;
	
	for (i=0; i<largo_vector; i++)
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
	

//------------------------------MOSTRAR  ----------------------------------------------// 	
void mostrar_datos(strEstructura vector[], int pos, char *mensaje)
{
	//codigo
	printf("\n El codigo del disco %s es : %d. \n", mensaje, vector[pos].cod);
	//posicion
	printf("\n El %s se encontraba en la posicion %d del vector. \n", mensaje, pos);
	//titulo
	printf("\n El titulo del disco es: %s. ", vector[pos].titulo);
	//tracks	
	printf ("\n El numero de tracks del disco de %s es : %d . \n", mensaje, vector[pos].tracks);
	//precio
	printf("\n El precio del disco %s es :%d.\n", mensaje, vector[pos].precio);
	return;
}
//------------------------------MOSTRAR  ----------------------------------------------//}


//------------------------------ ORDENAMIENTO  ----------------------------------------------//
void ordenar_vector(strEstructura vector[], int largo_vector)
{
	
	int i = 0;
	int j, aux;
	bool cambio = true;
	
	while (i<=largo_vector-1 && cambio)
	{	
		cambio=false;
		
		for (j=0; j<=largo_vector-i; j++)
			{
			if (vector[j].cod > vector[j+1].cod)
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

void mostrar_datos_vector_ordenado(strEstructura vector[], int largo_vector)
{
	int i;
	for (i=0; i<largo_vector ; i++)
	{
		mostrar_datos(vector, i, "ordenado");
		
	}
	
	return;
}
//------------------------------ ORDENAMIENTO  ----------------------------------------------//

//------------------------------ BUSQUEDA BINARIA ----------------------------------------------//
int ingreso_busqueda_binaria(strEstructura vector[], int largo_vector)
{
	int inf = 0;
	int sup = largo_vector;
	int centro;
	int dato;
	bool bandera = false;
	int num;
	
	printf("si desea informacion de un CD en especial introdusca 1, si no introduaca otro numero: ");
	scanf("%i", &num);
		
	if(num == 1){
		
		printf("Por favor, ingrese el codigo del CD que buscar: \n");
		scanf("%d", &dato);
	
		while (inf <= sup)
		{
			centro = (inf+sup)/2;
		
			if ((vector[centro].cod) == dato)
			{	
				printf ("\n El dato fue encontrado y su informacion es:  \n");
				mostrar_datos(vector, centro, "solicitado" );
			
				return centro;
			
			}
			else
			{
				if (dato<vector[centro].cod)
					sup=centro-1;
				else 
					inf=centro+1;
			}
		
		}
		printf("El valor no fue encontrado\n");
	}

	
	return 0;
	
}

//------------------------------BUSQUEDA BINARIA  ----------------------------------------------//


//------------------------------CANTIDAD DE CD POR TRACKS---------------------------------------//
void cantidad_tracks(strEstructura vector[], int largoVector){
	
	int i, j, contador;
	
	for(i = 1; i <= 25; i++){
		
		contador = 0;
		
		for(j = 0; j <= largoVector; j++ ){
			
			if(vector[j].tracks == i){
				
				contador++;
				
			}
				
		}
		if(contador != 0)
			printf("Hay %i de CD con %i track.\n", contador, i);
		
	}
	return;
}
//------------------------------CANTIDAD DE CD POR TRACKS---------------------------------------//

//------------------------------ MAIN ----------------------------------------------//
int main()
{	int largoVector, posMaximo, posMinimo, precioPromedio, i;
	
	strEstructura vector[500];
	
	largoVector=carga(vector);
	
	for (i=0; i<largoVector; i++)
	{
		printf("Codigo del vector en la posicion %d:: %d \n", i, vector[i].precio);
	}
	
	precioPromedio= precio_promedio(vector, largoVector);
	
	printf("\n El precio promedio de los discos es de: %d.", precioPromedio);
	system("pause");
	
	printf("========================================================================");
	
	posMaximo= pos_maximo(vector, largoVector);
	
	printf("\n La posicion maxima es: %d. Sus datos son: \n", posMaximo);
	//muestra los datos del precio maximo
	mostrar_datos(vector, posMaximo, "de precio maximo");	
 	
	system("pause");
	
	printf("========================================================================");
	
	posMinimo= pos_minimo(vector, largoVector);
	
	printf("\n La posicion del minimo es: %d \n", posMinimo);
	
	//muestra los datos del precio minimo
	mostrar_datos(vector, posMinimo, "de precio minimo"); 	
	

	
	ordenar_vector (vector, largoVector);
	
	system("pause");
	
	printf("========================================================================");
	
 	mostrar_datos_vector_ordenado(vector, largoVector);
 	
 	system("pause");
	
	printf("========================================================================\n");
	
	ingreso_busqueda_binaria(vector, largoVector);
	
	printf("========================================================================\n");
	
	cantidad_tracks (vector, largoVector);
	
	
	return 0;
}
