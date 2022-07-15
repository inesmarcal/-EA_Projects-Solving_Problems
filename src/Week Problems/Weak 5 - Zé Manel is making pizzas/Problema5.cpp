#include <iostream>
#include <vector>
#include <math.h>

int total_soma;

int pizza(int n, std::vector<int> pizzas){

    int metade_total = std::floor(total_soma/2);
    //n+1 linhas e cada linha vai ser o vetor bool e cada vetor bool tem metade_total+1 entradas
    std::vector<std::vector<bool>> DP(n+1, std::vector<bool>(metade_total + 1));

    //n+1 linhas
    for(int i = 0; i < n+1; i++){
        DP[i][0] = true;
    }

    //metade_total+1 colunas
    for(int j = 1; j < metade_total + 1; j++){
        DP[0][j] = false;
    }

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < metade_total + 1; j++){
            //O j percorre o tempo total de umas metades, se o tempo total dessa pizza for superior ao tempo das colunas para uma das metades
            //dá assign do valor anterior que provavelmente é zero
            //array de pizzas começar com indice a 0
            if (pizzas[i-1] > j){
                
                DP[i][j] = DP[i - 1][j];

            }else{

                DP[i][j] = DP[i-1][j] || DP[i-1][j-pizzas[i-1]];
            }
        }
    }

    //Começa na última linha do True
    for(int j = metade_total; j > -1; j-- ){

        if(DP[n][j] == true){
            //j=soma de uma das metades
            //total_soma - j = soma do total do outro conjunto de pizzas
            return std::abs(j - (total_soma - j));
        }
    }

    return 0;

}


int main(){

    int n, aux;
    std::vector<int> pizzas;

    while(std::cin >> n){

        pizzas= {};
        total_soma = 0;
        for(int i = 0; i < n; i++){

            std::cin >> aux;
            pizzas.push_back(aux);
            total_soma += aux;
        }

        std::cout << pizza(n, pizzas) << "\n";
    }  

}