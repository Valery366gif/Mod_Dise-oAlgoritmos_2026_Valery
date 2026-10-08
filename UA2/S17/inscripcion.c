// Inscripcion.c viene de algoritmo inscripcion cursos

#include <stdio.h>
#define COSTO_MODULO 15000.0;

int main(void){

    // Cadenas: arreglos de caracter
      char nombre[30];
        char cedula[15];
          int cantidadModulos;
            double total;
   //Logico en C (1 Verdadero y 0 Falso)
      int tienesDescuento = true;

    //Entradas
     //pide y alamacena nombre. El tipo char NO use & para almacenar con scanf
       printf("Nombre: ");
         scanf("%29s", nombre);

   //leer cedula como texto
      printf("Cedula: ");
        scanf("%14s", cedula);

    //Pedir y almacenar la cantidad de modulos
      printf("Cantidad de modulos: ");
        scanf("%d", &cantidadModulos);


    //Procesos total = 3 * 15000 -> 45000
       total = cantidadModulos * COSTO_MODULO

    //A la pregunta tiene descuento se responde con 1 para si o 0 para no
      tienesDescuento = cantidadModulos >= 3;
    
   // SALIDAS
    printf("Estudiante: %s (%s)\n", nombre, cedula);
     printf("Total de Inscripción: %.2f\n", total);
        printf("¿Aplica para descuento? %d (1 = si, 0 = no)\n", tienesDescuento);
    
return 0;
     
}