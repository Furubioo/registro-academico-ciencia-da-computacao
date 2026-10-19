numeros = int(input("digite os números"))
contador = 1
soma = numeros
media = soma / contador
while numeros > 0:
    numeros = int(input("digite os números"))
    if numeros > 0:
        soma = numeros + soma
        print(soma)
        contador = contador + 1
    if numeros < 0:
        media = soma / contador
        print(media)
        break
