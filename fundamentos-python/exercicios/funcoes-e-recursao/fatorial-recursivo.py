def fatorial():
    n = int(input("digite um numero"))
    if n < 1:
        print("numero negativo,digite um numero novamente")
        return fatorial()
    multi = 1
    for i in range(n, 1, -1):
        multi = multi * i
    print(f"o resultado de {n} é: {multi}")


fatorial()
