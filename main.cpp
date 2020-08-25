#include <iostream>
#include <fstream>
#include <vector>
#include "viagem.hpp"

using std::string;
using std::vector;


int main (int argc, char **argv){

    if(argc > 0){
        std::ifstream entrada;
        string nomeArquivo = argv[1];
        entrada.open(nomeArquivo);

        if (!entrada) {
            std::cout << "Falha para abrir o arquivo";
            return -1;
        }
        
        double custo, pontuacao;
        Viagem viagem;
        vector<Ilha> ilhas;
        Ilha ilha;

        entrada >> viagem.orcamento;
        entrada >> viagem.numeroIlhas;

        for (int i = 0; i < viagem.numeroIlhas; i++){
            entrada >> custo;
            entrada >> pontuacao;

            ilha.custo = custo;
            ilha.pontuacao = pontuacao;
            ilha.custoBeneficio = custo/pontuacao;

            ilhas.push_back(ilha);
        }

        viagem.solucaoGulosa(ilhas);
        std::cout << "\n";
        viagem.solucaoDinamica(ilhas);

        entrada.close();
    }       
    else{
        std::cout << "Por favor explicite como parâmetro um arquivo a ser lido";
    }
    
}