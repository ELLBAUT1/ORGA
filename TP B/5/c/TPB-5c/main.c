#include <stdio.h>
#include <stdlib.h>

int determinarascendente(int * arreglo, int n){
    for(int i = 0; i < n-1; i++){
        if(arreglo[i] > arreglo[i+1]){
            return 0;
        }
    }
    return 1;
}

int main(){

}
