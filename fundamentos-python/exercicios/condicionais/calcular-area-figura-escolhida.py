def escolha_figura():
    figura = (input("escolha a figura geometrica"))
    return figura


def dados_triangulo():
    baset = int(input("digite o valor da base do triângulo"))
    alturat = int(input("digite o valor da altura do triângulo"))
    return baset, alturat


def dados_retâgulo():
    baser = int(input("digite o valor da base do retâgulo"))
    alturar = int(input("digite o valor da altura do retângulo"))
    return baser, alturar


def calculo_triângulo(baset, alturat):
    triângulo = baset * alturat / 2
    print(f" a area do triângulo {triângulo}")


def calculo_retângulo(baser, alturar):
    retângulo = baser * alturar
    print(f"a area do retângulo{retângulo}")


figura = escolha_figura()
if figura == "triângulo":
    baset, alturat = dados_triangulo()
    calculo_triângulo(baset, alturat)

if figura == "retângulo":
    baser, alturar = dados_retâgulo()
    calculo_retângulo(baser, alturar)
