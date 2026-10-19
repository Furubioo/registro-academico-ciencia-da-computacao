def escolha_numero():
    numero = int(input("digite o numero"))
    return numero


def numero_par_ou_impar(numero):
    if numero % 2 == 0:
        print("numero par")
    else:
        print("numero impar")


def numero_perfeito(numero):
    soma = 0
    for i in range(1, numero):
        if numero % i == 0:
            soma = soma + i
    if soma == numero:
        print("numero perfeito")
    else:
        print("numero não perfeito")


def numero_primo(numero):
    if numero < 2:
        print("não é numero primo")
        return
    primo = True
    for j in range(2, numero):
        if numero % j == 0:
            primo = False
            break
    if primo:
        print("numero primo")
    else:
        print("não é numero primo")


numero = escolha_numero()
numero_par_ou_impar(numero)
numero_perfeito(numero)
numero_primo(numero)
