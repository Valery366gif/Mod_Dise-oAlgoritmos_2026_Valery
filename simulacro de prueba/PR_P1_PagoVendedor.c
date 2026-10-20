/*
 ============================================================================
 Enunciado: Una distribuidora paga a sus vendedores una comisión sobre las 
            ventas del mes. El programa recibe el nombre del vendedor y las 
            ventas de las 4 semanas, valida que no sean negativas, calcula 
            las ventas totales, comisión (5%), bono de 50 si supera 2000, 
            retención (2% de comisión + bono) y el pago final.
 Qué se logra: Automatizar el cálculo de la nómina mensual de un vendedor 
               aplicando reglas de negocio, validaciones y formato monetario.
 Cómo se logra: Utilizando un arreglo de tipo double para las 4 semanas, 
                ciclos do-while para validar entradas no negativas, acumuladores, 
                y constantes definidas para las tasas, bonos y límites.
 Resultado esperado: Mostrar desglosadas las ventas semanales, ventas del mes, 
                     comisión, bono, retención y el pago neto con dos decimales.
 ============================================================================
*/

#include <stdio.h>

// Definición de constantes para las reglas de negocio
#define TASA_COMISION 0.05
#define LIMITE_BONO 2000.00
#define VALOR_BONO 50.00
#define TASA_RETENCION 0.02
#define NUM_SEMANAS 4

int main() {
    // Declaración de variables
    char nombre[50];                 // Almacena el nombre del vendedor
    double ventas[NUM_SEMANAS];      // Arreglo para almacenar las ventas de cada semana
    double ventasMes = 0.0;          // Acumulador de las ventas totales del mes
    double comision = 0.0;           // Monto correspondiente a la comisión por ventas
    double bono = 0.0;               // Bono otorgado si se supera el límite de ventas
    double baseRetencion = 0.0;      // Suma de comisión y bono sobre la cual se calcula la retención
    double retencion = 0.0;          // Monto retenido según la tasa establecida
    double pagoFinal = 0.0;          // Pago neto final a entregar al vendedor
    int i;                           // Variable de control para los ciclos

    // Entrada de datos
    printf("=== Pago del vendedor ===\n");
    printf("Nombre del vendedor: ");
    scanf(" %[^\n]", nombre); // Lee una cadena con espacios

    // Lectura y validación de ventas semanales usando do-while y arreglos
    for (i = 0; i < NUM_SEMANAS; i++) {
        do {
            printf("Ventas de la semana %d:\n", i + 1);
            scanf("%lf", &ventas[i]);
            if (ventas[i] < 0) {
                printf("Error: Las ventas no pueden ser negativas. Intente de nuevo.\n");
            }
        } while (ventas[i] < 0);
        
        // Acumular las ventas del mes
        ventasMes += ventas[i];
    }

    // Cálculos financieros
    comision = ventasMes * TASA_COMISION;

    if (ventasMes > LIMITE_BONO) {
        bono = VALOR_BONO;
    } else {
        bono = 0.0;
    }

    baseRetencion = comision + bono;
    retencion = baseRetencion * TASA_RETENCION;
    pagoFinal = (comision + bono) - retencion;

    // Salida de resultados detallados
    printf("\nPago de %s\n", nombre);
    for (i = 0; i < NUM_SEMANAS; i++) {
        printf("Semana %d:\n%.2f\n", i + 1, ventas[i]);
    }
    
    printf("Ventas del mes:\n%.2f\n", ventasMes);
    printf("Comision (5%%):\n%.2f\n", comision);
    printf("Bono:\n%.2f\n", bono);
    printf("Retencion (2%%):\n%.2f\n", retencion);
    printf("Pago del mes:\n%.2f\n", pagoFinal);

    return 0;
}