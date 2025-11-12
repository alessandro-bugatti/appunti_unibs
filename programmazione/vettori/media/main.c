#include <stdio.h>
#include <stdlib.h>

const int MAX = 10000;

int main(void) {
    float reddito[MAX];
    float media, somma = 0;
    int N;
    printf("Quanti sono i redditi che vuoi inserire?");
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        reddito[i] = (rand() * 2) % 45001 + 5000;
        somma += reddito[i];
    }
    media = somma / N;
    int maggiori = 0, minori = 0;
    for (int i = 0; i < N; ++i) {
        if (reddito[i] > media) {
            maggiori++;
        }
        else {
            minori++;
        }
    }
    printf("I redditi maggiori della media sono %d e quelli minori sono %d\n", maggiori, minori);
    return 0;
}