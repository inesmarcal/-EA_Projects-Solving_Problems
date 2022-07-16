// Inês Martins Marçal 2019215917
// Noémia Quintano Mora Gonçalves 2019219433

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <queue>

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
        child = nodes[c].parents[i]; 
        inVector[child] = 1;
    }
    
    for (int i = 0;  i < int(nodes[p].parents.size()); i++){
        
        child = nodes[p].parents[i];
      
        if (inVector[child] == 0){
            //Adiciono esse pai como pai do 4
            nodes[c].parents.push_back(child);
        }
    }
 
    if (inVector[p] == 0){
        nodes[c].parents.push_back(p);
    }
   
}



void BFS(int start)
{
    int child, t, counter;
    priority_queue <int, vector<int>, greater<int>> q;

   
    q.push(start);

    counter = 0;

    nodes[start].best = nodes[start].time;

 
    while (!q.empty())
    {
        
        t = q.top();
       
        sum += nodes[t].time;

       
        if (int(q.size()) == 1 && int(topologicalOrder.size()) == int(nodes[t].parents.size()))
        {
            bottlenecks.push_back(t);
        }
        q.pop();
        
        if (int(nodes[t].children.size()) == 0)
        {
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
      
        for (int i = 0; i < int(nodes[t].children.size()); i++)
        {

            child = nodes[t].children[i];
            
            addParent(t, child);
            
        
            if (nodes[t].best + nodes[child].time > nodes[child].best)
            {
                nodes[child].best = nodes[t].best + nodes[child].time;
            }
            
            nodes[child].indegree--;
            
            if (nodes[child].indegree == 0)
            {
                q.push(child);
            }
           
        }
      
        topologicalOrder.push_back(t);
        counter++;
    }
    
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

    
    cin >> nTasks;
    for (int i = 1; i < nTasks + 1; i++)
    {
        
        cin >> time;
        nodes[i].time = time;
        cin >> ndependencies;
        nodes[i].indegree = ndependencies;
        
        if (ndependencies == 0)
        {
            
            if (start != -1)
            {
                cout << "INVALID\n";
                return 0;
            }
            
            start = i;
        
        }
        
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
      
    }

    if (operation == 1)
    {
        cout << sum << "\n";
        for (int i = 0; i < int(topologicalOrder.size()); i++)
        {
            cout << topologicalOrder[i] << "\n";
        }

       
    }

    if (operation == 2)
    {

        cout << nodes[endNode].best << "\n";
       
    }

    if (operation == 3)
    {
        for (int i = 0; i < int(bottlenecks.size()); i++)
        {
            cout << bottlenecks[i] << "\n";
        }
       
    }

    return 0;
}
