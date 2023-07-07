#include <stdio.h>

void ordenarNumeros(float numeros[], int cantidadNumeros) {
    int i, j;
    float temp;

    for (i = 0; i < cantidadNumeros - 1; i++) {
        for (j = 0; j < cantidadNumeros - i - 1; j++) {
            if (numeros[j] < numeros[j + 1]) {
                temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
}

float calcularMedia(int cantidadNumeros) {
    int i, numero;
    int suma = 0;

    for (i = 0; i < cantidadNumeros; i++) {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &numero);
        suma += numero;
    }

    return (float)suma / cantidadNumeros; // Calcula la media dividiendo la suma entre la cantidad de números
}

int main() {
    int cantidadNumeros;

    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &cantidadNumeros);

    float numeros[cantidadNumeros];
    int i;

    for (i = 0; i < cantidadNumeros; i++) {
        numeros[i] = calcularMedia(1);
    }

    ordenarNumeros(numeros, cantidadNumeros);

    printf("La media de los numeros ingresados es %.2f\n", numeros[0]);

    printf("Numeros ordenados de mayor a menor: ");
    for (i = 0; i < cantidadNumeros; i++) {
        printf("%.2f ", numeros[i]);
    }
    printf("\n");

    return 0;
}

