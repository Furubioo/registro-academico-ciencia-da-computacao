senhacorreta = 164209
senha = int(input("digite a senha"))
while senha != senhacorreta:
    print("acesso negado")
    senha = int(input("digite a senha"))
print("acesso permitido")
