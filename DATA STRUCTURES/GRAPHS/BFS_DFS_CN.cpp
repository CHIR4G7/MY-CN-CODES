#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;


//DEPTH FIRST SEARCH
void dfs(int **graph,int nodes, int node_at, bool *visited)
{
    cout << node_at << " ";
    visited[node_at] = true;

    for(int i=0;i<nodes;i++)
    {
        if(i==node_at)
        {
            continue;
        }
        if(graph[node_at][i]==1)
        {
            if(visited[i]==false)
            {
                dfs(graph,nodes,i,visited);
            }
        }
    }
}

void DFS(int **graph, int nodes)
{
    bool *visited = new bool[nodes];
    for(int i=0;i<nodes;i++)
    {
        visited[i] = false;
    }
    for(int i=0;i<nodes;i++)
    {
        if(visited[i]==false)
        {
            dfs(graph,nodes,i,visited);
        }
    }
}

//BREADTH FIRST SEARCH

void bfs(int **graph,int nodes,int node_at,bool *visited)
{
    queue<int> q;
    q.push(node_at);
    visited[node_at] = true;

    while(q.size()!=0)
    {
        int frontNode = q.front();
        q.pop();
        cout << frontNode << " ";
        for(int i=0;i<nodes;i++)
        {
            if(graph[frontNode][i]==1)
            {
                if(visited[i]==false)
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
}

void BFS(int **graph,int nodes)
{
    bool *visited = new bool[nodes];
    for(int i=0;i<nodes;i++)
    {
        visited[i] = false;
    }
    for(int i=0;i<nodes;i++)
    {
        if(visited[i]==false)
        {
            bfs(graph,nodes,i,visited);
        }
    }
}
 
int main()
{
    int nodes, n_edges;
    cin >> nodes >> n_edges;

    int **graph = new int*[nodes];
    for(int i=0;i<nodes;i++)
    {
        graph[i] = new int[nodes];
        for(int j=0;j<nodes;j++)
        {
            graph[i][j] = 0;
        }
    }

    for(int i=0;i<n_edges;i++)
    {
        int u,v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "DFS : ";
    DFS(graph,nodes);
    cout << endl;

    cout << "BFS : ";
    BFS(graph,nodes);
    cout << endl;
}