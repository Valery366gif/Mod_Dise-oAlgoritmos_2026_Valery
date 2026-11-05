/* ENUNCIADO: Sistema de préstamo de libros para una biblioteca escolar.
  QUÉ SE LOGRA: Gestionar el control de hasta 5 libros (creación, consulta,
  préstamo de ejemplares, dar de baja y búsqueda por código)
  utilizando programación estructurada y arreglos paralelos en memoria.
  CÓMO SE LOGRA: Mediante un menú interactivo con bucle do-while y switch,
  funciones modularizadas con prototipos, validación estricta
  de rangos numéricos y paso de parámetros por valor y por dirección.
  RESULTADO ESPERADO: Un sistema robusto y libre de errores de compilación que 
  satisface todos los casos de prueba del INA.
  AUTORA: Valery Shanay Mora Acevedo
  MÓDULO: CSTI12010 Diseño de algoritmos
  FACILITADOR: Giovanni Antonio Coto Calderón */

#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 5
#define TAM_TITULO 20

// Prototipos de funciones requeridas  
int leerEntero(int min, int max, const char *mensaje);
int buscarCodigo(const int codigos[], const int estados[], int n, int buscado);
void incluir(int codigos[], char titulos[][TAM_TITULO], int disponibles[], int estados[], int *n);
void consultar(const int codigos[], const char titulos[][TAM_TITULO], const int disponibles[], const int estados[], int n);
void prestar(int codigos[], int disponibles[], const int estados[], int n);
void darDeBaja(int estados[], const int codigos[], int n);
void buscarLibro(const int codigos[], const char titulos[][TAM_TITULO], const int disponibles[], const int estados[], int n);

int main(void) {
   
  int codigos[MAX_LIBROS] = {101, 102, 103};
  char titulos[MAX_LIBROS][TAM_TITULO] = {"Quijote", "Principito", "Cocori"};
   int disponibles[MAX_LIBROS] = {3, 2, 4};
    int estados[MAX_LIBROS] = {1, 1, 1}; // 1 = activo, 0 = dado de baja
    int cantidadLibros = 3;
     int opcion;

   do {
    printf("\n-----------------------------------------\n");
      printf(" SISTEMA DE LIBROS DE BIBLIOTECA ESCOLAR\n");
       printf("-----------------------------------------\n");
        printf("1. Incluir libro\n");
        printf("2. Consultar libros\n");
        printf("3. Prestar un ejemplar\n");
        printf("4. Dar de baja un libro\n");
        printf("5. Buscar libro\n");
        printf("0. Salir\n");

opcion = leerEntero(0, 5, "Seleccione una opcion: ");

 switch (opcion) {
 case 1:
   incluir(codigos, titulos, disponibles, estados, &cantidadLibros);
    break;

 case 2:
    consultar(codigos, titulos, disponibles, estados, cantidadLibros);
     break;

 case 3:
   prestar(codigos, disponibles, estados, cantidadLibros);
    break;

  case 4:
    darDeBaja(estados, codigos, cantidadLibros);
     break;

 case 5:
   buscarLibro(codigos, titulos, disponibles, estados, cantidadLibros);
    break;

 case 0:
  printf("\n¡Gracias por utilizar el sistema de biblioteca. Hasta luego!\n");
   break;

 default:
  printf("Opción inválida. Intente de nuevo.\n");
      }
   } while (opcion != 0);

    return 0;
}

 //Función para leer y validar enteros dentro de un rango permitido 
int leerEntero(int min, int max, const char *mensaje) {
   int valor;
    char basura;
 do {
  printf("%s", mensaje);
    if (scanf("%d", &valor) != 1) {
      printf("Error: Debe ingresar un número entero válido.\n");
        while ((basura = getchar()) != '\n' && basura != EOF); // Limpiar búfer de entrada
      valor = min - 1; // Forzar que repita
       } else if (valor < min || valor > max) {
          printf("Valor fuera de rango. Debe estar entre %d y %d.\n", min, max);
      }
    } while (valor < min || valor > max);
return valor;
}

//Búsqueda secuencial de un libro ACTIVO por código; devuelve la posición o -1 
 int buscarCodigo(const int codigos[], const int estados[], int n, int buscado) { 
 int i;
  for (i = 0; i < n; i++) {
   if (codigos[i] == buscado && estados[i] == 1) {
     return i;
   }
}
   return -1;
}

