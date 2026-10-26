/*
 * Enunciado: Escriba un programa en C que pida el nombre de 4 estudiantes y sus notas en 3 evaluaciones,
 * muestre una tabla con notas y promedios, promedios por evaluacion, el estudiante con mejor promedio,
 * y permita buscar un estudiante para indicar su condicion (APROBADO o NO APROBADO con nota >= 70).
 * Que se logra: Administrar y evaluar el rendimiento academico de un grupo pequeno de estudiantes.
 * Como se logra: Usando una matriz de enteros para las notas, un arreglo de cadenas para los nombres,
 * arreglos para los promedios, ciclos anidados para filas y columnas, y strcmp para busquedas.
 * Resultado esperado: Tabla de notas por estudiante con su promedio, promedios de cada evaluacion,
 * mejor estudiante y resultado de busqueda individual.
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    // notas: matriz de 4 filas (estudiantes) y 3 columnas (evaluaciones).
    int notas[4][3];
    // nombres: arreglo de cadenas para almacenar los nombres de los 4 estudiantes.
    char nombres[4][15];
    // prom_estudiante: arreglo para almacenar el promedio de cada estudiante.
    float prom_estudiante[4];
    // prom_evaluacion: arreglo para almacenar el promedio de cada evaluacion (columna).
    float prom_evaluacion[3];
    // condicion: cadena para almacenar la condicion del estudiante (APROBADO / NO APROBADO).
    char condicion[15];
    // busqueda: cadena para almacenar el nombre del estudiante a buscar.
    char busqueda[15];
    // i, j: variables de control para los ciclos.
    int i, j;
    // suma: acumulador para calculos.
    float suma;
    // mejor_estudiante: indice del estudiante con el mejor promedio.
    int mejor_estudiante = 0;
    // encontrado: bandera para indicar si el estudiante buscado fue hallado.
    int encontrado = 0;

    printf("=== Notas del grupo ===\n");

    // Pedir nombres y notas (0 a 100)
    for (i = 0; i < 4; i++) {
        printf("Nombre del estudiante %d: ", i + 1);
        scanf("%14s", nombres[i]);

        for (j = 0; j < 3; j++) {
            do {
                printf("Nota %d de %s: ", j + 1, nombres[i]);
                if (scanf("%d", &notas[i][j]) != 1) {
                    while (getchar() != '\n');
                    notas[i][j] = -1;
                }
            } while (notas[i][j] < 0 || notas[i][j] > 100);
        }
    }

    // Calcular promedio de cada estudiante (recorrido por filas)
    for (i = 0; i < 4; i++) {
        suma = 0.0;
        for (j = 0; j < 3; j++) {
            suma += notas[i][j];
        }
        prom_estudiante[i] = suma / 3.0;
    }

    // Encontrar el mejor promedio
    mejor_estudiante = 0;
    for (i = 1; i < 4; i++) {
        if (prom_estudiante[i] > prom_estudiante[mejor_estudiante]) {
            mejor_estudiante = i;
        }
    }

    // Calcular promedio de cada evaluacion (recorrido por columnas)
    for (j = 0; j < 3; j++) {
        suma = 0.0;
        for (i = 0; i < 4; i++) {
            suma += notas[i][j];
        }
        prom_evaluacion[j] = suma / 4.0;
    }

    // Mostrar tabla con nombre, tres notas y promedio
    printf("\nNombre\tN1\tN2\tN3\tPromedio\n");
    for (i = 0; i < 4; i++) {
        printf("%s\t%d\t%d\t%d\t%.2f\n", nombres[i], notas[i][0], notas[i][1], notas[i][2], prom_estudiante[i]);
    }

    // Mostrar promedios de evaluaciones y mejor promedio
    for (j = 0; j < 3; j++) {
        printf("Promedio de la evaluacion %d: %.2f\n", j + 1, prom_evaluacion[j]);
    }
    printf("Mejor promedio: %s (%.2f)\n", nombres[mejor_estudiante], prom_estudiante[mejor_estudiante]);

    // Buscar estudiante
    printf("Buscar estudiante: ");
    scanf("%14s", busqueda);

    encontrado = 0;
    for (i = 0; i < 4; i++) {
        if (strcmp(nombres[i], busqueda) == 0) {
            encontrado = 1;
            if (prom_estudiante[i] >= 70.0) {
                strcpy(condicion, "APROBADO");
            } else {
                strcpy(condicion, "NO APROBADO");
            }
            printf("%s: %.2f %s\n", nombres[i], prom_estudiante[i], condicion);
            break;
        }
    }

    if (!encontrado) {
        printf("Estudiante no encontrado.\n");
    }

    return 0;
}