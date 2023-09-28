int listar(int *tamanho) {
    int usuarios = 0;

    // Verifica se o ponteiro 'cadastro' é nulo
    if (cadastro == NULL) {
        printf("Erro: Nenhum cadastro encontrado.\n");
        return 0;
    }

    // Loop para varrer todos os Cadastros e exibir todos na tela
    for (int i = 0; i < *tamanho; i++) {
        if (cadastro[i].id != 0) {
            printf("ID: %d\n", cadastro[i].id);
            printf("Dono: %s", cadastro[i].dono);
            printf("Nome: %s", cadastro[i].nome);
            printf("Pet: %s", cadastro[i].pet);
            printf("Raca: %s", cadastro[i].raca);
            printf("Senha: %s", cadastro[i].senha);
            printf("Servico: %s", cadastro[i].servico);
            printf("Horario: %s", cadastro[i].horario);
            printf("Data: %s", cadastro[i].data);
            printf("Saldo: %.2f\n", cadastro[i].saldo);
            printf("------------------------------\n\n");
            usuarios++;
        }
    }

    if (usuarios == 0) {
        printf("Nenhum usuário cadastrado.\n");
    }

    return usuarios;
}
