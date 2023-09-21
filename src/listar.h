int listar(int *tamanho) {
    int usuarios = 0;

    for (int i = 0; i < *tamanho; i++) {
        if (cadastro[i].id != 0) {
            printf("ID: %d\n", cadastro[i].id);
            printf("Dono: %s\n", cadastro[i].dono);
            printf("Nome: %s\n", cadastro[i].nome);
            printf("Pet: %s\n", cadastro[i].pet);
            printf("Raca: %s\n", cadastro[i].raca);
            printf("Senha: %s\n", cadastro[i].senha);
            printf("Saldo: %.2f\n", cadastro[i].saldo);
            printf("------------------------------\n\n");
            usuarios++;
        }
    }

    if (usuarios == 0) {
        return 0;
    }

    return usuarios;
}