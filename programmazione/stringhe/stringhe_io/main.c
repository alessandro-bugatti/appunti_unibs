#include <stdio.h>

#define N 20

int main(void) {
    char s[N];
    printf("Inserisci una parola:");
    scanf("%s", s);
    printf("La parola inserita è %s\n", s);
    printf("Verifica del contenuto della stringa\n");
    for (int i = 0; i < N; ++i) {
        printf("%c -> %d\n", s[i], s[i]);
    }
    s[4] = 'a';
    printf("Stringa alterata dall'istruzione precedente: %s\n", s);
    return 0;
}
