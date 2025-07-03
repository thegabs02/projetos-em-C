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

void ganhador(estrutura candidato[], int num_candidatos, int total);
void votos_cant(int eleitores, int num_candidatos, estrutura candidato[], string pref[][num_candidatos], int total);
void eliminado(estrutura candidato[], int num_candidatos, int total);
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
    
    string voto;
    int total = 0;
    int eleitores = get_int("qual é a quantidade de eleitores? ");
    string pref[eleitores][num_candidatos];


    for(int i = 0; i < eleitores; i++)
    {
        for(int o = 0; o < num_candidatos; o++)
        {
            voto = get_string("Pra quem é o seu %iº voto? ", o + 1);
            
            if(eh_candidato(voto, candidato, num_candidatos))
            {
                total++;
                pref[i][o] = voto;
                continue;
            }
        }
    }
    
    votos_cant(eleitores, num_candidatos, candidato, pref, total);

}
bool eh_candidato(string voto, estrutura candidato[], int num_candidatos)
{
    for(int i = 0; i < num_candidatos; i++)
    {
        if(strcmp(candidato[i].nome, voto) == 0)
        {
            return true;
        }
    }
    return false;
    return 0;
}
void votos_cant(int eleitores, int num_candidatos, estrutura candidato[], string pref[][num_candidatos], int total)
{
    int cont = 0;
    for(int j = 0; j < eleitores; j++)
    {
        for(int k = 0; k < num_candidatos; k++)
        {
            if(strcmp(pref[j][cont], candidato[k].nome) == 0)
            {
                candidato[k].votos++;
            }
        }
    }
    cont++;
    eliminado(candidato, num_candidatos, total);
}
void eliminado(estrutura candidato[], int num_candidatos, int total)
{
    int menor = candidato[0].votos;
    for(int k = 0; k < num_candidatos; k++)
    {
        if(menor > candidato[k].votos)
        {
          menor = candidato[k].votos;
        }       
        
    }
    for(int h= 0; h < num_candidatos; h++)
    {
        if(menor == candidato[h].votos)
        {
            candidato[h].eliminado = true;
            printf("%s foi eliminado[a]\n", candidato[h].nome);
        }
    
    }
    ganhador(candidato, num_candidatos, total);
}
void ganhador(estrutura candidato[], int num_candidatos, int total)
{
    int media = total / 2;
    
    for(int i = 0; i < num_candidatos; i++)
    {
        if(candidato[i].votos >= media)
        {
            printf("candidato %s ganhou", candidato[i].nome);
        }
    }
    //repetir eleiçao
}