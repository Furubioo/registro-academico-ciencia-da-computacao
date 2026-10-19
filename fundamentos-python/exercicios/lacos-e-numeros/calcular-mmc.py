a = int(input("digite o numero"))
b = int(input("digite o numero"))

limite = a * b
mmc = limite

for i in range(1, limite + 1):
    for k in range(1, limite + 1):
        if a * i == b * k:
            mmc = a * i
            break
    if a * i == mmc:
        break
print(f"{a} e {b} = {mmc}")
