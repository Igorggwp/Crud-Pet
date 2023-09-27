#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto {
    int id;
    char nome[50];
    int quantidade;
    float preco;
}*produtos;

void logo () {

    printf("-----------------------------\n");
    printf("|        Pet&Gato           |\n");
    printf("-----------------------------\n");

}

int init(int *tamanho) {
    FILE *file;
    file = fopen("produto-pet.txt", "r");
    if (file == NULL) {
        printf("Problemas na consulta do banco de dados.\n");
        return 0;
    }

    char vet[20], aux[20];
    int cont = 0, i = -1, mal = 0;

    while (fgets(vet, 100, file) != NULL) {
        
        if(cont == 0){
            if(mal == 0){
                produtos = (struct produto*) malloc(sizeof(struct produto));
                mal++;
                if(produtos == NULL){
                    printf("Erro na alocacao");
                        
                }   
            }else{
                produtos = (struct produto*) realloc(produtos, (*tamanho+1) * sizeof(struct produto));
            }
            strcpy(aux, vet);
            i++;
            produtos[i].id = atoi(aux);
            *tamanho += 1;
        }

        if(cont == 1){
            strcpy(aux, vet);
            strcpy(produtos[i].nome, aux);
        }
        if(cont == 2){
            strcpy(aux, vet);
            produtos[i].quantidade = atoi(aux);
        }
        if(cont == 3){
            strcpy(aux, vet);
            produtos[i].preco = atof(aux);
        }
        cont++;
        if (cont >=4){
            cont = 0;
        }   
    }
    fclose(file);
    return 0;
}

int finit(int *tamanho) {
    FILE *file;
    file = fopen("produto-pet.txt", "w");
    if (file == NULL) {
        printf("Problemas na gravacao do banco de dados.\n");
        return 0;
    }
    for (int i = 0; i < *tamanho; i++) {
        fprintf(file, "%i\n", produtos[i].id);
        fprintf(file, "%s", produtos[i].nome);
        fprintf(file, "%i\n", produtos[i].quantidade);
        fprintf(file, "%f\n", produtos[i].preco);
    }
    fclose(file);
    return 0;
}

/* Cadastrar Produto */

int CadastrarProduto(int *tamanho) {
    int idcad = 0;

    for (int i = 0; i < *tamanho; i++) {
        if (produtos[i].id > idcad) {
            idcad = produtos[i].id;
        }
    }

    idcad++;

    produtos = (struct produto *)realloc(produtos, (*tamanho + 1) * sizeof(struct produto));

    if (produtos == NULL) {
        printf("Erro na realocacao de memoria.\n");
        return 0;
    }

    produtos[*tamanho].id = idcad;
    fflush(stdin);
    printf("Digite o nome do Produto: ");
    gets(produtos[*tamanho].nome);
    strcat(produtos[*tamanho].nome, "\n");
    fflush(stdin);
    printf("Digite a quantidade de Produtos: ");
    scanf("%d", &produtos[*tamanho].quantidade);
    fflush(stdin);
    printf("Digite o valor do Produto: ");
    scanf("%f", &produtos[*tamanho].preco);
    fflush(stdin);
    printf("CADASTRADO COM SUCESSO!\nO ID do produto e: %d\n", idcad);

    *tamanho += 1;

    finit(tamanho);
    return idcad;
}

/* Procurar Produto */

void ProcurarProduto(int *tamanho) {
    int id_procurar, produto_encontrado = 0;

    printf("Digite o ID do produto que deseja procurar: ");
    scanf("%d", &id_procurar);

    for (int i = 0; i < *tamanho; i++) {
        if (id_procurar == produtos[i].id) {
            printf("Produto encontrado!\n");
            printf("ID: %d\n", produtos[i].id);
            printf("Nome do Produto: %s", produtos[i].nome);
            printf("Quantidade de Produtos: %d\n", produtos[i].quantidade);
            printf("Preco do Produto: %.2f\n", produtos[i].preco);
            produto_encontrado = 1;
            break;
        }
    }

    if (!produto_encontrado) {
        printf("Produto com ID %d nao encontrado.\n", id_procurar);
    }
}

/* Atualizar Produto */

