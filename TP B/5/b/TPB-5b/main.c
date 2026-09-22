#include <stdio.h>
#include <stdlib.h>

void ordenarascendentemente(int * arreglo, int n){
    int cambiados;
    for(int i = 0; i < n-1; i++){
        cambiados = 0;
        for(int j = 0; j < n-1; j++){
            if(arreglo[j] > arreglo[j+1]){
                int aux = arreglo[j+1];
                arreglo[j+1] = arreglo[j];
                arreglo[j] = aux;
                cambiados = 1;
            }
        }
        if(cambiados == 0){
            break;
        }
    }
}

int main(){
    return 0;
}
