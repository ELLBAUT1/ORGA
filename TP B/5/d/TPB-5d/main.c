#include <stdio.h>
#include <stdlib.h>

void intercalararreglos(int* arreglo1, int largo1, int* arreglo2, int largo2, int* arreglofinal){
    int indice1 = 0;
    int indice2 = 0;
    int indiceresult = 0;
    int numero1 = arreglo1[indice1];
    int numero2 = arreglo2[indice2];
    while(indice1 < largo1 && indice2 < largo2){
        numero1 = arreglo1[indice1];
        numero2 = arreglo2[indice2];
        if(numero1 < numero2){
            if(indiceresult == 0){
                arreglofinal[indiceresult] = numero1;
                indice1 += 1;
                indiceresult+= 1;
            }
            else{
                if(arreglofinal[indiceresult-1] != numero1){
                    arreglofinal[indiceresult] = numero1;
                    indiceresult+=1;
                }
                indice1 += 1;
            }
        }
        else if(numero1 == numero2){
            if(indiceresult == 0){
                arreglofinal[indiceresult] = numero1;
                indice1 += 1;
                indice2 += 1;
                indiceresult+= 1;
            }
            else{
                if(arreglofinal[indiceresult-1] != numero1){
                    arreglofinal[indiceresult] = numero1;
                    indiceresult+= 1;
                }
                indice1 += 1;
                indice2 += 1;
            }
        }
        else{
            if(indiceresult == 0){
                arreglofinal[indiceresult] = numero2;
                indice2 += 1;
                indiceresult+=1;
            }
            else{
                if(arreglofinal[indiceresult-1] != numero2){
                    arreglofinal[indiceresult] = numero2;
                    indiceresult+=1;
                }
                indice2 += 1;
            }
        }
    }
    if(indice1 != largo1){
        while(indice1 < largo1){
            numero1 = arreglo1[indice1];
            if(indiceresult == 0){
                arreglofinal[indiceresult] = numero1;
                indiceresult += 1;
            }
            else if(arreglofinal[indiceresult-1] != numero1){
                arreglofinal[indiceresult] = numero1;
                indiceresult += 1;
            }
            indice1 += 1;
        }
    }
    else if(indice2 < largo2){
        while(indice2 < largo2){
            numero2 = arreglo2[indice2];
            if(indiceresult == 0){
                arreglofinal[indiceresult] = numero2;
                indiceresult += 1;
            }
            else if(arreglofinal[indiceresult-1] != numero2){
                arreglofinal[indiceresult] = numero2;
                indiceresult += 1;
            }
            indice2 += 1;
        }
    }
}

int main(){

    return 0;
}
