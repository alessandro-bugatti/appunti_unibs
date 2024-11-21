#include <stdio.h>

int is_hex_digit(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    if (c >= 'A' && c <= 'F') {
        return 1;
    }
    if (c >= 'a' && c <= 'f') {
        return 1;
    }
    return 0;
}

int is_hex(char s[]) {
    if (s[0] != '0') {
        return 0;
    }
    if (!(s[1] == 'x' || s[1] == 'X')) {
        return 0;
    }
    int n_caratteri = 0;
    int i = 0;
    while (s[i] != '\0') {
        n_caratteri++;
        i++;
    }
    if (n_caratteri > 10) {
        return 0;
    }
    for(int i = 2; s[i] != '\0'; ++i) {
        if (!is_hex_digit(s[i])) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    char s1[] = "0xFF134422";
    char s2[] = "0xFF1G4422";
    char s3[] = "0FF1422";
    char s4[] = "0xF14222222222";

    if(is_hex(s2)) {
        printf("%s è un numero esadecimale\n", s2);
    }
    else {
        printf("%s non è esadecimale\n", s2);
    }

    return 0;
}
