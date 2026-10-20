/*
 ============================================================================
 Enunciado: Una librería registra los libros de cada pedido mediante un ciclo controlado 
            por centinela ("FIN"). Lee título, precio y cantidad (positivos), cuenta 
            unidades totales, calcula un descuento del 10% si hay 5 o más unidades, 
            calcula el envío según la cantidad total de libros, aplica impuesto 
            del 13% y determina el total a pagar.
 Qué se logra: Procesar pedidos dinámicos complejos con múltiples reglas comerciales, 
               estructuras repetitivas con lectura anticipada y control de cadenas.
 Cómo se logra: Usando un ciclo while con lectura previa, comparación de cadenas con 
                strcmp, arreglos paralelos para almacenar los datos del pedido, funciones 
                de copiado de cadenas (strcpy) y condicionales anidados para costos de envío.
 Resultado esperado: Imprimir la tabla detallada del pedido con títulos, precios, cantidades 
                     y subtotales, seguido del resumen financiero completo.
 ============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIBROS 10

int main() {
    // Declaración de arreglos paralelos y variables de control
    char titulos[MAX_LIBROS][50];     // Arreglo bidimensional para almacenar los títulos de los libros
    double precios[MAX_LIBROS];       // Arreglo para los precios de cada libro
    int cantidades[MAX_LIBROS];       // Arreglo para las cantidades de cada libro
    int totalLibrosCatalogo = 0;      // Contador de libros ingresados (filas válidas)
    
    char entradaTitulo[50];           // Variable temporal para lectura anticipada del título
    double precioTemp;                // Variable temporal para validar precio positivo
    int cantidadTemp;                 // Variable temporal para validar cantidad positiva
    
    int i;                            // Variable iteradora
    int unidadesTotales = 0;          // Suma total de cantidades de libros pedidos
    double subtotalGeneral = 0.0;     // Acumulador del costo bruto de los libros
    double descuento = 0.0;           // Monto de descuento aplicado
    double subtotalConDescuento = 0.0;// Monto después de aplicar descuento
    double envio = 0.0;               // Costo de envío según reglas
    double impuesto = 0.0;            // Impuesto del 13%
    double totalPagar = 0.0;          // Total definitivo a pagar

    printf("=== Pedido de la libreria ===\n");

    // Lectura anticipada (sentinela con "FIN")
    printf("Titulo del libro (FIN para terminar): ");
    scanf(" %[^\n]", entradaTitulo);

    // Ciclo while para lectura de datos hasta llegar a MAX_LIBROS o digitar FIN
    while (totalLibrosCatalogo < MAX_LIBROS && strcasecmp(entradaTitulo, "FIN") != 0) {
        
        // Validación de precio positivo
        do {
            printf("Precio: ");
            scanf("%lf", &precioTemp);
            if (precioTemp <= 0) {
                printf("El precio debe ser mayor a cero. Intente de nuevo.\n");
            }
        } while (precioTemp <= 0);

        // Validación de cantidad positiva
        do {
            printf("Cantidad: ");
            scanf("%d", &cantidadTemp);
            if (cantidadTemp <= 0) {
                printf("La cantidad debe ser mayor a cero. Intente de nuevo.\n");
            }
        } while (cantidadTemp <= 0);

        // Almacenar datos en los arreglos paralelos
        strcpy(titulos[totalLibrosCatalogo], entradaTitulo);
        precios[totalLibrosCatalogo] = precioTemp;
        cantidades[totalLibrosCatalogo] = cantidadTemp;
        
        totalLibrosCatalogo++;

        // Siguiente lectura anticipada
        if (totalLibrosCatalogo < MAX_LIBROS) {
            printf("Titulo del libro (FIN para terminar): ");
            scanf(" %[^\n]", entradaTitulo);
        }
    }

    // Procesamiento y cálculos del pedido
    for (i = 0; i < totalLibrosCatalogo; i++) {
        unidadesTotales += cantidades[i];
        subtotalGeneral += (precios[i] * cantidades[i]);
    }

    // Regla de descuento: 10% si el pedido tiene 5 unidades o más
    if (unidadesTotales >= 5) {
        descuento = subtotalGeneral * 0.10;
    } else {
        descuento = 0.0;
    }

    subtotalConDescuento = subtotalGeneral - descuento;

    // Regla de envío: 8 si < 50, 4 si < 150, gratis (0) desde 150 (en función del subtotal de libros)
    if (subtotalGeneral < 50.0) {
        envio = 8.0;
    } else if (subtotalGeneral < 150.0) {
        envio = 4.0;
    } else {
        envio = 0.0;
    }

    // Impuesto (13% del total con descuento)
    impuesto = subtotalConDescuento * 0.13;

    // Total a pagar final
    totalPagar = subtotalConDescuento + impuesto + envio;

    // Mostrar detalle en formato de tabla
    printf("\n%-20s %-10s %-10s %-10s\n", "Titulo", "Precio", "Cant", "Subtotal");
    for (i = 0; i < totalLibrosCatalogo; i++) {
        double subtotalLinea = precios[i] * cantidades[i];
        printf("%-20s %-10.2f %-10d %-10.2f\n", titulos[i], precios[i], cantidades[i], subtotalLinea);
    }

    // Mostrar resumen del pedido
    printf("\nUnidades:\n%d\n", unidadesTotales);
    printf("Total de libros:\n%.2f\n", subtotalGeneral);
    printf("Descuento:\n%.2f\n", descuento);
    printf("Impuesto (13%%):\n%.2f\n", impuesto);
    printf("Envio:\n%.2f\n", envio);
    printf("TOTAL A PAGAR:\n%.2f\n", totalPagar);

    return 0;
}