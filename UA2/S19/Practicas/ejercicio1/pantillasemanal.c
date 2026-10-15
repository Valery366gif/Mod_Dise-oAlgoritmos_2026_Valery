#include <stdio.h> 
#include <stdlib.h> 

#define LIMITE 48 
#define RECARGO 1.5
#define CENTINELA -1 // Indica cuándo termina la entrada de datos.

int main(void) { 
    float horas, tarifa, horasExtra, pago, totalPlanilla = 0; // Declara las variables y comienza el acumulador en cero.
    int personas = 0, conExtra = 0; // Inicializa los contadores en cero.

    printf("Horas de la semana (-1 para terminar): "); 
    scanf("%f", &horas);

    while (horas != CENTINELA) {                          // Repite mientras no se ingrese -1.
        if (horas < 0 || horas > 72) {                        // Comprueba si las horas están fuera del rango permitido.
            printf("Horas invalidas. Ingrese entre 0 y 72.\n"); // Informa que el dato no es válido.
        } else {                                                 // Procesa las horas cuando son válidas.
            printf("Tarifa por hora: ");                            // Solicita el pago por hora.
            scanf("%f", &tarifa);                                      // Lee la tarifa ingresada.

            if (horas > LIMITE) {                                  // Comprueba si hay horas extra.
                horasExtra = horas - LIMITE;                         // Calcula las horas que superan las 48.
                pago = LIMITE * tarifa + horasExtra * tarifa * RECARGO; // Calcula el pago normal y las horas extra.
                conExtra++;                                               // Aumenta el contador de personas con horas extra.
            } else {                                                       // Se ejecuta si no hay horas extra.
                pago = horas * tarifa;                                      // Calcula el pago normal.
            }

            printf("Pago: %.2f\n", pago); // Muestra el pago de la persona.
            totalPlanilla += pago;           // Suma el pago al total de la planilla.
            personas++;                        // Cuenta una persona procesada.
        }

        printf("Horas de la semana (-1 para terminar): "); // Solicita las horas de la siguiente persona.
        scanf("%f", &horas);                                 // Lee las nuevas horas o el centinela.
    }

    printf("Personas: %d\n", personas); // Muestra la cantidad de personas procesadas.
    printf("Con horas extra: %d\n", conExtra); // Muestra cuántas personas hicieron horas extra.
    printf("Total de la planilla: %.2f\n", totalPlanilla); // Muestra el total de los pagos.

        system("pause");
        
    return 0; 
}