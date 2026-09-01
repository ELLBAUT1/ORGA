#include <stdio.h>

long long mediano(long long numero, int cant){
    if(numero/10 == 0){
        if(cant % 2 == 0){
            return -numero;
        }
        else{
            return numero;
        }
    }
    else{
        if(cant % 2 == 0){
            return mediano(numero/10, cant+1) - (numero % 10);
        }
        else{
            return mediano(numero/10, cant+1) + (numero % 10);
        }
    }
}

int main(){
    long long numero = 0;
    long long median = 0;
    printf("Ingrese el numero a calcular su mediano: ");
    scanf("%lld", &numero);
    median = mediano(numero, 1);
    printf("El mediano del numero %lld es: %lld", numero, median);
}

/*
El problema del codigo era simplemento que al hacer cant++, el post incremento se resuelve luego de terminar la recursion, entonces siempre le pasaba el 1 a la nueva recursion
*/