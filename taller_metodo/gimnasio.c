//ENUNCIADO: Un gimnasio registra las inscripciones del día (de 1 a 10). De cada una se digita el nombre del socio (una palabra), el plan (1 Mensual 18000, 2 Trimestral 48000, 3 Anual 160000) y la edad (de 15 a 90); un dato inválido se vuelve a pedir. Los socios de 65 años o más tienen 20 % de descuento y los menores de 18, 15 %. Mostrar una tabla con nombre, edad y monto,el total del día, la inscripción mayor y cuántas tuvieron descuento.


#include <stdio.h>
/// definición de constantes para el límite de registros, costos de los planes y tasas de descuento
#define MAX_COMPRAS 10
#define PRECIO_MENSUAL 18000
#define PRECIO_TRIMESTRAL 48000
#define PRECIO_ANUAL 160000
#define DESCUENTO_MENOR 18
#define DESCUENTO_MAYOR 65
#define TAZA_MENOR 0.15
#define TAZA_MAYOR 0.20

// Prototipos de funciones encargadas de la validación, precios, cálculos y resumen general
int leerEntero(const char mensaje[], int minimo, int maximo);
double precioCuota(int tipo);
double calcularTotal(int tipo, int edad);
void resumir(const int cant[], const double tot[],int n, double *total, int *posMayor, int *conDescuento);

int main(void){

    // Declaración de arreglos para almacenar los nombres, edades y montos totales por cliente
    char clientes[MAX_COMPRAS][15];
    int edad[MAX_COMPRAS];
    double totales[MAX_COMPRAS];

    int n, i = 0, tipo;

    double totalDia;
    int posMayor, conDescuento = 0;

// Despliegue del encabezado principal en la consola
printf("==== Registro de inscripciones ====\n");
printf("Tipos: 1. Mensual 18000, 2. Trimestral 48000, 3. Anual 160000\n");

// Lectura de la cantidad de registros a procesar con validación de rango permitida
n = leerEntero("Cantidad de compras", 1, MAX_COMPRAS);

// Ciclo para capturar la información correspondiente a cada cliente registrado
for (i = 0; i < n; i++)
{
    printf("Compra %d\n Cliente: ", i + 1);//Numero de compra y pedido de cliente
    scanf("%14s",clientes[i]);

   // Solicitud y validación del tipo de membresía (1, 2 o 3)
    tipo = leerEntero("Tipo",1,3);

    // Solicitud y validación de la edad del socio dentro del rango permitido (15 a 90)
    edad[i] = leerEntero("Edad",15,90);
    
      // Cálculo del costo final aplicando las reglas de negocio según la edad del socio
    totales[i] = calcularTotal(tipo, edad[i]);
}

// La función de resumen para procesar totales, mayor compra y cantidad de descuentos
resumir(edad, totales, n, &totalDia, &posMayor, &conDescuento);


printf("\n%-12s%9s%12s\n","Clientes","Edad","Subtotal");

// Ciclo para desplegar en formato de tabla los datos de cada cliente registrado
for (i = 0; i < n; i++)
{

    printf("%-12s%9d%12.2f\n", clientes[i],edad[i], totales[i]);
}

  // Impresión de los resultados globales obtenidos al finalizar el procesamiento del día
    printf("Total del dia: %12.2f\n", totalDia);

    printf("Compra Mayor: %s (%.2f)\n", clientes[posMayor],totales[posMayor]);

    printf("Con descuento:      %d compra(s)\n", conDescuento);

    return 0;
}

//Encargada de leer números enteros y validar que se encuentren dentro del rango establecid
int leerEntero(const char mensaje[], int minimo, int maximo){
    int numero;

    do
    {
        printf("%s (%d a %d): ",mensaje,minimo,maximo);
        scanf("%d", &numero);
        
    } while (numero < minimo || numero > maximo); // Se repite el ciclo si el valor ingresado es inválido

    return numero;
}

// Función que retorna el costo base de la cuota de acuerdo con el tipo de plan seleccionado
double precioCuota(int tipo){
    switch (tipo)
    {
    case 1:
        return PRECIO_MENSUAL; // Retorna el precio del plan mensual.
    case 2:
        return PRECIO_TRIMESTRAL; // Retorna el precio del plan trimestral
    case 3:
        return PRECIO_ANUAL; // Retorna el precio del plan anual
    default:
        return 0;
    }
}

double calcularTotal(int tipo, int edad){
    double total = precioCuota(tipo);
  
    if (edad < DESCUENTO_MENOR) // Aplica el descuento del 15% si el socio es menor de 18 años
    {
        total = total * (1 - TAZA_MENOR);
    }
    else if (edad >= DESCUENTO_MAYOR) // Aplica el descuento del 20% si el socio tiene 65 años o más
    {
        total = total * (1 - TAZA_MAYOR);
    }
    
    return total;
}

//Definir resumir
void resumir(const int cant[], const double tot[],int n, double *total, int *posMayor, int *conDescuento){
    int i;

    *total = 0;
    *posMayor = 0;

    //Recorre el arreglo de compras para evaluar cada elemento registrado
    for  (i = 0; i < n; i++)
    {
        *total += tot[i]; // Acumula el subtotal de cada compra al total general del día

        if (tot[i] > tot[*posMayor]) // Evalúa si el subtotal actual es mayor al registrado previamente para actualizar la posición
        {
            *posMayor = i;
        }

        // Incrementa el contador si la edad del socio califica para recibir algún tipo de descuento
        if (cant[i] < DESCUENTO_MENOR || cant[i] >= DESCUENTO_MAYOR)
        {
            *conDescuento = *conDescuento + 1;
        }
    }
    
}