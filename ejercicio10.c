#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CIUDADES 100
#define MAX_CALLES 100

typedef struct {
    int id;
    char nombre[50];
} Ciudad;

typedef struct {
    int idCalle;
    int idCiudad;
    char nombreCalle[50];
    float valorViento;
} Sensor;

typedef struct {
    char nombreCiudad[50];
    char nombreCalle[50];
    float valorViento;
} DatosSensor;

Ciudad ciudades[MAX_CIUDADES];
Sensor sensores[MAX_CALLES];
DatosSensor datosSensores[MAX_CALLES];
int numCiudades = 0;
int numSensores = 0;

void cargarDatos() {
    FILE *archivoCiudades, *archivoSensores;
    char linea[100];

    // Cargar ciudades
    archivoCiudades = fopen("C:/Users/juanan.fernandez/Juan-Antonio/ciudades.txt", "r");
    if (archivoCiudades == NULL) {
        printf("No se pudo abrir el archivo ciudades.txt\n");
        exit(1);
    }

    while (fgets(linea, sizeof(linea), archivoCiudades) != NULL) {
        sscanf(linea, "%d %[^\n]", &ciudades[numCiudades].id, ciudades[numCiudades].nombre);
        numCiudades++;
    }

    fclose(archivoCiudades);

    // Cargar sensores
    archivoSensores = fopen("C:/Users/juanan.fernandez/Juan-Antonio/sensores.txt", "r");
if (archivoSensores == NULL) {
    printf("No se pudo abrir el archivo sensores.txt\n");
    exit(1);
}

while (fgets(linea, sizeof(linea), archivoSensores) != NULL) {
    sscanf(linea, "%d %d %s %f", &sensores[numSensores].idCalle, &sensores[numSensores].idCiudad, sensores[numSensores].nombreCalle, &sensores[numSensores].valorViento);
    numSensores++;
}

fclose(archivoSensores);

}

void mostrarDatos() {
    printf("=== Ciudades ===\n");
    for (int i = 0; i < numCiudades; i++) {
        printf("ID: %d, Nombre: %s\n", ciudades[i].id, ciudades[i].nombre);
    }

    printf("\n=== Sensores ===\n");
    for (int i = 0; i < numSensores; i++) {
        printf("ID Calle: %d, ID Ciudad: %d, Nombre Calle: %s, Valor Viento: %.2f\n",
            sensores[i].idCalle, sensores[i].idCiudad, sensores[i].nombreCalle, sensores[i].valorViento);
    }

    printf("\n");
}

void consultarCiudad() {
    char ciudadBuscada[50];

    printf("Introduce el nombre de la ciudad: ");
    fgets(ciudadBuscada, sizeof(ciudadBuscada), stdin);
    ciudadBuscada[strcspn(ciudadBuscada, "\n")] = '\0'; // Eliminar el carácter de nueva línea

    printf("\n=== Resultado ===\n");

    float sumaVientos = 0;
    int totalSensores = 0;
    int encontrado = 0;

    for (int i = 0; i < numSensores; i++) {
        if (strcmp(ciudades[sensores[i].idCiudad - 1].nombre, ciudadBuscada) == 0) {
            printf("Ciudad: %s, Calle: %s, Valor Viento: %.2f\n", ciudadBuscada, sensores[i].nombreCalle, sensores[i].valorViento);
            sumaVientos += sensores[i].valorViento;
            totalSensores++;
            encontrado = 1;
        }
    }

    if (encontrado) {
        printf("Media del viento en la ciudad: %.2f\n", sumaVientos / totalSensores);
    } else {
        printf("No se encontraron sensores para la ciudad especificada.\n");
    }

    printf("\n");
}


void consultarCalleVientoMayor50() {
    char ciudadBuscada[50];

    printf("Introduce el nombre de la ciudad: ");
    fgets(ciudadBuscada, sizeof(ciudadBuscada), stdin);
    ciudadBuscada[strcspn(ciudadBuscada, "\n")] = '\0'; // Eliminar el carácter de nueva línea

    printf("\n=== Resultado ===\n");

    int encontrado = 0;
    for (int i = 0; i < numSensores; i++) {
        if (strcmp(ciudades[sensores[i].idCiudad].nombre, ciudadBuscada) == 0 && sensores[i].valorViento > 50.0) {
            printf("Calle: %s, Valor Viento: %.2f\n", sensores[i].nombreCalle, sensores[i].valorViento);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se encontraron calles con viento mayor a 50 km/h en la ciudad especificada.\n");
    }

    printf("\n=== Ciudades ===\n");
    for (int i = 0; i < numCiudades; i++) {
        printf("Nombre Ciudad: %s\n", ciudades[i].nombre);
    }

    printf("\n");
}


int main() {
    int opcion;

    cargarDatos();

    do {
        printf("=== Menú ===\n");
        printf("1. Mostrar todos los datos\n");
        printf("2. Consultar datos de una ciudad\n");
        printf("3. Consultar calles con viento mayor a 50km/h\n");
        printf("4. Salir\n");
        printf("Introduce tu opción: ");
        scanf("%d", &opcion);
        getchar(); // Consumir el carácter de nueva línea

        printf("\n");

        switch (opcion) {
            case 1:
                mostrarDatos();
                break;
            case 2:
                consultarCiudad();
                break;
            case 3:
                consultarCalleVientoMayor50();
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Inténtalo de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}
