#include <stdio.h>

void juntarArchivos(FILE *archivoDestino, FILE *archivoOrigen) {
    char c;
    while ((c = fgetc(archivoOrigen)) != EOF) {
        fputc(c, archivoDestino);
    }
}

int main() {
    FILE *archivoDestino, *archivoOrigen;
    char nombreArchivoDestino[] = "C:\\Users\\juanan.fernandez\\Juan-Antonio\\resultado.txt";
    char nombreArchivoOrigen1[] = "C:\\Users\\juanan.fernandez\\Juan-Antonio\\archivo1.txt";
    char nombreArchivoOrigen2[] = "C:\\Users\\juanan.fernandez\\Juan-Antonio\\archivo2.txt";
    char nombreArchivoOrigen3[] = "C:\\Users\\juanan.fernandez\\Juan-Antonio\\archivo3.txt";
    
    archivoDestino = fopen(nombreArchivoDestino, "w");
    if (archivoDestino == NULL) {
        printf("Error al abrir el archivo de destino: %s\n", nombreArchivoDestino);
        return 1;
    }

    archivoOrigen = fopen(nombreArchivoOrigen1, "r");
    if (archivoOrigen == NULL) {
        printf("Error al abrir el archivo de origen 1: %s\n", nombreArchivoOrigen1);
        fclose(archivoDestino);
        return 1;
    }
    
    juntarArchivos(archivoDestino, archivoOrigen);
    fclose(archivoOrigen);
    
    archivoOrigen = fopen(nombreArchivoOrigen2, "r");
    if (archivoOrigen == NULL) {
        printf("Error al abrir el archivo de origen 2: %s\n", nombreArchivoOrigen2);
        fclose(archivoDestino);
        return 1;
    }
    
    juntarArchivos(archivoDestino, archivoOrigen);
    fclose(archivoOrigen);
    
    archivoOrigen = fopen(nombreArchivoOrigen3, "r");
    if (archivoOrigen == NULL) {
        printf("Error al abrir el archivo de origen 3: %s\n", nombreArchivoOrigen3);
        fclose(archivoDestino);
        return 1;
    }
    
    juntarArchivos(archivoDestino, archivoOrigen);
    fclose(archivoOrigen);
    
    fclose(archivoDestino);
    
    printf("Archivos juntados exitosamente en %s.\n", nombreArchivoDestino);
    
    return 0;
}
