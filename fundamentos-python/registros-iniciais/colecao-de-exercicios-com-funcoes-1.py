
# def escolha_numero():
#     numero=int(input("digite o numero"))
#     return numero
# def numero_par_ou_impar(numero):
#     if numero % 2 == 0:
#      print("numero par")
#     else:
#        print("numero impar")

# def numero_perfeito(numero):
#    soma= 0
#    for i in range(1,numero):
#       if numero % i == 0:
#          soma=soma + i
#    if soma == numero:
#          print("numero perfeito")
#    else:
#          print("numero não perfeito")
         
# def numero_primo(numero):
#    for j in range(1,numero + 1):
#       if numero % j == 0:
#          print("não é numero primo")
#       else:
#          print("numero primo") 
#       break
# numero=escolha_numero()
# numero_par_ou_impar(numero)
# numero_perfeito(numero)
# numero_primo(numero)




# def escolha_figura():
#    figura= (input("escolha a figura geometrica"))
#    return figura

# def dados_triangulo():
#    baset=int(input("digite o valor da base do triângulo"))
#    alturat=int(input("digite o valor da altura do triângulo"))
#    return baset,alturat

# def dados_retâgulo():
#    baser=int(input("digite o valor da base do retâgulo"))
#    alturar=int(input("digite o valor da altura do retângulo"))
#    return baser,alturar

# def calculo_triângulo(baset,alturat):
#    triângulo= baset * alturat /2
#    print(f" a area do triângulo {triângulo}")
  

# def calculo_retângulo(baser, alturar):
#    retângulo= baser * alturar
#    print(f"a area do retângulo{retângulo}")
   

# figura = escolha_figura()
# if figura == "triângulo":
#   baset,alturat=dados_triangulo()
#   calculo_triângulo(baset,alturat)

# if figura == "retângulo":
#   baser,alturar=dados_retâgulo()
#   calculo_retângulo(baser,alturar)




# def dados_equação_2grau():
#     a= int(input("digite os numeros"))
#     b= int(input("digite os numeros"))
#     c= int(input("digite os numeros"))
#     return a,b,c

# def calculo_delta(a,b,c):
#     delta=b**2 - 4 *a*c
#     return delta

# def calculo_x1(delta,a,b):
#     x1=(- b + (delta ** 0.5))/(2*a)
#     print(f"a primeira raiz {x1}")

# def calculo_x2(delta,a,b):
#     x2=(- b - (delta ** 0.5))/(2*a)
#     print(f"a segunda raiz {x2}")

# a,b,c=dados_equação_2grau()
# delta=calculo_delta(a,b,c)
# calculo_x1(delta,a,b)
# calculo_x2(delta,a,b)


    

# def somatorio():
#   n= int(input("digite o numero"))
#   soma= 0
#   return n,soma
# def calcular_dados(n,soma):
#   for i in range(1,n + 1):
#     soma+= i
#   print(f"resultado da soma {soma}")

# n,soma= somatorio()
# calcular_dados(n,soma)


# def dados_parametros():
#     n= int(input("digite o primeiro numero"))
#     n1= int(input("digite o segundo numero"))
#     return n,n1

# def calculo_parametros(n,n1):
#    if n > n1:
#      print(f"{n} é maior.")
#    else:
#       print(f"{n1} é menor")

# def calculo_média(n,n1):
#    média= (n + n1) / (2)
#    print(f"{média}resultado da média")

# n,n1= dados_parametros()
# calculo_parametros(n,n1)
# calculo_média(n,n1)

# def dados_numero():
#    n= int(input("digite o número"))
#    return n
# def fatorial_numero(n):
#   mult1=1
#   for i in range(n,1,-1):
#      mult1= mult1 * i
#   print(f"resultado do fatorial{mult1}")
   
# n= dados_numero()
# fatorial_numero(n)


# def dados():
#   palavra=(input("digite a palavra"))
#   return palavra

# def filtra_vogais(palavra):
#   for i in palavra:
#     if i!= "a" and i!= "e" and i!= "i" and i!= "o" and i!= "u":
#       print(i)
     
# palavra=dados()
# filtra_vogais(palavra)




# def dados():
#     n= int(input("digite o valor"))
#     return n

# def cacular_dados(horas,minutos,segundos):
#     horas= 0
#     minutos=60
#     segundos=0
#     # if horas 