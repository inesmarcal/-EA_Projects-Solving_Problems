#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <unordered_map>

std::vector<std::vector<int>> connections;
std::vector<int> colors;
std::vector<std::vector<int>> trains_stations;

bool algorithm(int v)
{

    int t, u;
    std::queue<int> Q;
    colors[v - 1] = 1;
    Q.push(v);

    while (!Q.empty())
    {
        //retiro da fila
        t = Q.front();
        Q.pop();

        //Percorrer os elementos que estão ligados ao que retirei
        //Primeiro elemento já é a contagem
        for (int i = 0; i < trains_stations[t-1][0]; i++)
        {
                //Os que estão ligados ao t
                //3, 2, 3, 4 pk o primeiro elemento é o count e o for só vai até ao número de estações e é preciso mais um para o count
                u = trains_stations[t-1][i+1];
                if (colors[u - 1] == 0)
                {
                    colors[u - 1] = 1 - colors[t - 1];
                    Q.push(u);
        
                }
                else if (colors[u - 1] == colors[t - 1])
                {
                    return false;
                }
        
        }
    }

    return true;
}

int main()
{

    int total_trains;
    int total_stations;
    int s_t1;
    int s_t2;

    while (std::cin >> total_trains >> total_stations)
    {

        colors = std::vector<int>(total_trains, 0);
        trains_stations = std::vector<std::vector<int>>(total_trains);

        for(int i = 0; i < total_trains; i++){
            //indices de comboios de 1 acima e não zero
            trains_stations[i].push_back(0);
        }

        for (int i = 0; i < total_stations; i++)
        {
            //lista de adjacência
            std::cin >> s_t1 >> s_t2;
            //Fazemos menos um por causa dos números começarem em 1 e não em zero
            trains_stations[s_t1-1].push_back(s_t2);
            trains_stations[s_t2-1].push_back(s_t1);

            trains_stations[s_t1-1][0]++;
            trains_stations[s_t2-1][0]++;
        }

        if (algorithm(1))
        {
            std::cout << "NOT SURE\n";
        }
        else
        {
            std::cout << "NO\n";
        }

        trains_stations = {};
    }
}