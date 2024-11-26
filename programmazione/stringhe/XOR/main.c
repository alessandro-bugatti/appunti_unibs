#include <stdio.h>

void xor(char s[]) {
    for (int i=0; s[i] != '\0'; ++i) {
        s[i] = s[i] ^ 0x5A;
    }
}

int main(void) {
    char s[] = "ciao a tutti";
    xor(s);
    printf("%s\n", s);
    xor(s);
    printf("%s\n", s);
    return 0;
}