#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dados
{
    char motivo[50];
    char data[11];
    float valor;
};

void inserir_gasto(struct Dados *dados, int *num_gastos) {
    printf("Nome do gasto: ");
    scanf("%s", dados[*num_gastos].motivo);
    printf("Valor do gasto: ");
    scanf("%f", &dados[*num_gastos].valor);
    printf("Data do gasto (DD/MM/AAAA): ");
    scanf("%s", dados[*num_gastos].data);

    (*num_gastos)++;
    printf("Gasto inserido com sucesso!\n");
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
    float num_gasto = 0;
    struct Dados dados[100];

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
        case '0':
            printf("Saindo...\n");     
            break;        
        
        default:
            printf("Opcao invalida. Escolha novamente.\n");
        }

    } while ( choice != '0');
    
    return 0;
}