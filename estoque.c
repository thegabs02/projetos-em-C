#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char nome[30];
  int preço;
  int quant;  
} estoque;

void config_menu(estoque *produto, int n);
int menu(estoque *produto, int n);

int main (void)
{
    estoque *produto;
    int n;

    printf("qual sera o numero de produtos?\n");
    scanf("%i", &n);
    getchar();

    produto = malloc(n * sizeof(estoque));
    config_menu(produto, n);
}

void config_menu(estoque *produto, int n)
{
    char nome[30];

    for(int i = 0; i < n; i++)
    {
        printf("qual sera o nome do %iº produto?\n", i+1);
        fgets(produto[i].nome, 30, stdin);
        produto[i].nome[strcspn(produto[i].nome, "\n")] = '\0';   

        printf("qual sera o preço?\n");
        scanf("%i", &produto[i].preço);
        getchar();

        printf("qual sera a quantidade do %iº produto?\n", i+1);
        scanf("%i", &produto[i].quant);
        getchar();
    }
    menu(produto, n);
}

int menu(estoque *produto, int n)
{
    int op;
    do{
        
        printf("MENU--------\n");
        printf("1 - listar produtos\n");
        printf("2 - comprar\n");
        printf("3 - adicionar ao estoque\n");
        printf("4 - sair\n");
        scanf("%i", &op);
    
        int add = 0 ;

        switch(op)
        {
            case 1:
                for(int i = 0; i < n+add; i++)
                {
                    printf("%iº produto == %s\n", i+1, produto[i].nome);
                }
                break;
        
            case 2:
                getchar();
                char nome[30];
                int compra;
                int encontrado = 0;

                printf("deseja comprar qual produto?\n");
                fgets(nome, 30, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                for(int i = 0; i < n; i++)
                {
                    if(strcmp(nome, produto[i].nome) == 0)
                    {
                        encontrado = 1;
                        printf("quantos %s deseja comprar?\n", produto [i].nome);
                        scanf("%i", &compra);
                        getchar();

                        if(produto[i].quant >= compra)
                        {
                            produto[i].quant -= compra;
                            printf("compra efetuada com sucesso\n");
                        }
                        else
                        {
                            printf("vc pd comprar apenas %i unidades desse produto\n", produto[i].quant);
                        }
                    }
               
                }
                if(encontrado == 0)
                {
                    printf("produto invalido\n");
                }
                break;
            case 3:

                printf("deseja adicionar quantos itens?\n");
                scanf("%i", &add);
                getchar();

                produto = realloc(produto, add+n * sizeof(estoque));
                int cont = n;
                for(int i = n; i < add+n; i++)
                {
                    printf("qual sera o nome do %iº produto?\n", i+1);
                    fgets(produto[cont].nome, 30, stdin);
                    produto[cont].nome[strcspn(produto[cont].nome, "\n")] = '\0';   

                    printf("qual sera o preço?\n");
                    scanf("%i", &produto[cont].preço);
                    getchar();

                    printf("qual sera a quantidade do %iº produto?\n", i+1);
                    scanf("%i", &produto[cont].quant);
                    getchar();
                
                    cont++;
                }
                break;
            case 4:
                printf("saindo...\n");
                return 0;
        }    

    }while (op != 4);
    return 0;
}