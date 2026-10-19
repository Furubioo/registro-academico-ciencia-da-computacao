# n = int(input("Digite a quantidade de números pares que quer ver: "))

# numero = 0

# contador = 0 

# while contador < n:
#     print(numero)
#     contador = contador + 1
#     numero = numero + 2

# senha = int(input("Informe a sua senha de cinco dígitos(números): "))
# if senha == 12345:
#     print("Acesso permitido.")
# while senha != 12345:
#  senha = int(input("Tente novamente: "))
# if senha == 12345:
#    print("Acesso permitido.")

# senha_correta = 12345
# senha = int(input("Digite a senha: "))

# while senha != senha_correta:
#     senha = int(input("Tente novamente: "))
# print("Acesso permitido!")

# quantidade_numeros_pares = int(input("Digite a quantidade de números pares: "))

# numero_par_inicial = 0

# while numero_par_inicial < quantidade_numeros_pares:
#     print(numero_par_inicial * 2)
#     numero_par_inicial = numero_par_inicial + 1

# n1 = int(input("Digite o primeiro número: "))
# n2 = int(input("Digite o segundo número: "))

# n1 = n1 + 1

# while n1 < n2:
#     print(n1)
#     n1 = n1 + 1

# n1 = int(input("Digite o primeiro valor da média: "))
# n2 = int(input("Digite o segundo valor da média: "))

# media = (n1 + n2)/2

# while n1 >=0 and n2>=0:
#     media = (n1 + n2)/2
#     print(f"A sua média é: {media}")
#     n1 = int(input("Digite o primeiro valor da média: "))
#     n2 = int(input("Digite o segundo valor da média: "))
# print("Um dos números digitados não é natural. Fim do código.")

# multiplos = 0

# contador = 0

# while multiplos < 25:
#     print(multiplos)
#     multiplos = multiplos + 5
#     contador = contador + 1
    
# Questão 1: Contagem de 1 a 100 

# contador = 1
# numero = 100

# while contador <= numero:
#     print(contador)
#     contador = contador + 1

# 2 Questão: monte um sistema  de validação de email: peça um email até conter @ e .

# email = input("Digite o seu e-mail: ")

# conta = "abcdef@gmail.com"

# while email != conta:
#     print("Email incorreto, tente novamente: ")
#     email = input("Digite o seu e-mail: ")
# print("Email correto, acesso garantido.")

# 3 questão: Peça números até que o usuário digite um múltiplo de 7.

# numero = int(input("Digite o número\n: "))

# while numero % 7 != 0:
#     numero = int(input("Esse número não é múltiplo de 7, tente novamente\n: "))
# print("O número digitado é múltiplo de 7.")

# 4a questão: imprima os 5 primeiros múltiplos de 5.

# par = 0

# impar = 0

# numero = int(input("Digite o número que deseja saber os divisores: "))

# divisor = 1

# while divisor <= numero:
#     if numero % divisor == 0:
#         print(divisor)
#     divisor += 1

# a = int(input("Digite o primeiro número: "))
# b = int(input("Digite o segundo número: "))

# while a != b:
#         if a > b:
#           a = a - b
#         else:
#           b = b - a

# print(f"O MDC entre os números é:{a} ")
       
# n = 1

# par = 0
# impar = 0 

# while n != 0:
#     n = int(input("Digite os números que deseja saber se são pares ou ímpares(digite 0 para finalizar o código): "))
#     if n != 0:
#      if n % 2 == 0:
#       par = par + 1
#      else:
#       impar = impar + 1
# print(f"A quantidade de números pares é:{par} e  ímpar:{impar}")

# Masculino = "M"
# Feminino = "F"
# nome = input("Digite o seu sexo: ")
# while nome != Masculino and nome != Feminino:
#         print("Apenas digite M para Masculino e F para Feminino.")
#         nome = input("Digite o seu sexo: ")
# if nome == Masculino:
#  print("O seu sexo é masculino")
# elif nome == Feminino:
#  print("O seu sexo é feminino")

# numero_secreto = 7

# print("*********Adivinhação de número!!!!!!!*********")
# print("O número secreto está entre 0 e 10, podendo ser um deles.")
# tentativa = int(input("Digite a sua primeira tentativa: "))
# contador = 0 

# while tentativa != numero_secreto:
#     tentativa = int(input("Você errou! tente novamente: "))
#     contador += 1
# if tentativa == 7:    
#  print(f"Caramba, você acertou de primeira! parabéns!")
# if contador > 1:
#  print(f"Você acertou! A sua quantidade de tentativas foi: {contador}")

# n1 = int(input("Digite o primeiro número: "))
# n2 = int(input("Digite o segundo número: "))
# print("[1]somar")
# print("[2]multiplicar")
# print("[3]maior")
# print("[4]novos números")
# print("[5]sair do programa")
# pergunta = int(input("O que deseja escolher? Digite: "))

# soma = n1 + n2
# multiplicar = n1 * n2

# if pergunta == 1:
#   print(f"A soma entre os números digitados é: {soma}")

# if pergunta == 2:
#   print(f"A multiplicação entre os dois números é: {multiplicar}")

# if pergunta == 3:

#  if n1 > n2:
#     print(f"O primeiro número({n1}) é maior que o segundo({n2}). ")
#  else:
#     print(f"O segundo número({n2}) é maior que o primeiro({n1})")

