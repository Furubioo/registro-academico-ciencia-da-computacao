def area_retangulo():
    base_r = int(input("digite o valor da base"))
    altura_r = int(input("digite o valor da altura"))
    area = base_r * altura_r
    if area:
        print(f"area do retangulo: {area}")
    return area

area_retangulo()
