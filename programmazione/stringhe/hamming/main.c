#include <stdio.h>
#include <string.h>

/**
 * Calcola la distanza di Hamming tra due stringhe s1 e s2
 * @param s1
 * @param s2
 * @return -1 se non hanno la stessa lunghezza, la distanza di Hamming negli altri casi
 */
int hamming(char s1[], char s2[]) {
    if (strlen(s1) != strlen(s2)) {
        return -1;
    }
    int conta = 0;
    for (int i = 0; s1[i] != '\0'; ++i) {
        if (s1[i] != s2[i]) {
            conta++;
        }
    }
    return conta;
}

int main(void) {
    char s1[] = "tavolino";
    char s2[] = "Casetta";
    char s3[] = "casette";
    printf("Confronto tra %s e %s -> %d\n", s1, s2, hamming(s1, s2));
    printf("Confronto tra %s e %s -> %d\n", s2, s3, hamming(s2, s3));
    return 0;
}