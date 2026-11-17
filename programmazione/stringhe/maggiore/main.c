#include <stdio.h>
#include <string.h>

#define LUNGHEZZA 30
#define QUANTE 10


int main(void) {
    //Una matrice di caratteri
    //oppure un vettore di stringhe, con QUANTE stringhe, ognuna di lunghezza LUNGHEZZA
    char s[QUANTE][LUNGHEZZA];
    strncpy(s[0], "albero", LUNGHEZZA);
    strncpy(s[1], "marmellata", LUNGHEZZA);
    strncpy(s[2], "frutto", LUNGHEZZA);
    strncpy(s[3], "dado", LUNGHEZZA);
    int n = 4;
    char max[LUNGHEZZA];
    strncpy(max, s[0], LUNGHEZZA);
    for (int i = 0; i < n; ++i) {
        if (strncmp(s[i], max, LUNGHEZZA) > 0) {
            strncpy(max, s[i], LUNGHEZZA);
        }
    }
    printf("La parola che viene dopo è %s\n", max);
    return 0;
}
