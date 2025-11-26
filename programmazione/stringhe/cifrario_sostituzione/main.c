#include <stdio.h>

void codifica_sostituzione(char chiaro[], char cifrato[],
                                char chiave[]) {
    int i;
    for (i = 0; chiaro[i] != '\0' ; ++i) {
        int indice = chiaro[i] - 'a';
        cifrato[i] = chiave[indice];
    }
    cifrato[i] = '\0'; //"chiudiamo" la stringa
}

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

int cerca(char chiave[], char c) {
    for (int i = 0;  chiave[i] != '\0'; ++i) {
        if (chiave[i] == c) {
            return i;
        }
    }
}

void decodifica_sostituzione(char cifrato[], char chiaro[], char chiave[]) {
    int i;
    for (i = 0; cifrato[i] != '\0'; ++i) {
        int posizione = cerca(chiave, cifrato[i]);
        chiaro[i] = posizione + 'a';
    }
    chiaro[i] = '\0';
}

int main(void) {
    char chiave[] = "qwertyuioplkjhgfdsazxcvbnm";
    char chiaro[MAX], cifrato[MAX];
    printf("Inserisci il messaggio da cifrare: ");
    fgets(chiaro, MAX, stdin);
    pulisci_stringa(chiaro);
    codifica_sostituzione(chiaro, cifrato, chiave);
    printf("IL messaggio cifrato è \"%s\"\n", cifrato);
    decodifica_sostituzione(cifrato, chiaro, chiave);
    printf("IL messaggio decodificato è \"%s\"\n", chiaro);

    return 0;
}