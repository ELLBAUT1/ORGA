#include <stdio.h>
#include <stdlib.h>

//La primera variante no es posible desconocer el largo del arreglo

void reemplazar(int* arr, int a, int n, int size){
    for(int i = 0; i < size, i++){
        if(arr[i] == a){
            arr[i] = n;
        }
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
