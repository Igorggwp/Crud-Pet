#include <stdio.h>

int excluir(int *tamanho) {
    int idb = 0, flag = 0, esc = 0;

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

        for (int i = 0; i < *tamanho; i++) {
            if (idb == cadastro[i].id) {
                flag = 1;
                printf("Dono do Pet: %s\n", cadastro[i].dono);
                printf("Nome do Pet: %s\n", cadastro[i].nome);
                printf("Pet: %s\n", cadastro[i].pet);
                printf("Raca do Pet: %s\n", cadastro[i].raca);
                printf("Senha do Usuario: %s\n", cadastro[i].senha);
                printf("Saldo: %.2f\n", cadastro[i].saldo);
                printf("Tem certeza que deseja excluir esse usuario? (Acao nao reversivel.)\n[1]Sim\n[2]Nao\n->");
                if (scanf("%d", &esc) != 1) {
                    printf("Entrada invalida. Operacao cancelada.\n");
                    while (getchar() != '\n');
                    return -1;
                }

                if (esc == 1) {
                    if (i == *tamanho-1) {
                        cadastro = (struct dados*) realloc(cadastro, (*tamanho-1) * sizeof(struct dados));
                    } else {
                        cadastro[i].id = cadastro[*tamanho-1].id;
                            strcpy(cadastro[i].dono, cadastro[*tamanho-1].dono);
                            strcpy(cadastro[i].nome, cadastro[*tamanho-1].nome);
                            strcpy(cadastro[i].pet, cadastro[*tamanho-1].pet);
                            strcpy(cadastro[i].raca, cadastro[*tamanho-1].raca);
                            strcpy(cadastro[i].senha, cadastro[*tamanho-1].senha);
                            cadastro[i].saldo = cadastro[*tamanho-1].saldo;
                            cadastro = (struct dados*) realloc(cadastro, (*tamanho-1) * sizeof(struct dados));
                    }
                    *tamanho -= 1;
                    printf("Usuario excluido com sucesso\n");
                    esc = -1;
                }
            }
        }

        if (flag == 0) {
            printf("Conta nao encontrada!\n");
            printf("Deseja digitar novamente o ID da conta?\n[1]Sim\n[2]Nao: ");
            if (scanf("%d", &esc) != 1) {
                printf("Entrada invalida. Operacao cancelada.\n");
                while (getchar() != '\n');
                return -1;
            }
        }

    } while (esc == 1);

    return 0;
}
