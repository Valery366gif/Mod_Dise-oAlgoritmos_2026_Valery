#include <stdio.h>

int main(void) {
    // Declaración de variable real para la nota
    double nota;

    // Solicita la nota al usuario
    printf("Nota (0 a 100): ");
    scanf("%lf", &nota);

    // Decisión anidada: valida el rango y clasifica el rendimiento
    if (nota < 0 || nota > 100) {
        printf("Nota invalida: debe estar entre 0 y 100\n");
    } else if (nota >= 70) {
        printf("Aprobado (%.1f)\n", nota);
    } else {
        printf("Reprobado (%.1f)\n", nota);
    }

    return 0;
}