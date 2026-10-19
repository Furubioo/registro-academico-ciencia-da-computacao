a = int(input("digite o coeficiente a "))
b = int(input("digite o coenficiente b "))
c = int(input("digite o coeficiente c "))
if a == 0:
    print("isso nao e uma equaçao de segundo grau(a deve ser diferente de 0) ")
else:
    delta = b**2 - 4*a*c
    print(f"(delta)= {delta}")
    if delta > 0:
        print("a equaçao possui duas raizes reais e diferentes ")
    elif delta == 0:
        print("a equaçao possui duas raizes reais e iguais ")
    else:
        print("a equaçao possui duas raizes complexas ")
