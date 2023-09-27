/* Procurar Produto */

void ProcurarProduto(int *tamanho_produto) {
    int id_procurar, produto_encontrado = 0;

    printf("Digite o ID do produto que deseja procurar: ");
    scanf("%d", &id_procurar);

    for (int i = 0; i < *tamanho_produto; i++) {
        if (id_procurar == produtos[i].id) {
            printf("Produto encontrado!\n");
            printf("ID: %d\n", produtos[i].id);
            printf("Nome do Produto: %s", produtos[i].nome);
            printf("Quantidade de Produtos: %d\n", produtos[i].quantidade);
            printf("Preco do Produto: %.2f\n", produtos[i].preco);
            produto_encontrado = 1;
            break;
        }
    }

    if (!produto_encontrado) {
        printf("Produto com ID %d nao encontrado.\n", id_procurar);
    }
}