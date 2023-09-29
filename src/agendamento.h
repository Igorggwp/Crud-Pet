void agendamento(int *tamanho) {
    int idservico = 0, exist = -1;
    char senha[20];
    char novaData[20];
    char novoHorario[20];
    do {
        printf("Digite seu ID: ");
        scanf("%i", &idservico);
    } while (idservico <= 0);

    for (int i = 0; i < *tamanho; i++) {
        if (idservico == cadastro[i].id) {
            exist = i;
            break;
        }
    }

    if (exist == -1) {
        printf("ID nao encontrado.\n");
        return;
    }

    printf("Digite sua senha: ");
    fflush(stdin);
    fgets(senha, 10, stdin);
    fflush(stdin);
            
    if (strcmp(senha, cadastro[exist].senha) != 0) {
        printf("Senha incorreta.\n");
        return;
    } else {
        
        // Mostrar o saldo atual
        printf("Seu saldo atual: R$ %.2f\n", cadastro[exist].saldo);

        // Oferecer opções de serviço
        printf("Escolha o tipo de servico:\n");
        printf("[1] Banho (R$ 50)\n");
        printf("[2] Tosa (R$ 50)\n");
        printf("[3] Banho e Tosa (R$ 100)\n");
        printf("[4] Cancelar\n");
        printf("Digite a opção desejada: ");
        int opcao_servico;
        scanf("%d", &opcao_servico);

        float valor_servico;
        char tipo_servico[20];

        if (opcao_servico == 1) {
            valor_servico = 50.0;
            strcpy(tipo_servico, "Banho");
        } else if (opcao_servico == 2) {
            valor_servico = 50.0;
            strcpy(tipo_servico, "Tosa");
        } else if (opcao_servico == 3) {
            valor_servico = 100.0;
            strcpy(tipo_servico, "Banho e Tosa");
        } else {
            printf("Opcão invalida.\n");
            return;
        }

        // Verificar se o cliente possui saldo suficiente
        if (cadastro[exist].saldo >= valor_servico) {
                cadastro[exist].saldo -= valor_servico;

                // Atualizar o tipo de serviço
                fflush(stdin);
                strcpy(cadastro[exist].servico, tipo_servico);
                strcat(cadastro[exist].servico, "\n");

                // Agendar horário
                fflush(stdin);
                printf("Escolha a data (formato DD/MM/AAAA): ");
                scanf("%s", novaData);
                fflush(stdin);
                printf("OBSERVACAO! Os nossos procedimentos tem duração de 1 hora, escolha horários como 10:00, 14:00, 17:00... \n");
                printf("Escolha o horário (formato HH:MM): ");
                scanf("%s", novoHorario);

                // Verifica se a data e horario sao iguais de outro usuario
                for (int i = 0; i < *tamanho; i++) {
                    if (i != exist &&
                        strcmp(novaData, cadastro[i].data) == 0 &&
                        strcmp(novoHorario, cadastro[i].horario) == 0) {
                        printf("Data e horario ja estao ocupados.\n");
                        return;
                    }
                }

                // Salvar no cadastro da pessoa, os dados atualizados de Horario e Data
                fflush(stdin);
                strcpy(cadastro[exist].horario, novoHorario);
                strcat(cadastro[exist].horario, "\n");

                fflush(stdin);
                strcpy(cadastro[exist].data, novaData);
                strcat(cadastro[exist].data, "\n");

                printf("Agendamento realizado com sucesso:\n");
                printf("Tipo de serviço: %s\n", cadastro[exist].servico);
                printf("Horario agendado: %s\n", cadastro[exist].horario);
                printf("Data agendada: %s\n", cadastro[exist].data);
                printf("Saldo restante: R$ %.2f\n", cadastro[exist].saldo);
            } else {
                printf("Saldo insuficiente para agendar o servico.\n");
        }
    }
}