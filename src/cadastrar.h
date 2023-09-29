/* Cadastrar Clientes */

int cadastrar(int *tamanho){ // Ponteiro tamanho como parametro
    int idcad = 0;

    // Itera sobre os cadastros existentes para encontrar o maior ID
    for (int i = 0; i < *tamanho; i++)
    {
        if (cadastro[i].id > idcad)
        {
            idcad = cadastro[i].id;
        }
    }

    idcad++; // Incrementa o maior ID encontrado para obter o proximo ID disponivel

    // Realoca memoria para o vetor 'cadastro' para acomodar o novo cadastro
    cadastro = (struct dados *)realloc(cadastro, (*tamanho + 1) * sizeof(struct dados));

    if (cadastro == NULL)
    { // Verifica se a realocação foi bem-sucedida
        printf("Erro na realocação de memória.\n");
        return 0;
    }

    // Preenche os detalhes do novo cadastro
    cadastro[*tamanho].id = idcad;
    fflush(stdin);
    printf("Digite o nome do Dono: ");
    gets(cadastro[*tamanho].dono);
    strcat(cadastro[*tamanho].dono, "\n");

    fflush(stdin);
    printf("Digite o nome do Pet: ");
    gets(cadastro[*tamanho].nome);
    strcat(cadastro[*tamanho].nome, "\n");

    fflush(stdin);
    printf("Digite qual animal é seu pet: ");
    gets(cadastro[*tamanho].pet);
    strcat(cadastro[*tamanho].pet, "\n");

    fflush(stdin);
    printf("Digite a raça do pet: ");
    gets(cadastro[*tamanho].raca);
    strcat(cadastro[*tamanho].raca, "\n");

    fflush(stdin);
    printf("Digite sua senha de acesso: ");
    gets(cadastro[*tamanho].senha);
    strcat(cadastro[*tamanho].senha, "\n");

    // Inicializa servico e horario com espaco vazio
    strcpy(cadastro[*tamanho].servico, "\n");
    strcpy(cadastro[*tamanho].horario, "\n");
    strcpy(cadastro[*tamanho].data, "\n");

    fflush(stdin);
    cadastro[*tamanho].saldo = 0.00;
    printf("CADASTRADO COM SUCESSO!\nSeu ID é: %d\n", idcad);

    *tamanho += 1; // Atualiza o tamanho do vetor 'cadastro'

    finit(tamanho); // Chama a função 'finit' para finalizar o cadastro
    return idcad;   // Retorna o ID cadastrado
}
