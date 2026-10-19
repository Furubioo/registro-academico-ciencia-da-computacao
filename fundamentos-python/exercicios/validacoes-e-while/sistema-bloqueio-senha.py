contador = 3
while True:
    senha = int(input("digite a senha correta"))
    senha_correta = 1234
    if senha != senha_correta:
        contador = contador - 1
        print("acesso bloqueado")
    if senha == senha_correta:
        print("acesso concedido")
        break
    if contador == 0:
        print("o número de tentativas acabou")
        break
