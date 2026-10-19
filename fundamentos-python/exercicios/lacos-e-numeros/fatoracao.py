fatoraçao = int(input("digite o numero"))
n = 1
for i in range(fatoraçao, 0, -1):
    n = i * n
print(n)
