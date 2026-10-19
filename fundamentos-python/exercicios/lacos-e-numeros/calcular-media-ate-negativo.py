contador = 0
soma = 0
media = 0
while 0 < 1:
    n = int(input("digite o numero"))
    if n > 0:
        contador = contador + 1
        soma = n + soma
        print(soma)
    if n < 0:
        media = soma / contador
        print(media)
        break
