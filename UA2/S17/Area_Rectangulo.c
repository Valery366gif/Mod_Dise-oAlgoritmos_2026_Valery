//area.c saca la area de un rectangulo

#include <stdio.h>

int main(void){
    //Declarar variables double
    double base, altura, area;

    //Entrada de datos, lee la base = 5
     printf("Digite la base del rectangulo (cm): ");
     scanf ("%lf", &base);
     
     //Muestra el mensaje y lee altura que va ser = 3
     printf("Digite la altura del rectangulo (cm): ");
     scanf ("%lf", &altura);

     //Proceso: multiplica y guarda el resultado = 15

     area = base * altura;

     //Salida: Muestra el area con 2 decimales

     printf ("El area del rectangulo es %.2f cm2\n", area);

     return 0;
}