numero1 = int(input("digite o numero1 "))
numero2 = int(input("digite o numero2 "))
numero3 = int(input("digite o numero3 "))
if numero1 == numero2 and numero2 == numero1:
    print(f"o primeiro e o segundo sao iguais{numero3} e diferente ")
elif numero3 == numero1 and numero1 == numero3:
    print(f"o terceiro e o primeiro sao iguais{numero2} e diferente ")
elif numero2 == numero3 and numero3 == numero2:
    print(f"o segundo e o terceiro sao iguais{numero1} e diferente ")
elif numero1 != numero2 != numero3:
    print("os tres sao diferentes ")
