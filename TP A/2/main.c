#include <stdio.h>
void convertirhora(long segundos){
    printf("%l segundos equivalen a %i:%i:%i hs", (segundos - ((segundos - (segundos % 60)) % 60)) /3600 , ((segundos - (segundos % 60)) / 60) % 60, segundos % 60);
}

void main(){
    convertirhora(8654);
}
