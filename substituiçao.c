#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void criptografia(char chave[27]);
int main (int argc, char *argv[])
{
     if(argc != 2)
     {
        printf("digite a chave de criptografia\n");
        return 0;
     }

    int tam = 0;
    char car;
    for(int i = 0; i < strlen(argv[1]); i++)
    {
        if(isdigit(argv[1] [i]))
        {
            printf("todos os caracteres precisam ser letras\n");
            return 0;
        }
        car = argv[1][i];
        for(int o = i + 1; o < strlen(argv[1]); o++)
        {
            if(car == argv[1][o])
            {
                
                printf("nao podem aver caracteres repetidos\n");
                return 0;
            }
           
        }
        tam++;
    }
    if(tam != 26)
    {
        printf("a chave precisa ter 26 caracteres\n");
        return 0;
    }
    char chave[27];
    strcpy(chave, argv[1]);
    criptografia(chave);
}
void criptografia(char chave[27])
{
    char texto[50];
    printf("digite o texto para ser criptografado\n");
    scanf("%s", texto);
    
    char letra;
    char cifre;
    for(int i = 0; i < strlen(texto); i++)
    {
        letra = texto[i] - 'a';
        cifre = chave[letra];

       if(isupper(texto[i]))
       {
            printf("%c", toupper(cifre));
       }

       else if(islower(texto[i]))
       {
            printf("%c", tolower(cifre));
       }
    }
    
}