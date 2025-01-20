import random

def gerar_lista(tamanho):
    numeros = set()
    while len(numeros) < tamanho:
        # Gerar números no intervalo de -1 milhão a 1 milhão
        numeros.add(random.randint(-1000000, 1000000))
    # Retorna a lista ordenada
    return sorted(list(numeros))

def salvar_lista_em_arquivo(lista, nome_arquivo):
    with open(nome_arquivo, 'w') as arquivo:
        for numero in lista:
            arquivo.write(f"{numero} ")

tamanho = int(input("Informe o tamanho da lista: "))

nome_arquivo = f"{tamanho}-entradas-ordenadas.txt"

lista_gerada = gerar_lista(tamanho)
salvar_lista_em_arquivo(lista_gerada, nome_arquivo)

print(f"A lista foi salva em '{nome_arquivo}'.")
