def dados():
    palavra = (input("digite a palavra"))
    return palavra


def filtra_vogais(palavra):
    for i in palavra:
        if i != "a" and i != "e" and i != "i" and i != "o" and i != "u":
            print(i)


palavra = dados()
filtra_vogais(palavra)
