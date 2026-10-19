def calculo():
    n = int(input("digite o primeiro numero inteiro"))
    n1 = int(input("digite o segundo numero inteiro"))
    if n < n1:
        print("digite novamente")
        return calculo()
    if n1 == 0:
        print("não é possível dividir por zero, digite novamente")
        return calculo()
    divisão = n/n1
    print(f"o valor da divisão é:{divisão}")
    if divisão < 0:
        print("a divisão deu um valor negativo,tente novamente ")
        return calculo()


calculo()
