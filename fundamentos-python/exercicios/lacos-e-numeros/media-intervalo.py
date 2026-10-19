n1 = int(input("digite o numero"))
n2 = int(input("digite o numero"))
soma = 0
media = 0
quantidade = 0
for i in range(n1, n2 + 1):
    soma = soma + i
    quantidade = quantidade + 1
    media = soma/quantidade
print(media)
