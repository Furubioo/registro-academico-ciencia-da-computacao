numero = (int(input("digite os números")))
pares = 0
impares = 0
while numero != 0:
    if numero % 2 == 0:
        pares += 1
    else:
        impares += 1
    numero = (int(input("digite 0, codigo finalizado")))
print("pares", pares)
print("impares", impares)
