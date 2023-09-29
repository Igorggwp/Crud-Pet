#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Struct para armazenar dados dos clientes
struct dados {
    int id;
    char dono[20];
    char nome[20];
    char pet[20];
    char raca[20];
    char senha[20];
    char servico[20]; 
    char horario[20];
    char data [20];
    float saldo;
}*cadastro; 

// Struct para armazenar dados dos produtos
struct produto {
    int id;
    char nome[50];
    int quantidade;
    float preco;
}*produtos;

// Logo do sistema
void logo () {
    SetConsoleOutputCP(CP_UTF8);
    printf("\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa2\x80\xe2\xa3\xa0\xe2\xa3\xa4\xe2\xa3\xb6\xe2\xa3\xb6\xe2\xa3\xb6\xe2\xa3\xb6\xe2\xa3\xb6\xe2\xa3\xa4\xe2\xa3\x84\xe2\xa1\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\n\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa3\xa0\xe2\xa3\xb4\xe2\xa3\xbe\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xb6\xe2\xa3\x84\xe2\xa1\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\n\xe2\xa0\x80\xe2\xa0\x80\xe2\xa3\xa0\xe2\xa3\xb4\xe2\xa3\xb4\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xae\xe2\xa3\xb5\xe2\xa3\x84\xe2\xa0\x80\xe2\xa0\x80\n\xe2\xa0\x80\xe2\xa2\xbe\xe2\xa3\xbb\xe2\xa3\xbf\xe2\xa2\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa2\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa1\x80\xe2\xa0\x80\n\xe2\xa0\xb8\xe2\xa3\xbd\xe2\xa3\xbb\xe2\xa0\x83\xe2\xa3\xbf\xe2\xa1\xbf\xe2\xa0\x8b\xe2\xa3\x89\xe2\xa0\x9b\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\x8f\xe2\xa1\x9f\xe2\xa0\x89\xe2\xa1\x89\xe2\xa2\xbb\xe2\xa3\xbf\xe2\xa1\x8c\xe2\xa3\xbf\xe2\xa3\xb3\xe2\xa1\xa5\xe2\xa0\x80\n\xe2\xa2\x9c\xe2\xa3\xb3\xe2\xa1\x9f\xe2\xa2\xb8\xe2\xa3\xbf\xe2\xa3\xb7\xe2\xa3\x84\xe2\xa3\xa0\xe2\xa3\xb4\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xa7\xe2\xa3\xa4\xe2\xa3\xa0\xe2\xa3\xbc\xe2\xa3\xbf\xe2\xa3\x87\xe2\xa2\xb8\xe2\xa2\xa7\xe2\xa2\xa3\xe2\xa0\x80\n\xe2\xa0\xa8\xe2\xa2\xb3\xe2\xa0\x87\xe2\xa3\xb8\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa2\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa1\xbf\xe2\xa0\xbf\xe2\xa0\xbf\xe2\xa0\xbf\xe2\xa2\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa0\x80\xe2\xa1\x9f\xe2\xa2\x86\xe2\xa0\x80\n\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x88\xe2\xa0\x80\xe2\xa3\xbe\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbc\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa1\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa0\x80\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbd\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa0\x90\xe2\xa0\x88\xe2\xa0\x80\xe2\xa0\x80\n\xe2\xa0\x80\xe2\xa2\x80\xe2\xa3\x80\xe2\xa3\xbc\xe2\xa3\xb7\xe2\xa3\xad\xe2\xa3\x9b\xe2\xa3\xaf\xe2\xa1\x9d\xe2\xa0\xbf\xe2\xa2\xbf\xe2\xa3\x9b\xe2\xa3\x8b\xe2\xa3\xa4\xe2\xa3\xa4\xe2\xa3\x80\xe2\xa3\x89\xe2\xa3\x9b\xe2\xa3\xbb\xe2\xa1\xbf\xe2\xa2\x9f\xe2\xa3\xb5\xe2\xa3\x9f\xe2\xa3\xaf\xe2\xa3\xb6\xe2\xa3\xbf\xe2\xa3\x84\xe2\xa1\x80\xe2\xa0\x80\n\xe2\xa3\xb4\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xb7\xe2\xa3\xb6\xe2\xa3\xb6\xe2\xa3\xb6\xe2\xa3\xbe\xe2\xa3\xb6\xe2\xa3\xb6\xe2\xa3\xb4\xe2\xa3\xbe\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa2\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xa7\n\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa0\xbf\xe2\xa2\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa3\xbf\xe2\xa0\xbf\xe2\xa0\xbf\xe2\xa3\xbf\xe2\xa1\xbf\n'");
    printf("-----------------------------\n");
    printf("|        Pet&Gato           |\n");
    printf("-----------------------------\n");

}

