#include <stdio.h>

// Definición de constante simbólica para el bono
#define BONO 5000.0

int main(void) {
    // Declaración de variables reales para horas y pago por hora
    double horas, pagoHora, salario;

    // Solicita las horas trabajadas en la semana
    printf("Horas trabajadas en la semana: ");
    // Lee las horas trabajadas
    scanf("%lf", &horas);

    // Solicita el pago por hora
    printf("Pago por hora: ");
    // Lee el pago por hora
    scanf("%lf", &pagoHora);

    // Proceso: calcula el salario total sumando el bono
    salario = (horas * pagoHora) + BONO;

    // Salida: imprime el comprobante con columnas formateadas
    printf("%-18s %10.2f\n", "Horas:", horas);
    printf("%-18s %10.2f\n", "Pago por hora:", pagoHora);
    printf("%-18s %10.2f\n", "Bono:", (double)BONO);
    printf("%-18s %10.2f\n", "Pago semanal:", salario);

    return 0;
}