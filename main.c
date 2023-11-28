#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//modifiquei o nome do struct e coloquei um apelido para interagir melhor com o codigo
//nome da variavel mudado de motivo para nome
typedef struct Gasto
{
    //nome da variavel mudado para nome (cuidado quando chamar);
    char nome[50];
    char data[11];
    float valor;
}Gasto;

// 
void inserir_gasto(Gasto *dados, int *num_gastos) {
    printf("Nome do gasto: ");
    scanf("%s", dados[*num_gastos].nome);
    printf("Valor do gasto: ");
    scanf("%f", &dados[*num_gastos].valor);
    printf("Data do gasto (DD/MM/AAAA): ");
    scanf("%s", dados[*num_gastos].data);

    (*num_gastos)++;
    printf("Gasto inserido com sucesso!\n");
}

void salvar_em_arquivo(Gasto *gastos, int numGastos, char *nomeArquivo) {
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

void imprimir_interface()
{
    printf("=====================================\n");
    printf("|         Registro de gastos        |\n");
    printf("!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!\n");
    printf("| 1- Adcionar gastos                |\n");
    printf("| 2- Buscas gastos/ listar          |\n");
    printf("| 3- Editar gasto                   |\n");
    printf("| 4- Remover gasto                  |\n");
    printf("| 5- Mostrar soma/ media dos gastos |\n");
    printf("| 6- Salvar em arquivo              |\n"); 
    printf("| 0- Sair                           |\n"); 
    printf("=====================================\n");
    printf("Escolha: ");
}

int main()
{    
    char choice;
    int num_gasto = 0;
    Gasto dados[100];
    
    do
    {
        imprimir_interface();
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            inserir_gasto(dados, &num_gasto);
            break;
        case '2':
        
            break;
        case '3':
        
            break;
        case '4':
        
            break;
        case '5':
        
            break;
        case '6':
            printf("Escolha o nome do arquivo onde o gasto sera guardado. ");
            salvar_em_arquivo(dados,num_gasto,"arquivo.txt");
            break;
        case '0':
            printf("Saindo...\n");     
            break;        
        
        default:
            printf("Opcao invalida. Escolha novamente.\n");
        }

    } while ( choice != '0');
    
    return 0;
}