#include <stdio.h>

/**
 * Verifica se una stringa è palindroma
 * @param s
 * @param inizio
 * @param fine
 * @return 1 se è palindroma, 0 se non lo è
 */
int palindroma(char s[], int inizio, int fine){
    int i = inizio;
    int j = fine;
    while (i < j){
        if (s[i] != s[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int trova_spazio(char s[], int inizio){
    int i = inizio;
    while(s[i] != ' '){
        i++;
    }
    return i;
}

int main() {
    char s[1001];
    printf("Inserisci una frase terminata da uno spazio.");
    fgets(s, 1000, stdin);
    int inizio, fine, conta = 0;
    inizio = 0;
    fine = trova_spazio(s, inizio) - 1;
    while (s[inizio] != '\0'){
        conta += palindroma(s, inizio, fine);
        inizio = fine + 2;
        if (s[fine] != '\0')
            fine = trova_spazio(s, inizio) - 1;
    }
    printf("Ci sono %d parole palindrome.\n", conta);
    return 0;
}
