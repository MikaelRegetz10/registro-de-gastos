#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Gasto
{
    char *nome;
    char data[11];
    float valor;
}Gasto;

void limpar_buffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void listar_ou_buscar_gastos(Gasto *dados, int num_gastos) 
{
    while (1)
    {
        int digito;
        printf("O que voce quer fazer:\n1. Listar gastos;\n2. Buscar Gastos.\n");
        scanf("%d", &digito);

        if (digito == 1) 
        {
            if (num_gastos == 0) 
            {
                printf("Nenhum gasto registrado.\n");
            } else {
                for (int i = 0; i < num_gastos; i++) {
                    printf("%d. Nome: %s - Valor: R$ %.2f - Data: %s\n", i + 1, dados[i].nome, dados[i].valor, dados[i].data);
                }
            }
            break;
        } 
        else if (digito == 2) {
            char nomeBusca[50];
            printf("Digite o nome do gasto a ser buscado: ");
            scanf("%s", nomeBusca);
            
            for (int i = 0; i < num_gastos; i++) {
                if (strcmp(dados[i].nome, nomeBusca) == 0) {
                    printf("Nome: %s - Valor: R$ %.2f - Data: %s\n", dados[i].nome, dados[i].valor, dados[i].data);
                    return;
                }
            }
            printf("Gasto com nome '%s' não encontrado.\n", nomeBusca);
            break;
        }
        else {
            printf("Opcao nao identificada.\n");
        }
    }
}

void editar_gasto(struct Gasto *dados, int num_gastos) 
{
    char nomeEdicao[50];
    printf("Digite o nome do gasto a ser editado: ");
    scanf("%s", nomeEdicao);

    for (int i = 0; i < num_gastos; i++) {
        if (strcmp(dados[i].nome, nomeEdicao) == 0) {
            printf("Novo valor do gasto: ");
            scanf("%f", &dados[i].valor);
            printf("Nova data do gasto: ");
            scanf("%s", dados[i].data);
            printf("Gasto editado com sucesso!\n");
            return;
        }
    }

    printf("Gasto com nome '%s' nao encontrado.\n", nomeEdicao);
}

void remover_gasto(Gasto *dados, int *num_gastos) 
{
    char nomeRemocao[50];
    printf("Digite o nome do gasto a ser removido: ");
    scanf("%s", nomeRemocao);

    for (int i = 0; i < *num_gastos; i++) {
        if (strcmp(dados[i].nome, nomeRemocao) == 0) {

            for (int j = i; j < *num_gastos - 1; j++) {
                dados[j] = dados[j + 1];
            }
            (*num_gastos)--;

            printf("Gasto removido com sucesso!\n");
            return;
        }
    }

    printf("Gasto com nome '%s' nao encontrado.\n", nomeRemocao);
}


void inserir_gasto(Gasto *dados, int *num_gastos) 
{
    dados[*num_gastos].nome = (char *)malloc(100 * sizeof(char)); 

    limpar_buffer();

    printf("Nome do gasto: ");
    fgets(dados[*num_gastos].nome, 100, stdin);
    dados[*num_gastos].nome[strcspn(dados[*num_gastos].nome, "\n")] = '\0';

    printf("Valor do gasto: ");
    scanf("%f", &dados[*num_gastos].valor);
    limpar_buffer(); 

    // VALIDAÇÃO DE DIA
    int dia, mes, ano;

    while (1) {
        printf("Digite a data no formato DD/MM/AAAA: ");
        fgets(dados[*num_gastos].data, sizeof(dados[*num_gastos].data), stdin);
        dados[*num_gastos].data[strcspn(dados[*num_gastos].data, "\n")] = '\0'; 

        if (sscanf(dados[*num_gastos].data, "%d/%d/%d", &dia, &mes, &ano) == 3) {
            if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && ano >= 1000 && ano <= 9999) {
                (*num_gastos)++;
                printf("Gasto inserido com sucesso!\n");
                break;
            } else {
                printf("Data invalida. Certifique-se de digitar uma data valida.\n");
            }
        } else {
            printf("Formato invalido. Certifique-se de seguir o formato DD/MM/AAAA.\n");
        }
    }
}

void salvar_em_arquivo(Gasto *gastos, int numGastos) 
{
    char nomearquivo[15];
    printf("Em qual arquivo o gasto sera guardado? ");
    fflush(stdin);
    fgets(nomearquivo,sizeof(nomearquivo),stdin);
    nomearquivo[strcspn(nomearquivo, "\n")] = '\0';
    
    char arquivoDest[50] = "gastos\\";
    strcat(arquivoDest, nomearquivo);
    FILE *arquivo = fopen(arquivoDest, "w");

    for (int i = 0; i < numGastos; i++) {
        fprintf(arquivo, "Nome: %s, Valor: R$ %.2f Data: %s\n", gastos[i].nome, gastos[i].valor, gastos[i].data);
    }

    fclose(arquivo);
    printf("Lista de gastos salva em arquivo.\n");
}

void calcular_soma_media(struct Gasto *gastos, int numGastos)
{
    float soma = 0;

    if (numGastos == 0){
        printf("Nenhum gasto cadastrado.\n");
        return;
    }

    for (int i = 0; i < numGastos; i++){
        soma += gastos[i].valor;
    }

    printf("Soma dos gastos: R$%.2f\n", soma);
    printf("Media dos gastos: R$%.2f\n", soma / numGastos);
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
            listar_ou_buscar_gastos(dados, num_gasto);
            break;
        case '3':
            editar_gasto(dados, num_gasto);
            break;
        case '4':
            remover_gasto(dados, &num_gasto);
            break;
        case '5':
            calcular_soma_media(dados, num_gasto);
            break;
        case '6':
            salvar_em_arquivo(dados, num_gasto);
            break;
        case '0':
            printf("Saindo...\n");     
            break;        
        
        default:
            printf("Opcao invalida. Escolha novamente.\n");
        }

    } while ( choice != '0');
    
    for (int i = 0; i < num_gasto; i++) {
            free(dados[i].nome);
        }


    return 0;
}
