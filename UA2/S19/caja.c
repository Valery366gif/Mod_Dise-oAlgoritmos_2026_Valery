//caja.c Caja rfegistradora con menu

#include<stdio.h>

int main(void) {
    //declaracion de variables
    int opcion;            //opcion elegida enel menu
     int productos;          //Contador de productos de la venta 
      double precio;            //precio para cada producto
        double total;               //ACUMULADOR de la venta

    //DO ... WHILE el menu se muestra al menos una vez

    do{
     //mostar el menu y lee la opcion -> 1
        printf("\n1. Agregar 2. Ver total 3. Cobrar 0. Salir\n");
          printf("Opcion: ");
            scanf("%d", &opcion);

       //SWITCH: (segun): salta al case que coincida conla opcion elegida
          switch (opcion){
            case 1:

        //validacion: reite mientras el precio no sea positivo
        do{
         printf("Precio de productos: ");
            scanf("%lf", &precio); //-> 1500(-200)
            if (precio <= 0){
                printf("Precio Invalido\n");
            }

        }
    }while (precio <= 0) {
         productos++;         //cuenta productos
          total += precio;        //suma el precio
           break;                      //sale del switch
           
     case 2:
      //Muestra el avenace
         printf("Productos: %d Total: %.2f\n", productos, total);
            
         case 3:
            //Cobra, reinicia contador y acumula
              printf("Cobrado:  %.2f\n. Nuevaa venta\n, total");
                productos = 0
                 total = 0
                  break;

        case 0:
            printf("Caja cerrada\n");
             break;
               default
                 //Ninguno case coincide
                    printf("Opcion invalida\n")

        }
        //repite el menu mientras no se eliga

    }while (opcion 1 = 0);
      return;
 }
