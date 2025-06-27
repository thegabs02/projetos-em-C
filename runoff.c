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

bool eh_candidato(string voto, estrutura candidato[], int num_candidatos);
void eleiçao(int num_candidatos, estrutura candidato[]);
int main (int argc, string argv[])
{
    if(argc < 3)
    {
        printf("coloque tres candidatos ou mais\n");
        return  1;
    }


    int num_candidatos = argc - 1;
    estrutura candidato[num_candidatos];

    for(int j = 0; j < num_candidatos; j++)
    {
        candidato[j].nome = argv[j + 1];
        candidato[j].votos = 0;
        candidato[j].eliminado = false;
    }
    eleiçao(num_candidatos, candidato);

    return 0;

}

void eleiçao(int num_candidatos, estrutura candidato[])
{

    int eleitores = get_int("qual é a quantidade de eleitores? ");

    for(int i = 0; i < eleitores; i++)
    {
        for(int o = 0; o < num_candidatos; o++)
        {
            string voto = get_string("Pra quem é o seu %iº voto? ", i + 1);
            if(eh_candidato(voto, candidato, num_candidatos))
            {
                continue;
            }
            else
            {
                printf("candidato invalido\n");
            }
        }
    }
     for(int k = 0; k < num_candidatos; k++)
     {
        //O proximo codigo começa daq, se lembra do if e do eliminar talvez dividir por dois ajude o vencedor precisa da maioria testes com 3eleitos
            printf("%s, %i\n", candidato[k].nome, candidato[k].votos);
     }

}
bool eh_candidato(string voto, estrutura candidato[], int num_candidatos)
{
    for(int i = 0; i < num_candidatos; i++)
    {
        if(strcmp(candidato[i].nome, voto) == 0)
        {
            candidato[i].votos++;
            return true;
        }
    }
    return false;
    return 0;
}
