#include <stdio.h>
#include <string.h>

#define MAX_UTENTI 10
#define MAX_LUNGHEZZA 30

int cerca(char s[], char m[][MAX_LUNGHEZZA], int righe) {
    for (int i = 0; i < righe; ++i) {
        if (strncmp(s,  m[i], MAX_LUNGHEZZA) == 0) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    char usernames[MAX_UTENTI][MAX_LUNGHEZZA];
    char passwords[MAX_UTENTI][MAX_LUNGHEZZA];
    int n_utenti = 0;
    int scelta;
    printf("Inserisci la tua scelta\n 1 - Registrati\n2 - Loggati\n0 - Esci");
    scanf("%d", &scelta);
    while (scelta != 0) {
        if (scelta == 1) {
            printf("Registrazione\nUsername: ");
            scanf("%s", usernames[n_utenti]);
            printf("Password: ");
            scanf("%s", passwords[n_utenti]);
            n_utenti++;
        }
        if (scelta == 2) {
            char username[MAX_LUNGHEZZA];
            char password[MAX_LUNGHEZZA];
            printf("Login\nUsername: ");
            scanf("%s", username);
            printf("Password: ");
            scanf("%s", password);
            int pos_user = cerca(username, usernames, n_utenti);
            int pos_pass = cerca(password, passwords, n_utenti);
            if ( pos_user == pos_pass && pos_user != -1) {
                char benvenuto[100];
                strncpy(benvenuto, "Ciao ", 100);
                strncat(benvenuto, username, 100 - strlen(benvenuto));
                printf("%s\n", benvenuto);
            }
            else {
                printf("Credenziali non corrette\n");
            }
        }
        printf("Inserisci la tua scelta\n 1 - Registrati\n2 - Loggati\n0 - Esci");
        scanf("%d", &scelta);
    }
    return 0;
}