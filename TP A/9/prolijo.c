#include <stdio.h>

int ascendente(long long numero){
    if(numero/10 == 0){
        return 1;
    }
    int ult = numero % 10;
    int antult = (numero / 10) % 10;
    if(antult == ult){
        return 0;
    }
    else{
        if(antult > ult){
            return ascendente(numero / 10)*1;
        }
        else{
            return 0;
        }
    }
}

int descendente(long long numero){
    if(numero/10 == 0){
        return 1;
    }
    int ult = numero % 10;
    int antult = (numero / 10) % 10;
    if(antult == ult){
        return 0;
    }
    else{
        if(antult < ult){
            return descendente(numero / 10);
        }
        else{
            return 0;
        }
    }
}

int prolijo(long long numero){
    if(numero/10 == 0){
        return 1;
    }
    else{
        int ult = numero % 10;
        int antult = (numero / 10) % 10;
        if(antult == ult){
            return 0;
        }
        else{
            if(antult > ult){
                return ascendente(numero / 10);
            }
            else{
                return descendente(numero/10);
            }
        }
    }
}

void main(){
 long long numero;
 int result = -1;
 printf("Ingrese un numero: ");
 scanf("%lld", &numero);
 result = prolijo(numero);
 if(result == 0){
    printf("El numero %lld no es prolijo", numero);
 }
 else{
    printf("El numero %lld es prolijo", numero);
 }
}