/* Inicializar txt dos dados dos clientes */

int init(int *tamanho) {
    // Abre o txt para a leitura
    FILE *file;
    file = fopen("banco-pet.txt", "r");
    // Verifica se o arquivo foi aberto corretamente
    if (file == NULL) {
        printf("Problemas na consulta do banco de dados.\n");
        return 0;
    }

    char vet[20], aux[20]; // Vetores para armazenar temporariamente os dados
    int cont = 0, i = -1, mal = 0; // Variaveis de controle

    while (fgets(vet, 100, file) != NULL) { // Le o arquivo linha por linha
        
        if(cont == 0){

            if(mal == 0){ // Alocação de memoria para a struct dados e inicializacao de campos
                cadastro = (struct dados*) malloc(sizeof(struct dados));
                mal++;
                if(cadastro == NULL){
                    printf("Erro na alocacao");
                        
                }   
            }else{
                cadastro = (struct dados*) realloc(cadastro, (*tamanho+1) * sizeof(struct dados));
            }
            strcpy(aux, vet);
            i++;
            cadastro[i].id = atoi(aux);
            *tamanho += 1; // Atualiza o tamanho
        }

        // Armazena os dados nos campos correspondentes
        if(cont == 1){
            strcpy(aux, vet);
            strcpy(cadastro[i].dono, aux);
        }
        if(cont == 2){
            strcpy(aux, vet);
            strcpy(cadastro[i].nome, aux);
        }
        if(cont == 3){
            strcpy(aux, vet);
            strcpy(cadastro[i].pet, aux);
        }
        if(cont == 4){
            strcpy(aux, vet);
             strcpy(cadastro[i].raca, aux);
        }
        if(cont == 5){
            strcpy(aux, vet);
            strcpy(cadastro[i].senha, aux);
        }
        if(cont == 6){
            strcpy(aux, vet);
            strcpy(cadastro[i].servico, aux);
        }
        if(cont == 7){
            strcpy(aux, vet);
            strcpy(cadastro[i].horario, aux);
        }
        if(cont == 8){
            strcpy(aux, vet);
            strcpy(cadastro[i].data, aux);
        }
        if(cont == 9){
            strcpy(aux, vet);
            cadastro[i].saldo = atof(aux);
        }
        cont++;
        if (cont >=10){
            cont = 0; // Reinicia o contador de campos
        }   
    }
    fclose(file); // Fecha o arquivo
    return 0;
}

/* Inicializar txt dos dados dos Produtos */

int pinit(int *tamanho_produto) {
    FILE *file;
    // Abre o txt para a leitura
    file = fopen("produto-pet.txt", "r");
    // Verifica se o arquivo foi aberto corretamente
    if (file == NULL) {
        printf("Problemas na consulta do banco de dados.\n");
        return 0;
    }

    char vet[20], aux[20]; // Vetores para armazenar temporariamente os dados
    int cont = 0, i = -1, mal = 0; // Variaveis de controle

    while (fgets(vet, 100, file) != NULL) {  // Le o arquivo linha por linha
        
        if(cont == 0){
            if(mal == 0){ // Alocação de memoria para a struct dados e inicializacao de campos
                produtos = (struct produto*) malloc(sizeof(struct produto));
                mal++;
                if(produtos == NULL){
                    printf("Erro na alocacao");
                        
                }   
            }else{
                produtos = (struct produto*) realloc(produtos, (*tamanho_produto+1) * sizeof(struct produto));
            }
            strcpy(aux, vet);
            i++;
            produtos[i].id = atoi(aux);
            *tamanho_produto += 1; // Atualiza o tamanho
        }

        // Armazena os dados nos campos correspondentes
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
            cont = 0; // Reinicia o contador de campos
        }   
    }
    fclose(file); // Fecha o arquivo
    return 0;
}

