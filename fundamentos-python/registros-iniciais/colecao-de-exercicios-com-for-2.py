# for i in range(1,6):
#     for k in range (1,i + 1):
#         print (k,end=" ")
#     print()


# mult= 0
# for i in range(1,11):
#     for k in range(1,11):
#         mult= i * k
#         print(f"{i} * {k} = {mult}")
#     print()
       

# n1= int(input("digite o numero"))
# n2= int(input("digite o numero"))
# contador= 0
# for i in range(n1,n2 + 1):
#     soma=0
#     for k in range(1,i):
#         if i % k == 0:
#          soma = soma + k
#     if i == soma:
#            contador= contador + 1
# print(f"a quantidade de numeros perfeito e {contador}")
 



# n1= int(input("digite o numero"))
# n2= int(input("digite o numero"))
# multiplos= n1 > 1 and n2 > 1
# while True:
#    if multiplos > 1:





# a= int(input("digite o numero"))
# b= int(input("digite o numero"))

# limite= a * b
# mmc = limite

# for i in range(1,limite+1):
#     for k in range(1,limite+1):
#       if a * i == b * k:
#          mmc= a * i
#          break
#     if a * i == mmc:
#          break
# print(f"{a} e {b} = {mmc}")


n= int(input("digite o numero"))
if n < 2:
    print(f"{n} não é primo") 
else: 
    primo = 1
    for i in range(2,n):
        for k in range(1,2):
            if n % i == 0:
                primo= 0
                break
        if primo == 0:
          break
    if primo == 1:
         
     print("numero primo")
    else:
     print("o numero não e primo")

