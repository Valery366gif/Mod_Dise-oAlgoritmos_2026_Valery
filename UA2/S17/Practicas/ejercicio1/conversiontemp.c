// Convertir de grados Celcius o Fahrenheit 

#include <stdio.h>

int main() {
    // Declaración de variables para la temperatura en Celsius y Fahrenheit
    double celsius, fahrenheit;

    // ENTRADA: Solicitar la temperatura en grados Celsius al usuario
    printf("Temperatura en grados Celsius: ");
    scanf("%lf", &celsius);

    // PROCESO: Calcular la conversión de Celsius a Fahrenheit usando 9.0/5.0
    fahrenheit = celsius * 9.0 / 5.0 + 32;

    // SALIDA: Mostrar el resultado con un decimal
    printf("%.1f C equivalen a %.1f F\n", celsius, fahrenheit);

    return 0;
}