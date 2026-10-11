#include <stdio.h>

int main(void) {
    // Declaración de variables reales para celsius y fahrenheit
    double celsius, fahrenheit;

    // Solicita al usuario la temperatura en grados Celsius
    printf("Temperatura en grados Celsius: ");
    // Lee el valor ingresado como double
    scanf("%lf", &celsius);

    // Proceso: convierte celsius a fahrenheit usando 9.0/5.0
    fahrenheit = celsius * 9.0 / 5.0 + 32;

    // Salida: muestra el resultado con un decimal
    printf("%.1f C equivalen a %.1f F\n", celsius, fahrenheit);

    return 0;
}