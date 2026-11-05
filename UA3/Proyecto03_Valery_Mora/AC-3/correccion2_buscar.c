#include <stdio.h>
#include <string.h>
#define N 4

int buscar (const char nombres[][15], int n, const char buscado []) {
    int i;
    // ERROR: Condición de iteración incorrecta en el bucle for.
   // POR QUE: Se usó 'i <= n', lo que provoca un desbordamiento de búfer (buffer overflow) intentando acceder a nombres[4], cuando los índices válidos van de 0 a 3 (N-1).
   // CORRECCION: Se cambió la condición estricta a 'i < n'.
    for (i = 0; i < n; i++)
         // ERROR: Comparación inválida de cadenas de caracteres con el operador '=='.
        // POR QUE: En C, las cadenas (arreglos de caracteres) no se pueden comparar con '==' porque se compararía la dirección de memoria de los punteros y no su contenido de texto.
       // CORRECCION: Se debe utilizar la función 'strcmp(nombres[i], buscado) == 0'.
    if (strcmp(nombres[i], buscado) == 0)
          return i;
    return -1;
}

int main(void) {
     // ERROR: Sintaxis de inicialización de arreglos incorrecta con paréntesis.
    // POR QUE: Se utilizaron paréntesis '(' en lugar de llaves '{' para inicializar las matrices y arreglos.
   // CORRECCION: Se reemplazaron los paréntesis por llaves '{' y '}'.
    char nombres[N][15] = {"Arroz", "Frijoles", "Cafe", "Azucar"};
    double precios[N] = {1200, 1500, 3200, 900};

    char buscado[15];
    int pos;

    printf("Producto: ");
    scanf("%14s", buscado);

     // ERROR: Falta del operador de asignación al invocar la función de búsqueda.
    // POR QUE: Estaba escrito 'pos buscar (...);' omitiendo el signo '='.
   // CORRECCION: Se corrigió a 'pos = buscar(nombres, N, buscado);'.
   pos = buscar(nombres, N, buscado);

    if (pos == -1)
    printf("No existe\n");
   else
     printf("%s cuesta %.2f\n", nombres[pos], precios[pos]);

  return 0;
}





















































