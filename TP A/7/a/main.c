#include <stdio.h>

long long contardigitos(long long numero){
    if(numero/10 == 0){
        return 1;
    }
    else{
        return contardigitos(numero/10) + 1;
    }
}

void main(){
    long long numero;
    printf("Ingrese un numero: ");
    scanf("%lld", &numero);
    long long cant = contardigitos(numero);
    printf("La cantidad de digitos del numero %lld es: %lld", numero, cant);
}