#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mergeAcciones(int *bolsa, int izquierda, int derecha, int *maximo){
    if (izquierda == derecha){
        maximo[0] = izquierda;
        maximo[1] = derecha;
        maximo[2] = bolsa[izquierda];
        return;
    }

    int parteizquierda[3], partederecha[3];
    int mediana = (izquierda+derecha)/2;//, maximoizquierdo[3], maximoderecho[3];

    mergeAcciones(bolsa, izquierda, mediana, parteizquierda);
    mergeAcciones(bolsa, mediana + 1, derecha, partederecha);
    int temp[3] = {parteizquierda[0], parteizquierda[1], parteizquierda[2]};
    if (parteizquierda[2] > partederecha[2]){
        maximo[0] = parteizquierda[0];
        maximo[1] = parteizquierda[1];
        maximo[2] = parteizquierda[2];
    }
    else{
        maximo[0] = partederecha[0];
        maximo[1] = partederecha[1];
        maximo[2] = partederecha[2];
    }
    int i;
    for(i = parteizquierda[1] +1; i <= partederecha[0]; i++){
        if(i == partederecha[0]){
            temp[1] = partederecha[1];
            temp[2] += partederecha[2];
        }
        else{
            temp[1] = i;
            temp[2] += bolsa[i];
        }
        if(temp[2] >= maximo[2]){
                maximo[0] = temp[0];
                maximo[1] = temp[1];
                maximo[2] = temp[2];
        }
    }
    return;
}

int main(){
    char valor[100];
    int bolsa[100], i, counter;
    for(counter = 0; counter < 10000; counter++){
        fgets(valor, sizeof(valor), stdin);
        if(valor[0] == '\n'){
            break;
        }
        sscanf(valor, "%i", &i);
        bolsa[counter] = i;
        valor[0] = '\0';
    }
    int maximo[3];
    mergeAcciones(bolsa, 0, counter-1, maximo);
    printf("%i %i\n%i\n", maximo[0]+1, maximo[1]+1, maximo[2]);
    return 0;
}
