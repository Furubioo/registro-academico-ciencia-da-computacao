n1 = (int(input("digite o número")))
n2 = (int(input("digite o numero")))
soma = n1
while soma <= n2:
    if soma % 2 == 0 and soma % 6 != 0:
        print(soma)
    soma = soma + 1
