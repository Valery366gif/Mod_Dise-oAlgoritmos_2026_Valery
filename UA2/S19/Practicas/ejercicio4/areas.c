#include <stdio.h>

// Definición de la constante PI para el cálculo del círculo
#define PI 3.14159265358979323846

int main() {
    // Declaración de variable entera para almacenar la opción del menú
    int opcion = 0;
    // Declaración de variables reales para las dimensiones geométricas de las figuras
    float lado = 0, base = 0, altura = 0, radio = 0;

    // Ciclo do-while para mantener el menú activo hasta que el usuario elija salir (opción 0)
    do {
        // Mostrar las opciones disponibles en la terminal
        printf("1. Cuadrado 2. Rectangulo 3. Circulo 0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        // Estructura switch para bifurcar la ejecución según la opción seleccionada
        switch (opcion) {
            case 1:
                // Cálculo del área del cuadrado
                printf("Lado: ");
                scanf("%f", &lado);
                printf("Area: %.2f\n", lado * lado); // Multiplicar lado por sí mismo (C no tiene operador de potencia nativo)
                break; // Romper el flujo para salir del switch

            case 2:
                // Cálculo del área del rectángulo
                printf("Base: ");
                scanf("%f", &base);
                printf("Altura: ");
                scanf("%f", &altura);
                printf("Area: %.2f\n", base * altura); // Multiplicar base por altura
                break;

            case 3:
                // Cálculo del área del círculo
                printf("Radio: ");
                scanf("%f", &radio);
                printf("Area: %.2f\n", PI * (radio * radio)); // Multiplicar PI por el radio al cuadrado
                break;

            case 0:
                // Opción para terminar el programa amablemente
                printf("Hasta luego\n");
                break;

            default:
                // Mensaje en caso de que el usuario ingrese una opción fuera del rango válido
                printf("Opcion invalida\n");
                break;
        }
    } while (opcion != 0); // Repetir el menú mientras la opción sea diferente de 0

    return 0; // Fin del programa
}