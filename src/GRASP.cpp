//
// Created by Puca Penna on 03/10/19.
//

#include <cmath>
#include <iostream>
#include <ctime>
#include "GRASP.h"
#include "Construcao.h"
#include "Util.h"
#include "Descida.h"
#include "Arquivos.h"

float GRASP(int n, std::vector<int> &s, float **d, float alpha, int GRASP_max /*, int tipo_construcao*/)
{
    vector<int> s_star;
    float fo_star = 100000; //infinito
    float fo;

    for (int i = 0; i < GRASP_max; ++i)
    {
        printf("\ni: %d\tfo: %.5lf", i, fo);
        //Construcao
        constroi_solucao_parcialmente_gulosa_vizinho_mais_proximo(n, s, d, alpha);

        //Busca Local
        fo = descida_best_improvement(n, s, d);

        if(fo < fo_star)
        {
            s_star = s;
            fo_star = fo;
        }
    }
    
    s = s_star;

    return fo_star;
}

