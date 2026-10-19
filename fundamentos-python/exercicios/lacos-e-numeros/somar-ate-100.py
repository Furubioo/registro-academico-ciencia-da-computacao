quantidade = 0
soma = 0
while True:
    n = int(input("digite os números"))
    if n >= 0:
        quantidade = quantidade + 1
        soma = soma + n
    if soma > 100:
        print(f" o valor da soma ultrapassou 100 {soma} {quantidade} ")
        break
