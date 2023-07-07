cadena_busqueda = input("Ingrese la cadena de texto a buscar: ")

try:
    nombre_archivo = "C:/Users/juanan.fernandez/Juan-Antonio/fichero.txt"
except:
    print("Error de fichero")

with open(nombre_archivo, 'r') as archivo:

    for linea in archivo:
        if cadena_busqueda in linea:
            print(linea)


archivo.close()