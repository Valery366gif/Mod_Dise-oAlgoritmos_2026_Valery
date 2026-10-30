#include <stdio.h>
//Definir constantes
#define MAX_COMPRAS 10
#define PRECIO_MENSUAL 18000
#define PRECIO_TRIMESTRAL 48000
#define PRECIO_ANUAL 160000
#define DESCUENTO_MENOR 18
#define DESCUENTO_MAYOR 65
#define TAZA_MENOR 0.15
#define TAZA_MAYOR 0.20


int leerEntero(const char mensaje[], int minimo, int maximo);
double precioCuota(int tipo);
double calcularTotal(int tipo, int edad);
void resumir(const int cant[], const double tot[],int n, double *total, int *posMayor, int *conDescuento);

int main(void){

    char clientes[MAX_COMPRAS][15];
    int edad[MAX_COMPRAS];
    double totales[MAX_COMPRAS];

    int n, i = 0, tipo;

    double totalDia;
    int posMayor, conDescuento = 0;


printf("==== Registro de inscripciones ====\n");
printf("Tipos: 1. Mensual 18000, 2. Trimestral 48000, 3. Anual 160000\n");


n = leerEntero("Cantidad de compras", 1, MAX_COMPRAS);


for (i = 0; i < n; i++)
{
    printf("Compra %d\n Cliente: ", i + 1);//Numero de compra y pedido de cliente
    scanf("%14s",clientes[i]);


    tipo = leerEntero("Tipo",1,3);

    edad[i] = leerEntero("Edad",15,90);
    

    totales[i] = calcularTotal(tipo, edad[i]);
}


resumir(edad, totales, n, &totalDia, &posMayor, &conDescuento);


printf("\n%-12s%9s%12s\n","Clientes","Edad","Subtotal");


for (i = 0; i < n; i++)
{

    printf("%-12s%9d%12.2f\n", clientes[i],edad[i], totales[i]);
}

    printf("Total del dia: %12.2f\n", totalDia);

    printf("Compra Mayor: %s (%.2f)\n", clientes[posMayor],totales[posMayor]);

    printf("Con descuento:      %d compra(s)\n", conDescuento);

    return 0;
}

//Definiciones. Leer entero
int leerEntero(const char mensaje[], int minimo, int maximo){
    int numero;

    do
    {
        printf("%s (%d a %d): ",mensaje,minimo,maximo);
        scanf("%d", &numero);
        
    } while (numero < minimo || numero > maximo);

    return numero;
}

//definicion precioEntrada
double precioCuota(int tipo){
    switch (tipo)
    {
    case 1:
        return PRECIO_MENSUAL;
    case 2:
        return PRECIO_TRIMESTRAL;
    case 3:
        return PRECIO_ANUAL;
    default:
        return 0;
    }
}

double calcularTotal(int tipo, int edad){
    double total = precioCuota(tipo);

    if (edad < DESCUENTO_MENOR)
    {
        total = total * (1 - TAZA_MENOR);
    }
    else if (edad >= DESCUENTO_MAYOR)
    {
        total = total * (1 - TAZA_MAYOR);
    }
    
    return total;
}

//definir resumir
void resumir(const int cant[], const double tot[],int n, double *total, int *posMayor, int *conDescuento){
    int i;

    *total = 0;
    *posMayor = 0;

    //rocorrer las compras
    for  (i = 0; i < n; i++)
    {
        *total += tot[i];

        if (tot[i] > tot[*posMayor])
        {
            *posMayor = i;
        }

        if (cant[i] < DESCUENTO_MENOR || cant[i] >= DESCUENTO_MAYOR)
        {
            *conDescuento = *conDescuento + 1;
        }
    }
    
}