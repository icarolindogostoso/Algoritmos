a,b = map(int,input().split())

menor = a
if b < menor:
    menor = b

i = 2
mdc = 1
while i < menor:
    if a%i == 0 and b%i == 0:
        mdc = mdc * i
        a = a//i
        b = b//i
    else:
        i = i + 1
    

print(mdc)