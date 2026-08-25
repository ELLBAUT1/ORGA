#include <stdio.h>

void millashakilometrosm(float millas){
    printf("%f millas/h corresponden a %f km/m", millas, (millas*1.60934)/60);
}

void main(){
    millashakilometrosm(100);
}
