#include <iostream>

//Quantos saltos os cavalos podem dar
//O número de células distintas que consoante os n cavalos colocados poderiam percorrer a seguir

//Coordenadas -200 a 200
int board[401][401];

int chess(int x, int y, int m){

    int v = 0;
    
    if (board[x + 200][y + 200] == 0){

        //Marco como visitado, se a célula não está visitada
        board[x + 200][y + 200] = 1;
        //Visitados
        //Como não estava visitado conta como um movimento
        v = 1;
    }

    if (m > 0){
        //Mudo a posição para casa chamada, 8 possíveis e decremento o número de jogadas agora disponíveis, m
        v += chess(x+1, y+2, m-1)
            + chess(x+1,y-2, m-1)
            + chess(x-1, y+2, m-1)
            + chess(x-1, y-2, m-1)
            + chess(x+2, y+1, m-1)
            + chess(x-2, y+1, m-1)
            + chess(x+2, y-1, m-1)
            + chess(x-2, y-1, m-1);
    }

    return v;
    
}


int main(){

    int num_cavalos;
    int posicaox, posicaoy;
    int moves;
    int moves_cavalos = 0;

    //Número de cavalos
    std::cin >> num_cavalos;

    //Posição x e y de cada cavalo e quantos movimentos esse cavalo pode fazer
    //Número de movimentos possíveis no jogo, sendo marcados os já visitados
    for(int i = 0; i < num_cavalos; i++){

        std::cin >> posicaox >> posicaoy >> moves;

        moves_cavalos += chess(posicaox, posicaoy, moves);
    }

    std::cout << moves_cavalos << "\n";

}