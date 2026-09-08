#include <stdio.h>

long long contardigitos(long long numero){
    if(numero/10 == 0){
        return 1;
    }
    else{
        return contardigitos(numero/10) + 1;
    }
}

void cantdigenposimpar(){
    long long numero;
    int largo = 0;
    int cant = 0;
    printf("Ingrese un número: ");
    scanf("%lld", &numero);
    largo = contardigitos(numero);
    if(largo % 2 == 1){
        cant = largo/2 + 1;
    }
    else{
        cant = largo/2;
    }
    printf("La cantidad de digitos en posiciones impares en el número %lld es: %i", numero, cant);
}

void main(){
    cantdigenposimpar();
}