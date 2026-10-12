
#include <stdio.h>

#include <stdbool.h>

int main(void) {
    // Declaración de variable entera para el año y lógica para bisiesto
    int anio;
    bool esBisiesto;

    // Solicita el año a evaluar
    printf("Ingrese el año: ");
    scanf("%d", &anio);

    // Proceso: aplica la regla del año bisiesto
    esBisiesto = ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0));

    // Salida: utiliza el operador ternario ?: para imprimir el mensaje correspondiente
    printf("%d %s es bisiesto\n", anio, esBisiesto ? "" : "no");

    return 0;
}