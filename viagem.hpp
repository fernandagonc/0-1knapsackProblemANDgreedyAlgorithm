#ifndef VIAGEM
#define VIAGEM

#include <iostream>
#include <vector>

using::std::vector;


struct Ilha{
    int custo;
    int pontuacao;
    double custoBeneficio;
};

class Viagem{
    
    public:    
        int numeroIlhas;
        static int orcamento;
        
        static bool comparacao(Ilha &a, Ilha &b);
        void solucaoGulosa(vector<Ilha> ilhas);
        int max(int numero1, int numero2);
        void solucaoDinamica(vector<Ilha> ilhas);

};






#endif