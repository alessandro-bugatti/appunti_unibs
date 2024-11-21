#include <stdio.h>

int is_alpha(char c) {
    if ((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z')) {
        return 1;
    }
    return 0;
}

void pulisci_stringa(char s[]) {
    int j = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (is_alpha(s[i])) {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
}

int main(void)
{
    char s[] = "Hello, World!";
    pulisci_stringa(s);
    printf("Stringa pulita: %s\n", s);
    return 0;
}
