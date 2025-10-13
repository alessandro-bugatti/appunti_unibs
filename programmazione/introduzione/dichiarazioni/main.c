#include <stdio.h>

int main(void) {
    int a; //Dichiarazione di una variabile intera
    int b, c; //Dichiarazione di più variabili, il separatore è la virgola
    b = 5;
    c = 7;
    a = b + c;
    float f = 9.8773643786;
    double d = 9.83497239849;
    int g = b / 2; //g varrà due per il troncamento effettuato dalla divisione
    int h = b / 2.0; //h varrà due perchè nell'assegnamento il valore 2.5 viene troncato

    return 0;
}