quantidade = 0
soma = 0
while True:
    n = int(input("digite os números"))
    if n % 2 != 0:
        quantidade = quantidade + 1
    if n != 0:
        continue
    if n == 0:
        print(quantidade)
        break
