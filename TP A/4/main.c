#include <stdio.h>
#include <limits.h>

void main(){
    long numero;
    long mayor = LONG_MIN;
    long menor = LONG_MAX;
    long suma = 0;
    int contador = 0;
    printf("Ingresa los numeros (Escribe una LETRA como 's' para terminar):\n");
    while(scanf("%ld", &numero) == 1){
        if(numero > mayor){
            mayor = numero;
        }
        if(numero < menor){
            menor = numero;
        }
        suma += numero;
        contador++;
    }

    if(contador > 0){
        printf("El menor es: %ld\n", menor);
        printf("El mayor es: %ld\n", mayor);
        printf("El promedio de la serie es: %.2f\n", (float)suma / contador);
    }
    else{
        printf("No se ingresaron numeros.");
    }
}
