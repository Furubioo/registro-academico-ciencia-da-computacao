def dados_equação_2grau():
    a = int(input("digite os numeros"))
    b = int(input("digite os numeros"))
    c = int(input("digite os numeros"))
    return a, b, c


def calculo_delta(a, b, c):
    delta = b**2 - 4 * a*c
    return delta


def calculo_x1(delta, a, b):
    x1 = (- b + (delta ** 0.5))/(2*a)
    print(f"a primeira raiz {x1}")


def calculo_x2(delta, a, b):
    x2 = (- b - (delta ** 0.5))/(2*a)
    print(f"a segunda raiz {x2}")


a, b, c = dados_equação_2grau()
if a == 0:
    print("não é uma equação de segundo grau (a deve ser diferente de 0)")
else:
    delta = calculo_delta(a, b, c)
    calculo_x1(delta, a, b)
    calculo_x2(delta, a, b)
