/* Adcionar Saldo ao Cliente */

void adicionarSaldo(int *tamanho){ // Ponteiro tamanho como parametro
    int idsaldo = 0, exist = -1;
    float saldo = 0;
    char senha[10];

    do
    {
        printf("Digite seu ID: ");
        scanf("%i", &idsaldo);
    } while (idsaldo <= 0);

    for (int i = 0; i < *tamanho; i++)
    {
        if (idsaldo == cadastro[i].id)
        {
            exist = i;
            break;
        }
    }

    if (exist == -1)
    {
        printf("ID nao encontrado.\n");
        return;
    }

    printf("Digite sua senha: ");
    fflush(stdin);
    fgets(senha, 10, stdin);
    fflush(stdin);

    if (strcmp(senha, cadastro[exist].senha) != 0)
    { // Verifica a senha
        printf("Senha incorreta.\n");
        return;
    }
    else
    {
        printf("Digite o valor que deseja adicionar: ");
        scanf("%f", &saldo);

        cadastro[exist].saldo += saldo; // Adciona o saldo ao Usuario

        printf("\nSaldo atual: %.2f\n", cadastro[exist].saldo); // Exibe o novo saldo ao Usuario
        printf("Saldo adicionado com sucesso!\n");
    }
}