void AtualizarProduto(int *tamanho) {
    int idat, subs, exist = -1, new, new2, atualizado = 1;

    printf("Digite o ID do cadastro que deseja atualizar\nDigite 0 para cancelar\n->");
    scanf("%i", &idat);
    if (idat == 0) {
        return;
    }

    for (int i = 0; i < *tamanho; i++) {
        if (idat == produtos[i].id) {
            exist = i;
        }
    }

    if (exist == -1) {
        printf("\nCadastro nao encontrado!\n");
    } else {
        do {
            printf("-------------------\n");
            for (int i = 0; i < *tamanho; i++) {
                if (idat == produtos[i].id) {
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

            switch (subs) {
                case 1:
                    printf("Nome do Produto: ");
                    fflush(stdin);
                    gets(produtos[new].nome);
                    strcat(produtos[new].nome, "\n");
                    atualizado = 1;
                    break;
                case 2:
                    printf("Quantidade de Produtos: ");
                    fflush(stdin);
                    scanf("%d", &produtos[new].quantidade);
                    atualizado = 1;
                    break;
                case 3:
                    printf("Valor do Produto: ");
                    fflush(stdin);
                    scanf("%f", &produtos[new].preco);
                    atualizado = 1;
                    break;
                case 4:
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
    finit(tamanho);
}


/* Listar Produtos */

int ListarProdutos(int *tamanho) {
    int usuarios = 0;

    for (int i = 0; i < *tamanho; i++) {
        if (produtos[i].id != 0) {
            printf("ID: %d\n", produtos[i].id);
            printf("Nome do Produto: %s\n", produtos[i].nome);
            printf("Quantidade do Produto: %i\n", produtos[i].quantidade);
            printf("Valor do Produto: %.2f\n", produtos[i].preco);
            printf("------------------------------\n\n");
            usuarios++;
        }
    }

    if (usuarios == 0) {
        return 0;
    }

    return usuarios;
}

/* Excluir Produto */

int ExcluirProduto(int *tamanho) {
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
        for (int i = 0; i < *tamanho; i++) {
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
                    if (i == *tamanho-1) {
                        produtos = (struct produto*) realloc(produtos, (*tamanho-1) * sizeof(struct produto));
                    } else {
                        produtos[i].id = produtos[*tamanho-1].id;
                        produtos[i].quantidade = produtos[*tamanho-1].quantidade;
                        produtos[i].preco = produtos[*tamanho-1].preco;
                        produtos = (struct produto*) realloc(produtos, (*tamanho-1) * sizeof(struct produto));
                    }
                    *tamanho -= 1;
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
    for (int i = 0; i < *tamanho; i++) { //variaveis de controle
        for (int j = i; j < *tamanho; j++) {
            if (produtos[i].id > produtos[j].id) { //se i for maior que j, ocorre a troca crescente
                struct produto temp = produtos[i]; // struct dados temp armazena temporariamente uma cadastro durante a troca
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }

    return 0;
}

int main () {
    
    int tamanho = 0;
    init(&tamanho);

    int esc_adm, very = 0, very3 = 0, esc = 0, flag = 0, very4 = 0;
    char senha[8], confsenha[8] = "petshop";

    do {
        system("cls");
        logo();
        do {
            printf("Selecione a opcao desejada:\n[1]ADM\n[2]Sair\n->");
            scanf("%i", &esc);
            switch (esc) {
            case 1:
                do {
                    flag = 0;
                    printf("Digite a senha de acesso: ");
                    getchar();
                    fgets(senha, sizeof(senha), stdin);
                    senha[strcspn(senha, "\n")] = '\0';
                    if (strcmp(senha, confsenha) == 0) {
                        do {
                            very3 = 2;
                            very4 = 0;
                            flag = 0;
                            system("cls");
                            logo();
                             printf("Seja bem vindo!\n\nSelecione a opcao desejada\n[1]Cadastrar Produtos\n[2]Procurar Produto\n[3]Atualizar Produto\n[4]Listar Produto\n[5]Excluir Produto\n[6]Voltar\n->");
                            scanf("%i", &esc_adm);
                            switch (esc_adm) {
                            case 1:
                                system("cls");
                                printf("----------------------------------------\n");
                                printf("|           Cadastrar Produto          |\n");
                                printf("----------------------------------------\n");
                                CadastrarProduto(&tamanho);

                                break;
                            case 2:
                                system("cls");
                                printf("----------------------------------------\n");
                                printf("|           Procurar Produto           |\n");
                                printf("----------------------------------------\n");
                                ProcurarProduto(&tamanho);

                                break;
                            case 3:
                                system("cls");
                                printf("----------------------------------------\n");
                                printf("|            Atualizar Produto            |\n");
                                printf("----------------------------------------\n");
                                AtualizarProduto(&tamanho);

                                break;
                            case 4:
                                system("cls");
                                printf("----------------------------------------\n");
                                printf("|             Listar Produto           |\n");
                                printf("----------------------------------------\n");
                                ListarProdutos(&tamanho);

                                break;
                            case 5:
                                system("cls");
                                printf("----------------------------------------\n");
                                printf("|           Excluir Produto           |\n");
                                printf("----------------------------------------\n");
                               ExcluirProduto(&tamanho);

                                break;
                            case 6:
                                system("cls");
                                logo();
                                very = 1;
                                very4 = 0;
                                flag = 1;
                                break;
                            default:
                                system("cls");
                                printf("Opcao invalida!\n");
                                very = 1;
                                break;
                            }

                            if (flag != 1) {
                                printf("[1]Voltar\n->");
                                scanf("%i", &very4);
                            }

                        } while (very4 != 0);
                    }
                    else {
                        printf("Senha Invalida!\n");
                        printf("Tentar Novamente?\n[1]Sim\n[2]Nao\n->");
                        scanf("%i", &very3);
                    }
                } while (very3 != 2);
                break;

            case 2:
                printf("Obrigado por escolher o melhor PET SHOP do Brasil!");
                very = 0;
                very3 = 1;
                break;
            default:
                break;
            }
        } while (very3 != 1);

    } while (very != 0);
    finit(&tamanho);
    free(produtos);
}