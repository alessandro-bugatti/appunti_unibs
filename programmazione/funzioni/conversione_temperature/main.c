#include <stdio.h>

//c2k versione ultracompatta in inglese
float da_celsius_a_kelvin(float celsius) {
    return celsius + 273.15;
}

float da_kelvin_a_celsius(float kelvin) {
    return kelvin - 273.15;
}

int main(void) {
    float c = 16.8;
    printf("La temperatura in Celsius di %.1f° in gradi Kelvin è %.1f°\n",
        c, da_celsius_a_kelvin(c));
    printf("La temperatura in Kelvin di %.1f° in gradi Celsius è %.1f°\n",
        c, da_kelvin_a_celsius(c));
    printf("La temperatura in Kelvin di %.1f° in gradi Celsius è %.1f°\n",
        da_celsius_a_kelvin(c), da_kelvin_a_celsius(da_celsius_a_kelvin(c)));
    return 0;
}
