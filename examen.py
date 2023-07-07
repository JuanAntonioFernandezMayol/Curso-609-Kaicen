def enumera(archivo):
    with open(archivo, 'r') as file:
        for i, linea in enumerate(file, start=1):
            print(f'{i}: {linea.strip()}')

def buscar(archivo, palabra):
    with open(archivo, 'r') as file:
        for i, linea in enumerate(file, start=1):
            if palabra in linea:
                print(f'Línea {i}: {linea.strip()}')

archivo = 'fichero.txt'
enumera(archivo)

palabra_buscada = input("Introduce la palabra a buscar: ")
buscar(archivo, palabra_buscada)
