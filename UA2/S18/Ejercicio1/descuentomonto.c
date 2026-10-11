#include <stdio.h>

// Definición de constante mínima para el descuento
#define MINIMO 50000.0

int main(void) {
    // Declaración de constante para la tasa de descuento
    const double TASA = 0.10;
    // Declaración de variables reales para compra, descuento y total
    double compra, descuento, total;

    // Solicita el monto de la compra
    printf("Monto de la compra: ");
    // Lee el monto ingresado
    scanf("%lf", &compra);

    // Condición: si la compra es mayor o igual al mínimo
    if (compra >= MINIMO) {
        // Calcula el descuento aplicando la tasa
        descuento = compra * TASA;
    } else {
        // Si no alcanza el mínimo, el descuento es 0
        descuento = 0.0;
    }

    // Proceso: calcula el total a pagar restando el descuento
    total = compra - descuento;

    // Salida: muestra el descuento y el total con dos decimales
    printf("Descuento: %.2f\n", descuento);
    printf("Total a pagar: %.2f\n", total);

    return 0;
}