#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

// https://bit.ly/3M4jIX5

bool isCyclic(unordered_map<int, list<int>> &adj, int node, unordered_map<int, bool> &visited)
{
    unordered_map<int, int> parent;
    parent[node] = -1;
    visited[node] = true;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto neighbour : adj[front])
        {
            if (visited[neighbour] == true && neighbour != parent[front])
            {
                return true;
            }
            else if (visited[neighbour] == false)
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    // create adjacency list

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handle disconnected components
    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclic(adj, i, visited);
            if (ans == 1)
            {
                return "Yes";
            }
        }
    }
    return "No";
}

int main()
{
    int nodes, n_edges;
    cin >> nodes >> n_edges;

    vector<pair<int, int>> graph;

    for (int i = 0; i < n_edges; i++)
    {
        pair<int, int> p;
        int u, v;
        cin >> u >> v;
        p.first = u;
        p.second = v;
        graph.push_back(p);
    }

    // main code is pervfect just create a edges list with vector<vector<int>> instead of pair.
    //  string cycleDetect = cycleDetection(,nodes,n_edges);
}