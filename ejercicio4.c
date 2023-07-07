#include <stdio.h>

void ordenarDescendente(int numeros[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (numeros[i] < numeros[j]) {
                temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }
}

int main() {
    int numeros[10];
    int i;

    printf("Ingresa 10 numeros separados por enter:\n");

    for (i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    ordenarDescendente(numeros, 10);

    printf("Numeros ordenados de mayor a menor:\n");
    for (i = 0; i < 10; i++) {
        printf("%d\n", numeros[i]);
    }

    return 0;
}
