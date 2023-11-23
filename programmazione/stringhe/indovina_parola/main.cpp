#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "parole.h"

#define MAX_TENTATIVI 8

void inizializza(char cercata[], char lettere[], int lunghezza){
    for (int i = 0; i < lunghezza; ++i) {
        cercata[i] = '_';
    }
    cercata[lunghezza] = '\0';
    lettere[0] = '\0';
}

void stampa_parola_cercata(char parola[]){
    for (int i = 0; parola[i] != '\0' ; ++i) {
        printf("%c ", parola[i]);
    }
}

void stampa_lettere_provate(char parola[]){
    printf("%c", parola[0]);
    for (int i = 1; parola[i] != '\0' ; ++i) {
        printf(", %c", parola[i]);
    }
}

int indovinata(char parola[]){
    for (int i = 0; parola[i] != '\0' ; ++i) {
        if (parola[i] == '_')
            return 0;
    }
    return 1;
}

void aggiorna_parola(char cercata[], char segreta[], char lettera){
    for (int i = 0; segreta[i] != '\0'; ++i) {
        if (segreta[i] == lettera)
            cercata[i] = lettera;
    }
}

int main() {
    char parola_segreta[30], parola_cercata[30], lettere_provate[30];
    int tentativi = 0;
    char lettera;
    srand(time(NULL));
    strncpy(parola_segreta, parole[rand()%200], 30);
    inizializza(parola_cercata, lettere_provate, strlen(parola_segreta));
    printf("Indovina la parola\n");
    stampa_parola_cercata(parola_cercata);
    printf("\n");
    while(!indovinata(parola_cercata) && tentativi < MAX_TENTATIVI){
        printf("Tentativi numero %d\n", tentativi + 1);
        printf("Inserisci una lettera:\n");
        if(strlen(lettere_provate) != 0) {
            printf("Hai già provato queste lettere:");
            stampa_lettere_provate(lettere_provate);
            printf("\n");
        }
        scanf(" %c", &lettera);
        aggiorna_parola(parola_cercata, parola_segreta, lettera);
        tentativi++;
        int temp = strlen(lettere_provate);
        lettere_provate[temp] = lettera;
        lettere_provate[temp + 1] = '\0';
        stampa_parola_cercata(parola_cercata);
        printf("\n");
    }
    if (indovinata(parola_cercata)){
        printf("Bravo, hai indovinato in %d tentativi\n", tentativi);
    }
    else{
        printf("Peccato, la parola da indovinare era %s\n", parola_segreta);
    }
    return 0;
}
