/*
 * Enunciado: Crear una cuenta de usuario pidiendo el nombre completo, armando el nombre de usuario
 * con la primera letra y el primer apellido, pidiendo contrasena y confirmacion con validaciones.
 * Que se logra: Automatizar la generacion de cuentas de usuario y validacion robusta de credenciales.
 * Como se logra: Leyendo cadenas con espacios usando fgets y strcspn, recorriendo caracteres para hallar
 * espacios, copiando subcadenas con strcpy y strcat, y validando longitudes con strlen y comparaciones con strcmp.
 * Resultado esperado: Mostrar el usuario generado con su longitud y un mensaje de cuenta creada con exito.
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    // nombre_completo: cadena para almacenar el nombre completo ingresado.
    char nombre_completo[100];
    // usuario: cadena para almacenar el nombre de usuario generado (inicial + apellido).
    char usuario[50];
    // contrasena: cadena para almacenar la contrasena ingresada.
    char contrasena[50];
    // confirmacion: cadena para almacenar la confirmacion de la contrasena.
    char confirmacion[50];
    // mensaje_final: cadena resultante de unir partes con strcpy y strcat.
    char mensaje_final[150];
    // i, j: variables de control e indices.
    int i = 0, j = 0;
    // primer_espacio: posicion del primer espacio encontrado en el nombre completo.
    int primer_espacio = -1;
    // largo_usuario: longitud de la cadena del usuario generado.
    int largo_usuario = 0;

    // Pedir nombre completo (con espacios, no vacio)
    do {
        printf("Nombre completo: ");
        fgets(nombre_completo, sizeof(nombre_completo), stdin);
        nombre_completo[strcspn(nombre_completo, "\n")] = '\0';
    } while (strlen(nombre_completo) == 0);

    // Armar el nombre de usuario: primera letra + primer apellido
    for (i = 0; nombre_completo[i] != '\0'; i++) {
        if (nombre_completo[i] == ' ') {
            primer_espacio = i;
            break;
        }
    }

    if (primer_espacio == -1) {
        strcpy(usuario, nombre_completo);
    } else {
        usuario[0] = nombre_completo[0];
        j = 1;
        for (i = primer_espacio + 1; nombre_completo[i] != '\0' && nombre_completo[i] != ' '; i++) {
            usuario[j] = nombre_completo[i];
            j++;
        }
        usuario[j] = '\0';
    }

    // Pedir contrasena y confirmacion con validaciones
    while (1) {
        printf("Contrasena (minimo 8 caracteres): ");
        fgets(contrasena, sizeof(contrasena), stdin);
        contrasena[strcspn(contrasena, "\n")] = '\0';

        if (strlen(contrasena) < 8) {
            printf("Muy corta: debe tener al menos 8 caracteres\n");
            continue;
        }

        printf("Confirme la contrasena: ");
        fgets(confirmacion, sizeof(confirmacion), stdin);
        confirmacion[strcspn(confirmacion, "\n")] = '\0';

        if (strcmp(contrasena, confirmacion) != 0) {
            printf("Las contrasenas no coinciden\n");
            continue;
        }

        break;
    }

    // Mostrar usuario y mensaje final usando strcpy y strcat
    largo_usuario = strlen(usuario);
    printf("Usuario: %s (%d caracteres)\n", usuario, largo_usuario);

    strcpy(mensaje_final, "Cuenta creada para ");
    strcat(mensaje_final, nombre_completo);
    printf("%s\n", mensaje_final);

    return 0;
}