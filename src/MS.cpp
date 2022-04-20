//
// Created by Puca Penna on 13/09/19.
//

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "Descida.h"
#include "Util.h"
#include "Construcao.h"
#include "Arquivos.h"
#include "MS.h"

#ifndef CLK_TCK
#define  CLK_TCK 1000000
#endif

float MS(int n, std::vector<int> &s, float **d, int iter_max)
{
    float fo_star, fo;
    clock_t inicio_CPU, fim_CPU;
    vector<int> s_star;

    //atualiza s_star
    s_star = s;

    fo = fo_star = 99999;//calcula_fo(n, s, d);
    limpa_arquivo((char*)"MS.txt");
    inicio_CPU = fim_CPU = clock();
    imprime_fo((char*)"MS.txt", (fim_CPU - inicio_CPU)/CLK_TCK,fo_star,0);

    int iter = 0;
    while (iter < iter_max)
    {
        iter++;
        constroi_solucao_aleatoria(n, s, d);
        descida_best_improvement(n, s, d);

        fo = calcula_fo(n, s, d);
        
        if(fo < fo_star){
            fo_star = fo;
            s_star = s;
        }
    }

    fim_CPU = clock();
    imprime_fo((char*)"MS.txt", (fim_CPU - inicio_CPU)/CLK_TCK,fo_star,0);

    // atualiza s
    s = s_star;
    return fo_star;
}








