dia = int(input("digite o número"))
mês = int(input("digite o número"))
contador = 1
while contador > 0:
    if dia > 31 or mês > 12:
        print("invalido")
        dia = int(input("digite o número"))
        mês = int(input("digite o número"))
        continue
    contador += 1
    if dia <= 31 and mês <= 12:
        print("valido")
        break
