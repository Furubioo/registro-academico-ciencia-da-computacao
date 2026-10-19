n1 = int(input("Digite a sua primeira nota: "))
n2 = int(input("Digite a sua segunda nota: "))

media = (2 * n1 + 3 * n2)/5

if media >=7:
    print("Parabéns, você foi aprovado.")

else:
    notanecessaria = 10 - media 
    print(f"Você está na final e precisa de {notanecessaria} para passar.")

final = int(input("Digite a nota da sua final: "))

mediafinal = (media + final)/2

if mediafinal + notanecessaria >= 10:
    print("Você foi aprovado na final.")

else:
    print("Você foi reprovado na final.")
    




