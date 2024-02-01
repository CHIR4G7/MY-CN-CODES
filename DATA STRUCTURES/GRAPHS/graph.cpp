#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{
    public :
    unordered_map<int,list<int> > adj_list;

    void add_edge(int u,int v,bool isDirected)
    {
        //isDirected = 0 -> undrected graph
        //isDirected = 1 -> directed graph

        //create a edge from u -> v
        adj_list[u].push_back(v);
        if(isDirected==false)//undirected
        {
            adj_list[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for(auto i: adj_list)
        {
            cout << i.first << "->";
            for(auto j:i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

};
 
int main()
{
    int n;
    cout << "enter the number of nodes : ";
    cin >> n;

    int e;
    cout << "enter the number of edges : ";
    cin >> e;

    Graph G;

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin >> u >> v;

        G.add_edge(u,v,0);//undirected graph
    }
    G.printAdjList();

}