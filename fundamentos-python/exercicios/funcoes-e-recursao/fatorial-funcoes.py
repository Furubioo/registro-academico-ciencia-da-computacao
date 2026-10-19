def dados_numero():
    n = int(input("digite o número"))
    return n


def fatorial_numero(n):
    mult1 = 1
    for i in range(n, 1, -1):
        mult1 = mult1 * i
    print(f"resultado do fatorial{mult1}")


n = dados_numero()
fatorial_numero(n)
