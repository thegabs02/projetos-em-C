#include<stdio.h>
#include<string.h>

int calculadora (char player1[], char player2[]);
void pontuaçaof (int somap1, int somap2, char player1[], char player2[]);
int main (void)
{
    char player1[11];
    char player2[11];

    printf("escreva suas palavras [minimo de 10 letras]\n");
    
    printf("player1: ");
    scanf("%s", player1);

    printf("player2: ");
    scanf("%s", player2);
    calculadora (player1, player2);
}
int calculadora (char player1[], char player2[])
{
  int tabela[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
  
  int pontosp1 = 0;
  int letrap1;
  int somap1 = 0;
  int pontosp2 = 0;
  int letrap2;
  int somap2 = 0;
  
  for(int i = 0; i < strlen(player1); i++)
  {
    letrap1 = player1[i];  
    letrap1 = letrap1 - 'a';

    pontosp1 = tabela[letrap1];
    
    somap1 += pontosp1;
  }
   

  for(int o = 0; o < strlen(player2); o++)
  {
    letrap2 = player2[o];  
    letrap2 = letrap2 - 'a';

    pontosp2 = tabela[letrap2];
    
    somap2 += pontosp2;
  }
  pontuaçaof (somap1, somap2, player1, player2);
  return somap1, somap2;  
}
void pontuaçaof (int somap1, int somap2, char player1[], char player2[])
{
  printf("a palavra  %s possui %i pontos\n", player1, somap1);
  printf("enquanto a palavra  %s possui %i pontos\n", player2, somap2);

  if (somap1 > somap2)
  {
    printf("o player1 venceu!");
  }

  else if (somap2 > somap1)
  {
    printf("o player1 venceu!");
  }
  else
  {
    printf("empate");
  }
}
