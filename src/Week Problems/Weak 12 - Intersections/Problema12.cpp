#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> coords;
int n;

int intersectCubes(){
    int ix_min, iy_min, iz_min, ix_max, iy_max, iz_max;
    ix_min = iy_min = iz_min = -1000000;
    ix_max = iy_max = iz_max = 1000000;
    for(int i = 0; i < n; i++){
        ix_min = std::max(ix_min, coords[i][0]);
        iy_min = std::max(iy_min, coords[i][1]);
        iz_min = std::max(iz_min, coords[i][2]);
        ix_max = std::min(ix_max, coords[i][0] + coords[i][3]);
        iy_max = std::min(iy_max, coords[i][1] + coords[i][3]);
        iz_max = std::min(iz_max, coords[i][2] + coords[i][3]);
    }
    return std::max(0, ix_max - ix_min) * std::max(0, iy_max - iy_min) * std::max(0, iz_max - iz_min);
}

int main(){

    std::vector<int> aux;
    int auxV;

    std::cin >> n;

    for (int i = 0; i < n; i++){

        for(int j = 0; j < 4; j++){
            std::cin >> auxV;
            aux.push_back(auxV);
         }
        coords.push_back(aux);
        aux = {};
    }

    std::cout << intersectCubes() << "\n";

    /*»
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            std::cout << coords[i][j] << " ";
        }
        std::cout << "\n";
    }
    */



}