/* finit Escreve os registros do vetor 'cadastro' no arquivo 'banco-pet.txt'. */

int finit(int *tamanho) {
    // Abre o txt para a escrita
    FILE *file;
    file = fopen("banco-pet.txt", "w");
    // Verifica se o arquivo foi aberto corretamente
    if (file == NULL) {
        printf("Problemas na gravacao do banco de dados.\n");
        return 0;
    }
    for (int i = 0; i < *tamanho; i++) { // Itera sobre os registros e os escreve no arquivo
        // Escreve cada campo dos dados no arquivo
        fprintf(file, "%i\n", cadastro[i].id);
        fprintf(file, "%s", cadastro[i].dono);
        fprintf(file, "%s", cadastro[i].nome);
        fprintf(file, "%s", cadastro[i].pet);
        fprintf(file, "%s", cadastro[i].raca);
        fprintf(file, "%s", cadastro[i].senha);
        fprintf(file, "%s", cadastro[i].servico);
        fprintf(file, "%s", cadastro[i].horario);
        fprintf(file, "%s", cadastro[i].data);
        fprintf(file, "%f\n", cadastro[i].saldo);
    }
    fclose(file); // Fecha o arquivo
    return 0;
}

/* finit Escreve os registros do vetor 'cadastro' no arquivo 'produto-pet.txt'. */

int pfinit(int *tamanho_produto) {
    // Abre o txt para a escrita
    FILE *file;
    file = fopen("produto-pet.txt", "w");
    // Verifica se o arquivo foi aberto corretamente
    if (file == NULL) {
        printf("Problemas na gravacao do banco de dados.\n");
        return 0;
    }
    for (int i = 0; i < *tamanho_produto; i++) { // Itera sobre os registros e os escreve no arquivo
    // Escreve cada campo dos dados no arquivo
        fprintf(file, "%i\n", produtos[i].id);
        fprintf(file, "%s", produtos[i].nome);
        fprintf(file, "%i\n", produtos[i].quantidade);
        fprintf(file, "%f\n", produtos[i].preco);
    }
    fclose(file); // Fecha o arquivo
    return 0;
}

#include "src/cadastrar.h"
#include "src/adicionarSaldo.h"
#include "src/atualizar.h"
#include "src/excluir.h"
#include "src/listar.h"
#include "src/agendamento.h"
#include "src/produto/CadastrarProduto.h"
#include "src/produto/ProcurarProduto.h"
#include "src/produto/AtualizarProduto.h"
#include "src/produto/ListarProduto.h"
#include "src/produto/ExcluirProduto.h"

