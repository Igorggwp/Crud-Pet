<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct para armazenar dados dos clientes
struct dados {
    int id;
    char dono[20];
    char nome[20];
    char pet[20];
    char raca[20];
    char senha[20];
    char servico[20]; 
    char horario[20];
    float saldo;
}*cadastro; 

//logo do sistema
void logo () {

    printf("-----------------------------\n");
    printf("|        Pet&Gatô           |\n");
    printf("-----------------------------\n");

}

int init(int *tamanho) {
    FILE *file;
    file = fopen("banco-pet.txt", "r");
    if (file == NULL) {
        printf("Problemas na consulta do banco de dados.\n");
        return 0;
    }

    char vet[20], aux[20];
    int cont = 0, i = -1, mal = 0;

    while (fgets(vet, 100, file) != NULL) {
        
        if(cont == 0){
            if(mal == 0){
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
            *tamanho += 1;
        }

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
            cadastro[i].saldo = atof(aux);
        }
        cont++;
        if (cont >=9){
            cont = 0;
        }   
    }
    fclose(file);
    return 0;
}

int finit(int *tamanho) {
    FILE *file;
    file = fopen("banco-pet.txt", "w");
    if (file == NULL) {
        printf("Problemas na gravacao do banco de dados.\n");
        return 0;
    }
    for (int i = 0; i < *tamanho; i++) {
        fprintf(file, "%i\n", cadastro[i].id);
        fprintf(file, "%s", cadastro[i].dono);
        fprintf(file, "%s", cadastro[i].nome);
        fprintf(file, "%s", cadastro[i].pet);
        fprintf(file, "%s", cadastro[i].raca);
        fprintf(file, "%s", cadastro[i].senha);
        fprintf(file, "%s", cadastro[i].servico);
        fprintf(file, "%s", cadastro[i].horario);
        fprintf(file, "%f\n", cadastro[i].saldo);
    }
    fclose(file);
    return 0;
}

#include "src/cadastrar.h"
#include "src/adicionarSaldo.h"
#include "src/atualizar.h"
#include "src/excluir.h"
#include "src/listar.h"

int main () {
    
    int tamanho = 0;
    init(&tamanho);

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
                        printf("Seja bem vindo!\n\nSelecione a opcao desejada\n[1]Cadastrar\n[2]Adcionar Saldo\n[3]Atualizar Usuario\n[4]Voltar\n->");
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
                        system("cls")
                        printf("----------------------------------------\n");
                        printf("|            Agendamento               |\n");
                        printf("----------------------------------------\n");
                        servico(&tamanho);

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
                            printf("Escolha a opcao desejada:\n[1]Listar Usuarios\n[2]Excluir usuario\n[3]Voltar\n->");
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
                                printf("|             Excluir Conta            |\n");
                                printf("----------------------------------------\n");
                                excluir(&tamanho);

                                break;
                            case 3:
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
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct para armazenar dados dos clientes
struct dados {
    int id;
    char dono[20];
    char nome[20];
    char pet[20];
    char raca[20];
    char senha[20];
    char servico[20]; 
    char horario[20];
    float saldo;
}*cadastro; 

//logo do sistema
void logo () {

    printf("-----------------------------\n");
    printf("|        Pet&Gatô           |\n");
    printf("-----------------------------\n");

}

int init(int *tamanho) {
    FILE *file;
    file = fopen("banco-pet.txt", "r");
    if (file == NULL) {
        printf("Problemas na consulta do banco de dados.\n");
        return 0;
    }

    char vet[20], aux[20];
    int cont = 0, i = -1, mal = 0;

    while (fgets(vet, 100, file) != NULL) {
        
        if(cont == 0){
            if(mal == 0){
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
            *tamanho += 1;
        }

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
            cadastro[i].saldo = atof(aux);
        }
        cont++;
        if (cont >=9){
            cont = 0;
        }   
    }
    fclose(file);
    return 0;
}

int finit(int *tamanho) {
    FILE *file;
    file = fopen("banco-pet.txt", "w");
    if (file == NULL) {
        printf("Problemas na gravacao do banco de dados.\n");
        return 0;
    }
    for (int i = 0; i < *tamanho; i++) {
        fprintf(file, "%i\n", cadastro[i].id);
        fprintf(file, "%s", cadastro[i].dono);
        fprintf(file, "%s", cadastro[i].nome);
        fprintf(file, "%s", cadastro[i].pet);
        fprintf(file, "%s", cadastro[i].raca);
        fprintf(file, "%s", cadastro[i].senha);
        fprintf(file, "%s", cadastro[i].servico);
        fprintf(file, "%s", cadastro[i].horario);
        fprintf(file, "%f\n", cadastro[i].saldo);
    }
    fclose(file);
    return 0;
}

#include "src/cadastrar.h"
#include "src/adicionarSaldo.h"
#include "src/atualizar.h"
#include "src/excluir.h"
#include "src/listar.h"

int main () {
    
    int tamanho = 0;
    init(&tamanho);

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
                        printf("Seja bem vindo!\n\nSelecione a opcao desejada\n[1]Cadastrar\n[2]Adcionar Saldo\n[3]Atualizar Usuario\n[4]Voltar\n->");
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
                            printf("Escolha a opcao desejada:\n[1]Listar Usuarios\n[2]Excluir usuario\n[3]Voltar\n->");
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
                                printf("|             Excluir Conta            |\n");
                                printf("----------------------------------------\n");
                                excluir(&tamanho);
                                break;
                            case 3:
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
>>>>>>> main
}