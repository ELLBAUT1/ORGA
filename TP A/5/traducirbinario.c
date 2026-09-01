#include <stdio.h>

void traducirbinario(long long binario) {
    long long copia_binario = binario;
    long long resultado = 0;
    long long multiplicador = 1;

    while (copia_binario > 0) {
        int digito = copia_binario % 10;
        resultado += digito * multiplicador;       
        copia_binario = copia_binario / 10;        
        multiplicador = multiplicador * 2;         
    }

    printf("El numero binario %lld corresponde al numero decimal %lld\n", binario, resultado);
}

int main() {
    long long numero_ingresado;
    
    printf("Ingrese un numero en notacion binaria: ");
    scanf("%lld", &numero_ingresado);
    
    traducirbinario(numero_ingresado);
    
    return 0;
}

