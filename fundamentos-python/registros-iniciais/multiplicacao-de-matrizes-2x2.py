n1 = int(input("Digite o primeiro número da matriz 1: "))
n2 = int(input("Digite o segundo número da matriz 1: "))
n3 = int(input("Digite o terceiro número da matriz 1: "))
n4 = int(input("Digite o quarto número da matriz 1: "))
print(f"\n[{n1} {n2}]")
print(f"[{n3} {n4}]\n")
print("Essa é a sua primeira matriz 2x2.")

n5 = int(input("Digite o primeiro número da matriz 2: "))
n6 = int(input("Digite o segundo número da matriz 2: "))
n7 = int(input("Digite o terceiro número da matriz 2: "))
n8 = int(input("Digite o quarto número da matriz 2: "))
print(f"\n[{n5} {n6}]")
print(f"[{n7} {n8}]\n")
print("Essa é a sua segunda matriz 2x2.")

multmatriz1 = (n1 * n5) + (n2 * n7)
multmatriz2 = (n1 * n6) + (n2 * n8)
multmatriz3 = (n3 * n5) + (n4 * n7)
multmatriz4 = (n3 * n6) + (n4 * n8)


questionamento = (input("Deseja realizar a multiplicação entre as matrizes? "))

if questionamento == 'sim':
    print("A multiplicação entre as matrizes é: ")
    print(f"[{multmatriz1} {multmatriz2}]")
    print(f"[{multmatriz3} {multmatriz4}] .")
else:
    print("Decisão aceita, fim do código.")
    