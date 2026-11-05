#include <stdio.h>

// ERROR: La función estaba declarada como void y recibía los parámetros por valor.
// POR QUE: Al pasar 'puntos' por valor, los cambios realizados dentro de la función no afectaban a la variable 'puntos' del main.
// CORRECCION: Se cambió el tipo de retorno a 'int' para devolver la suma actualizada de los puntos.
int sumarPuntos (int puntos, int compra) {
  return puntos + compra / 1000;
}

int main(void) {
    int puntos = 0, compra, i;

    for (i = 1; i <= 3; i++) {
        printf("Compra %d: ", i);

        //ERROR: Faltaba el operador de dirrección (´&´) en el scanf
        //POR QUÉ: La funcion scanf requiere obligatoriamente la dirreción de memoria de la variable (&compra) para almacenar  el valor ingresado por el usuario.
        //CORRECION: Se corrigío a scanf("%d", &compra);
        scanf("%d", &compra);

        //ERROR: No se estsba guardando el resultado devuelto por la funcion sumarPuntos.
        //POR QUÉ: Aunque la funcion calculaba la suma, la variable 'puntos' en el main nunca se actualizaba
        //CORRECION: Se asignó el resultado a la variable puntos: puntos = sumarPuntos(puntos, compra);
       puntos = sumarPuntos(puntos, compra);
    }

    printf("Puntos acumulados: %d\n", puntos);
    return 0;
}
