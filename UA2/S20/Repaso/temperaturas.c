/*
 * Enunciado: Escriba un programa en C que pida la temperatura maxima de cada dia de la semana,
 * calcule el promedio, encuentre el dia mas caluroso y muestre los dias que superaron el promedio.
 * Que se logra: Un control semanal de temperaturas maximas y un reporte estadistico basico.
 * Como se logra: Utilizando un arreglo de cadenas para los dias, un arreglo de flotantes para las 
 * temperaturas, validando rangos de 0 a 45, calculando promedios y buscando el indice de la temperatura maxima.
 * Resultado esperado: Muestra la temperatura de cada dia, el promedio general con dos decimales,
 * el dia mas caluroso y la lista de dias que superaron el promedio.
 */

#include <stdio.h>

int main(void) {
    // dias: arreglo bidimensional con las abreviaturas de los dias de la semana.
    char dias[7][4] = {"Lun", "Mar", "Mie", "Jue", "Vie", "Sab", "Dom"};
    // temp: arreglo unidimensional para almacenar la temperatura maxima de cada dia.
    float temp[7];
    // suma: acumulador para sumar las temperaturas y calcular el promedio.
    float suma = 0.0;
    // promedio: valor promedio de las temperaturas de la semana.
    float promedio = 0.0;
    // pos_mayor: indice del dia con la temperatura maxima.
    int pos_mayor = 0;
    // i: variable de control para los ciclos.
    int i;
    // contador_superan: cuenta cuantos dias superaron el promedio.
    int contador_superan = 0;

    printf("=== Temperaturas de la semana ===\n");

    // Pedir temperaturas con validacion de 0 a 45
    for (i = 0; i < 7; i++) {
        do {
            printf("Temperatura del %s (0 a 45): ", dias[i]);
            if (scanf("%f", &temp[i]) != 1) {
                while (getchar() != '\n'); // Limpiar buffer en entrada invalida
                temp[i] = -1;
            }
        } while (temp[i] < 0 || temp[i] > 45);
        suma += temp[i];
    }

    // Calcular promedio
    promedio = suma / 7.0;

    // Buscar el dia mas caluroso guardando su posicion
    pos_mayor = 0;
    for (i = 1; i < 7; i++) {
        if (temp[i] > temp[pos_mayor]) {
            pos_mayor = i;
        }
    }

    // Mostrar reporte de la semana
    printf("\n---- Reporte de la semana ----\n");
    for (i = 0; i < 7; i++) {
        printf("%s: %.1f C\n", dias[i], temp[i]);
    }
    printf("Promedio: %.2f C\n", promedio);
    printf("Mas caluroso: %s (%.1f C)\n", dias[pos_mayor], temp[pos_mayor]);

    // Mostrar dias que superaron el promedio
    printf("Sobre el promedio: ");
    for (i = 0; i < 7; i++) {
        if (temp[i] > promedio) {
            printf("%s ", dias[i]);
            contador_superan++;
        }
    }
    printf("(%d dias)\n", contador_superan);

    return 0;
}