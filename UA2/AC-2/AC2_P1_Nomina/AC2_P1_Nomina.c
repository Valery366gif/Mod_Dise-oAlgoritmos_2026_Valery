/*
 * Enunciado: Sistema de calculo de nomina para una empresa de consultoria.
 * Que se logra: Calcular los descuentos (CAJA, IESS y el impuesto sobre la renta) y el salario neto 
 *             de un empleado a partir de su salario bruto y mostrar un comprobante detallado.
 * Como se logra: Se solicita el nombre completo usando fgets (limpiando el salto de linea con strcspn) 
 *                y se valida que no este vacio. Se solicita el salario bruto usando un ciclo do-while 
 *                para garantizar que sea mayor que cero. Se aplican constantes para las tasas (CAJA 9.5%, 
 *                IESS 2.5%, Renta 10% si supera 800) y se imprimen los resultados con dos decimales y alineados.
 * Resultado esperado: Comprobante de pago con el salario neto correcto (ejemplo para 1000: neto 780.00).
 */

#include <stdio.h>
#include <string.h>

#define TASA_CAJA 0.095
#define TASA_IESS 0.025
#define TASA_RENTA 0.10
#define LIMITE_RENTA 800.0

int main() {
    char nombre[100];
    float salario_bruto = 0.0;
    float desc_caja = 0.0;
    float desc_iess = 0.0;
    float impuesto_renta = 0.0;
    float salario_neto = 0.0;

    // Recibir y validar el nombre completo del empleado/a
    while (1) {
        printf("Nombre del empleado: ");
        if (fgets(nombre, sizeof(nombre), stdin) != NULL) {
            nombre[strcspn(nombre, "\n")] = '\0';
            if (strlen(nombre) > 0) {
                break;
            }
        }
        printf("El nombre no puede estar vacio. Intente de nuevo.\n");
    }

    // Recibir y validar el salario bruto
    do {
        printf("Salario bruto: ");
        if (scanf("%f", &salario_bruto) != 1) {
            printf("Entrada invalida. Ingrese un numero.\n");
            while (getchar() != '\n');
            salario_bruto = 0.0;
        } else if (salario_bruto <= 0) {
            printf("El salario bruto debe ser mayor que 0.\n");
        }
    } while (salario_bruto <= 0);

    // Para calcular descuentos
    desc_caja = salario_bruto * TASA_CAJA;
    desc_iess = salario_bruto * TASA_IESS;
    
    if (salario_bruto > LIMITE_RENTA) {
        impuesto_renta = salario_bruto * TASA_RENTA;
    } else {
        impuesto_renta = 0.0;
    }

    salario_neto = salario_bruto - desc_caja - desc_iess - impuesto_renta; //calculo de salario neto

    //Muestra la informacion
    printf("\n--- Calculo de nomina ---\n");
    printf("Comprobante de pago\n");
    printf("Empleado:\t\t%s\n", nombre);
    printf("Salario bruto:\t\t%.2f\n", salario_bruto);
    printf("Descuento CAJA (9.5%%):\t%.2f\n", desc_caja);
    printf("Descuento IESS (2.5%%):\t%.2f\n", desc_iess);
    printf("Impuesto renta (10%%):\t%.2f\n", impuesto_renta);
    printf("Salario neto:\t\t%.2f\n", salario_neto);

    return 0;
}