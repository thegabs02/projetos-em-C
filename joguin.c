#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    int vida;
    int passos;
    char nickname[10];
}status;

void mapa (status player[1]);
int main (void)
{
    //pegando o nome do jogador
    status player[1];
 
    printf("digite seu nome player: ");
    fgets(player->nickname, sizeof(player->nickname), stdin);
    mapa(player);
}

void mapa (status player[1])
{
    //criando o mapa *teste
    //primeiro for é linha e o segundos as colunas
    for(int i = 0; i < 5; i++)
    {
        for(int j = 1; j < 10; j++)
        {
            if(i == 2 && j == 5)
            {
                printf( "%2s", "& ");
            }
            else
            {
                printf("%2s", "# ");
            }
        }
        printf("\n");
        
    }
}