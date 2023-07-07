import os

def obtener_ultimo_id():
    try:
        with open('coches.txt', 'r') as file:
            lineas = file.readlines()
            if lineas:
                ultimo_registro = lineas[-1]
                campos = ultimo_registro.strip().split(',')
                return int(campos[0])
            else:
                return 0
    except FileNotFoundError:
        return 0

def agregar_registro():
    os.system("cls")

    id_actual = obtener_ultimo_id() + 1

    nombre = input("Ingrese el nombre: ")
    edad = input("Ingrese la edad: ")
    marca = input("Ingrese la marca: ")
    modelo = input("Ingrese el modelo: ")

    registro = f"{id_actual},{nombre},{edad},{marca},{modelo}\n"

    with open('coches.txt', 'a') as file:
        file.write(registro)

    os.system("cls")

    print("Registro agregado exitosamente.")

def mostrar():
    os.system("cls")

    nombre_buscado = input("Ingrese el nombre a buscar: ")
    found = False
    with open('coches.txt', 'r') as file:
        for line in file:
            campos = line.strip().split(',')
            if campos[1] == nombre_buscado:
                print(f"Información completa para {nombre_buscado}:")
                print(f"ID: {campos[0]}")
                print(f"Edad: {campos[2]}")
                print(f"Marca: {campos[3]}")
                print(f"Modelo: {campos[4]}")
                found = True
                break
    if not found:
        print(f"No se encontró información para {nombre_buscado}.")

    input("Presione Enter para continuar...")
    os.system("cls")

while True:
    os.system("cls")

    print("---- Menú ----")
    print("1. Añadir un registro")
    print("2. Buscar registros")
    print("3. Salir")

    opcion = input("Ingrese la opción deseada: ")

    if opcion == "1":
        agregar_registro()
    elif opcion == "2":
        mostrar()
    elif opcion == "3":
        print("¡Hasta luego!")
        break
    else:
        print("Opción inválida. Por favor, ingrese una opción válida.")