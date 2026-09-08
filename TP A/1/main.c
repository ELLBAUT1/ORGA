#include <stdio.h>
#include <locale.h>
void validafecha(int dia, int mes, int anio){
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes ==12){
        if(dia >= 1 && dia <= 31){
            printf("La fecha es válida.\n");
        }
        else
            printf("La fecha es inválida.\n");
    }
    else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){

        if(dia >= 1 && dia <= 30){
            printf("La fecha es válida.\n");
        }
        else
            printf("La fecha es inválida.\n");
    }
    else if(mes == 2){
        int esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
        if (esBisiesto && dia >= 1 && dia <= 29) {
            printf("La fecha es válida.\n");
        } else if (!esBisiesto && dia >= 1 && dia <= 28) {
            printf("La fecha es válida.\n");
        } else {
            printf("La fecha es inválida.\n");
        }
    }
    else
        printf("La fecha es inválida.\n");
}

int main() {
    setlocale(LC_ALL, "");
    printf("Prueba 1 (20/8/2026): ");
    validafecha(20, 8, 2026);

    printf("Prueba 2 (31/4/2026): ");
    validafecha(31, 4, 2026);

    printf("Prueba 3 (29/2/2026): ");
    validafecha(29, 2, 2026);

    return 0;
}
