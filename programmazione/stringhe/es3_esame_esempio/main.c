#include <stdio.h>
#include <string.h>

/**
 *
 * @param s La stringa da invertire
 * @param n Solo i primi n caratteri
 */
void inverti(char s[], int n) {
    for (int i = 0; i < n / 2; ++i) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
}

void modifica(char S[], char N) {
    if (N > strlen(S)) {
        inverti(S, strlen(S));
    } else {
        inverti(S, N);
        inverti(&S[N], strlen(S) - N);
    }
}

int main(void) {
    char s[] = "capitolazione";
    modifica(s, 7);
    printf("%s\n", s);
    return 0;
}