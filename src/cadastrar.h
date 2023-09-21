int cadastrar(int *tamanho) {
    int idcad = 0;

    for (int i = 0; i < *tamanho; i++) {
        if (cadastro[i].id > idcad) {
            idcad = cadastro[i].id;
        }
    }

    idcad++;

    cadastro = (struct dados *)realloc(cadastro, (*tamanho + 1) * sizeof(struct dados));

    if (cadastro == NULL) {
        printf("Erro na realocacao de memoria.\n");
        return 0;
    }

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
    printf("Digite qual animal e seu pet: ");
    gets(cadastro[*tamanho].pet);
    strcat(cadastro[*tamanho].pet, "\n");
    fflush(stdin);
    printf("Digite a raca do pet: ");
    gets(cadastro[*tamanho].raca);
    strcat(cadastro[*tamanho].raca, "\n");
    fflush(stdin);
    printf("Digite sua senha de acesso: ");
    gets(cadastro[*tamanho].senha);
    strcat(cadastro[*tamanho].senha, "\n");
    fflush(stdin);
    cadastro[*tamanho].saldo = 0.00;
    printf("CADASTRADO COM SUCESSO!\nSeu ID e: %d\n", idcad);

    *tamanho += 1;

    finit(tamanho);
    return idcad;
}
