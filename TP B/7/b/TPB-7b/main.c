#include <stdio.h>
#include <stdlib.h>

void invertir_arr_punt(int * arr[], int size){
    int inicio =0;
    int cola = size - 1;
    int * aux;
    while(inicio != cola){
        aux = arr[inicio];
        arr[inicio] = arr[cola];
        arr[cola] = aux;
        if ((++inicio)!=cola)
            cola--;
    }
}

int main()
{

}
