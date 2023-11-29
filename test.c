#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar informações de um gasto
struct Gasto {
    char nome[50];
    float valor;
    char data[11]; // DD/MM/AAAA
};

// Função para inserir um novo gasto
void inserirGasto(struct Gasto *gastos, int *numGastos) {
    printf("Nome do gasto: ");
    scanf("%s", gastos[*numGastos].nome);
    printf("Valor do gasto: ");
    scanf("%f", &gastos[*numGastos].valor);
    printf("Data do gasto (DD/MM/AAAA): ");
    scanf("%s", gastos[*numGastos].data);

    (*numGastos)++;
    printf("Gasto inserido com sucesso!\n");
}

// Função para listar todos os gastos
void listarGastos(struct Gasto *gastos, int numGastos) {
    if (numGastos == 0) {
        printf("Nenhum gasto registrado.\n");
    } else {
        for (int i = 0; i < numGastos; i++) {
            printf("%d. Nome: %s - Valor: R$ %.2f - Data: %s\n", i + 1, gastos[i].nome, gastos[i].valor, gastos[i].data);
        }
    }
}

// Função para buscar um gasto pelo nome
void buscarGasto(struct Gasto *gastos, int numGastos) {
    char nomeBusca[50];
    printf("Digite o nome do gasto a ser buscado: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < numGastos; i++) {
        if (strcmp(gastos[i].nome, nomeBusca) == 0) {
            printf("Nome: %s - Valor: R$ %.2f - Data: %s\n", gastos[i].nome, gastos[i].valor, gastos[i].data);
            return;
        }
    }

    printf("Gasto com nome '%s' não encontrado.\n", nomeBusca);
}

// Função para editar um gasto pelo nome
void editarGasto(struct Gasto *gastos, int numGastos) {
    char nomeEdicao[50];
    printf("Digite o nome do gasto a ser editado: ");
    scanf("%s", nomeEdicao);

    for (int i = 0; i < numGastos; i++) {
        if (strcmp(gastos[i].nome, nomeEdicao) == 0) {
            printf("Novo valor do gasto: ");
            scanf("%f", &gastos[i].valor);
            printf("Nova data do gasto (DD/MM/AAAA): ");
            scanf("%s", gastos[i].data);
            printf("Gasto editado com sucesso!\n");
            return;
        }
    }

    printf("Gasto com nome '%s' não encontrado.\n", nomeEdicao);
}

// Função para remover um gasto pelo nome
void removerGasto(struct Gasto *gastos, int *numGastos) {
    char nomeRemocao[50];
    printf("Digite o nome do gasto a ser removido: ");
    scanf("%s", nomeRemocao);

    for (int i = 0; i < *numGastos; i++) {
        if (strcmp(gastos[i].nome, nomeRemocao) == 0) {
            // Move os elementos à frente para preencher o espaço vago
            for (int j = i; j < *numGastos - 1; j++) {
                gastos[j] = gastos[j + 1];
            }
            (*numGastos)--;
            printf("Gasto removido com sucesso!\n");
            return;
        }
    }

    printf("Gasto com nome '%s' não encontrado.\n", nomeRemocao);
}

// Função para mostrar soma e média dos gastos
void mostrarSomaMedia(struct Gasto *gastos, int numGastos) {
    if (numGastos == 0) {
        printf("Nenhum gasto registrado.\n");
        return;
    }

    float soma = 0;
    for (int i = 0; i < numGastos; i++) {
        soma += gastos[i].valor;
    }

    float media = soma / numGastos;
    printf("Soma dos gastos: R$ %.2f\n", soma);
    printf("Média dos gastos: R$ %.2f\n", media);
}

// Função para salvar a lista de gastos em um arquivo
void salvarEmArquivo(struct Gasto *gastos, int numGastos, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < numGastos; i++) {
        fprintf(arquivo, "%s %.2f %s\n", gastos[i].nome, gastos[i].valor, gastos[i].data);
    }

    fclose(arquivo);
    printf("Lista de gastos salva em arquivo.\n");
}

int main() {
    struct Gasto gastos[100]; // Capacidade para 100 gastos
    int numGastos = 0;

    while (1) {
        printf("\n=== Menu ===\n");
        printf("1. Inserir novo gasto\n");
        printf("2. Listar gastos\n");
        printf("3. Buscar gasto\n");
        printf("4. Editar gasto\n");
        printf("5. Remover gasto\n");
        printf("6. Mostrar soma e média dos gastos\n");
        printf("7. Salvar em arquivo\n");
        printf("0. Sair\n");

        int escolha;
        printf("Escolha a opção desejada: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                inserirGasto(gastos, &numGastos);
                break;
            case 2:
                listarGastos(gastos, numGastos);
                break;
            case 3:
                buscarGasto(gastos, numGastos);
                break;
            case 4:
                editarGasto(gastos, numGastos);
                break;
            case 5:
                removerGasto(gastos, &numGastos);
                break;
            case 6:
                mostrarSomaMedia(gastos, numGastos);
                break;
            case 7: {
                char nomeArquivo[50];
                printf("Digite o nome do arquivo para salvar: ");
                scanf("%s", nomeArquivo);
                //salvarEmAr
            }
        }
    }
}