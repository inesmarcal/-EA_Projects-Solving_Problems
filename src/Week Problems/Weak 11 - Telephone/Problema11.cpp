#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

/*  Cada uma das próximas no máximo N linhas contém o número de um lugar seguido pelos números de alguns 
lugares para os quais há uma linha direta deste lugar.  */


std::vector<std::vector<int>> lig;
std::vector<int> parent;
std::vector<int> dfs;
std::vector<int> low;
//Vetor para guardar o numero de filhos(ligações) de cada nó
std::vector<int> size;
/* 
O 5 seria contabilizado como ponto de articulação pelo 3 e 2 e ficaria repetido logo marca-se os pontos já contabilizados como pontos de articulação.
     8
     |
     5
   /   \
   3   2
*/
std::vector<int> pontos_marcados;
int t;
int pontos_articulacao;

void algorithm(int v){
    int w;
    low[v] = dfs[v] = t;
    t++;
    //Para cada aresta em que o v esteja envolvido
    for(int i = 0; i < size[v]; i++){
        w = lig[v][i];
        if(dfs[w] == 0){
            parent[w] = v;
            algorithm(w);
            low[v] = std::min(low[v], low[w]);
            if ( pontos_marcados[v] != 1){
                if(dfs[v] == 1 && dfs[w] != 2){
                    pontos_articulacao++;
                    pontos_marcados[v] = 1;
                }
                if(dfs[v] != 1 && low[w] >= dfs[v]){
                    pontos_articulacao++;
                    pontos_marcados[v] = 1;
                }
            }
            
        }else if( parent[v] != w){
            low[v] = std::min(low[v], dfs[w]);
        }
    }
}


int main(){

    int n;
    std::string s;
    int aux;
    int place;

    while(std::cin >> n){

        if(n == 0){
            return 0;
        }

        //Do número de nós para as linhas seguintes há um \n e tem de ser retirado
        getline(std::cin, s);

        //n vetores de filhos na matriz
        //Em cada caso novo reescreve-se o ligs
        lig = std::vector<std::vector<int>> (n);
        t = 1;
        pontos_articulacao = 0;

        for(int i = 0; i < n; i++){
            dfs.emplace_back(0);
            parent.emplace_back(0);
            low.emplace_back(0);
            size.emplace_back(0);
            pontos_marcados.emplace_back(0);
            
        }

        //Ler as ligações como strings pk não se saber a quantos o nó esta ligado
        while (getline(std::cin, s))
        { 

            //Acabou o caso teste pode-se chamar a função do algoritmo
            if( s == "0"){
                algorithm(0);
                std::cout << pontos_articulacao << "\n";
                break;
            }
            std::stringstream linha(s);
            //marcar o parent(primeiro numero da linha)
            place = -1;

            //Ler cada elemento da linha
            //Para cada elemento da linha, ou seja, o lig[5] = 4, o lig[4] = 5
            while(linha >> aux){
                
                if(place == -1){
                //tem de ser o indice do nó
                    place = aux - 1;
                //Nó com ligação place
                }else{
                    //Colocar esse nó no array dos filhos do place
                    lig[place].emplace_back(aux - 1);
                    size[place]++;
                    //O grafo é bidirecional logo tem de se considerar nos dois sentidos
                    lig[aux - 1].emplace_back(place);
                    size[aux - 1]++;

                }

            }
        }
        /*
        for(int i = 0; i < n; i++){
            for(int j = 0; j < size[i]; j++){
                std::cout << lig[i][j] << " ";
            }
            std::cout << "\n";
        }
        */
        dfs = {};
        parent = {};
        low = {};
        size = {};
        pontos_marcados = {};                                                                                                                                                                    
    }
    
}
