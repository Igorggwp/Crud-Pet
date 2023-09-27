/* Listar Produtos */

int ListarProdutos(int *tamanho_produto) {
    int usuarios = 0;

    for (int i = 0; i < *tamanho_produto; i++) {
        if (produtos[i].id != 0) {
            printf("ID: %d\n", produtos[i].id);
            printf("Nome do Produto: %s\n", produtos[i].nome);
            printf("Quantidade do Produto: %i\n", produtos[i].quantidade);
            printf("Valor do Produto: %.2f\n", produtos[i].preco);
            printf("------------------------------\n\n");
            usuarios++;
        }
    }

    if (usuarios == 0) {
        return 0;
    }

    return usuarios;
}