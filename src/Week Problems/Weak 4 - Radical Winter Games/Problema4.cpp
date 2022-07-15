#include <iostream>
#include <vector>
#include <algorithm>

int algorithm(std::vector<std::vector<int>> pontosObtidos, int size){
    int max = -1;
    //Caso base
    /*       7
          /     \
       10(7+3)  15(7+8) 
    */
    pontosObtidos[1][0] += pontosObtidos[0][0];
    pontosObtidos[1][1] += pontosObtidos[0][0];

    for(int i = 2; i < size; i++){

        for(int j = 0; j < i + 1; j++){

            if(j == 0){
                pontosObtidos[i][j] += pontosObtidos[i-1][j];

            }else if( j == i ){

                pontosObtidos[i][j] += pontosObtidos[i-1][j-1];

            }else{

                pontosObtidos[i][j] += std::max(pontosObtidos[i-1][j], pontosObtidos[i-1][j-1]);
            }
        }


    }

    for(int k = 0; k < size; k++){

        if( max < pontosObtidos[size-1][k]){

            max = pontosObtidos[size-1][k];
        }
    }

    return max;


}


int main(){

    int numInputs;
    int niveis;
    int auxNum;
    std::vector<std::vector<int>> pontuacao;
    std::vector<int> aux;

    std::cin >> numInputs;

    for(int i = 0; i < numInputs; i++){

        std::cin >> niveis;

        for(int j = 0; j < niveis; j++){

            for(int k = 0; k < j + 1; k++){

                std::cin >> auxNum;
                aux.push_back(auxNum);

            }
            pontuacao.push_back(aux);
            aux = {};

        }
        std::cout << algorithm(pontuacao, niveis) << "\n";
        pontuacao = {};
    }


    

    return 0;
}