#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool dfs(int node,int nodes,unordered_map<int,vector<int> > &adjlist,vector<bool> &visited,vector<bool> &recStack)
{
    visited[node] = true;
    recStack[node] = true;

    for(auto neighbour : adjlist[node])
    {
        if(visited[node]==false)
        {
            if(dfs(neighbour,nodes,adjlist,visited,recStack))
            {
                return true;
            }
            else if(recStack[neighbour])
            {
                return true;
            }
        }
    }
    recStack[node] = false;
    return false;
}

bool isCyclic(int nodes,unordered_map<int,vector<int> > &adjlist)
{
    vector<bool> visited(nodes,false);
    vector<bool> recStack(nodes,false);

    for(int i=0;i<nodes;i++)
    {
        if(dfs(i,nodes,adjlist,visited,recStack))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int nodes, n_edges;
    cin >> nodes >> n_edges;

    vector<vector<int> > edges;
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

    // creating adjanceny list and visited array;
    unordered_map<int, vector<int> > adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    cout << isCyclic(nodes,adjList);
}