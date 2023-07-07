#include <stdio.h>

#define PI 3.14159

int main() {
    float radio, perimetro, area;

    printf("Ingrese el radio del circulo: ");
    scanf("%f", &radio);

    perimetro = 2 * PI * radio;
    area = PI * radio * radio;

    printf("El perimetro del circulo es: %.2f\n", perimetro);
    printf("El area del circulo es: %.2f\n", area);

    return 0;
}