#include <iso646.h>
#include <stdio.h>

#define L_MAX 100

/**
 *
 * @param s stringa da codificare
 * @param n di quante posizioni la lettera deve essere "spostata"
 */
void cifra(char s[], int n) {
    for (int i = 0; s[i] != '\0'; ++i) {
        s[i] = (((s[i] - 'a')  + n) % 26) + 'a';
    }
}

void pulisci(char originale[], char pulita[]) {
    int j = 0;
    for (int i = 0; originale[i] != '\0' ; ++i) {
        if (originale[i] >= 'a' && originale[i] <= 'z') {
            pulita[j] = originale[i];
            j++;
        }
        if (originale[i] >= 'A' && originale[i] <= 'Z') {
            pulita[j] = originale[i] - 'A' + 'a';
            j++;
        }
    }
    pulita[j] = '\0';
}

int main(void) {
    char frase[L_MAX], cifrata[L_MAX];
    int n = 3;
    printf("inserisci la frase da cifrare: ");
    fgets(frase, L_MAX, stdin);
    pulisci(frase, cifrata);
    printf("Stringa ripulita: %s", cifrata);
    cifra(cifrata, n);
    printf("Stringa cifrata: %s", cifrata);
    return 0;
}
