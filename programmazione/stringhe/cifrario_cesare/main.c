#include <stdio.h>

const int MAX = 200;

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


void codifica(char chiaro[], char cifrato[], int n) {
    int i;
    for (i = 0; chiaro[i] != '\0' ; ++i) {
        cifrato[i] = (chiaro[i] - 'a' + n ) % 26 + 'a';
    }
    cifrato[i] = '\0';

}

void decodifica(char cifrato[], char chiaro[], int n) {
    int i = 0;
    for (i = 0; cifrato[i] != '\0'; ++i) {
        chiaro[i] = (cifrato[i] - 'a' - n + 26) % 26 + 'a';
    }
    chiaro[i] = '\0';
}

int main(void) {
    char chiaro[MAX], cifrato[MAX], decifrato[MAX];
    int n = 7;
    printf("Inserisci il messaggio originale:");
    fgets(chiaro, MAX, stdin);
    pulisci_stringa(chiaro);
    codifica(chiaro, cifrato, n);
    printf("Messaggio codificato: %s\n", cifrato);
    decodifica(cifrato, decifrato, n);
    printf("Messaggio decodificato: %s\n", decifrato);
    return 0;
}