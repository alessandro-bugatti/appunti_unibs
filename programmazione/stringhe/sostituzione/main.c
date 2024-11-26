#include <stdio.h>

void sostituzione (char s[], char chiave[]) {
    for (int i = 0; s[i] != '\0'; ++i) {
        s[i] = chiave[s[i] - 'a'];
    }
}

char cerca (char c, char chiave[]) {
    for (int i = 0; i < 26; ++i) {
        if (c == chiave[i]) {
            return i + 'a';
        }
    }
}

void decodifica (char s[], char chiave[]) {
    for (int i = 0; s[i] != '\0'; ++i) {
        s[i] = cerca(s[i], chiave);
    }
}

int main(void) {
    char s[] = "buongiorno";
    char chiave[] = "qazwscedvrfbtgnyhmujikolp";
    sostituzione(s, chiave);
    printf("%s \n", s);
    decodifica(s, chiave);
    printf("%s \n", s);
    return 0;
}