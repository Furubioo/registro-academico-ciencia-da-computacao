conta = int(input("informe o valor da conta em reais "))
pessoas = int(input("informe a quantidade de pessoas "))
desconto1 = 10/100 * conta
desconto2 = 5/100 * conta
if conta > 150 and pessoas > 4:
    descontototal = conta - desconto1
    print(f"o valor da conta e {descontototal}")
else:
    descontototal2 = conta - desconto2
    print(f"o valor da contae e {descontototal2}")
