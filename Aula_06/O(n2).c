int soma_matriz (int a[][100], int n){
    int soma = 0; // 1 atribuicao

    for (int i = 0; i < n; i++){ // 1 atribuicao, (1 comparacao, 1 operacao, 1 atribuicao) * n
        for (int j = 0; j < n; j++){ // (1 atribuicao) * n, (1 comparacao, 1 operacao, 1 atribuicao) * n^2
            soma = soma + a[i][j]; // (1 acesso a array, 1 acesso a array, 1 operacao, 1 atribuicao) * n^2
        }
    }
    return soma; // 1 retorno

    // total = 3 + 4n + 7n^2
}