# while pergunta == 4:
#   print("Digite dois novos números.")
#   n1 = int(input("Digite o primeiro número: "))
#   n2 = int(input("Digite o segundo número: "))
#   print("[1]somar")
#   print("[2]multiplicar")
#   print("[3]maior")
#   print("[4]novos números")
#   print("[5]sair do programa")
#   pergunta = int(input("O que deseja escolher? Digite: "))

# if pergunta == 5:
#   print("Fim do programa.")

# n = int(input("Digite os números que deseja saber a quantidade de pares e ímpares: "))

# par = 0

# impar = 0

# contador = 0

# while contador < n:
#     if contador % 2 == 0:
#         par += 1
#     else:
#         impar += 1
#     contador += 1
# print(f"Essa quantidade se refere a {par} números pares e {impar} números ímpares")

# n = int(input("Digite o número:"))
# print(f"O seu número é:{n}")
# i = 0

# while n >= i:
#     n = int(input("Digite o número:"))
#     print(f"O seu número é:{n}")
#     if n < 0:
#         print("Você digitou um número negativo. Fim do código.")
#         break

# n1 = int(input("Digite o primeiro número: "))
# n2 = int(input("Digite o segundo número: "))

# contador = n1

# while contador <= n2:
#     if contador % 2 == 0 and contador % 6 != 0:
#         print(contador)
#     contador += 1

# print("Digite os números positivos(>0) que deseja ver a soma,\n e escreva um número negativo para ter a média de todos os números digitados.")

# numero = int(input("Digite o número: "))

# i = 0

# soma = numero

# while numero >=i:
#     numeros1 = int(input("Digite o número(digite 0 para sair):"))
#     if numeros1 == 0:
#         break
#     soma = numeros1 + soma
# print(f"Soma total: {soma}")

# print("Digite números. Com o decorrer da digitação dos números,\no próximo será somado ao anterior.\nDigite um número negativo para finalizar.")
# numero = int(input("Digite o número: "))

# contador = numero

# while contador >= 0:
#      numero = int(input("Digite o número: "))
#      contador = contador + numero
#      print(contador)
#      if numero <0:
#       print("Fim do código.")
#       break
# print("****Sequência de números inteiros****\nDigite um número negativo para finalizar a contagem.")
# sequencia = int(input("Digite os números: "))

# contador = 0

# i = 0

# while sequencia >= i:
#      sequencia = int(input("Digite os números: "))
#      if sequencia > 0:
#       contador+= 1
#      if sequencia < 0:
#         print(f"A quantidade de números digitados é: {contador}")

# contador = 0
# soma_pares = 0
# quantidade_pares = 0

# print("Digite números pares e você saberá a média!!")

# while contador <5:
#     n = int(input("Digite o número: "))
#     if n > 0 and n % 2 == 0:
#         soma_pares = n + soma_pares
#         quantidade_pares += 1
#     contador  += 1
#     if contador ==5:
#         media = soma_pares / quantidade_pares
#         print(f"A soma dos números digitados é: {soma_pares}")
#         print(f"A média dos números digitados é: {media}")
   
# contador = 1

# while contador > 0:
#         dia = int(input("Digite o dia: "))
#         if dia > 31:
#           print("Você forneceu um valor para dia incorreto, tente novamente.")
#           continue
#         mes = int(input("Digite o mês: "))
#         if mes > 12:
#           print("Você forneceu um número de mês incorreto, tente novamente.")
#           continue
#         contador += 1
#         if dia <=31 and mes <=12:
#          break
# print(f"Você forneceu uma data correta! a sua data é: {dia}/{mes}.")

# Q. da sequência de Fibonacci(0,1,1,2,3,5,8,13,21,34,55, 89, ...)

# print("**Sequência de Fibonacci**")
# n = int(input("Digite a quantidade desejada: "))
# t1 = 0
# t2 = 1
# contador=3
# print(t1)
# print(t2)
# while contador <= n:
#     t3 = t1 + t2
#     print(t3)
#     t1 = t2
#     t2 = t3
#     contador+=1

# for linha in range(1, 6):
#      for numero in range(1, linha + 1):
#       print(numero, end =' ')
#      print()

# mult = 1

# for i in range(1,10+1):
#    for j in range(1,10+1):
#       mult = j * i
#       print(f"{i} x {j} = \033[91m{mult}\033[0m")

# n1 = int(input("Digite o primeiro número do intervalo: "))
# n2 = int(input("Digite o segundo número do intervalo: "))
# contador = 0
# if n1 > n2:
#   n1, n2 = n2,n1
# for i in range(n1,n2+1):
#  soma = 0
#  for j in range(1, i):
#      if i % j == 0:
#       soma +=j
#  if soma == i:
#   print(f"{i} é um número perfeito.")
#   contador+=1
# print(f"A quantidade de números perfeitos nesse intervalo é: {contador}")


a = int(input("Digite o primeiro número: "))
b = int(input("Digite o segundo número: "))

limite = a * b
mmc = limite

for i in range(1, limite+1):
    for j in range(1, limite+1):
        if a * i ==  b * j:
         mmc = a* i
         break
    if a * i == mmc:
       break
print(f"O MMC de {a} e {b} é {mmc}")



 








    







       





       

    

        
