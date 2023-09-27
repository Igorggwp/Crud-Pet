/* Excluir Produto */

int ExcluirProduto(int *tamanho_produto) {
    int idb = 0, flag = 0, esc = 0;

    //inicio do loop princiapl
    do {
        flag = 0;
        printf("Digite o ID para excluir ou digite [0] para cancelar:\n ");
        if (scanf("%d", &idb) != 1) {
            printf("Entrada invalida. Operacao cancelada.\n");
            while (getchar() != '\n');
            return -1;
        }

        if (idb == 0) {
            printf("Operacao cancelada.\n");
            return 0;
        }

        // percorrer o array de produtos
        for (int i = 0; i < *tamanho_produto; i++) {
            if (idb == produtos[i].id) { // verificar se o ID corresponde a um cadastro
                flag = 1;
                // exibe as informacoes
                printf("Nome do Produto: %s\n", produtos[i].nome);
                printf("Quantidade do Produto: %i\n", produtos[i].quantidade);
                printf("Valor do Produto: %.2f\n", produtos[i].preco);
                // confirmacao para excluir
                printf("Tem certeza que deseja excluir esse usuario? (Acao nao reversivel.)\n[1]Sim\n[2]Nao\n->");
                if (scanf("%d", &esc) != 1) {
                    printf("Entrada invalida. Operacao cancelada.\n");
                    while (getchar() != '\n');
                    return -1;
                }

                if (esc == 1) { // excluindo o cadastro
                    if (i == *tamanho_produto-1) {
                        produtos = (struct produto*) realloc(produtos, (*tamanho_produto-1) * sizeof(struct produto));
                    } else {
                        produtos[i].id = produtos[*tamanho_produto-1].id;
                        produtos[i].quantidade = produtos[*tamanho_produto-1].quantidade;
                        produtos[i].preco = produtos[*tamanho_produto-1].preco;
                        produtos = (struct produto*) realloc(produtos, (*tamanho_produto-1) * sizeof(struct produto));
                    }
                    *tamanho_produto -= 1;
                    printf("Usuario excluido com sucesso\n");
                    esc = -1;
                }
            }
        }

        if (flag == 0) { // se o ID nao foi encontrado
            printf("Conta nao encontrada!\n");
            printf("Deseja digitar novamente o ID da conta?\n[1]Sim\n[2]Nao: ");
            if (scanf("%d", &esc) != 1) {
                printf("Entrada invalida. Operacao cancelada.\n");
                while (getchar() != '\n');
                return -1;
            }
        }

    } while (esc == 1);

    // Ordenacao do array 'produtos' por meio de bubble sort
    for (int i = 0; i < *tamanho_produto; i++) { //variaveis de controle
        for (int j = i; j < *tamanho_produto; j++) {
            if (produtos[i].id > produtos[j].id) { //se i for maior que j, ocorre a troca crescente
                struct produto temp = produtos[i]; // struct dados temp armazena temporariamente uma cadastro durante a troca
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }

    return 0;
}