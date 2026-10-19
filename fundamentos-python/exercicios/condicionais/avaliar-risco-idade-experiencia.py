idade = int(input(" digite sua idade "))
experiencia = int(input("digite o tempo de experiencia "))
if idade < 18 and experiencia < 1:
    print("alto risco ")
elif idade >= 18 and idade <= 60 and experiencia <= 5:
    print("risco medio ")
elif experiencia >= 5:
    print("baixo risco ")
