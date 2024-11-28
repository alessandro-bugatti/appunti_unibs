#include <stdio.h>
#include <string.h>

char cifre[][100] = {
    "one",
    "two"
};

int main(void) {
    char s[] = "two1nine";
    for (int i = 0; i < 2; ++i) {
        if (strncmp(cifre[i], s, strlen(cifre[i])) == 0) {
            printf("%i\n", i + 1);
        }
    }
    return 0;
}