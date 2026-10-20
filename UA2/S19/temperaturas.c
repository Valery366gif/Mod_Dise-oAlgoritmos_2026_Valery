// temperaturas.c - Temperaturas de una semana
// ENUNCIADO: pedir la temperatura (grados enteros) de cada uno de los 7
//   dias de la semana. Un dato fuera del rango -10 a 45 se rechaza y se
//   vuelve a pedir para el mismo dia. Al final mostrar el promedio con un
//   decimal, la temperatura maxima y cuantos dias fueron calurosos (mas
//   de 30 grados).
// QUE SE LOGRA: validar cada dato y resumir la semana en tres resultados.
// COMO SE LOGRA: un for de 7 vueltas (un dia por vuelta); dentro, un
//   do-while que repite la pregunta mientras el dato sea invalido; un
//   acumulador para la suma, una comparacion para la maxima y un contador
//   para los dias calurosos; el promedio se calcula con casting a float.
// RESULTADO ESPERADO: con 28 31 50 29 33 27 30 26 -> el 50 se rechaza,
//   Promedio: 29.1 grados, Maxima: 33 grados, Dias calurosos: 2
#include <stdio.h>                    // printf y scanf
#define DIAS 7                        // cantidad de dias de la semana
#define MINIMA -10                    // menor temperatura aceptada
#define MAXIMA 45                     // mayor temperatura aceptada

int main(void) {
    int temp;              // temperatura digitada para un dia
    int suma = 0;          // ACUMULADOR: suma de las temperaturas validas
    int maxima = MINIMA;   // mayor temperatura (inicia en el minimo posible)
    int calurosos = 0;     // CONTADOR de dias con mas de 30 grados
    int i;                 // contador del for: dia actual (0 a 6)
    float promedio;        // promedio de la semana, con decimales

    printf("=== Temperaturas de la semana ===\n");
    // FOR: una vuelta por dia -> i = 0, 1, ..., 6
  for (i = 0; i < DIAS; i++) { //se cambio la formula  "for (i = 1; i < DIAS; i++)"
        // DO-WHILE: pide el dato y lo repite mientras este fuera de rango
        do {
            printf("Temperatura dia %d: ", i + 1);
            scanf("%d", &temp);  //error corrgido le faltaba &
            if (temp < MINIMA || temp > MAXIMA)
                printf("  Fuera de rango (%d a %d)\n", MINIMA, MAXIMA);
        } while (temp < MINIMA || temp > MAXIMA); //error coregido le faltaba ; y  y se cambio la estructura "(temp >= MINIMA && temp <= MAXIMA)"

        suma = suma + temp;           // acumula -> 28, 59, 88, ...
        if (temp > maxima)            // guarda la mayor -> 33
            maxima = temp;
        if (temp > 30)             // cuenta los calurosos -> 31 y 33 // error corregido: se quitó el ; sobrante
            calurosos++;
    }

    promedio = (float)suma / DIAS;         // 204 / 7 -> 29.142857 //error corregido le faltaba (float)
    printf("\nPromedio: %.1f grados\n", promedio);
    printf("Maxima: %d grados\n", maxima);
    printf("Dias calurosos: %d\n", calurosos);
    return 0;
}
