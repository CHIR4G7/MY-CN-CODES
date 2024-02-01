#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;

bool checkBipartite(vector<vector<int>> &edges,int n,int node)
{
    vector<vector<int> > adjlist(n);
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    vector<int> color(n,-1);
    queue<int> pending;
    pending.push(node);
    color[node] = 0;//initially coloring node with 0
    bool c = false;//reperesnt color of the prev node(false-0 true-1)

    while(pending.size()!=0)
    {
        int front  = pending.front();
        pending.pop();

        for(auto i : adjlist[front])
        {
            if(color[i]==-1)
            {
                color[i] = 1-color[front];
                pending.push(i);
            }
            else if(color[i]==color[front])
            {
                return false;
            }
        }
    }
    return false;
}

int main()
{
    int nodes, n_edges;
    cin >> nodes >> n_edges;

    vector<vector<int>> edges;
    for (int i = 0; i < n_edges; i++)
    {
        vector<int> p;
        for (int i = 0; i < 2; i++)
        {
            int u;
            cin >> u;
            p.push_back(u);
        }
        edges.push_back(p);
    }
   
}