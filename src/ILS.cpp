#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <utility> //funcao swap (para versao anterior a C11 usar <algorithm>)
#include "Arquivos.h"
#include "Construcao.h"
#include "Descida.h"
#include "Util.h"

using namespace std;


float perturbacao(int n, vector<int> &s, float **d, float fo, int nivel)
{
    int ntrocasMax = nivel + 1;
    int ntrocas = 0, i, j;

    while (ntrocas < ntrocasMax)
    {
        ntrocas++;
        // seleciona as posicoes das cidades para trocar
        i = rand() % n;
        do {
            j = rand() % n;
        } while (i == j);
        
        float delta1 = calcula_delta(n,s,d,i,j);
        
        // Faz o movimento
        swap(s[i], s[j]);
        float delta2 = calcula_delta(n,s,d,i,j);
        
        // Calcular a nova distancia
          fo = fo - delta1 + delta2;
    } 
    return fo;
}

float ILS(int n, vector<int> &s, float **d, int ILSmax) 
{
    int i, j, iter, MelhorIter;
    float fo, fo_2l;

    //Solucao Inicial
    constroi_solucao_gulosa_vizinho_mais_proximo(n, s, d);
    vector<int> s_star = s;

    //Busca Local
    fo = descida_best_improvement(n, s, d);

    MelhorIter = iter = 0;
    int nivel = 1;

    while(iter - MelhorIter < ILSmax)
    {
        printf("\niter %d: fo %.5f", iter, fo);
        iter++;

        perturbacao(n, s, d, fo, nivel);
        fo_2l = descida_best_improvement(n, s, d);

        if(fo_2l < fo)
        {
            s_star = s;
            MelhorIter = iter;
            nivel = 1;
            fo = fo_2l;
        }
        
        else 
        {
            nivel++;
        }
    }
    

    return fo;
}

float SmartILS(int n, vector<int> &s, float **d, int nivel, int nVezesNivel, int ILSMax)
{
    int i, j, iter, MelhorIter;
    float fo, fo_2l;

  

    return fo;
}

