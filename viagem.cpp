#include "viagem.hpp"
#include <vector>
#include <algorithm> 

int Viagem::orcamento;
bool Viagem::comparacao(Ilha &a, Ilha &b){ //organiza as ilhas em ordem decrescente de valor de custo beneficio
    
    if(a.custoBeneficio == b.custoBeneficio){ 
        int restoA = orcamento % a.custo;
        int restoB = orcamento % b.custo;
        return restoA > restoB;

    }
    return a.custoBeneficio > b.custoBeneficio;
}

void Viagem::solucaoGulosa(vector<Ilha> ilhas){

    int opcaoIlhas = numeroIlhas - 1;//comeca a analise pela ilha com melhor custo beneficio, ou seja
                                    //a que o resultado da divisao (custo/pontuacao) foi o menor
    int dias = 0;
    int custoAtual = 0;
    int pontuacao = 0;
    int recursoRestante = orcamento - custoAtual;
    int nroIlha;
    std::sort(ilhas.begin(), ilhas.end(), comparacao); 


    while(opcaoIlhas >= 0){ //considerando indices de 0 a (numeroIlhas - 1)
        recursoRestante = orcamento - custoAtual;
        nroIlha = recursoRestante/ilhas[opcaoIlhas].custo;

        if(custoAtual + ilhas[opcaoIlhas].custo <= orcamento){//adicionamos a ilha na solução caso o custo não ultrapasse o orçamento
            dias += nroIlha;
            custoAtual = custoAtual + nroIlha * ilhas[opcaoIlhas].custo;
            pontuacao = pontuacao + nroIlha * ilhas[opcaoIlhas].pontuacao;
            opcaoIlhas--;
        }
        else if(custoAtual + ilhas[opcaoIlhas].custo > orcamento){
            opcaoIlhas--;
        }

    }

    std::cout << pontuacao << " " << dias;
}

int Viagem::max(int numero1, int numero2){
    if(numero1 > numero2) return numero1;
    else return numero2;    
}

void Viagem::solucaoDinamica(vector<Ilha> ilhas){
 
    int i, orcamentoAtual; 
    int matriz[numeroIlhas+1][orcamento+1]; 
    int dias = 0;
    int custo = orcamento;

   for (i = 0; i <= numeroIlhas; i++) { 
       for (orcamentoAtual = 0; orcamentoAtual <= orcamento; orcamentoAtual++){ 
           if (i == 0 || orcamentoAtual == 0) //caso base, em que não há ilhas ou não há orçamento
               matriz[i][orcamentoAtual] = 0; 

           else if (ilhas[i-1].custo <= orcamentoAtual) {//caso em que é possível incluir a ilha na solução
                matriz[i][orcamentoAtual] = max(ilhas[i-1].pontuacao + matriz[i-1][orcamentoAtual - ilhas[i-1].custo],  matriz[i-1][orcamentoAtual]); 
           }
           else//caso em que não é possível incluir a ilha na solução (custo da ilha > orçamento)
                matriz[i][orcamentoAtual] = matriz[i-1][orcamentoAtual]; 
       } 
   } 
  
    //recuperando quantas ilhas foram escolhidas na solução
    for (i = numeroIlhas; i > 0; i--) {      
        if (matriz[i][custo] > matriz[i-1][custo]){
            dias++;         
            custo = custo - ilhas[i-1].custo;
        }
    } 

   std::cout << matriz[numeroIlhas][orcamento] << " " << dias;


}
