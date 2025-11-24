#include <stdio.h>

char minuscolo(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a';
    }
    return c;
}

int carattere(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    return 0;
}

void pulisci_stringa(char s[]) {
    int j = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        char c = minuscolo(s[i]);
        if (carattere(c) == 1) {
            s[j] = c;
            j++;
        }
    }
    s[j] = '\0';
}

int main(void) {
    char s[] = "Hello, World!";
    pulisci_stringa(s);
    printf("%s\n", s);
    return 0;
}