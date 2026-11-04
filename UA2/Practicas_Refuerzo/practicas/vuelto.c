#include <stdio.h>
#include <ctype.h>

#define NUM_DENOMINACIONES 11

// Prototipos sugeridos[cite: 1]
int leerEntero(const char mensaje[], int minimo, int maximo);
char leerSN(const char mensaje[]);
int cuantas(int *resto, int denominacion);

int main(void) {
    // Almacenar las 11 denominaciones en un arreglo constante, de mayor a menor
    const int DEN[NUM_DENOMINACIONES] = {20000, 10000, 5000, 2000, 1000, 500, 100, 50, 25, 10, 5};
    char otra;

    do {
        // QUÉ: Solicitar el total de la compra y validar que el pago no sea menor
        // CÓMO: Usando validación estricta con ciclos de repetición
        int totalCompra = leerEntero("Digite el total de la compra (1 a 1,000,000): ", 1, 1000000);
        
        int montoPagado;
        do {
            montoPagado = leerEntero("Digite el monto pagado: ", totalCompra, 10000000);
            if (montoPagado < totalCompra) {
                printf("Error: El monto pagado no puede ser menor que el total de la compra.\n");
            }
        } while (montoPagado < totalCompra);

        int vuelto = montoPagado - totalCompra;
        int resto = vuelto;
        int totalPiezas = 0;

        printf("\nTotal de la compra: ₡%d\n", totalCompra);
        printf("Monto pagado: ₡%d\n", montoPagado);
        printf("Vuelto total a entregar: ₡%d\n", vuelto);
        printf("Desglose de piezas:\n");

        // QUÉ: Recorrer el arreglo de denominaciones mediante un ciclo for
        // CÓMO: Invocando la función cuantas pasando la dirección del resto (&resto)
        // PARA: Obtener el desglose preciso de billetes y monedas
        for (int i = 0; i < NUM_DENOMINACIONES; i++) {
            int piezas = cuantas(&resto, DEN[i]);
            if (piezas > 0) {
                printf(" - %d pieza(s) de ₡%d\n", piezas, DEN[i]);
                totalPiezas += piezas;
            }
        }

        // Si sobran colones que no se pueden entregar (menos de 5)
        if (resto > 0) {
            printf(" * Quedan %d colón(es) sin moneda (inferior a la denominación mínima de 5).\n", resto);
        }

        printf("Cantidad total de piezas entregadas: %d\n", totalPiezas);
        printf("----------------------------------------\n");

        otra = leerSN("Desea calcular otro vuelto? (S/N): ");

    } while (otra == 's' || otra == 'S');

    return 0;
}

// Función para leer y validar enteros dentro de un rango permitido
int leerEntero(const char mensaje[], int minimo, int maximo) {
    int valor;
    char basura;
    do {
        printf("%s", mensaje);
        if (scanf("%d", &valor) != 1) {
            while ((basura = getchar()) != '\n' && basura != EOF);
            valor = minimo - 1;
        }
        if (valor < minimo || valor > maximo) {
            printf("Error: Valor fuera de rango permitido. Intente de nuevo.\n");
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

// Función que calcula cuántas piezas caben y actualiza el resto mediante puntero
int cuantas(int *resto, int denominacion) {
    int piezas = *resto / denominacion;
    *resto = *resto % denominacion;
    return piezas;
}