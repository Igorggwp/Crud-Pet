/* Atualizar Produto */

int AtualizarProduto(int *tamanho_produto){// Ponteiro tamanho_produto como parametro
    int idat, subs, exist = -1, new, new2, atualizado = 1;

    printf("Digite o ID do cadastro que deseja atualizar\nDigite 0 para cancelar\n->");
    scanf("%i", &idat);
    if (idat == 0)
    {
        return 0;
    }

    for (int i = 0; i < *tamanho_produto; i++)
    { // Verificacao do ID do produto
        if (idat == produtos[i].id)
        {
            exist = i;
        }
    }

    if (exist == -1)
    {
        printf("\nCadastro não encontrado!\n");
    }
    else
    {
        do
        { // Verifica os dados do produto
            printf("-------------------\n");
            for (int i = 0; i < *tamanho_produto; i++)
            {
                if (idat == produtos[i].id)
                {
                    printf("Quais dados deseja substituir?\n");
                    printf("-------------------\n");
                    printf("id: %i\n", produtos[i].id);
                    printf("[1] Nome do Produto: %s\n", produtos[i].nome);
                    printf("[2] Quantidade de Produtos: %i\n", produtos[i].quantidade);
                    printf("[3] Valor do Produto: %.2f\n", produtos[i].preco);
                    printf("[4] Alterar todos os dados\n");
                    printf("[5] Cancelar\n");
                    printf("-------------------\n");
                    new = i;
                    scanf("%i", &subs);
                }
            }

            switch (subs)
            {
            case 1: // Atualizar Nome do Produto
                printf("Nome do Produto: ");
                fflush(stdin);
                gets(produtos[new].nome);
                strcat(produtos[new].nome, "\n");
                atualizado = 1;
                break;
            case 2: // Atualizar Quantidade de Produtos
                printf("Quantidade de Produtos: ");
                fflush(stdin);
                scanf("%d", &produtos[new].quantidade);
                atualizado = 1;
                break;
            case 3: // Atualizar Valor do Produto
                printf("Valor do Produto: ");
                fflush(stdin);
                scanf("%f", &produtos[new].preco);
                atualizado = 1;
                break;
            case 4: // Atualizar Todos os Dados
                printf("Nome do Produto: ");
                fflush(stdin);
                gets(produtos[new].nome);
                strcat(produtos[new].nome, "\n");

                printf("Quantidade de Produtos: ");
                fflush(stdin);
                scanf("%d", &produtos[new].quantidade);

                printf("Valor do Produto: ");
                fflush(stdin);
                scanf("%f", &produtos[new].preco);
                atualizado = 1;
                break;
            case 5:
                atualizado = 0;
                break;
            }
            if (atualizado == 1)
            { // Caso atualizar
                printf("----------------------------------------\n");
                printf("|      Dados atualizados com sucesso!   |\n");
                printf("----------------------------------------\n");
                printf("\nDeseja alterar mais alguma informacao?\n");
                printf("[1] SIM\n");
                printf("[2] NAO\n");
                scanf("%i", &new2);
            }
            else
            { // Caso nao atualizar
                printf("----------------------------------------\n");
                printf("|      Operacao Cancelada              |\n");
                printf("----------------------------------------\n");
                printf("\nDeseja alterar mais alguma informacao?\n");
                printf("[1] SIM\n");
                printf("[2] NAO\n");
                scanf("%i", &new2);
            }
        } while (new2 == 1);
    }
    pfinit(tamanho_produto);
    return 0;
}