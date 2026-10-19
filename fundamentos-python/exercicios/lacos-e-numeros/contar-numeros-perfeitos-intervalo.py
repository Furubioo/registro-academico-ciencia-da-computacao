n1 = int(input("digite o numero"))
n2 = int(input("digite o numero"))
contador = 0
for i in range(n1, n2 + 1):
    soma = 0
    for k in range(1, i):
        if i % k == 0:
            soma = soma + k
    if i == soma:
        contador = contador + 1
print(f"a quantidade de numeros perfeito e {contador}")
