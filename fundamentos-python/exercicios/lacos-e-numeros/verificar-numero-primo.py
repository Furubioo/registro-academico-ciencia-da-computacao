n = int(input("digite o numero"))
if n < 2:
    print(f"{n} não é primo")
else:
    primo = 1
    for i in range(2, n):
        for k in range(1, 2):
            if n % i == 0:
                primo = 0
                break
        if primo == 0:
            break
    if primo == 1:
        print("numero primo")
    else:
        print("o numero não e primo")
