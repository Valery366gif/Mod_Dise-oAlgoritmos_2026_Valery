#include <stdio.h>
int main(void) {
    int edad;
    printf("Edad: ");
    scanf("%d", &edad); //faltaba el &
    printf("Edad: %d\n", edad);
    return 0;
}
