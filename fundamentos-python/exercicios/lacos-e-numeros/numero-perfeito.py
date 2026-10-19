n = int(input("digite o numero"))
soma = 0
for i in range(1, n + 1):
    if n % i == 0 and i < n:
        soma = soma + i
if soma == n:
    print("numero perfeito")
else:
    print("numero imperfeito")
