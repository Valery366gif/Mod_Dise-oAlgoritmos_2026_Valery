//hola.c
 // hola.c - Prueba del entorno de la UA2
#include <stdio.h> 
// biblioteca de entrada y salida: printf y scanf
 
 int main(void) {
 int edad;
 // Muestra un mensaje -> Entorno listo para la UA2
printf("Entorno listo para la UA2\n");
// Pide y lee un número entero -> edad = 20
printf("Digite su edad: ");
 scanf("%d", &edad);
 // Muestra el dato leído -> Edad registrada: 20
 printf("Edad registrada: %d\n", edad);
 return 0; // termina sin errores
 }