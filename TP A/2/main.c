#include <stdio.h>
void convertirhora(long long segundos){
    printf("%lld segundos equivalen a %i:%i:%i hs", segundos, (segundos - ((segundos - (segundos % 60)) % 60)) /3600 , ((segundos - (segundos % 60)) / 60) % 60, segundos % 60);
}

int main(){
    convertirhora(8654);
    return 0;
}
