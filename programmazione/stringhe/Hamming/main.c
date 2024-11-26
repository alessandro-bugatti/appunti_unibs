#include <stdio.h>
#include <string.h>

int hamming (char s1[], char s2 []) {
    if (strlen(s1) != strlen(s2))
        return -1;
    int conta = 0;
    for (int i = 0; s1[i] != '\0'; ++i) {
        if ( s1[i] != s2[i])
            conta++;
    }
    return conta;
}

int main(void) {
    printf ( "%d\n", hamming("ciao","tiro"));

    return 0;
}