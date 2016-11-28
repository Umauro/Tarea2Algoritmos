#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int arbolOptimo(int, int*);

int arbolOptimo(int numero, int * arregloProba){
	/** Variables **/
	
	int i;
	int d;
	int j;
	int k;
	int s;
	int valorMinimo;
	int suma;
	int numeroUtil = numero - 1;

	/** Creación de matriz para utilizar el algoritmo **/
	int** matriz;
	matriz = (int **)malloc(sizeof(int *)*(numero));
	for(i=0;i < numero; i++){
		matriz[i] = (int *)malloc(sizeof(int)*(numero));
	}

	
	/**Empieza el algoritmo**/
	for(i = 0; i < numeroUtil; i++){
		matriz[i][i] = 0;
		
		matriz[i][i+1] = arregloProba[i];
	}
	
	matriz[numeroUtil][numeroUtil] = 0;


	for(d = 0; d < numeroUtil; d++){
		for(i = 0; i < numero-d; i++){
			j = i + d;
			valorMinimo = 1000000;
			for(k = i; k < j ; k++){
				if(matriz[i][k-1] + matriz[k+1][j] < valorMinimo){
					valorMinimo = matriz[i][k-1] + matriz[k+1][j];
					printf("Valor minimo: %d\n", valorMinimo);

				}
			}
			suma = arregloProba[i];
			for(s = i+1; s < j+1; s++){
				suma += arregloProba[s];
			}
			matriz[i][j] = valorMinimo + suma;
		}

	}
	return matriz[0][numeroUtil];
}

int main(){
	int array[3];
	array[0] = 0.33;
	array[1] = 0.34;
	array[2] = 0.33;
	int resultado = arbolOptimo(4, array);
	printf("%d\n",resultado);
	return 0;
}