#include <stdio.h>

void encoding(char s[], char e[]) {
    int conta = 1, j = 0;
    for (int i = 0; s[i] != '\0' ; ++i) {
        if (s[i] == s[i+1]) {
            conta++;
            if (conta == 9) {
                e[j] = '9';
                e[j + 1] = s[i];
                conta = 2;
                j += 2;
            }
        }else {
            if (conta == 1) {
                e[j] = s[i];
                j++;
            } else {
                e[j] = conta + '0';
                e[j+1] = s[i];
                j += 2;
                conta = 1;
            }
        }
    }
    e[j] = '\0'; //dobbiamo terminarla
}

void decoding(char s[], char d[]) {
    int i = 0, j = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'a' && s[i] <= 'z') {
            d[j] = s[i];
            i++;
            j++;
        } else {
            int volte = s[i] - '0';
            for (int k = 0; k < volte; ++k) {
                d[j] = s[i + 1];
                j++;
            }
            i += 2;
        }
    }
    d[j] = '\0';
}

int main(void) {
    char s[] = "affgggggfgkkkkkkg", e[100], d[100];
    encoding(s, e);
    puts(e);
    decoding(e, d);
    puts(d);
    return 0;
}
