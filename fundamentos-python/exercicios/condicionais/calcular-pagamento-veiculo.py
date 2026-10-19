veiculo = str(input("informe seu veiculo "))
horas = int(input("informe as horas "))
if veiculo == "carro":
    pagamento1 = 5*horas
    print(f"o valor do pagamento{pagamento1}")
elif veiculo == "moto":
    pagamento2 = 3*horas
    print(f"o valor do pagamento{pagamento2}")
elif veiculo == "outros":
    pagamento3 = 7*horas
    print(f"o valor do pagamento{pagamento3}")
