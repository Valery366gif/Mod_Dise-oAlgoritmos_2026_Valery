#include <stdio.h>
int main(void) {
    int tipo = 1;
    switch (tipo) {
                   //Les falta el break en cada case del switch
    case 1: printf("Residencial\n");
     break;

     case 2: printf("Comercial\n"); 
      break;

     default: printf("Tipo invalido\n");
      break;

    }
    return 0;
}
