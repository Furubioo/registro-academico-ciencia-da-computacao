def dados_parametros():
    n = int(input("digite o primeiro numero"))
    n1 = int(input("digite o segundo numero"))
    return n, n1


def calculo_parametros(n, n1):
    if n > n1:
        print(f"{n} é maior.")
    else:
        print(f"{n1} é maior")


def calculo_média(n, n1):
    média = (n + n1) / (2)
    print(f"{média}resultado da média")


n, n1 = dados_parametros()
calculo_parametros(n, n1)
calculo_média(n, n1)