int main () {
    
    int tamanho = 0;
    init(&tamanho);

    int tamanho_produto = 0;
    pinit(&tamanho_produto);

    int esc_adm, very = 0, very3 = 0, esc = 0, flag = 0, very4 = 0, esc_cl;
    char senha[8], confsenha[8] = "petshop";

    do {
        system("cls");
        logo();
        do {
            printf("Selecione a opcao desejada:\n[1]Cliente\n[2]ADM\n[3]Sair\n->");
            scanf("%i", &esc);
            switch (esc) {
                case 1:
                    do {
                        very4 = 1;
                        very = 1;
                        flag = 0;
                        system("cls");
                        logo();
                        printf("Seja bem vindo!\n\nSelecione a opcao desejada\n[1]Cadastrar\n[2]Adcionar Saldo\n[3]Atualizar Usuario\n[4]Realizar Agendamento\n[5]Voltar\n->");
                    scanf("%i", &esc_cl);

                    switch (esc_cl)
                    {
                    case 1:
                        system("cls");
                        printf("----------------------------------------\n");
                        printf("|          Cadastro de Usuario         |\n");
                        printf("----------------------------------------\n");
                        cadastrar(&tamanho);

                        break;
                    case 2:
                        system("cls");
                        printf("----------------------------------------\n");
                        printf("|              Adcionar Saldo          |\n");
                        printf("----------------------------------------\n");
                        adicionarSaldo(&tamanho);

                        break;
                    case 3:
                        system("cls");
                        printf("----------------------------------------\n");
                        printf("|            Atualizar Usuario         |\n");
                        printf("----------------------------------------\n");
                        atualizar(&tamanho);

                        break;
                    case 4:
                        system("cls");
                        printf("----------------------------------------\n");
                        printf("|            Agendamentos              |\n");
                        printf("----------------------------------------\n");
                        agendamento(&tamanho);

                        break;
                    case 5:
                        system("cls");
                        logo();
                        very4 = 0;
                        flag = 1;
                        break;

                    default:
                        break;
                    }
                    if (flag != 1) {
                        printf("[1]Voltar\n->");
                        scanf("%i", &very4);
                    }
                } while (very4 != 0);
                    break;

            case 2:
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
                            printf("Escolha a opcao desejada:\n[1]Listar Usuarios\n[2]Gerenciar Produtos\n[3]Excluir usuario\n[4]Voltar\n->");
                            scanf("%i", &esc_adm);
                            switch (esc_adm) {
                            case 1:
                                system("cls");
                                very = 1;
                                printf("----------------------------------------\n");
                                printf("|             Listar Usuarios          |\n");
                                printf("----------------------------------------\n");
                                listar(&tamanho);

                                break;
                            case 2:
                                system("cls");
                                printf("----------------------------------------\n");
                                printf("|          Gerenciar Produtos           |\n");
                                printf("----------------------------------------\n");
                                int opc_prod;
                                printf("Escolha a opcao desejada:\n[1]Cadastrar Produto\n[2]Procurar Produto\n[3]Atualizar Produto\n[4]Listar Produtos\n[5]Excluir Produto\n[6]Voltar\n->");
                                scanf("%d", &opc_prod);
                                switch (opc_prod) {
                                case 1:
                                    system("cls");
                                    printf("----------------------------------------\n");
                                    printf("|           Cadastrar Produto          |\n");
                                    printf("----------------------------------------\n");
                                    CadastrarProduto(&tamanho_produto);

                                break;
                                case 2:
                                    system("cls");
                                    printf("----------------------------------------\n");
                                    printf("|           Procurar Produto           |\n");
                                    printf("----------------------------------------\n");
                                    ProcurarProduto(&tamanho_produto);

                                break;
                                case 3:
                                    system("cls");
                                    printf("----------------------------------------\n");
                                    printf("|            Atualizar Produto            |\n");
                                    printf("----------------------------------------\n");
                                    AtualizarProduto(&tamanho_produto);

                                break;
                                case 4:
                                    system("cls");
                                    printf("----------------------------------------\n");
                                    printf("|             Listar Produto           |\n");
                                    printf("----------------------------------------\n");
                                    ListarProdutos(&tamanho_produto);

                                break;
                                case 5:
                                    system("cls");
                                    printf("----------------------------------------\n");
                                    printf("|           Excluir Produto           |\n");
                                    printf("----------------------------------------\n");
                                    ExcluirProduto(&tamanho_produto);

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
            
                                break;
                            }

                                break;
                            case 3:
                                system("cls");
                                printf("----------------------------------------\n");
                                printf("|             Excluir Conta            |\n");
                                printf("----------------------------------------\n");
                                excluir(&tamanho);

                                break;
                            case 4:
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

            case 3:
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
    free(cadastro);
    pfinit(&tamanho_produto);
    free(produtos);
}