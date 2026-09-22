#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializarprimerosn(int* arreglo, int n){
    for(int i = 0; i < n; i++){
        arreglo[i] = rand();
    }
}

int main(){
    srand(time(NULL));
    int n;
    printf("Ingrese el largo del arreglo: \n");
    scanf("%i", &n);
    int arreglo[n];
    inicializarprimerosn(arreglo, n);
    printf("El arreglo se inicializó así: \n");
    for(int i = 0; i < n; i++){
        printf("valor %i\n", arreglo[i]);
    }
    return 0;
}
