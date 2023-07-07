#include <stdio.h>

int main() {
    int numeros[10];
    int i, maximo;

    printf("Ingresa 10 numeros separados por enter:\n");

    for (i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    maximo = numeros[0];
    for (i = 1; i < 10; i++) {
        if (numeros[i] > maximo) {
            maximo = numeros[i];
        }
    }

    printf("El numero máximo es: %d\n", maximo);

    return 0;
}
