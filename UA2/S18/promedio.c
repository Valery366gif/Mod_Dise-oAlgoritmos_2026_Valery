// promedio.c genera promedio de notas enteras

#include <stdio.h>

int main(void){

    // 3 notas enteras y su suma
    int nota1, nota2, nota3, suma;
    // dos resultados reales para comparar
    double promedioMal, promedioBien;

    // ENTRADAS Y LECTURAS   notas 80, 75 y 90
    printf("Digite las 3 notas: ");
    scanf("%d %d %d", &nota1, &nota2, &nota3);

    //PROCESOS: suma de enterod -> 245
    suma = nota1 + nota2 + nota3;
    
    // int / int = division entera: 245 / 3 = 81, se guarda como 81.0
    promedioMal = suma / 3;

    // (double) convierte suma a 245.0 antes de dividir -> 81.66666....
    promedioBien = (double) suma / 3;

    // SALIDAS: sin casting 81.0 y con casting 81.67
    printf("Sin casting: %.2f\n", promedioMal);
    printf("Con casting: %.2f\n", promedioBien);

    return 0;
}