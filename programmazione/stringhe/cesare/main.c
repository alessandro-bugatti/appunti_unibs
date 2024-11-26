#include <stdio.h>

int is_alpha(char c) {
    if ((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z')) {
        return 1;
        }
    return 0;
}

char minuscolo(char c) {
    if (c >= 'A' && c <= 'Z' ) {
        c = c -'A' + 'a';
    }
    return c;
}

void pulisci_stringa(char s[]) {
    int j = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (is_alpha(s[i])) {
            s[j] = minuscolo(s[i]);
            j++;
        }
    }
    s[j] = '\0';
}

void cesare(char s[], int n) {
    for (int i = 0; s[i] != '\0'; i++) {
        //s[i] += n;
        s[i]= (s[i] - 'a' + n) % 26 + 'a';
    }
}

int main(void) {
    char s[] = "Andiamo in vallez";
    pulisci_stringa(s);
    printf("%s\n", s);
    cesare(s,13);
    printf("%s\n", s);
    return 0;
}