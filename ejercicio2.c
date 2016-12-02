#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/** Variable global **/




float matriz[101][101];

float arbolOptimo(int numero, float * arregloProba){
	/** Variables **/
	
	int i;
	int d;
	int j;
	int k;
	int s;
	float valorMinimo;
	float suma;
	int numeroUtil = numero - 1;
	
	/**Empieza el algoritmo con los caso de borde**/

	for(i = 1; i <= numero; i++){
		matriz[i-1][i-1] = 0;
		
		matriz[i-1][i] = arregloProba[i-1];
	}
	
	matriz[numero][numero] = 0;

	
	
	for(d = 1; d <= numeroUtil; d++){
		
		for(i = 1; i <= numero - d; i++){
			
			j = i + d;
			
			valorMinimo = 1000000;
			for(k = i; k <= j ; k++){
				//printf("i - 1: %d\n  k - 1 : %d\n  k: %d\n  j:  %d\n",i-1,k-1,k,j);
				if(matriz[i-1][k-1] + matriz[k][j] < valorMinimo){
					
					valorMinimo = matriz[i-1][k-1] + matriz[k][j];
					
				}

			}
			

			/** Acá está el error **/

			suma = 0;
			
			for(s = i; s <= j; s++){
				suma += arregloProba[s-1];
			}
			
			/** Acá está el error **/

			matriz[i-1][j] = valorMinimo + suma;
		
		
		}
	

	}

	return matriz[0][numeroUtil];
}

int main(){
	float array[4];
	array[0] = 0.23;
	array[1] = 0.4;
	array[2] = 0.17;
	array[3] = 0.2;
	float resultado = arbolOptimo(5, array);
	printf("%.4f\n",resultado);
	return 0;
}