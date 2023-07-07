def fibonacci(n):
    sequence = [0, 1]
    if n == 0:
        return []
    elif n == 1:
        return [0]
    elif n == 2:
        return sequence

    for i in range(2, n):
        next_element = sequence[i-1] + sequence[i-2]
        sequence.append(next_element)

    return sequence

num_elements = int(input("Ingrese el número de elementos de la serie de Fibonacci que desea visualizar: "))

fib_sequence = fibonacci(num_elements)
print("Serie de Fibonacci:")
for num in fib_sequence:
    print(num)
