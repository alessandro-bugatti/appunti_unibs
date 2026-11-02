#include <iostream>

//Produce un numero casuale da 1 a n
int random(int n) {
    return rand() % n + 1;
}

//Produce un numero casuale compreso in un intervallo [a, b]
int random_intervallo(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int main() {

    std::cout << random(6) << std::endl;
    std::cout << random_intervallo(-898, 100) << std::endl;
    return 0;
}
