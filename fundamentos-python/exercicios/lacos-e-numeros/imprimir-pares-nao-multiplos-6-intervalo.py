n1 = int(input("digite o numero"))
n2 = int(input("digite o numero"))
contador = 0
numero = 0
while contador < n2:
    if numero > n1 and numero < n2:
        if numero % 2 == 0:
            if numero % 6 != 0:
                print(numero)
    contador += 1
    numero += 2
