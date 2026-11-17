#include <stdio.h>

#define N 100

/**
 *
 * @param s la frase
 * @return Il numero di lettere della parola più lunga nella frase
 */
int parola_lunga(char s[]) {
    int conta = 0, max = 0;
    for (int i = 0; s[i] != '\0' ; ++i) {
        conta++;
        if (s[i] == ' ') {
            if (conta - 1 > max) {
                max = conta - 1;
            }
            conta = 0;
        }
    }
    if (conta > max) {
        max = conta;
    }
    return max;
}

int main(void) {
    char s1[N], s2[N];
    printf("Inserisci la prima frase: ");
    fgets(s1, N, stdin);
    printf("Inserisci la seconda frase: ");
    fgets(s2, N, stdin);
    printf("La frase con la parola più lunga è la ");
    if (parola_lunga(s1) > parola_lunga(s2)) {
        printf("prima\n");
    }else {
        printf("seconda");
    }
    return 0;
}
