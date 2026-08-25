#include <stdio.h>

void traducirbinario(int binario){
    int numero = binario / 10;
    int resultado = 0;
    while (numero > 0){
        resultado++;
        numero /= 10;
    }
    printf("El numero binario %i corresponde al numero decimal %i", binario, resultado);
}

void main(){
    traducirbinario(1111111111);
}