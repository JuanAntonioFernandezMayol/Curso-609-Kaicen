def factorial(n):
    if n>1:
        return n * factorial(n -1)
    elif n == 1:
        return 1
    
numero = int(input("Introduce el numero ")) 
resultado = factorial(numero)
print(f"El factorial de {numero} es {resultado}")