// Inês Martins Marçal 2019215917
// Noémia Quintano Mora Gonçalves 2019219433

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>


using namespace std;

struct node
{
    int indegree = -1;
    int time;
    int best = 0;
    vector<int> parents;
    vector<int> children;
};

vector<int> bottlenecks;
vector<int> topologicalOrder;
array<node, 1001> nodes;

bool isValid = true;
int sum = 0;
int endNode = -1;
int start = -1;
int nTasks;
int operation;
//Exemplo 1
//p = 3 e c = 4

/* 
            0
        /       \
       3         8
       \         /
         \      2
           \   /
            4
*/
void addParent(int p, int c)
{
    array<int, 1001> inVector = {};
    int child;

    for (int i = 0; i < int(nodes[c].parents.size()); i++)
    {
        //No caso de um nós ter dois pais só dele, ele primeiro vai buscar os pais do primeiro e depois do segundo.
        //No entanto para o segundo os pais repetidos já se encontram marcados para não se repetir novamente
        child = nodes[c].parents[i]; 
        inVector[child] = 1;
    }
    
    //Percorro os pais do 3
    for (int i = 0;  i < int(nodes[p].parents.size()); i++){
        //Ir buscar o pai do 3
        child = nodes[p].parents[i];
        //Se esse pai não tiver marcado
        if (inVector[child] == 0){
            //Adiciono esse pai como pai do 4
            nodes[c].parents.push_back(child);
        }
    }
    //Se o pai direto p ainda não estiver no array de parents deste nó c, é então adicionado ao array de parents
    //O 3 é colocado aqui, ou sej ao próprio pai
    if (inVector[p] == 0){
        nodes[c].parents.push_back(p);
    }
   
}

// p = 2 e c= 4
//Percorro os pais do 4 e marco-os --> {0,3}
//Percorro os pais do 2 e adiciono como pais do 4 apenas os que não tiverem marcados ou seja o 8
//

void BFS(int start)
{
    int child, t, counter;
    vector<int> q;

    //Colocar o nó inicial
    q.push_back(start);

    counter = 0;
    //Inicializar o melhor tempo ao valor do tempo do nó inicial
    //Operação 2
    nodes[start].best = nodes[start].time;

    //Enquanto houver nós no vetor
    while (!q.empty())
    {
        //Ir ao ultimo nó no vetor
        t = q.back();
        //Somar o custo --> operação 1
        sum += nodes[t].time;
        //Se o tamanho do q.size for um, pk assim não há paralelos e se
        //o tamanho do topologicOrder for igual ao tamanho dos pais do nó t é um bootleneck.
        if (int(q.size()) == 1 && int(topologicalOrder.size()) == int(nodes[t].parents.size()))
        {
            bottlenecks.push_back(t);
        }
        q.pop_back();
        //Se o nó não tiver filhos é o nó final
        if (int(nodes[t].children.size()) == 0)
        {
            //Caso já exista um nó final
            if (endNode != -1)
            {
                isValid = false;
                return;
            }
            else
            {
                endNode = t;
            }
        }
        //Exemplo 2
        //Percorrer os filhos do nó em causa
        for (int i = 0; i < int(nodes[t].children.size()); i++)
        {

            child = nodes[t].children[i];
             //Passa-se o nó e os respetivos filhos
            addParent(t, child);
            //Operação 2 --> infinitos processadores --> a maior parte das operações podem ocorrer ao mesmo tempo
            //No caso do 4 vai ver qual dos caminhos até ele é maior
            if (nodes[t].best + nodes[child].time > nodes[child].best)
            {
                nodes[child].best = nodes[t].best + nodes[child].time;
            }
            //decrementar as dependências do filho
            nodes[child].indegree--;
            //Se o número de dependências do filho passar a 0 pode-se pô-lo na fila
            if (nodes[child].indegree == 0)
            {
                q.push_back(child);
            }
            //Percorre-se os filhos do 1, que são o 2 e 3. O primeiro child é o 2 faz as operações do addParent para este nó, faz-se a soma do maior caminho
            //e depois decrementa-se as ligações, ficando a 0 e coloca na queue e depois faz o mesmo para o 3 
        }
        //Colocar o 1, ao já ter sido percorrido, na ordem topológica
        //Conforme vamos retirando
        topologicalOrder.push_back(t);
        //Ordenar a fila das próximas a tarefas a ser executas
        if (!q.empty())
        {
            sort(q.begin(), q.end(), greater<int>());
        }
        //Incremento o número de tasks executadas
        counter++;
    }
    //Se o counter não tiver sido igual ao número de tasks, é porque ou não se percorreu todas(grafos desconexos) ou se percorreu demais(ciclos)
    if (counter != nTasks)
    {
        isValid = false;
    }
}

int main()
{

    int time;
    int ndependencies;
    int dependency;

    //Ver o número de tasks que vou ler
    cin >> nTasks;
    for (int i = 1; i < nTasks + 1; i++)
    {
        //tempo da task
        cin >> time;
        //Adiciona o tempo ao respetivo nó representado pelo índice
        nodes[i].time = time;
        //Lê o número de dependências do nó
        cin >> ndependencies;
        //Adiciona o número de dependências ao respetivo nó
        nodes[i].indegree = ndependencies;
        //Se tiver zero dependências é o nó inicial
        if (ndependencies == 0)
        {
            //Se o start não tiver a menos, já existe um inicio
            if (start != -1)
            {
                cout << "INVALID\n";
                return 0;
            }
            //Se não se encontra a -1 é considerado o inicial
            else
            {
                start = i;
            }
        }
        //Ler as dependências do nó e adiciona-lo ao array de filhos de cada uma das dependências
        for (int j = 0; j < ndependencies; j++)
        {
            cin >> dependency;
            nodes[dependency].children.push_back(i);
        }
    }
    cin >> operation;

    BFS(start);

    if (!isValid)
    {
        cout << "INVALID\n";
        return 0;
    }
    //Ciclos, desconexos e nó final a mais
    if (operation == 0)
    {
        if (isValid)
        {
            cout << "VALID\n";
        }
        else
        {
            cout << "INVALID\n";
        }
        return 0;
    }

    if (operation == 1)
    {
        cout << sum << "\n";
        for (int i = 0; i < int(topologicalOrder.size()); i++)
        {
            cout << topologicalOrder[i] << "\n";
        }

        return 0;
    }

    if (operation == 2)
    {

        cout << nodes[endNode].best << "\n";
        return 0;
    }

    if (operation == 3)
    {
        for (int i = 0; i < int(bottlenecks.size()); i++)
        {
            cout << bottlenecks[i] << "\n";
        }
        return 0;
    }

    return 0;
}
