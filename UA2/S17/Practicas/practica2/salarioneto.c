#include <stdio.h>

int main(void) {
    // Declaración de constante para la deducción
    const double DEDUCCION = 0.10;
    // Declaración de variables reales para horas, tarifa, bruto, deducción y neto
    double horas, tarifaHora, bruto, deduccion, neto;

    // Solicita las horas trabajadas
    printf("Horas trabajadas: ");
    // Lee las horas trabajadas
    scanf("%lf", &horas);

    // Solicita el pago por hora
    printf("Pago por hora: ");
    // Lee la tarifa por hora
    scanf("%lf", &tarifaHora);

    // Proceso: calcula el salario bruto
    bruto = horas * tarifaHora;
    // Proceso: calcula el monto de la deducción
    deduccion = bruto * DEDUCCION;
    // Proceso: calcula el salario neto
    neto = bruto - deduccion;

    // Salida: muestra el salario bruto con dos decimales
    printf("Salario bruto: %.2f\n", bruto);
    // Salida: muestra la deducción con dos decimales
    printf("Deduccion: %.2f\n", deduccion);
    // Salida: muestra el salario neto con dos decimales
    printf("Salario neto: %.2f\n", neto);

    return 0;
}