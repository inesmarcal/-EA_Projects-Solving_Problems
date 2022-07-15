#include <iostream>
#include <vector>

int nodes, links, max_links_node;
std::vector<int> visited;
std::vector<int> nligs;
std::vector<std::vector<int>> costs;
int best;

std::vector<std::vector<int>> costs_matrix(){

    //matrix nodes por nodes --> para construir as combinações
    //tenho n linhas que são os nodes e cada linha/nodes tem um vetor tamanho nodes

    //Tenho uma matriz n por n, armazeno os custos de cada ligação entre dois nós
    std::vector<std::vector<int>> aux(nodes, std::vector<int>(nodes, 0));
    return aux;

}

//O vetor vai ter 0 ou 1, se for 0 não foi visitado
std::vector<int> visited_matrix(){

    std::vector<int> aux(nodes);
    return aux;

}


std::vector<int> links_matrix(){

    //Cada elemento do vetor, que corresponde a um nó, vai ter o número de ligações que cada nó tem --> 4 nós 0 0 0 0
    std::vector<int> aux(nodes);
    return aux;

}

void net(int total_visit, int cost){

    //Custo da rede a construir passar o best podemos parar, pk já é um pior caso
    if (cost >= best){
        return;
    }

    //Já visitei os nós todos, o best vai ser assim atualizado
    if( total_visit == nodes){
        best = cost;
        return;
    }

    //Visitar os nós
    //Percorro os nós a partir do qual quero começar uma ligação
    for(int i = 0; i < nodes; i++){
        //Nó em causa não está visitado
        if(visited[i] == 0){
            //Percorre os nós ao qual está a fazer ligação
            for(int j = 0; j < nodes; j++){
                //Se esse nó já está visitado e se existe ligação entre o o i e j (0 não existe ligação)
                //e se o nó j ainda não atingiu o limite de ligações, sendo o nó j o nó ao qual quero me ligar
                if(visited[j] == 1 && costs[i][j] > 0 && nligs[j] < max_links_node){
                    //Incremento o número de ligações para cada nó
                    nligs[i] = nligs[i] + 1;
                    nligs[j] = nligs[j] + 1;
                    //Marco o nó como visitado
                    visited[i] = 1;
                    //Chama-se a função recursivamente
                    net(total_visit + 1 , cost + costs[i][j]);
                    //Para uma nova combinação desmarca o nó que marcamos
                    visited[i] = 0;
                    //Decremento o número de ligações de cada nó 
                    nligs[j] = nligs[j] - 1;
                    nligs[i] = nligs[i] - 1;

                }
            }
        }
    }

}


int main(){

    int num1, num2, cost;
    int worst = 0;

    //Ler o número de nós disponíveis, número de ligações possíveis no grafo, número de ligações de cada nó
    while(std::cin >> nodes >> links >> max_links_node){

        //Inicializar matriz
        costs = costs_matrix();
        //Ler as ligações disponíveis
        for(int i = 0; i < links; i++){

            //Cada ligação tem os nós que fazem ligação, e o custo dela
            std::cin >> num1 >> num2 >> cost;
            //Coloco na linha num1-1 e coluna num2-1 e o contrario
            //Marcar custo da ligação, tanto de um lado para outro
            costs[num1-1][num2-1] = cost;
            costs[num2-1][num1-1] = cost;
            //Inicializar no pior caso para depois encontrar o de menor
            worst += cost;
        }
        //Criar a matriz de nós visitados
        visited = visited_matrix();
        //Nó 0 como visitado pk vou partir daqui
        visited[0] = 1;
        //Matriz n links, cada nó só pode ter no máximo max_links_nodes
        nligs = links_matrix();
        //O meu best é igual ao pior caso, inicializar o best
        best = worst;


        //O 1 já foi marcado como visitado
        net(1, 0);

        if (best == worst){

            std::cout << "NO WAY!\n";

        }else{

            std::cout << best << "\n";
        }

    }


}