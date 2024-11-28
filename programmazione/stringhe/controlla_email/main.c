#include <stdio.h>
#include <string.h>

int conta_carattere(char s[], char c) {
    int conta = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == c) {
            conta++;
        }
    }
    return conta;
}

int is_lettera(char c) {
    if (c >= 'A' && c <= 'Z' ||
        c >= 'a' && c <= 'z') {
        return 1;
    }
    return 0;
}

int trova_carattere(char s[], char c) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return i;
        }
    }
    return -1;
}

int email_valido(char s[]) {
    //Verifica che ci sia solo una @
    if (conta_carattere(s, '@') != 1) {
        return 0;
    }
    //verifica che ci sia almeno un carattere prima della @
    if (trova_carattere(s, '@') <= 0) {
        return 0;
    }
    //verifica che il primo carattere sia una lettera
    if (!is_lettera(s[0])) {
        return 0;
    }
    int posizione_chiocciola = trova_carattere(s, '@');
    //Controlla che ci sia un solo punto dopo la @
    //if (conta_carattere(s + posizione_chiocciola + 1, '.') != 1) {
    if (conta_carattere(&s[posizione_chiocciola + 1],'.') != 1 ) {
        return 0;
    }
    //controlla che il punto non sia nella prima posizione dopo la @
    if (s[posizione_chiocciola + 1] == '.') {
        return 0;
    }
    //verifica che l'ultimo carattere non sia un punto
    if (s[strlen(s) - 1] == '.') {
        return 0;
    }
    //verifica che il punto sia in terzultima o quartultima posizione
    int posizione_punto = trova_carattere(&s[posizione_chiocciola + 1],'.');
    if (posizione_punto < strlen(&s[posizione_chiocciola + 1]) - 4 ||
        posizione_punto > strlen(&s[posizione_chiocciola + 1]) - 3) {
        return 0;
    }
    return 1;

}

int main(void) {
    char s[][50] = {
        "ale@ale.com@ale.it",
        "ale.it",
        "@ale.comale.it",
        "ale@",
        "ale@ale.com.it",
        "ale@alessandro.",
        "ale@.alessandro",
        "ale@aleco.m",
        "ale@alessandro.italia",
        "ale@ale.com",
        "ale@ale.it",

    };

    for (int i = 0; i < 11; ++i) {
        printf("%s -> %d\n", s[i], email_valido(s[i]));
    }
    return 0;
}