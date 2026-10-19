1.
# primeiro_numero = int(input("Digite o primeiro número: "))
# segundo_numero = int(input("Digite o segundo número: "))
# terceiro_numero = int(input("Digite o terceiro número: "))

# if primeiro_numero == segundo_numero and primeiro_numero != terceiro_numero:
#     print("O primeiro e segundo números são iguais, e o terceiro é diferente.")
# elif primeiro_numero == terceiro_numero and primeiro_numero != segundo_numero:
#     print("O primeiro e o terceiro números são iguais, e o segundo é diferente.")
# elif segundo_numero == primeiro_numero and segundo_numero != terceiro_numero:
#     print("O segundo e o primeiro números são iguais, e o terceiro é diferente.")
# elif segundo_numero == terceiro_numero and segundo_numero != primeiro_numero:
#     print("O segundo e o terceiro números são iguais, e o primeiro é diferente. ")
# elif terceiro_numero == primeiro_numero and terceiro_numero != segundo_numero:
#     print("O terceiro e o primeiro números são iguais, e o segundo é o diferente.")
# elif terceiro_numero == segundo_numero and terceiro_numero != primeiro_numero:
#     print("O terceiro e o segundo números são iguais, e o primeiro é diferente.")
# else:
#     print("Os três números são diferentes.")

# ------------------------------- // --------------------------------------------------
2.

# idade = int(input("Informe a sua idade: "))
# experiencia = int(input("Informe a sua experiência em anos: "))

# if idade < 18 and experiencia <=1:
#     print("Você possui um alto risco.")
# elif idade >=18 and idade <=60 and experiencia >=1 and experiencia <=5:
#     print("Você possui um risco médio.")
# elif experiencia >5:
#     print("Você possui um baixo risco.")

# ------------------------------- // --------------------------------------------------
3.

# conta = int(input("Informe o valor da conta em R$: "))
# pessoas = int(input("Informe a quantidade de pessoas: "))
# conta1 = 10/100 * conta
# conta2 = 5/100 * conta

# if pessoas > 4 and conta > 150:
#     desconto1 = conta - conta1
#     print(f"O valor da conta é de {desconto1}.")

# else:
#     desconto2 = conta - conta2
#     print(f"O valor da conta é de {desconto2}.")

# ------------------------------- // --------------------------------------------------

4. 

# coeficiente_a = int(input("Informe o coeficiente a: "))
# coeficiente_b = int(input("Informe o coeficiente b: "))
# coeficiente_c = int(input("Informe o coeficiente c: "))
# delta = coeficiente_b * coeficiente_b - 4 * coeficiente_a * coeficiente_c
# raiz_quadrada_delta = delta ** 1/2
# raiz1 = - coeficiente_b + raiz_quadrada_delta /2 * coeficiente_a
# raiz2 = - coeficiente_b - raiz_quadrada_delta /2 * coeficiente_a

# print(f"O discriminante é: {delta}")

# if raiz_quadrada_delta < 0:
#     print("As raízes são complexas.")

# elif raiz1 != raiz2:
#     print("As raízes são reais e diferentes.")

# elif raiz1 == raiz2:
#     print("As raízes são reais e iguais.")

# if coeficiente_a == 0:
#     print("Não é uma equação do segundo grau")


# ------------------------------- // --------------------------------------------------

5.

# tipo_de_veiculo = str(input("Informe o tipo de veículo: "))

# tempo_permanencia = int(input("Informe o tempo de permanência: "))

# if tipo_de_veiculo == "carro":
#     valor_a_pagar1 = 5 * tempo_permanencia
#     print(f"Você pagará R${valor_a_pagar1},00 reais.")

# elif tipo_de_veiculo == "moto":
#     valor_a_pagar2 = 3 * tempo_permanencia
#     print(f"Você pagará R${valor_a_pagar2},00 reais.")

# elif tipo_de_veiculo == "outros":
#     valor_a_pagar3 = 7 * tempo_permanencia
#     print(f"Você pagará {valor_a_pagar3},00 reais.")

# ------------------------------- // --------------------------------------------------
6.

# print("*****Sorteio de letra do alfabeto*****")
# print("De A a Z(minúsculos), adivinhe qual é a letra!")

# tentativa1 = str(input("Primeira tentativa: "))
# if tentativa1 == "k":
#   print("A letra sorteada era K, você acertou!!")
# elif tentativa1 != "k":
#    print("Você errou a letra sorteada! Ainda há mais uma chance!")

# tentativa2 = str(input("Segunda tentativa: "))
# if tentativa2 == "k":
#    print("A letra sorteada era K, você acertou!")
# else:
#    print("Você não acertou a letra sorteada :/")

# nova_tentativa = str(input("Deseja tentar mais uma vez? Obviamente, a letra será diferente.\n:"))
# if nova_tentativa == "sim":
#  print("*****Sorteio de letra do alfabeto*****")
#  print("De A a Z(minúsculos), adivinhe qual é a letra!")

#  tentativa3 = str(input("Primeira tentativa: "))
#  if tentativa3 == "f":
#   print("A letra sorteada era K, você acertou!!")
#  elif tentativa3 != "f":
#    print("Você errou a letra sorteada! Ainda há mais uma chance!")

#  tentativa4 = str(input("Segunda tentativa: "))
#  if tentativa4 == "f":
#    print("A letra sorteada era K, você acertou!")
#  elif tentativa4 != "f":
#     print("Você não acertou a letra sorteada :/")

# else:
#    print("Fim do sorteio.")

# ------------------------------- // ----------------------------------------------------------------------
7.

# media = int(input("Qual é a sua média? "))
# presença = int(input("Em %(percentual), qual é a sua presença? "))

# if media >= 7 and presença >=75:
#     print("Parabéns! Você está elegível para participar da competição de robótica.")
# elif media <7 and presença >=75:
#     print("Infelizmente, devido à sua média, você não está apto para participar da competição de robótica.")
# elif media >=7 and presença <75:
#     print("Infelizmente, devido à sua presença, você não poderá participar da competição de robótica.")
# elif media <7 and presença <75:
#     print("Infelizmente, devido à sua média e presença, você não poderá participar da competição de robótica.")



    
   