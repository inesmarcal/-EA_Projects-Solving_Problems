#include <iostream>
#include <array>
#include <vector>
#include <deque>

//número de nós; nó final
//Segue-se as linhas com o número de nós indicado acima
//id do nó(nó 1); custo de ligação para os restantes nós
//Não tem ligação direta o custo é -1


std::vector<std::vector<std::array<int, 2>>> destinos;
std::vector<int> distancias;
//número de arcos de cada nó
std::vector<int> arcos;
std::deque<int> q;
int infinito;
int num_nos;
int no_final;

int viagens(){
    int u = 0, v;
    int min  = infinito;

    //Colocar todos os nós com distância de infinito
    for(int i = 0; i < num_nos; i++){
        distancias[i] = infinito;
    }
    //Distancia do nó 1 ao nó inicial, como neste caso o nó um  é o inicial então a distância é 0.
    distancias[0] = 0;
    
    while( !q.empty()){

        for( int i = 0; i < num_nos; i++){

            //Tentar atualizar o minimo
            if(q[i] != -10){
                if(distancias[i] < min){
                    min = distancias[i];
                    //q[i] contém o nó com distância mais pequena até ao nó inicial
                   
                    //iterador
                     u = i;

                }
            }
        }

        q[u] = -10;

        //Se u for o nó final
        if(u == (no_final - 1)){
            break;
        }
        //nós ligados ao nó u
        for(int i = 0; i < arcos[u]; i++){
            //ir buscar ligações de destinos de u --> id
            v = destinos[u][i][0];
            //destinos[u][i][1] -> distância entre u e v
            if(distancias[v] > distancias[u] + destinos[u][i][1]){
                distancias[v] = distancias[u] + destinos[u][i][1];
            }
        }
        //Min volta a etr um valor grande
        min = infinito;
    }
    return distancias[no_final-1];

}

int main(){

    int id, aux;

    while(std::cin >> num_nos >> no_final){
        //Vai ter n vetores, um para cada nó e cada elemento do vetor lá dentro tem dois números(id do nó que a se liga, custo a ele)
        destinos = std::vector<std::vector<std::array<int,2>>> (num_nos,std::vector<std::array<int,2>>());
        distancias = std::vector<int> (num_nos);
        //número de setas a sair do nó
        arcos = std::vector<int> (num_nos);

        for(int i = 0; i < num_nos; i++){

            std::cin >> id;

            for(int j = 0; j < num_nos; j++){
                
                std::cin >> aux;
                if(aux > 0){
                    destinos[id-1].push_back({j, aux});
                    arcos[id-1]++;
                    //Incrementar o infinito com a distancia ao nó
                    infinito += aux;

                }

            }
            //q tem os ids dos nós
             q.push_back(i);

        }

        std::cout << viagens() << "\n";

        
    }

}