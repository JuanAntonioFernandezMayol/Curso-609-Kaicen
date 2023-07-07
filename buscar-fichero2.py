def buscar_palabra(archivo, palabra):
    lineas_encontradas = []
    contador_palabra = 0
    with open(archivo, 'r') as archivo_txt:
        for linea in archivo_txt:
            palabras = linea.split()
            for p in palabras:
                if p.lower() == palabra.lower():
                    lineas_encontradas.append(linea)
                    contador_palabra += 1
    print("Líneas encontradas:")
    for linea in lineas_encontradas:
        print(linea.strip())
    print("Total de veces que aparece la palabra:", contador_palabra)

nombre_archivo = "fichero.txt"
palabra_buscar = "un"

buscar_palabra(nombre_archivo, palabra_buscar)