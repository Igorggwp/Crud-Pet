/* Cadastrar Produto */

int CadastrarProduto(int *tamanho_produto){ // Ponteiro tamanho_produto como parametro
    int idcad = 0;

    // Itera sobre os cadastros existentes para encontrar o maior ID
    for (int i = 0; i < *tamanho_produto; i++)
    {
        if (produtos[i].id > idcad)
        {
            idcad = produtos[i].id;
        }
    }

    idcad++; // Incrementa o maior ID encontrado para obter o proximo ID disponivel

    // Realoca memoria para o vetor 'cadastro' para acomodar o novo cadastro
    produtos = (struct produto *)realloc(produtos, (*tamanho_produto + 1) * sizeof(struct produto));

    if (produtos == NULL)
    { // Verifica se a realocação foi bem-sucedida
        printf("Erro na realocação de memória.\n");
        return 0;
    }

    // Preenche os detalhes do novo cadastro
    produtos[*tamanho_produto].id = idcad;
    fflush(stdin);
    printf("Digite o nome do Produto: ");
    gets(produtos[*tamanho_produto].nome);
    strcat(produtos[*tamanho_produto].nome, "\n");
    fflush(stdin);
    printf("Digite a quantidade de Produtos: ");
    scanf("%d", &produtos[*tamanho_produto].quantidade);
    fflush(stdin);
    printf("Digite o valor do Produto: ");
    scanf("%f", &produtos[*tamanho_produto].preco);
    fflush(stdin);
    printf("CADASTRADO COM SUCESSO!\nO ID do produto e: %d\n", idcad);

    *tamanho_produto += 1; // Atualiza o tamanho do vetor 'cadastro'

    pfinit(tamanho_produto); // Chama a função 'finit' para finalizar o cadastro
    return idcad;            // Retorna o ID cadastrado
}