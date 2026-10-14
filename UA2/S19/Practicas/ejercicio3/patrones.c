#include <stdio.h>

int main() {
    // Declaración de variables enteras para las filas y las columnas
    int filas = 0, i = 0, j = 0;

    // Solicitar al usuario la cantidad de filas que tendrá el patrón
    printf("Cantidad de filas: ");
    scanf("%d", &filas);

    // Primer patrón: Triángulo de asteriscos
    // Ciclo externo para controlar el número de la fila actual
    for (i = 1; i <= filas; i++) {
        // Ciclo interno que se ejecuta tantas veces como el número de la fila actual (j <= i)
        for (j = 1; j <= i; j++) {
            printf("*"); // Imprimir un asterisco sin salto de línea
        }
        printf("\n"); // Salto de línea al terminar cada fila
    }

    // Segundo patrón: Triángulo de números secuenciales
    // Ciclo externo para controlar las filas
    for (i = 1; i <= filas; i++) {
        // Ciclo interno para imprimir los números desde 1 hasta el número de la fila actual (i)
        for (j = 1; j <= i; j++) {
            printf("%d", j); // Imprimir el valor actual de la columna j
        }
        printf("\n"); // Salto de línea al terminar cada fila
    }

    return 0; // Fin del programa
}