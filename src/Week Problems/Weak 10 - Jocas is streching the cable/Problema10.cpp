#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<std::vector<int>> coordsComputadores;
//árvores
std::vector<int> set;
std::vector<int> ranks;
std::vector<std::vector<double>> arestas;

void link(int a, int b){
    if(ranks[a] > ranks[b]){
        set[b] = a;
    }else{
        //Árvores do mesmo tamanho e se o rank[a] < rank[b]
        set[a] = b;
    }
    if(ranks[a] == ranks[b]){
        ranks[b]++;
    }
}

int find(int a){
    if(set[a] != a){
        set[a] = find(set[a]);
    }
    return set[a];
}

double algorithm(){

        double dist = 0;

        //Ordem crescente
        sort(arestas.begin(), arestas.end(), [](std::vector<double> aresta1, std::vector<double> aresta2) {
            return aresta1[0] < aresta2[0];
        });
        for(int i = 0; i < (int)arestas.size(); i++){
            //Se tiverem raíz diferente
            if(find(arestas[i][1]) != find(arestas[i][2])){
                dist += arestas[i][0];
                link(find(arestas[i][1]), find(arestas[i][2]));
            
            }
        }
        return dist;
}


int main(){

    int nComputadores;
    int coord1;
    int coord2;
    int nlig;
    int a, b;
    double custo;


    while(std::cin >> nComputadores){

        arestas = {};
        coordsComputadores = {};
        set = {};
        ranks = {};

        for(int i = 0; i < nComputadores; i++){

            std::cin >> coord1;
            std::cin >> coord2;
            coordsComputadores.push_back({coord1, coord2});
            set.push_back(i);
            //altura da árvore igual a 0 inicialmente
            ranks.push_back(0);
        }

        std::cin >> nlig;
        //Colocar nós já ligados
        for(int i = 0 ; i < nlig; i++){
            std::cin >> a;
            std::cin >> b;
            //Temos de ligar as raízes da árvore de cada um dos nós
            link(find(a-1), find(b-1));
        }

        for(int i = 0; i < nComputadores; i++){
            for(int j = i + 1; j < nComputadores; j++){

                custo = (double) sqrt( fabs(coordsComputadores[i][0] - coordsComputadores[j][0]) * fabs(coordsComputadores[i][0] - coordsComputadores[j][0]) + fabs(coordsComputadores[i][1] - coordsComputadores[j][1]) * fabs(coordsComputadores[i][1] - coordsComputadores[j][1]));
                arestas.push_back({custo, (double)i, (double)j});
            }
        }

        printf("%.2lf\n",algorithm());
	

        /*
         for(int i = 0; i < (int)arestas.size(); i++){
            std::cout << arestas[i][0] << " " << arestas[i][1] << " " << arestas[i][2] << "\n";
        }
        std::cout<< "\n";
        */

    }
}