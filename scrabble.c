#include<stdio.h>
#include<string.h>

int calculadora (char player1[], char player2[]);

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
  return 0;  
}
