#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;

void bfs(bool **graph, bool *visited,int node,int nodes)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        cout << frontNode << " ";
        for(int i=0;i<nodes;i++)
        {
            if(graph[frontNode][i]==true && visited[i]==false)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(bool **graph,int nodes)
{
    bool *visited = new bool[nodes]();
    for(int i=0;i<nodes;i++)
    {
        if(visited[i]==false)
        {
            bfs(graph,visited,i,nodes);
        }
    }
}
 
int main()
{
    int nodes,n_edges;
    cin >> nodes >> n_edges;
    
    bool **graph = new bool*[nodes];
    for(int i=0;i<nodes;i++)
    {
        graph[i] = new bool[nodes]();
    }

    for(int i=0;i<n_edges;++i)
    {
        int a,b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    BFS(graph,nodes);

    for(int i=0;i<nodes;i++)
    {
        delete [] graph[i];
    }
    delete [] graph;
}