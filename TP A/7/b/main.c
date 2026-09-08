#include <stdio.h>

int cantvecesnend(long long numero, int d){
    if(numero / 10 == 0){
        if(numero ==     d){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(numero % 10 == d){
            return cantvecesnend(numero/10, d)+1;
        }
        else{
            return cantvecesnend(numero/10, d);
        }
    }
}

void main(){
    int cant = 0;
    long long numero;
    int d;
    printf("Ingrese el numero a revisar: ");
    scanf("%lld", &numero);
    printf("Ingrese el digito a buscar: ");
    scanf("%i", &d);
    cant = cantvecesnend(numero, d);
    printf("La cantidad de veces que esta el digito %i en el numero %lld es: %i", d, numero, cant);
}