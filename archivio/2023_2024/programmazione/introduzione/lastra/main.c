#include <stdio.h>

int main() {
    float b,h;
    float lato=0;
    float  volume;
    float volumeMax=0, latoMax=0;


    printf("inserisci la base:");
    scanf("%f",&b);

    printf("inserisci la altezza:");
    scanf("%f",&h);

    while (lato < h/2){
        lato+=1;
        volume=lato*(b-2*lato)*(h-2*lato);
        //printf("volume: %f\n",volume);
        if(volume > volumeMax){
            volumeMax=volume;
            latoMax=lato;
        }

    }
    printf("il lato ottimo é di %f mm \n",latoMax);


    return 0;
}
