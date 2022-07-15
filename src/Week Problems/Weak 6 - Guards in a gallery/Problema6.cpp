#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

int range;
int num_objetos;
std::vector<int> posicao_pecas;
std::vector<int> posicao_guardas;

int guardas()
{

    int i = 0;
    posicao_guardas.push_back(posicao_pecas[0] + range);
    for (int j = 1; j < num_objetos; j++)
    {
        if (posicao_pecas[j] > posicao_guardas[i] + range)
        {
            posicao_guardas[i + 1] = posicao_pecas[j] + range;
            i = i + 1;
        }
    }

    return i+1;
}

int main()
{

    int n;
    int objeto;
    int num_guardas;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        range = 0;
        num_objetos = 0;
        posicao_pecas = {};
        posicao_guardas = {};

        std::cin >> num_objetos >> range;

        for (int i = 0; i < num_objetos; i++)
        {

            std::cin >> objeto;
            posicao_pecas.push_back(objeto);
        }

        std::sort(posicao_pecas.begin(), posicao_pecas.end());
        num_guardas = guardas();
        std::cout << num_guardas << "\n";
    }
}