#include <stdio.h>

int bisestile(int a) {
    if (a % 400 == 0) {
        return 1;
    }
    if (a % 100 == 0) {
        return 0;
    }
    if (a % 4 == 0) {
        return 1;
    }
    return 0;
}

int giorni_del_mese(int m, int a) {
    if (m == 2) {
        return 28 + bisestile(a);
    }
    if (m == 11 || m == 4 || m == 6 || m == 9) {
        return 30;
    }
    return 31;
}

/**
 * Questa funzione calcola il numero dei giorni che sono passati
 * a partire dal 1/1/1900 fino ad arrivare a g/m/a
 * @param g giorno
 * @param m mese
 * @param a anno
 * @return Il numero di giorni
 */
int giorni(int g, int m, int a) {
    //int g_anni = 365 * (a - 1); se non ci fossero i bisestili...
    int g_anni = 0;
    for (int i = 1900; i < a; ++i) {
        g_anni += 365 + bisestile(i);
    }
    //int g_mesi = 30 * (m -1); se tutti i mesi avessero 30 giorni...
    int g_mesi = 0;
    for (int i = 1; i < m; ++i) {
        g_mesi += giorni_del_mese(m, a);
    }
    return g_anni + g_mesi + g;
}

int differenza_date(int g1, int m1, int a1,
                    int g2, int m2, int a2) {
    return giorni(g2, m2, a2) - giorni(g1, m1, a1);
}

int main(void) {
    printf("%d\n", differenza_date(12, 2, 2024, 5, 11, 2025));
    return 0;
}