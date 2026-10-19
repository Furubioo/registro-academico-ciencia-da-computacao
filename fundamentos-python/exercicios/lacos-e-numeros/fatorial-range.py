fatorial = int(input("Digite o número que deseja saber o fatorial: "))
mult = 1
for i in range(fatorial, 0, -1):
    mult = i * mult
print(mult)
