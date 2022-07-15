#include <iostream>
#include <array>
#include <vector>

int m;
int n;
int best = 0;
std::vector<std::vector<int>> connections;
std::vector <int> neighbor;

void inicialize(){
    for(int i = 0; i < n; i ++){
        neighbor.push_back(0);
    }
}

void function(int v, int size){
    if (size > best ){
        best = size;
    }
    int UB = 0;
    for(int i = v+1; i < n; i++){
        if(neighbor[i] == 0){
            UB = UB +1;
        }
    }
    if ((size + UB) <= best){
        return;
    }
    for(int i = v + 1; i < n; i++){
        if(connections[i][v] == 1){
            neighbor[i]++;
        }
    }
     for(int i = v + 1; i < n; i++){
        if(neighbor[i] == 0){
            function(i, size+1);
        }
    }
     for(int i = v + 1; i < n; i++){
        if(connections[i][v] == 1){
            neighbor[i]--;
        }
    }



}

int main(){

    int conect1;
    int conect2;
    std::vector<int> aux;

    std::cin >> n;
    std::cin >> m;

    connections = std::vector<std::vector<int>> (n, std::vector<int>(n, 0));
    inicialize();
    for(int i = 0; i < m; i++){
        aux = {};
        std::cin >> conect1;
        std::cin >> conect2;
        connections[conect1][conect2] = 1;
        connections[conect2][conect1] = 1;        
    }

    for(int i = 0; i< n; i++){
        function(i, 1);
    }

    std::cout << best << "\n";
    return 0;
}