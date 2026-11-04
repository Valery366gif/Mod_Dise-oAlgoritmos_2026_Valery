#include <stdio.h>
#include <ctype.h>

// Definición de constantes para tarifas y cargos fijos
#define TARIFA_RES_1 80.0
#define TARIFA_RES_2 110.0
#define TARIFA_RES_3 150.0
#define LIMITE_RES_1 200
#define LIMITE_RES_2 400

#define TARIFA_COMERCIAL 130.0
#define CARGO_FIJO_COMERCIAL 3000.0
#define PORCENTAJE_ALUMBRADO 0.02

// Prototipos sugeridos
int leerEntero(const char mensaje[], int minimo, int maximo);
char leerSN(const char mensaje[]);
double energiaResidencial(int kwh);
double calcularRecibo(int tipo, int kwh);

int main(void) {
    int totalRecibos = 0;
    double totalFacturado = 0.0;
    
    int medidorMayor = 0;
    double mayorMonto = -1.0;
    
    char otra;

    do {
        // QUÉ: Solicitar y validar los datos de entrada de cada recibo
        // CÓMO: Usando la función leerEntero con validación de rangos permitidos
        // PARA GARANTIZAR: Que no se procesen datos inválidos
        int medidor = leerEntero("Digite el numero de medidor (1000 a 9999): ", 1000, 9999);
        int tipo = leerEntero("Digite el tipo de cliente (1: Residencial, 2: Comercial): ", 1, 2);
        int consumo = leerEntero("Digite el consumo del mes en kWh (0 a 3000): ", 0, 3000);

        // QUÉ: Calcular el monto total del recibo actual
        // CÓMO: Llamando a calcularRecibo con el tipo y consumo digitados
        // PARA: Obtener el valor exacto a pagar incluyendo alumbrado público
        double montoRecibo = calcularRecibo(tipo, consumo);

        // Actualizar estadísticas globales
        totalRecibos++;
        totalFacturado += montoRecibo;

        // Determinar si este es el recibo mayor hasta el momento
        if (montoRecibo > mayorMonto) {
            mayorMonto = montoRecibo;
            medidorMayor = medidor;
        }

        printf("\n--- Detalle del Recibo ---\n");
        printf("Medidor: %d | Total a pagar: ₡%.2f\n\n", medidor, montoRecibo);

        otra = leerSN("Desea ingresar otro recibo? (S/N): ");

    } while (otra == 's' || otra == 'S');

    // Mostrar resumen final al terminar el ciclo
    printf("\n========================================\n");
    printf("RESUMEN FINAL DE LA COOPERATIVA ELECTRICA\n");
    printf("========================================\n");
    printf("Total de recibos emitidos: %d\n", totalRecibos);
    printf("Total facturado general: ₡%.2f\n", totalFacturado);
    if (totalRecibos > 0) {
        printf("Recibo mayor: Medidor %d con un monto de ₡%.2f\n", medidorMayor, mayorMonto);
    }
    printf("========================================\n");

    return 0;
}

// Función para leer y validar números enteros dentro de un rango
int leerEntero(const char mensaje[], int minimo, int maximo) {
    int valor;
    char basura;
    do {
        printf("%s", mensaje);
        if (scanf("%d", &valor) != 1) {
            // Limpiar buffer de entrada si el usuario digita letras
            while ((basura = getchar()) != '\n' && basura != EOF);
            valor = minimo - 1; // Forzar repetición
        }
        if (valor < minimo || valor > maximo) {
            printf("Error: Valor fuera de rango [%d - %d]. Intente de nuevo.\n", minimo, maximo);
        }
    } while (valor < minimo || valor > maximo);
    return valor;
}

// Función para leer y validar respuestas de S/N
char leerSN(const char mensaje[]) {
    char respuesta;
    do {
        printf("%s", mensaje);
        scanf(" %c", &respuesta);
        respuesta = tolower(respuesta);
        if (respuesta != 's' && respuesta != 'n') {
            printf("Error: Debe responder 'S' o 'N'.\n");
        }
    } while (respuesta != 's' && respuesta != 'n');
    return respuesta;
}

// Calcula el costo de energía residencial por tramos
double energiaResidencial(int kwh) {
    double costoEnergia = 0.0;
    if (kwh <= LIMITE_RES_1) {
        costoEnergia = kwh * TARIFA_RES_1;
    } else if (kwh <= LIMITE_RES_2) {
        costoEnergia = (LIMITE_RES_1 * TARIFA_RES_1) + ((kwh - LIMITE_RES_1) * TARIFA_RES_2);
    } else {
        costoEnergia = (LIMITE_RES_1 * TARIFA_RES_1) + 
                       ((LIMITE_RES_2 - LIMITE_RES_1) * TARIFA_RES_2) + 
                       ((kwh - LIMITE_RES_2) * TARIFA_RES_3);
    }
    return costoEnergia;
}

// Calcula el recibo total seleccionando con switch según el tipo
double calcularRecibo(int tipo, int kwh) {
    double energia = 0.0;
    double alumbrado = 0.0;
    double subtotal = 0.0;

    switch (tipo) {
        case 1: // Residencial
            energia = energiaResidencial(kwh);
            break;
        case 2: // Comercial
            energia = (kwh * TARIFA_COMERCIAL) + CARGO_FIJO_COMERCIAL;
            break;
        default:
            energia = 0.0;
            break;
    }

    // El alumbrado público se calcula sobre el monto de la energía
    alumbrado = energia * PORCENTAJE_ALUMBRADO;
    subtotal = energia + alumbrado;

    return subtotal;
}