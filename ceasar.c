#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int convertor(int cifra, char palavra[]);
int main (int argc, char *argv[])
{
    if(argc > 2 && argc < 2)
    {
        printf("digite o numero de casas puladas ao iniciar\n");
    }

    int cifra = atoi(argv[1]);
    char palavra[50];

    printf("digite a palavra que deseja criptografar:\n");
    scanf("%s", palavra);

    convertor(cifra, palavra);
}
int convertor(int cifra, char palavra[])
{
    int index;
    int texto;
    int cont;
    for(int i = 0; i < strlen(palavra); i++)
    {
        char letra = palavra[i];
       
        if(islower(letra))
        {
            index = letra - 'a';

            texto = (index + cifra) % 26;
            
            texto += 'a';
            printf("%c", texto);   
        }
        else if(isalpha(letra))
        {
           
            index = letra - 'A';

            texto = (index + cifra) % 26;
            
            texto += 'A';
            printf("%c", texto);   
        }
        else
        {
            printf("%c", letra);
        }
    }
    
    
}