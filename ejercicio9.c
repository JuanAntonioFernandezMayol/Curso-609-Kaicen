#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE *archivo;
    char linea[MAX_LINE_LENGTH];

    archivo = fopen("C:/Users/juanan.fernandez/Juan-Antonio/datos.txt", "r"); // Reemplaza "datos.txt" por la ruta y nombre de tu archivo

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    while (fgets(linea, MAX_LINE_LENGTH, archivo) != NULL) {
        // Aquí puedes procesar la línea y extraer los datos que necesites
        // Por ejemplo, supongamos que el archivo contiene números enteros separados por espacios:

        int numero;
        char *ptr = linea;

        while (*ptr != '\0') {
            numero = strtol(ptr, &ptr, 10); // Convierte el valor al siguiente número entero encontrado
            printf("Número: %d\n", numero);
        }
    }

    fclose(archivo);

    return 0;
}
