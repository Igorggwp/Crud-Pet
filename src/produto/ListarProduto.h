/* Listar Produtos */

int ListarProdutos(int *tamanho_produto){// Ponteiro tamanho_produto como parametro
    int usuarios = 0; // Variavel para contar o numero de usuarios

    // Verifica se o ponteiro 'cadastro' é nulo
    if (cadastro == NULL)
    {
        printf("Erro: Nenhum cadastro encontrado.\n");
        return 0;
    }

    // Loop para varrer todos os Cadastros e exibir todos na tela
    for (int i = 0; i < *tamanho_produto; i++)
    {
        if (produtos[i].id != 0)
        {
            printf("ID: %d\n", produtos[i].id);
            printf("Nome do Produto: %s\n", produtos[i].nome);
            printf("Quantidade do Produto: %i\n", produtos[i].quantidade);
            printf("Valor do Produto: %.2f\n", produtos[i].preco);
            printf("------------------------------\n\n");
            usuarios++;
        }
    }

    // Caso nao tenha usuarios cadastrados
    if (usuarios == 0)
    {
        return 0;
    }

    return usuarios; // Retorna os usuarios
}