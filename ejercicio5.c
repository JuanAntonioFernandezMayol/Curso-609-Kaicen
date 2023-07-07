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

void ejercicio1() {
    int numeros[10];
    int i, maximo;

    printf("Ingresa 10 números separados por enter:\n");

    for (i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    maximo = numeros[0];
    for (i = 1; i < 10; i++) {
        if (numeros[i] > maximo) {
            maximo = numeros[i];
        }
    }

    printf("El número máximo es: %d\n", maximo);
}

void ejercicio2() {
    int numeros[10];
    int i;

    printf("Ingresa 10 números separados por enter:\n");

    for (i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    ordenarDescendente(numeros, 10);

    printf("Números ordenados de mayor a menor:\n");
    for (i = 0; i < 10; i++) {
        printf("%d\n", numeros[i]);
    }
}

int main() {
    int opcion;

    do {
        printf("\n-- Menú --\n");
        printf("1. Ejercicio 1: Encontrar el número máximo\n");
        printf("2. Ejercicio 2: Ordenar números de mayor a menor\n");
        printf("3. Salir\n");
        printf("Ingrese la opción deseada: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            ejercicio1();
        } else if (opcion == 2) {
            ejercicio2();
        } else if (opcion == 3) {
            printf("Saliendo del programa...\n");
        } else {
            printf("Opción inválida. Por favor, ingrese una opción válida.\n");
        }
    } while (opcion != 3);

    return 0;
}
