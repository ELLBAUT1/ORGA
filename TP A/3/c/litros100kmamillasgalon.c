#include <stdio.h>

void litros100kmamillasgalon(float litros){
    printf("%f litros cada 100 km corresponden a %f millas por galon", litros, (100/1.609344)/(litros*0.264172052));
}

void main(){
    litros100kmamillasgalon(100);
}
