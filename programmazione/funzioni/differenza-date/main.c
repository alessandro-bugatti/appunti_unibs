#include <stdio.h>

//La data zero per noi è il 1 gennaio 1900

/**
 *
 * @param a
 * @return 1 se l'anno è bisestile, 0 altrimenti
 */
int bisestile(int a) {
    if (a % 4 == 0 && a % 100 !=0 || a % 400 == 0) {
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

int giorni_per_mesi(int m, int a) {
    int giorni = 0;
    for (int i = 1; i < m; ++i) {
        giorni += giorni_del_mese(m, a);
    }
    return giorni;
}

int giorni_per_anni(int a) {
    int giorni = 0;
    for (int i = 1900; i < a; ++i) {
        giorni += 365 + bisestile(i);
    }
    return giorni;
    //return (a - 1900) * 365; //purtroppo non sempre corretta
}

int data_in_giorni(int g, int m, int a) {
    return giorni_per_anni(a) + giorni_per_mesi(m, a) + g;
}

int differenza_date(int g1, int m1, int a1,
                    int g2, int m2, int a2) {
    return data_in_giorni(g2, m2, a2) - data_in_giorni(g1, m1, a1);
}

int main(void) {
    printf("0 -> %d\n", differenza_date(2,11,2026, 2,11,2026));
    printf("1 -> %d\n", differenza_date(2,11,2026, 3,11,2026));
    printf("? -> %d\n", differenza_date(2,7,2018, 3,11,2026));

    return 0;
}
