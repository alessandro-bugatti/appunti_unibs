#include <stdio.h>
#include <string.h>

const int MAX = 100;
const int RIGHE = 10;

int trova_carattere(char s[], char c) {
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == c) {
            return i;
        }
    }
    return -1;
}

int conta_carattere(char s[], char c) {
    int conta = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == c) {
            conta++;
        }
    }
    return conta;
}

/**
 * Regole di validità
 * - un solo carattere @
 * - il dominio deve essere unibs.it
 * @param s L'indirizzo email da controllare
 * @return 1 se è valido, 0 altrimenti
 */
int email_valida(char s[]) {
    if (conta_carattere(s, '@') != 1) {
        return 0;
    }
    int posizione_chiocciola = trova_carattere(s, '@');
    if (strncmp("unibs.it", &s[posizione_chiocciola + 1], strlen(&s[posizione_chiocciola + 1])) != 0) {
        return 0;
    }
    return 1;
}

int quanti_validi(char emails[][MAX], int n) {
    int conta = 0;
    for (int i = 0; i < n; ++i) {
        if (email_valida(emails[i])) {
            conta++;
        }
    }
    return conta;
}

int main(void) {
    char emails[RIGHE][MAX];
    int n_emails = 3;
    //Pezzo di codice di test, non serve al programma,
    //è solo una verifica
    printf("Controlla ale@unibs.it %d\n", email_valida("ale@unibs.it"));
    printf("Controlla ale@unibs@it %d\n", email_valida("ale@unibs@it"));
    printf("Controlla ale@unipd.it %d\n", email_valida("ale@unipd.it"));
    for (int i = 0; i < n_emails; ++i) {
        printf("Inserisci l'indirizzo email: ");
        scanf("%s", emails[i]);
    }
    int validi = quanti_validi(emails, n_emails);
    printf("Gli indirizzi validi erano %d\n", validi);
    return 0;
}