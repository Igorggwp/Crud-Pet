/* Procurar Produto */

void ProcurarProduto(int *tamanho_produto){ // Ponteiro tamanho_produto como parametro
    int id_procurar, produto_encontrado = 0;

    printf("Digite o ID do produto que deseja procurar: ");
    scanf("%d", &id_procurar);

    // Loop para percorrer o array de produtos
    for (int i = 0; i < *tamanho_produto; i++)
    {
        // Verifica se o ID do produto corresponde ao ID procurado
        if (id_procurar == produtos[i].id)
        {
            printf("Produto encontrado!\n");
            printf("ID: %d\n", produtos[i].id);
            printf("Nome do Produto: %s", produtos[i].nome);
            printf("Quantidade de Produtos: %d\n", produtos[i].quantidade);
            printf("Preço do Produto: %.2f\n", produtos[i].preco);
            produto_encontrado = 1; // Indica que o produto foi encontrado
            break;                  // Sai do loop quando o produto for encontrado
        }
    }

    // Verifica se o produto foi encontrado
    if (!produto_encontrado)
    {
        printf("Produto com ID %d não encontrado.\n", id_procurar);
    }
}