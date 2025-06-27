#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void vencedor (int argc, string argv[], int votos[]);
bool cont_votos (int argc ,string argv[], string voto, int votos[]);
void contagem_votos(int argc, string argv[]);

int main (int argc, string argv[])
{
    if(argc < 2)
    {
        printf("INVALIDO\n");
        printf("é necessario quatro parametros\n");
        exit(1);
    }
    contagem_votos(argc, argv);
    return 0;
}
void contagem_votos(int argc, string argv[])
{
    int const num_candidatos = argc - 1;
    int votos[num_candidatos];

    for( int o = 0; o < num_candidatos; o++)
    {
        votos[o] = 0;
    }

    int num_eleitores = get_int("quantos eleirores vao participar? ");

    for(int i = 0; i < num_eleitores; i++)
    {
        string voto = get_string("digite o nome do seu candidato:");
        if(cont_votos(argc, argv, voto, votos))
        {
            continue;
        }
        else
        {
            printf("VOTO INVALIDO\n");
        }
    }

    for(int j = 0; j < num_candidatos; j++)
    {
        printf("%s, %i\n", argv[j + 1], votos[j]);
    }
    vencedor (argc, argv, votos);




}

bool cont_votos (int argc ,string argv[], string voto, int votos[])
{
    for(int i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], voto) == 0)
        {

            votos[i - 1]++;
            return true;
        }
    }
    return false;
}

void vencedor (int argc, string argv[], int votos[])
{
    int cont_candidatos = argc - 1;
    int maior = votos[0];

    for(int i = 1; i < cont_candidatos; i++)
    {
        if(votos[i] > maior)
        {
            maior = votos[i];
        }
    }

    printf("vencendor(es): ");

    for(int i = 0; i < cont_candidatos; i++)
    {
        if(votos[i] == maior)
        {
            printf("%s, %i\n", argv[i + 1], maior);
        }
    }
}
