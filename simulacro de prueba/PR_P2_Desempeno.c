/*
 ============================================================================
 Enunciado: Una empresa evalúa a sus colaboradores en tres criterios: puntualidad, 
            calidad y trabajo en equipo. El programa recibe el nombre y puntajes 
            (0 a 10) validando rangos, calcula el promedio, asigna un nivel de 
            desempeño (EXCELENTE, BUENO, NECESITA MEJORAR) e identifica el criterio 
            con el puntaje más bajo.
 Qué se logra: Evaluar de forma estructurada el rendimiento del personal 
               utilizando arreglos paralelos y algoritmos de búsqueda de mínimos.
 Cómo se logra: Empleando un arreglo de cadenas para los nombres de los criterios, 
                un arreglo numérico para los puntajes, validaciones con do-while, 
                cálculo de promedio aritmético y un recorrido para hallar el menor valor.
 Resultado esperado: Mostrar el nombre del colaborador, su promedio con dos decimales, 
                     el nivel de desempeño correspondiente y el criterio con menor nota.
 ============================================================================
*/

#include <stdio.h>
#include <string.h>

#define NUM_CRITERIOS 3

int main() {
    // Declaración de variables y arreglos
    char nombreColaborador[50];                     // Nombre del colaborador evaluado
    // Arreglo de cadenas con los nombres de los criterios de evaluación
    char *criterios[NUM_CRITERIOS] = {"puntualidad", "calidad", "trabajo en equipo"};
    double puntajes[NUM_CRITERIOS];                 // Arreglo para almacenar los puntajes de cada criterio
    double sumaPuntajes = 0.0;                      // Acumulador para calcular la sumatoria de puntajes
    double promedio = 0.0;                          // Promedio general de los puntajes
    int i;                                          // Variable de control para bucles
    int indiceMenor = 0;                            // Índice del criterio con el puntaje más bajo

    // Entrada de datos inicial
    printf("=== Evaluacion de desempeno ===\n");
    printf("Nombre del colaborador: ");
    scanf(" %[^\n]", nombreColaborador);

    // Lectura y validación de puntajes (0 a 10) para cada criterio
    for (i = 0; i < NUM_CRITERIOS; i++) {
        do {
            printf("Puntaje de %s (0 a 10): ", criterios[i]);
            scanf("%lf", &puntajes[i]);
            
            if (puntajes[i] < 0 || puntajes[i] > 10) {
                printf("Puntaje invalido, debe estar entre 0 y 10\n");
            }
        } while (puntajes[i] < 0 || puntajes[i] > 10);
        
        sumaPuntajes += puntajes[i];
    }

    // Cálculo del promedio
    promedio = sumaPuntajes / NUM_CRITERIOS;

    // Búsqueda del criterio con el puntaje más bajo
    for (i = 1; i < NUM_CRITERIOS; i++) {
        if (puntajes[i] < puntajes[indiceMenor]) {
            indiceMenor = i;
        }
    }

    // Salida de resultados
    printf("Colaborador: %s\n", nombreColaborador);
    printf("Promedio:\n%.2f\n", promedio);
    
    // Determinación del nivel de desempeño
    printf("Nivel:\n");
    if (promedio >= 9.0) {
        printf("EXCELENTE\n");
    } else if (promedio >= 7.0) {
        printf("BUENO\n");
    } else {
        printf("NECESITA MEJORAR\n");
    }

    // Mostrar el puntaje más bajo y el criterio asociado
    printf("Puntaje mas bajo: %s (%.1f)\n", criterios[indiceMenor], puntajes[indiceMenor]);

    return 0;
}