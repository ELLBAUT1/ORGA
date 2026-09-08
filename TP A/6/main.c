#include <stdio.h>

int hexadecimalaentero(){
    long long resultado = 0;
    char c;
    printf("Ingrese la entrada hexadecimal: \n");
    while( (c = getchar()) != '\n'){
        switch(c){
            case '0': { resultado = resultado * 16 + 0; break;}
            case '1': { resultado = resultado * 16 + 1; break;}
            case '2': { resultado = resultado * 16 + 2; break;}
            case '3': { resultado = resultado * 16 + 3; break;}
            case '4': { resultado = resultado * 16 + 4; break;}
            case '5': { resultado = resultado * 16 + 5; break;}
            case '6': { resultado = resultado * 16 + 6; break;}
            case '7': { resultado = resultado * 16 + 7; break;}
            case '8': { resultado = resultado * 16 + 8; break;}
            case '9': { resultado = resultado * 16 + 9; break;}
            case 'A': 
            case 'a': {resultado = resultado * 16 + 10;break;}
            case 'B':
            case 'b': {resultado = resultado * 16 + 11;break;}
            case 'C':
            case 'c': {resultado = resultado * 16 + 12;break;}
            case 'D':
            case 'd': {resultado = resultado * 16 + 13;break;}
            case 'E':
            case 'e': {resultado = resultado * 16 + 14;break;}
            case 'F':
            case 'f': {resultado = resultado * 16 + 15;break;}
        }
    }
    printf("El resultado es: %lld", resultado);
}

int main(){
    hexadecimalaentero();
}