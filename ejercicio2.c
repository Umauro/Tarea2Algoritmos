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
				
				if(matriz[i-1][k-1] + matriz[k][j] < valorMinimo){
					
					valorMinimo = matriz[i-1][k-1] + matriz[k][j];
					
				}

			}
			suma = 0;
			
			for(s = i; s <= j; s++){
				suma += arregloProba[s-1];
			}
			
			

			matriz[i-1][j] = valorMinimo + suma;
		}
	}

	return matriz[0][numeroUtil];
}

int main(){
	int i;
	int numeroNodos;
	int counter = 0;
	float array[101];
	float resultado;
	FILE * entrada = stdin;
	while(!(feof(entrada))){
		if(counter % 2 == 0){
			fscanf(entrada,"%d",&numeroNodos);
			counter++;
		}
		else if(counter % 2 == 1){
			for(i = 0; i < numeroNodos; i++){
				fscanf(entrada,"%f ",&array[i]);
			}
			resultado = arbolOptimo(numeroNodos + 1, array);
			printf("%.4f\n",resultado);
			counter++;
		}
	}
	
	return 0;
}