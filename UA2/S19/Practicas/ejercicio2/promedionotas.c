#include <stdio.h>

int main() {
    // Declaración de variables enteras para la cantidad y el índice del ciclo
    int cantidad = 0, i = 0;
    // Declaración de variables reales para la nota ingresada, la suma y el promedio
    float nota = 0, suma = 0, promedio = 0;

    // Validar con do-while que la cantidad de notas esté estrictamente entre 1 y 10
    do {
        printf("Cuantas notas (1 a 10): ");
        scanf("%d", &cantidad);
    } while (cantidad < 1 || cantidad > 10);

    // Ciclo for para recorrer y solicitar cada una de las notas según la cantidad indicada
    for (i = 1; i <= cantidad; i++) {
        // Validar con do-while que cada nota individual se encuentre entre 0 y 100
        do {
            printf("Nota %d (0 a 100): ", i);
            scanf("%f", &nota);
        } while (nota < 0 || nota > 100);

        // Acumular la nota válida en la variable suma
        suma += nota;
    }

    // Calcular el promedio dividiendo la suma total entre la cantidad de notas
    promedio = suma / cantidad;

    // Mostrar el resultado de la suma con dos decimales
    printf("Suma: %.2f\n", suma);
    // Mostrar el resultado del promedio con dos decimales
    printf("Promedio: %.2f\n", promedio);

    return 0; // Fin del programa
}