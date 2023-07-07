def cargar_distancias():
    distancias = {}
    with open("distancias.txt", "r") as archivo:
        ciudades = archivo.readline().split()
        for ciudad in ciudades:
            distancias[ciudad] = {}
        for linea in archivo:
            valores = linea.split()
            ciudad_origen = valores[0]
            for i in range(1, len(valores)):
                ciudad_destino = ciudades[i-1]
                distancia = int(valores[i])
                distancias[ciudad_origen][ciudad_destino] = distancia
    return distancias

def mostrar_menu():
    print("1. Calcular distancia entre dos ciudades")
    print("2. Ciudades más alejadas")
    print("3. Salir")

def calcular_distancia(ciudad_origen, ciudad_destino, distancias):
    try:
        distancia = distancias[ciudad_origen][ciudad_destino]
        print(f"La distancia entre {ciudad_origen} y {ciudad_destino} es de {distancia} km.")
    except KeyError:
        print("Las ciudades ingresadas no son válidas.")

def ciudades_mas_alejadas(distancias):
    max_distancia = 0
    ciudad_origen = ""
    ciudad_destino = ""

    for ciudad1 in distancias:
        for ciudad2 in distancias[ciudad1]:
            distancia = distancias[ciudad1][ciudad2]
            if distancia > max_distancia:
                max_distancia = distancia
                ciudad_origen = ciudad1
                ciudad_destino = ciudad2

    print(f"Las ciudades más alejadas son {ciudad_origen} y {ciudad_destino}.")
    print(f"La distancia entre ellas es de {max_distancia} km.")

# Programa principal
distancias = cargar_distancias()

while True:
    mostrar_menu()
    opcion = input("Ingrese una opción: ")

    if opcion == "1":
        ciudad_origen = input("Ingrese la ciudad de origen: ")
        ciudad_destino = input("Ingrese la ciudad de destino: ")
        calcular_distancia(ciudad_origen, ciudad_destino, distancias)
    elif opcion == "2":
        ciudades_mas_alejadas(distancias)
    elif opcion == "3":
        print("¡Hasta luego!")
        break
    else:
        print("Opción inválida. Por favor, ingrese una opción válida.")
