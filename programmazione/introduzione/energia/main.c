#include <stdio.h>

/*
 * Programma per il calcolo dell'energia cinetica e potenziale
 * Esercizio https://github.com/alessandro-bugatti/esercizi/tree/master/programmazione_C/sequenza/energia_meccanica
 */

int main(void)
{
    float m, v0, h0, t;
    float T, U, vt, ht;
    //Dichiarazione di una variabile costante
    const float G = 9.81;
    printf("Inserisci la massa: ");
    scanf("%f", &m);
    printf("Inserisci la velocità iniziale: ");
    scanf("%f", &v0);
    printf("Inserisci l'altezza iniziale: ");
    scanf("%f", &h0);
    printf("Inserisci il tempo: ");
    scanf("%f", &t);
    //Vedi libro di fisica Amaldi V1 p.232
    vt = v0 - (G * t);
    ht = h0 + v0*t - 0.5*G*t*t;
    T = 0.5 * m * vt * vt;
    U = m * G * ht;
    printf("L'energia cinetica all'istante %.3f vale %.3f\n", t, T);
    printf("L'energia potenziale all'istante %.3f vale %.3f\n", t, U);
    return 0;
}
