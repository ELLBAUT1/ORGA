#include <stdio.h>
#include <string.h>

int palindromo(char palabra[], int inicio, int final){
    if(inicio == final || inicio == final+1){
        return 1;
    }
    else{
        if(palabra[inicio] == palabra[final]){
            return palindromo(palabra, inicio+1, final-1);
        }
        else{
            return 0;
        }
    }
}

int main(){
    char palabra[200];
    printf("Ingrese la palabra a verificar: ");
    scanf("%s", palabra);
    int inicio = 0;
    int final = strlen(palabra)-1;
    int result = palindromo(palabra, inicio, final);
    if(result == 0){
        printf("La palabra no es palindroma.");
    }
    else{
        printf("La palabra es palindroma.");
    }
    return 0;
}
