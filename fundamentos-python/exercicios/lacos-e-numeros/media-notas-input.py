soma = 0
media = 0
quantidade = 0
while True:
    nota = int(input("digite sua nota"))
    if nota > 0:
        quantidade = quantidade + 1
        soma = soma + nota
    if nota < 0:
        media = soma/quantidade
        print(quantidade, media)
        break
