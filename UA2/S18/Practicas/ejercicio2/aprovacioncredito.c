#include <stdio.h>

int main(void) {
    // Declaración de variables para salario, cuota y antigüedad
    double salario, cuota;
    int antiguedad;
    // Declaración de variables de caracteres para deudas y fiador
    char respDeudas, respFiador;
    // Declaración de variables lógicas almacenadas como enteros (0 o 1)
    int capacidadPago, tieneDeudas, tieneFiador, aprobado;

    // Solicita el salario mensual
    printf("Salario mensual: ");
    scanf("%lf", &salario);

    // Solicita la cuota mensual del crédito
    printf("Cuota mensual del credito: ");
    scanf("%lf", &cuota);

    // Solicita si tiene deudas atrasadas (S/N)
    printf("Tiene deudas atrasadas? (S/N): ");
    scanf(" %c", &respDeudas); // El espacio antes de %c omite espacios en blanco previos

    // Solicita los años de antigüedad laboral
    printf("Anios de antiguedad laboral: ");
    scanf("%d", &antiguedad);

    // Solicita si tiene fiador (S/N)
    printf("Tiene fiador? (S/N): ");
    scanf(" %c", &respFiador);

    // Proceso: evalúa si la capacidad de pago es suficiente (salario >= cuota * 3)
    capacidadPago = (salario >= cuota * 3);
    
    // Proceso: determina si tiene deudas permitiendo 'S' o 's'
    tieneDeudas = (respDeudas == 'S' || respDeudas == 's');
    
    // Proceso: determina si tiene fiador permitiendo 'S' o 's'
    tieneFiador = (respFiador == 'S' || respFiador == 's');

    // Proceso: regla general de aprobación de crédito
    aprobado = (capacidadPago && !tieneDeudas && (antiguedad >= 10 || tieneFiador));

    // Decisión: si está aprobado o rechazado
    if (aprobado) {
        printf("Credito aprobado\n");
    } else {
        printf("Credito rechazado\n");
    }

    return 0;
}