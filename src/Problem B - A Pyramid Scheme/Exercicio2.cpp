// Inês Martins Marçal 2019215917
// Noémia Gonçalves 2019219433

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <sstream>
#include <unordered_map>

//Percorrer a árvore no menor número de nós e maior custo
using namespace std;
struct node
{
    //custo
    int value;
    //Dois arrays um de usar e outro não usar
    //Cada um com dois elementos
    array<array<int,2>,2> achievedValues;
    vector<int> children;
};

unordered_map<int, node> nodes;
unordered_map<int, vector<int>> treedepth;
int maxdepth;


//Recebe um id do nó e a profundidade a que ele vai estar
void depth(int nodeId, int d)
{
    //Se a profundidade desse nó for maior que o maxdepth, o maxdepth passa a ser esse valor
    if (d > maxdepth)
    {
        maxdepth = d;
    }
    //Buscar o nó
    node n = nodes[nodeId];
    int child;
    //Percorrer os filhos do nó
    for (int i = 0; i < int(n.children.size()); i++)
    {
        //Buscar o id do filho
        child = n.children[i];
        //Chamo a função para o filho com a profundidade incrementada a 1
        depth(child, d + 1);
    }
    //Depois de ir percorrer os filhos todos
    //Ver em que nível insiro este nó
    //Se não existe ainda um vetor para este nível
    if (treedepth.find(d) == treedepth.end())
    {
        //Cria-se
        treedepth.insert({d, vector<int>()});
        //Insiro o nó nesse vetor
        treedepth[d].push_back(nodeId);
    }
    else
    {
        //Apenas insiro o nó
        treedepth[d].push_back(nodeId);
    }
    //Ao terminar os filhos de um nó como acabou tudo na função recua para o pai destes último(no for)
    //Só coloca o nó pai no respetivo vetor de profundidade sempre que percorre os filhos
}

array<int, 2> getBest(int nodeId)
{
    //Ir buscar o array de usar o nó
    array<int, 2> use = nodes[nodeId].achievedValues[1];
    //Ir buscar o array de não usar o nó
    array<int, 2> dontUse = nodes[nodeId].achievedValues[0];
    //Se o número de nós do use for maior do que o número de nós do não usar
    //Escolhemos o de menor número --> dontUse
    if (use[0] > dontUse[0])
    {
        return dontUse;
    }
    //Se o número de nós do use for menor do que o número de nós do não usar
    //Escolhemos o de menor número --> Use
    if (use[0] < dontUse[0])
    {
        return use;
    }
    //Para desempatar se o número de nós for igual, verificamos qual tem maior custo
    if (use[0] == dontUse[0])
    {
        //Fica o use se este tiver maior custo
        if (use[1] > dontUse[1])
        {
            return use;
        }
        //Fica o dontUse se este tiver maior custo
        if (use[1] < dontUse[1])
        {
            return dontUse;
        }
    }
    return use;
}
void pyramidscheme()
{
    node n;
    array<int, 2> doesntUse, use, best;

    //Percorrer os níveis da árvore
    //Do maior para menor, ou seja de baixo para cima
    for (int i = maxdepth; i > -1; i--)
    {
        //Percorrer os ids dos nós nesse nível
        for (int j = 0; j < int(treedepth[i].size()); j++)
        {
            //Buscar o nó que corresponde ao id em causa do for
            n = nodes[treedepth[i][j]];
            //Se o número de filhos for zero
            if (int(n.children.size()) == 0)
            {   
                //Não usar é {0,0}
                doesntUse = {0,0};
                //Usar é ele próprio
                //Adiciona-se o usar e não usar ao array de arrays achievedValues
                nodes[treedepth[i][j]].achievedValues = {doesntUse,{1, n.value}};
            }
            //Se tiver filhos
            else
            {
                //Inicializar
                doesntUse = {0, 0};
                use = {0, 0};

                //Percorrer os filhos desse nó
                for (int k = 0; k < int(n.children.size()); k++)
                {
                        //Ao não usar incrementa as soluções que vêm dos filhos
                        //Soma de usar os filhos
                        doesntUse[0] += nodes[n.children[k]].achievedValues[1][0];
                        doesntUse[1] += nodes[n.children[k]].achievedValues[1][1];
                        
                        //Manda o id do nó filho
                        //Melhor resultado do filho, usar ou não usar esse nó
                        best = getBest(n.children[k]);
                        //Soma-o ao use o melhor valor que vem desse filho
                        use[0] += best[0];
                        use[1] += best[1];
                }
                //Adiciona-se o próprio nó ao use
                use[0] += 1;
                use[1] += n.value;
                //Adiciona-se o usar e não usar ao array de arrays achievedValues
                nodes[treedepth[i][j]].achievedValues = {doesntUse,use};
            }
        }
        //Não usar --> usar o debaixo, ir buscar o use
        //Usar--> Ir buscar o melhor dos filhos entre o usar e não usar e depois somar o próprio nó
    }
    //Vei biscar o melhor do nó 0, menor numero de nós e maior custo
    array<int, 2> result = getBest(0);
    cout << result[0] << " " << result[1] << "\n";
}

int main()
{
    string line;
    int parent = -1;
    int child;

    nodes.clear();
    //Enquanto tive nós para ler
    //Lendo já o parent (número inicial de cada linha --> nó)
    while (cin >> parent)
    {
        //resto da linha desse nó
        getline(cin, line);
        //Converte em string, para depois se poder iterar sobre a linha
        stringstream ss(line);
        //Se acabou o caso teste
        if (parent == -1)
        {
            //Colocar os nós nas respetivas profundidades no vetor
            depth(0, 0);
            //Chama a função
            pyramidscheme();
            //Clear de tudo para o próximo caso teste
            maxdepth = 0;
            treedepth.clear();
            nodes.clear();
            //Próximo caso teste
            continue;
        }
        //Se não entrei no if de acabou o caso teste
        //Crio uma entrada no dicionário com o id do nó(número inicial de cada linha), atribuindo a ela uma estrutura de nó vazio
        nodes.insert({parent, node()});

        //Ler os números restantes dessa linha, ou seja ligações desse nó
        while (ss >> child)
        {
            //Coloca-los como value desse nó no dicionário
            //Colocar os ids dos filhos no array de filhos(ligações) desse nó
            nodes[parent].children.push_back(child);
        }
        //No final o valor desse nó é o valor/custo do nó
        nodes[parent].value = nodes[parent].children.back();
        //E retiro-o pk depois já não o usamos
        nodes[parent].children.pop_back(); 

    }

    return 0;
}
