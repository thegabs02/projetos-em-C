#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct
{
    string nome;
    int votos;
    bool eliminado;
}estrutura;

bool eh_candidato(int argc ,string argv[], string voto);
void eleiçao(int argc, string argv[]);
int main (int argc, string argv[])
{
    if(argc < 3)
    {
        printf("coloque tres candidatos ou mais\n");
        return  true
    }
    eleiçao(argc, argv);
    return 0;

}

void eleiçao(int argc, string argv[])
{
    estrutura candidatos;

    int num_candidatos = argc - 1;

    int eleitores = get_int("qual é a quantidade de eleitores? ");

    for(int i = 0; i < eleitores; i++)
    {
        for(int o = 0; o < num_candidatos; o++)
        {
            string voto = get_string("Pra quem é o seu %iº voto? ", i + 1);
            if(eh_candidato(argc, argv, voto))
            {
                printf("candidato valido\n");
            }
            else
            {
                printf("candidato invalido\n");
            }
        }
    }
}
bool eh_candidato(int argc, string argv[], string voto)
{
    estrutura candidatos;
    for(int i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], voto) == 0)
        {
            return true;
        }
    }
    return false;
    return 0;
}

