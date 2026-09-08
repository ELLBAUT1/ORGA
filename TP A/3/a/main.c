#include <stdio.h>

void celciusafarenheit(float cel){
    printf("%f grados celcius corresponden a %f grados farenheit", cel, cel*33.8);
}

int main(){
    celciusafarenheit(102);
    return 0;
}
