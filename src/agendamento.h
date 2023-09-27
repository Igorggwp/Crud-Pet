#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void agendamento(struct dados *cadastro,  int *tamanho) {
    int id;
    char senha[20];
    printf("Digite seu ID: ");
    scanf("%d", &id);

    // Verificar se o ID e a senha são válidos
    int usuario_encontrado = 0;
    for (int i = 0; i < tamanho; i++) {
        if (cadastro[i].id == id) {
            printf("Digite sua senha: ");
            scanf("%s", senha);
            if (strcmp(cadastro[i].senha, senha) != 0) {
                usuario_encontrado = 1;

                // Mostrar o saldo atual
                printf("Seu saldo atual: R$ %.2f\n", cadastro[i].saldo);

                // Oferecer opções de serviço1
                printf("Escolha o tipo de servico:\n");
                printf("[1] Banho (R$ 50)\n");
                printf("[2] Tosa (R$ 50)\n");
                printf("[3] Banho e Tosa (R$ 100)\n");
                printf("[4] Cancelar\n");
                printf("Digite a opcao desejada: ");
                int opcao_servico;
                scanf("%d", &opcao_servico);

                float valor_servico;
                char tipo_servico[10];
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
                if (cadastro[i].saldo >= valor_servico) {
                    cadastro[i].saldo -= valor_servico;

                    // Agendar horário
                    printf("Escolha o horario (formato HH:MM): ");
                    scanf("%s", cadastro[i].horario);

                    // Atualizar o tipo de serviço
                    strcpy(cadastro[i].servico, tipo_servico);

                    printf("Agendamento realizado com sucesso:\n");
                    printf("Tipo de serviço: %s\n", tipo_servico);
                    printf("Horario agendado: %s\n", cadastro[i].horario);
                    printf("Saldo restante: R$ %.2f\n", cadastro[i].saldo);
                } else {
                    printf("Saldo insuficiente para agendar o servico.\n");
                }

                break; // Parar a busca
            } else {
                printf("Senha incorreta.\n");
                return;
            }
        }
    }

    if (!usuario_encontrado) {
        printf("ID não encontrado.\n");
    }
}