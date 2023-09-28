int atualizar(int *tamanho) {
    int idat, subs, exist = -1, new, new2, atualizado = 1;
    char senha[10];

    printf("Digite o ID do cadastro que deseja atualizar\nDigite 0 para cancelar\n->");
    scanf("%i", &idat);
    if (idat == 0) {
        return 0;
    }
    
    for (int i = 0; i < *tamanho; i++) {
        if (idat == cadastro[i].id) {
            exist = i;
        }
    }

    if (exist == -1) {
        printf("\nCadastro nao encontrado!\n");
    } else {
        printf("Digite sua senha: ");
        fflush(stdin);
        fgets(senha, 10, stdin);
        fflush(stdin);
        if (strcmp(senha, cadastro[exist].senha) != 0) {
            printf("Senha Incorreta.\n");
            return 0;
        } else {
            do {
                printf("-------------------\n");
                for (int i = 0; i < *tamanho; i++) {
                    if (idat == cadastro[i].id) {
                        printf("Quais dados deseja substituir?\n");
                        printf("-------------------\n");
                        printf("id: %i\n", cadastro[i].id);
                        printf("[1] Nome do Dono: %s\n", cadastro[i].dono);
                        printf("[2] Nome do Pet: %s\n", cadastro[i].nome);
                        printf("[3] Pet: %s\n", cadastro[i].pet);
                        printf("[4] Raca do Pet: %s\n", cadastro[i].raca);
                        printf("[5] Senha do Usuario: %s\n", cadastro[i].senha);
                        printf("[6] Alterar todos os dados\n");
                        printf("[7] Cancelar\n");
                        printf("-------------------\n");
                        new = i;
                        scanf("%i", &subs);
                    }
                }

                switch (subs) {
                    case 1:
                        printf("Nome do Dono: ");
                        fflush(stdin);
                        gets(cadastro[new].dono);
                        strcat(cadastro[new].dono, "\n");
                        atualizado = 1;

                        break;
                    case 2:
                        printf(" Nome do Pet: ");
                        fflush(stdin);
                        gets(cadastro[new].nome);
                        strcat(cadastro[new].nome, "\n");
                        atualizado = 1;

                        break;
                    case 3:
                        printf("Pet: ");
                        fflush(stdin);
                        gets(cadastro[new].pet);
                        strcat(cadastro[new].pet, "\n");
                        atualizado = 1;

                        break;
                    case 4:
                        printf("Senha do Usuario: ");
                        fflush(stdin);
                        gets(cadastro[new].raca);
                        strcat(cadastro[new].raca, "\n");
                        atualizado = 1;

                        break;
                    case 5:
                        printf("Senha: ");
                        fflush(stdin);
                        gets(cadastro[new].senha);
                        strcat(cadastro[new].senha, "\n");
                        atualizado = 1;

                        break;
                    case 6:
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

                        printf("Raca: ");
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
                if (atualizado == 1) {
                    printf("----------------------------------------\n");
                    printf("|      Dados atualizados com sucesso!   |\n");
                    printf("----------------------------------------\n");
                    printf("\nDeseja alterar mais alguma informacao?\n");
                    printf("[1] SIM\n");
                    printf("[2] NAO\n");
                    scanf("%i", &new2);
                } else {
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
    }
    finit(tamanho);
}
