/* Atualizar Cliente */

int atualizar(int *tamanho){ // Ponteiro tamanho como parametro
    int idat, subs, exist = -1, new, new2, atualizado = 1;
    char senha[10];

    printf("Digite o ID do cadastro que deseja atualizar\nDigite 0 para cancelar\n->");
    scanf("%i", &idat);
    if (idat == 0)
    {
        return 0;
    }

    for (int i = 0; i < *tamanho; i++)
    { // Verificacao do ID
        if (idat == cadastro[i].id)
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
        printf("Digite sua senha: "); // Verificacao de senha
        fflush(stdin);
        fgets(senha, 10, stdin);
        fflush(stdin);
        if (strcmp(senha, cadastro[exist].senha) != 0)
        {
            printf("Senha Incorreta.\n");
            return 0;
        }
        else
        {
            do
            { // Verifica os dados do usuario
                printf("-------------------\n");
                for (int i = 0; i < *tamanho; i++)
                {
                    if (idat == cadastro[i].id)
                    {
                        printf("Quais dados deseja substituir?\n");
                        printf("-------------------\n");
                        printf("id: %i\n", cadastro[i].id);
                        printf("[1] Nome do Dono: %s\n", cadastro[i].dono);
                        printf("[2] Nome do Pet: %s\n", cadastro[i].nome);
                        printf("[3] Pet: %s\n", cadastro[i].pet);
                        printf("[4] Raça do Pet: %s\n", cadastro[i].raca);
                        printf("[5] Senha do Usuário: %s\n", cadastro[i].senha);
                        printf("[6] Alterar todos os dados\n");
                        printf("[7] Cancelar\n");
                        printf("-------------------\n");
                        new = i;
                        scanf("%i", &subs);
                    }
                }

                switch (subs)
                {
                case 1: // Atualizar Dono
                    printf("Nome do Dono: ");
                    fflush(stdin);
                    gets(cadastro[new].dono);
                    strcat(cadastro[new].dono, "\n");
                    atualizado = 1;

                    break;
                case 2: // Atualizar Nome do Pet
                    printf(" Nome do Pet: ");
                    fflush(stdin);
                    gets(cadastro[new].nome);
                    strcat(cadastro[new].nome, "\n");
                    atualizado = 1;

                    break;
                case 3: // Atualizar o Pet
                    printf("Pet: ");
                    fflush(stdin);
                    gets(cadastro[new].pet);
                    strcat(cadastro[new].pet, "\n");
                    atualizado = 1;

                    break;
                case 4: // Atualizar a Raca do Pet
                    printf("Raça do Pet: ");
                    fflush(stdin);
                    gets(cadastro[new].raca);
                    strcat(cadastro[new].raca, "\n");
                    atualizado = 1;

                    break;
                case 5: // Atualizar a Senha do Usuario
                    printf("Senha: ");
                    fflush(stdin);
                    gets(cadastro[new].senha);
                    strcat(cadastro[new].senha, "\n");
                    atualizado = 1;

                    break;
                case 6: // Atualizar Todos os Dados
                    printf("Dono: ");
                    fflush(stdin);
                    gets(cadastro[new].dono);
                    strcat(cadastro[new].dono, "\n");

                    printf("Nome do Pet: ");
                    fflush(stdin);
                    gets(cadastro[new].nome);
                    strcat(cadastro[new].nome, "\n");

                    printf("Pet: ");
                    fflush(stdin);
                    gets(cadastro[new].pet);
                    strcat(cadastro[new].pet, "\n");

                    printf("Raça: ");
                    fflush(stdin);
                    gets(cadastro[new].raca);
                    strcat(cadastro[new].raca, "\n");

                    printf("Senha: ");
                    fflush(stdin);
                    gets(cadastro[new].senha);
                    strcat(cadastro[new].senha, "\n");
                    atualizado = 1;

                    break;
                case 7:
                    atualizado = 0;

                    break;
                }
                if (atualizado == 1)
                { // Caso atualizar
                    printf("----------------------------------------\n");
                    printf("|      Dados atualizados com sucesso!   |\n");
                    printf("----------------------------------------\n");
                    printf("\nDeseja alterar mais alguma informação?\n");
                    printf("[1] SIM\n");
                    printf("[2] NÃO\n");
                    scanf("%i", &new2);
                }
                else
                { // Caso nao atualizar
                    printf("----------------------------------------\n");
                    printf("|      Operação Cancelada              |\n");
                    printf("----------------------------------------\n");
                    printf("\nDeseja alterar mais alguma informação?\n");
                    printf("[1] SIM\n");
                    printf("[2] NÃO\n");
                    scanf("%i", &new2);
                }
            } while (new2 == 1);
        }
    }
    finit(tamanho);
    return 0;
}
