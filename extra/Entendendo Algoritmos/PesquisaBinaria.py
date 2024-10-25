def pesquisa_binaria (lista, item):
    baixo  = 0
    alto = len(lista)-1

    while baixo <= alto:
        meio = (baixo + alto)//2
        chute = lista[meio]

        if chute == item:
            return meio
        
        if chute > item:
            alto = meio - 1

        else:
            baixo = meio + 1
    return None

minha_lista = []

for i in range(1,1000):
    minha_lista.append(i*3)

print(pesquisa_binaria(minha_lista,3))
print(pesquisa_binaria(minha_lista,-1))