// Incluye un nuevo libro si hay espacio y el código no existe en un libro activo 
void incluir(int codigos[], char titulos[][TAM_TITULO], int disponibles[], int estados[], int *n) {
    if (*n >= MAX_LIBROS) {
        printf("\nError: No hay espacio disponible para registrar más libros (máximo %d).\n", MAX_LIBROS);
        return;
     }

    int nuevoCodigo = leerEntero(100, 999, "Ingrese el código del libro (100 a 999): ");

     //Validar si el código ya existe en un libro activo 
    if (buscarCodigo(codigos, estados, *n, nuevoCodigo) != -1) {
         printf("\nEl código %d ya existe.\n", nuevoCodigo);
         return;
    }

    printf("Ingrese el título (una sola palabra, máx 19 letras): ");
    scanf("%19s", titulos[*n]);

    int cantEjemplares = leerEntero(1, 20, "Ingrese la cantidad de ejemplares disponibles (1 a 20): ");

    //Registrar el nuevo libro 
    codigos[*n] = nuevoCodigo;
    disponibles[*n] = cantEjemplares;
    estados[*n] = 1; // Activo por defecto
    (*n)++;

    printf("\n¡Libro incluido exitosamente! (%d de %d)\n", *n, MAX_LIBROS);
}

// Muestra en columnas el código, título y disponibles de cada libro activo, y el total 
void consultar(const int codigos[], const char titulos[][TAM_TITULO], const int disponibles[], const int estados[], int n) {
    int i;
    int activosCount = 0;

    printf("\n----------------------------------------\n");
    printf(" LISTADO DE LIBROS ACTIVOS \n");
    printf("----------------------------------------\n");
    printf("%-10s | %-20s | %-12s\n", "CÓDIGO", "TÍTULO", "DISPONIBLES");
    printf("----------------------------------------\n");

    for (i = 0; i < n; i++) {
       if (estados[i] == 1) {
            printf("%-10d | %-20s | %-12d\n", codigos[i], titulos[i], disponibles[i]);
         activosCount++;
        }
    }
    printf("----------------------------------------\n");
    printf("Total de libros activos: %d\n", activosCount);
}

//Resta un ejemplar disponible al libro seleccionado 
void prestar(int codigos[], int disponibles[], const int estados[], int n) {
    int codigoBuscado = leerEntero(100, 999, "Ingrese el código del libro a prestar: ");
    int pos = buscarCodigo(codigos, estados, n, codigoBuscado);

     if (pos == -1) {
       printf("\nNo existe un libro activo con el código %d.\n", codigoBuscado);
      return;
    }

    if (disponibles[pos] > 0) {
      disponibles[pos]--;
      printf("\nPréstamo exitoso. Quedan %d ejemplares disponibles de '%s'.\n", disponibles[pos], codigos); // Nota: se imprime el disponible

    } else {
       printf("\nAviso: No hay ejemplares disponibles para este libro.\n");
    }
}

// Marca el estado de un libro como 0 (dado de baja) 
void darDeBaja(int estados[], const int codigos[], int n) {
    int codigoBuscado = leerEntero(100, 999, "Ingrese el código del libro a dar de baja: ");
    int pos = buscarCodigo(codigos, estados, n, codigoBuscado);

   if (pos == -1) {
      printf("\nNo existe un libro activo con el código %d.\n", codigoBuscado);
        return;
    }

    estados[pos] = 0;
    printf("\nLibro dado de baja exitosamente.\n");
}

// Busca un libro activo por código y muestra su información 
void buscarLibro(const int codigos[], const char titulos[][TAM_TITULO], const int disponibles[], const int estados[], int n) {
    int codigoBuscado = leerEntero(100, 999, "Ingrese el código del libro a buscar: ");
    int pos = buscarCodigo(codigos, estados, n, codigoBuscado);

   if (pos == -1) {
     printf("\nNo existe un libro activo con el código %d.\n", codigoBuscado);
      return;
    }

 printf("\n--- INFORMACIÓN DEL LIBRO ---\n");
  printf("Código: %d\n", codigos[pos]);
  printf("Título: %s\n", titulos[pos]);
   printf("Disponibles: %d\n", disponibles[pos]);
}