#include <stdio.h>
#include <string.h>

#define MAX_APPUNTAMENTI 1000

typedef struct
{
    char codice_fiscale[17];
    char data[11];
    int ore;
    int minuti;
} Appuntamento;

typedef struct
{
    Appuntamento appuntamenti[MAX_APPUNTAMENTI];
    int n_appuntamenti;
} Registro;

int data_disponibile(const Registro *registro, char data[], int ore, int minuti) {
    for (int i = 0; i < registro->n_appuntamenti; ++i) {
        if (strncmp(registro->appuntamenti[i].data, data, 11) == 0) {
            if (registro->appuntamenti[i].ore == ore &&
                registro->appuntamenti[i].minuti == minuti) {
                return 0;
            }
        }
    }
    return 1;
}

void elimina_appuntamenti(Registro *registro, char codice_fiscale[]) {
    int j = 0;
    for (int i = 0; i < registro->n_appuntamenti; ++i) {
        if (strncmp(registro->appuntamenti[i].codice_fiscale, codice_fiscale, 17) != 0) {
            registro->appuntamenti[j] = registro->appuntamenti[i];
            j++;
        }
    }
    registro->n_appuntamenti = j;
}

int main(void) {
    printf("Hello, World!\n");
    return 0;
}