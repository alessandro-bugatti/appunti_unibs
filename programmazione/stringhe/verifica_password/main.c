#include <stdio.h>
#include <string.h>

const int DIM = 30;

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


int main(void) {
    char password[DIM];
    printf("Inserisci la nuova password: ");
    scanf("%s", password);
    while (verifica_lunghezza(password, 8) == 0 ||
        verifica_cifra(password, 1) == 0) {
        printf("Non va bene, inserisci la nuova password: ");
        scanf("%s", password);
    }
    printf("La tua nuova password è %s\n", password);

    return 0;
}