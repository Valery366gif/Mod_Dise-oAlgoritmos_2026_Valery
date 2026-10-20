/*
 * Enunciado: Gestion de compras en una tienda de electronica con arreglos paralelos.
 * Que se logra: Registrar hasta 10 productos (nombre, precio unitario y cantidad), validar entradas, 
 *             calcular subtotales, aplicar descuentos por tramos, sumar el impuesto del 13% y emitir factura detallada.
 * Como se logra: Se usa fgets para el nombre del cliente y de los productos (limpiando el buffer con getchar). 
 *                Se almacenan los datos en arreglos paralelos (nombres, precios, cantidades). Se valida que precio y cantidad 
 *                sean positivos, y se pregunta si desea continuar ('S' o 'N'). Al finalizar se calcula el subtotal general, 
 *                el descuento segun rangos, el impuesto y el total a pagar.
 * Resultado esperado: Emitir una factura limpia y estructurada con todos los detalles y montos exactos.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTOS 10
#define TASA_IMPUESTO 0.13

int main() {
    char cliente[100];
    char nombres[MAX_PRODUCTOS][100];
    float precios[MAX_PRODUCTOS];
    int cantidades[MAX_PRODUCTOS];
    float subtotales[MAX_PRODUCTOS];
    
    int contador = 0;
    char continuar = 'S';
    float subtotal_general = 0.0;
    float porcentaje_desc = 0.0;
    float descuento = 0.0;
    float total_con_desc = 0.0;
    float impuesto = 0.0;
    float total_pagar = 0.0;

    // Recibir nombre del cliente
    while (1) {
        printf("Nombre del cliente: ");
        if (fgets(cliente, sizeof(cliente), stdin) != NULL) {
            cliente[strcspn(cliente, "\n")] = '\0';
            if (strlen(cliente) > 0) {
                break;
            }
        }
        printf("El nombre no puede estar vacio. Intente de nuevo.\n");
    }

    printf("\nCompra en la tienda\n");

    // Registrar productos en arreglos paralelos
    while (contador < MAX_PRODUCTOS && toupper(continuar) == 'S') {
        printf("\nProducto %d\n", contador + 1);

        while (1) {
            printf("Nombre: ");
            if (fgets(nombres[contador], sizeof(nombres[contador]), stdin) != NULL) {
                nombres[contador][strcspn(nombres[contador], "\n")] = '\0';
                if (strlen(nombres[contador]) > 0) {
                    break;
                }
            }
            printf("El nombre del producto no puede estar vacio.\n");
        }

        do {
            printf("Precio unitario: ");
            if (scanf("%f", &precios[contador]) != 1 || precios[contador] <= 0) {
                printf("Error: El precio debe ser mayor que 0.\n");
                while (getchar() != '\n');
                precios[contador] = -1.0;
            }
        } while (precios[contador] <= 0);

        do {
            printf("Cantidad: ");
            if (scanf("%d", &cantidades[contador]) != 1 || cantidades[contador] <= 0) {
                printf("Error: La cantidad debe ser un entero mayor que 0.\n");
                while (getchar() != '\n');
                cantidades[contador] = -1;
            }
        } while (cantidades[contador] <= 0);

        while (getchar() != '\n'); // Limpiar buffer

        subtotales[contador] = precios[contador] * cantidades[contador];
        printf("Subtotal: %.2f\n", subtotales[contador]);
        subtotal_general += subtotales[contador];
        contador++;

        if (contador < MAX_PRODUCTOS) {
            do {
                printf("Desea agregar otro producto? (S/N): ");
                scanf(" %c", &continuar);
                while (getchar() != '\n');
                continuar = toupper(continuar);
                if (continuar != 'S' && continuar != 'N') {
                    printf("Opcion invalida. Ingrese S o N.\n");
                }
            } while (continuar != 'S' && continuar != 'N');
        }
    }

    // Calcular descuentos y totales
    if (subtotal_general < 100.0) {
        porcentaje_desc = 0.0;
    } else if (subtotal_general < 500.0) {
        porcentaje_desc = 0.05;
    } else if (subtotal_general <= 1000.0) {
        porcentaje_desc = 0.10;
    } else {
        porcentaje_desc = 0.15;
    }

    descuento = subtotal_general * porcentaje_desc;
    total_con_desc = subtotal_general - descuento;
    impuesto = total_con_desc * TASA_IMPUESTO;
    total_pagar = total_con_desc + impuesto;

    // Mostrar factura
    printf("\n========================================\n");
    printf("                  FACTURA               \n");
    printf("========================================\n");
    printf("Cliente: %s\n", cliente);
    printf("----------------------------------------\n");
    printf("%-15s %-10s %-6s %-10s\n", "Producto", "Precio", "Cant", "Subtotal");
    printf("----------------------------------------\n");
    for (int i = 0; i < contador; i++) {
        printf("%-15s %-10.2f %-6d %-10.2f\n", nombres[i], precios[i], cantidades[i], subtotales[i]);
    }
    printf("----------------------------------------\n");
    printf("Productos registrados:\t%d\n", contador);
    printf("Subtotal:\t\t%.2f\n", subtotal_general);
    printf("Descuento:\t\t%.2f (%.0f%%)\n", descuento, porcentaje_desc * 100.0);
    printf("Total con descuento:\t%.2f\n", total_con_desc);
    printf("Impuesto (13%%):\t\t%.2f\n", impuesto);
    printf("TOTAL A PAGAR:\t\t%.2f\n", total_pagar);
    printf("========================================\n");

    return 0;
}