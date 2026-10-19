def somatorio():
    n = int(input("digite o numero"))
    soma = 0
    return n, soma


def calcular_dados(n, soma):
    for i in range(1, n + 1):
        soma += i
    print(f"resultado da soma {soma}")


n, soma = somatorio()
calcular_dados(n, soma)
