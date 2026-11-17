#include <stdio.h>
#include <string.h>

#define P 10
#define L 30

/**
 * Una password è valida se
 * - lunghezza minima 10
 * - almeno un carattere maiuscolo
 * - almeno un carattere minuscolo
 * - almeno un carattere speciale (!#?!^[])
 */

int lunghezza_corretta(char p[]) {
    if (strlen(p) >= 10) {
        return 1;
    }
    return 0;
}

int carattere_maiuscolo(char p[]) {
    for (int i = 0; p[i] != '\0' ; ++i) {
        if (p[i] >= 'A' && p[i] <= 'Z') {
            return 1;
        }
    }
    return 0;
}

int carattere_minuscolo(char p[]) {
    for (int i = 0; p[i] != '\0' ; ++i) {
        if (p[i] >= 'a' && p[i] <= 'z') {
            return 1;
        }
    }
    return 0;
}

int appartiene(char s[], char c) {
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == c) {
            return 1;
        }
    }
    return 0;
}

int carattere_speciale(char p[]) {
    char speciali[] = "!#?!^[]";
    for (int i = 0; p[i] != '\0'; ++i) {
        if (appartiene(speciali, p[i])) {
            return 1;
        }
    }
    return 0;
}


int password_corretta(char p[]) {
    if (lunghezza_corretta(p) &&
        carattere_maiuscolo(p) &&
        carattere_minuscolo(p) &&
        carattere_speciale(p)) {
        return 1;
        }
    return 0;
}



int main(void) {
    char passwords[P][L];
    for (int i = 0; i < 5; ++i) {
        printf("Inserisci la password %d\n", i + 1);
        scanf("%s", passwords[i]);
    }
    int conta = 0;
    for (int i = 0; i < 5; ++i) {
        if (password_corretta(passwords[i])) {
            conta++;
        }
    }
    printf("Sono state inserite %d password corrette.\n", conta);
    return 0;
}
