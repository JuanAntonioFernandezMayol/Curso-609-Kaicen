import math

def calcular_perimetro(radio):
    perimetro = 2 * math.pi * radio
    return perimetro

def calcular_superficie(radio):
    superficie = math.pi * (radio ** 2)
    return superficie

while True:
    print("1. Calcular perímetro")
    print("2. Calcular superficie")
    print("3. Salir")
    
    opcion = input("Ingrese el número de la opción que desea: ")
    
    if opcion == "1":
        radio = float(input("Ingrese el radio de la circunferencia: "))
        perimetro = calcular_perimetro(radio)
        print("El perímetro de la circunferencia es:", perimetro)
    elif opcion == "2":
        radio = float(input("Ingrese el radio de la circunferencia: "))
        superficie = calcular_superficie(radio)
        print("La superficie de la circunferencia es:", superficie)
    elif opcion == "3":
        break
    else:
        print("Opción inválida. Por favor, ingrese un número válido.")
