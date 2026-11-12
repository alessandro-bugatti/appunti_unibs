#include <stdio.h>

#define N 100

int main(void) {
    char s[N];
    printf("Inserisci una frase: ");
    fgets(s, N, stdin);
    printf("Hai inserito la frase %s\n", s);
    //La fgets può leggere qualsiasi cosa, se però fosse un numero, la conversione andrebbe "fatta a mano"
    int n = 0;
    for (int i = 0; s[i+1] != '\0'; ++i) {
        printf("%c -> %d\n", s[i], s[i]);
        n = n * 10 + (s[i] - '0');
    }
    printf("%d\n", n);

    return 0;
}
