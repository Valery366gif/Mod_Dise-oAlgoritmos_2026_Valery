// billetes.c Hace desgloce de billetes 
#include <stdio.h>

int main(void){
    // Definicion variables
    int monto, resto, cantidad;

    // Entrada datos lee monto = 47500
    printf("Monto a desglosar: ");
    scanf("%d", &monto);

    // PROCESOS: divison entera 47500 / 20000 -> cantidad = 2
    cantidad = resto / 20000;


    // % es el residuo: 47500 % 20000 -> resto = 7500
    resto = resto % 20000;
    // Muestre billetes de 20000: 2
    printf("Billetes de 20000: %d\n", cantidad);


    cantidad = resto / 10000; // 75000 / 5000 -> cantidad = 0
    // Forma compacta de resto =. resto % 10000 -> resto = 7500
    resto %= 10000; 
    printf("Billetes de 10000: %d\n", cantidad); // cantidad -> 0

    cantidad = resto / 5000; // 75000 / 5000 -> cantidad = 1
    resto %= 5000; 
    printf("Billetes de 5000: %d\n", cantidad); // cantidad -> 1

     cantidad = resto / 2000; // 75000 / 5000 -> cantidad = 0
    // Forma compacta de resto =. resto % 10000 -> resto = 7500
    resto %= 2000; 
    printf("Billetes de 2000: %d\n", cantidad); // cantidad -> 0

    cantidad = resto / 1000; // 500 / 1000 -> cantidad = 0
    resto %= 1000; 
    printf("Billetes de 1000: %d\n", cantidad); // cantidad -> 0

    // Lo que se entrega en monedas -> en monedas 500
    printf("En monedas: %d\n", resto);
  
    return 0;
}