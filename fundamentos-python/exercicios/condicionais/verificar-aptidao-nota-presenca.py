nota = int(input(" infome sua nota "))
presença = int(input(" informe sua presença "))
if nota >= 7 and presença >= 75:
    print("voce esta apto por media e presença ")
elif nota < 7 and presença >= 75:
    print("voce esta apto por presença e nao por nota ")
elif nota >= 7 and presença < 75:
    print("voce esta apto por nota e nao por presença ")
elif nota < 7 and presença < 75:
    print("nao esta apto por nota e nem por presença ")
