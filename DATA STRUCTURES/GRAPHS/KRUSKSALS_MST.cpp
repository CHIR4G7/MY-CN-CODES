#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

class Edge
{
    public :
    int source;
    int destination;
    int weight;

    void printEdge()
    {
        cout << min(source,destination) << " " << max(source,destination) << " " << weight;
    }
};

int findParent(int node,int *parent)
{
    if(parent[node]==node)
    {
        return node;
    }
    return findParent(parent[node],parent);
}

bool Compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

void krusksals(Edge *input,int nodes,int n_edges)
{
    //sort the input array
    sort(input,input+n_edges,Compare);

    Edge *output = new Edge[nodes-1];//mst array

    int count = 0;
    int i = 0;

    //UINION PARENT ALGO
    int *parent = new int[nodes];
    for(int i=0;i<nodes;i++)
    {
        parent[i] = i;
    }

    while(count!=(nodes-1))
    {
        Edge currentEdge = input[i];
        //check if adding currentedge feasible or not
        int soureParent = findParent(currentEdge.source,parent);
        int destParent = findParent(currentEdge.destination,parent);

        if(soureParent!=destParent)
        {
            output[count] = currentEdge;
            count++;

            parent[soureParent] = destParent;
        }
        i++;
    }

    for(int i=0;i<nodes-1;i++)
    {
        output[i].printEdge();
        cout << endl;
    }
}
 
int main()
{
    int nodes,n_edges;
    cin >> nodes >> n_edges;

    Edge *input = new Edge[n_edges];
    for(int i=0;i<n_edges;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;

        input[i].source = u;
        input[i].destination = v;
        input[i].weight = w;
    }

    krusksals(input,nodes,n_edges);
    
}