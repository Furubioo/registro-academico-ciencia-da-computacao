def somatorio():
    n = int(input("digite o numero"))
    if n < 1:
        print("por favor,insira um numero positivo maior ou igual a 1.")
        return somatorio()
    soma = sum(range(1, n + 1))
    print(f"o somatorio de 1 ate{n} é: {soma}")


somatorio()
