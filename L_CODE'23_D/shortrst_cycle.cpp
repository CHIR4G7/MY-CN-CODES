#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;

int bfs(int node,int nodes,unordered_map<int, vector<int>> &adj,vector<bool> &visited)
{
    queue<int> pending;
    pending.push(node);
    visited[node] = true;
    int count = 0;

    while(pending.size()!=0)
    {
        int front = pending.front();
        pending.pop();
        count++;
        for(auto i : adj[front])
        {
            if(visited[i]==false)
            {
                pending.push(i);
                visited[i] = true;
            }
        }
    }
    return count;
}

int findShortestCycle(int nodes, vector<vector<int>> &edges)
{
    // remove the edge e and find shortest path.
    for (int i = 0; i < edges.size(); i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            unordered_map<int, vector<int>> adj;
            if (i != j)
            {
                int u = edges[i][0];
                int v = edges[i][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            vector<bool> visited(nodes,false);
            
            int count = bfs(j,nodes,adj,visited);
        }
    }
}

int main()
{
    int nodes, n_edges;
    cin >> nodes >> n_edges;

    vector<vector<int>> edges;
    for (int i = 0; i < n_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        vector<int> p;
        p.push_back(u);
        p.push_back(v);
        edges.push_back(p);
    }
}