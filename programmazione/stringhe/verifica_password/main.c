#include <stdio.h>
#include <string.h>

const int DIM = 30;
const char SPECIALI[] = "^?&%$!#@";

int verifica_lunghezza(char s[], int min) {
    if (strlen(s) < min) {
        return 0;
    }
    return 1;
}

int verifica_cifra(char s[], int min) {
    int conta = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            conta++;
        }
    }
    if (conta < min) {
        return 0;
    }
    return 1;
}

/**
 * Controlla se c è presente in s
 * @param s stringa in cui cercare
 * @param c carattere da cercare
 * @return 1 se trovato, 0 altrimenti
 */
int in_stringa(char s[], char c) {
    for (int i = 0; s[i] != '\0'; ++i) {
        if (c == s[i]) {
            return 1;
        }
    }
    return 0;
}

int verifica_caratteri_speciali(char s[], int min) {
    int conta = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (in_stringa(SPECIALI, s[i])) {
            conta++;
        }
    }
    if (conta < min) {
        return 0;
    }
    return 1;
}

int main(void) {
    char password[DIM];
    printf("Inserisci la nuova password: ");
    scanf("%s", password);
    while (verifica_lunghezza(password, 8) == 0 ||
        verifica_cifra(password, 2) == 0 ||
        verifica_caratteri_speciali(password, 1) == 0) {
        printf("Non va bene, inserisci la nuova password: ");
        scanf("%s", password);
    }
    printf("La tua nuova password è %s\n", password);

    return 0;
}