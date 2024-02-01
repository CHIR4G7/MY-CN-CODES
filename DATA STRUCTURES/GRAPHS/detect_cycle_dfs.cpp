#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool dfs(int node, int nodes, unordered_map<int, vector<int> > &adjList, vector<bool> &visited, vector<int> &parent, int p)
{
    visited[node] = true;
    parent[node] = p;

    for (auto i : adjList[node])
    {
        if (visited[i] == false)
        {
            if (dfs(i, nodes, adjList, visited, parent, node))
            {
                return true;
            }
        }
        else if (visited[i] == true && i != parent[node])
        {
            return true;
        }
    }
    return false;
}

bool detectCycle(int nodes, unordered_map<int, vector<int> > &adjList, vector<bool> &visited)
{
    vector<int> parent(nodes, -1); // marking everyones parent as -1 initially;
    for (int i = 0; i < nodes; i++)
    {
        if (visited[i] == false)
        {
            bool ans = dfs(i, nodes, adjList, visited, parent, -1);
            if (ans == true)
            {
                return true;
            }
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
        adjList[v].push_back(u);
    }

    vector<bool> visited(nodes, false);
    cout << detectCycle(nodes, adjList, visited);
}