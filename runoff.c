#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct
{
    string nome;
    int votos1;
    int votos2;
    bool eliminado;
}estrutura;

int versos(int num_candidatos, int  eleitores, estrutura candidato[]);
int ganhador(estrutura candidato[], int num_candidatos, int total, int eleitores, string pref[][num_candidatos]);
void votos_cant(int eleitores, int num_candidatos, estrutura candidato[], string pref[][num_candidatos], int total);
void eliminado(estrutura candidato[], int num_candidatos, int total, int eleitores, string pref[][num_candidatos]);
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
        candidato[j].votos1
         = 0;
        candidato[j].eliminado = false;
    }

    eleiçao(num_candidatos, candidato);
    return 0;

}

void eleiçao(int num_candidatos, estrutura candidato[])
{

    string voto;
    int total = 0;
    int eleitores = get_int("qual é a quantidade de eleitores?\n ");
    string pref[eleitores][num_candidatos];


    for(int i = 0; i < eleitores; i++)
    {
        for(int o = 0; o < num_candidatos; o++)
        {
            bool valido = false;
            do
            {
                voto = get_string("Pra quem é o seu %iº voto?\n", o + 1);
                for(int j = 0; j < num_candidatos; j++)
                {
                    if(strcmp(candidato[j].nome, voto) == 0)
                    {
                        valido = true;
                        candidato[j].votos2++;
                        pref[i][o] = voto;
                    }
                    if(valido)
                    {
                        total++;
                    }
                }
                if(!valido)
                {
                printf("%s é inválido, repita seu voto\n", voto);
                break;
                }
                
            }
            while(!valido);
        }
    }

    votos_cant(eleitores, num_candidatos, candidato, pref, total);

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
                candidato[k].votos1
                ++;
            }
        }
    }
    cont++;
    eliminado(candidato, num_candidatos, total, eleitores, pref);
}
void eliminado(estrutura candidato[], int num_candidatos, int total, int eleitores, string pref[][num_candidatos])
{
    int menor = candidato[0].votos1;
    for(int k = 0; k < num_candidatos; k++)
    {
        if(menor > candidato[k].votos1
        )
        {
          menor = candidato[k].votos1
          ;
        }

    }
    for(int h= 0; h < num_candidatos; h++)
    {
        if(menor == candidato[h].votos1
        )
        {
            candidato[h].eliminado = true;
        }

    }
    ganhador(candidato, num_candidatos, total, eleitores, pref);
}
int ganhador(estrutura candidato[], int num_candidatos, int total, int eleitores, string pref[][num_candidatos])
{
    int media = total / 2;
 
    for(int i = 0; i < num_candidatos; i++)
    {
        if(candidato[i].votos1>= media)
        {
            printf("ganhador por preferencia %s\n", candidato[i].nome);
            versos(num_candidatos, eleitores, candidato);
            return 0;
        }
    }
    votos_cant(eleitores, num_candidatos, candidato, pref, total);
}
int versos(int num_candidatos, int  eleitores, estrutura candidato[])
{
    string ganhador = candidato[0].nome;
    int maior = candidato[0].votos2;
    for(int i = 1; i < num_candidatos; i++)
    {
        if(candidato[i].votos2 > maior)
        {
            ganhador = candidato[i].nome;
            maior = candidato[i].votos2;
        }
    }
    printf("ganhador por maioria de votos %s\n", ganhador);
    return 0;
}