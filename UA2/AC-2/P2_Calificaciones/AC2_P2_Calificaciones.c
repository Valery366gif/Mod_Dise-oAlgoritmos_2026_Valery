/*
 * Enunciado: Validacion de calificaciones estudiantiles para un centro educativo.
 * Que se logra: Recibir tres calificaciones (0 a 100) en un arreglo, calcular el promedio, 
 *             encontrar la nota mas alta y determinar la condicion academica del estudiante.
 * Como se logra: Se solicita el nombre del estudiante con fgets. Se usa un ciclo for junto con 
 *                un do-while para ingresar y validar cada una de las 3 notas en el rango permitido. 
 *                Se recorre el arreglo para acumular la suma, calcular el promedio y hallar el maximo. 
 *                Se asigna la condicion usando strcpy segun el promedio obtenido.
 * Resultado esperado: Mostrar el reporte con el promedio con dos decimales, la nota mas alta y la condicion (APROBADO, EN RIESGO, NO APROBADO).
 */

#include <stdio.h>
#include <string.h>

#define NUM_NOTAS 3
#define NOTA_MIN 0.0
#define NOTA_MAX 100.0
#define PROMEDIO_APROBADO 70.0
#define PROMEDIO_RIESGO 60.0

int main() {
    char nombre[100];
    float notas[NUM_NOTAS];
    float suma = 0.0;
    float promedio = 0.0;
    float nota_alta = 0.0;
    char condicion[30];

    // Escribir el nombre del estudiante
    while (1) {
        printf("Nombre del estudiante: ");
        if (fgets(nombre, sizeof(nombre), stdin) != NULL) {
            nombre[strcspn(nombre, "\n")] = '\0';
            if (strlen(nombre) > 0) {
                break;
            }
        }
        printf("El nombre no puede estar vacio. Intente de nuevo.\n");
    }

    // Escribir tres calificaciones con validacion
    printf("=== Calificaciones del estudiante ===\n");
    for (int i = 0; i < NUM_NOTAS; i++) {
        do {
            printf("Calificacion %d (0 a 100): ", i + 1);
            if (scanf("%f", &notas[i]) != 1) {
                printf("Entrada invalida. Ingrese un numero.\n");
                while (getchar() != '\n');
                notas[i] = -1.0;
            } else if (notas[i] < NOTA_MIN || notas[i] > NOTA_MAX) {
                printf("Calificacion fuera de rango. Debe estar entre 0 y 100.\n");
            }
        } while (notas[i] < NOTA_MIN || notas[i] > NOTA_MAX);
    }

    // Calcular promedio y nota mas alta
    nota_alta = notas[0];
    for (int i = 0; i < NUM_NOTAS; i++) {
        suma += notas[i];
        if (notas[i] > nota_alta) {
            nota_alta = notas[i];
        }
    }
    promedio = suma / NUM_NOTAS;

    // Determinar condicion
    if (promedio >= PROMEDIO_APROBADO) {
        strcpy(condicion, "APROBADO");
    } else if (promedio >= PROMEDIO_RIESGO) {
        strcpy(condicion, "EN RIESGO");
    } else {
        strcpy(condicion, "NO APROBADO");
    }

    // Mostrar resultados
    printf("\nResultado\n");
    printf("Estudiante:\t\t%s\n", nombre);
    for (int i = 0; i < NUM_NOTAS; i++) {
        printf("Calificacion %d:\t\t%.1f\n", i + 1, notas[i]);
    }
    printf("Promedio:\t\t%.2f\n", promedio);
    printf("Nota mas alta:\t\t%.1f\n", nota_alta);
    printf("Condicion:\t\t%s\n", condicion);

    return 0;
}