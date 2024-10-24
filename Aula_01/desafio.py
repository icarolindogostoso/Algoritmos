a,b = map(int,input().split())

while b > 0:
    valor = a % b
    a = b
    b = valor

print(valor)