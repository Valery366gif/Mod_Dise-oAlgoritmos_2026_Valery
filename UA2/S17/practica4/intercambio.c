#include <stdio.h>

int main(void) {
    // Declaración e inicialización de las variables a, b y auxiliar
    int a = 5, b = 9, aux;

    // Salida: muestra los valores antes del intercambio
    printf("Antes: a = %d b = %d\n", a, b);

    // Proceso: guarda el valor de a en aux
    aux = a;
    // Proceso: asigna el valor de b a a
    a = b;
    // Proceso: asigna el valor de aux (antiguo valor de a) a b
    b = aux;

    // Salida: muestra los valores después del intercambio
    printf("Despues: a = %d b = %d\n", a, b);

    return 0;
}