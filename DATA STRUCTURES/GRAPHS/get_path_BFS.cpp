#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> getPath_BFS_helper(int **graph,int nodes,int sv,int ev,bool *visited)
{
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    visited[sv] = true;
    bool done = false;
    vector<int> output;
    output.push_back(sv);

    while(pendingNodes.size()!=0 && done==false)
    {
        int front = pendingNodes.front();
        pendingNodes.pop();
        for(int i=0;i<nodes;i++)
        {
            if(graph[front][i]==1 && visited[i]==false)
            {
                output.push_back(i);
                pendingNodes.push(i);
                visited[i] = true;
                
                if(i==ev)
                {
                    done = true;
                    break;
                }
                
            }
        }
    }
    return output;
}

vector<int> getPath_BFS(int **graph,int nodes, int sv,int ev)
{
    bool *visited = new bool[nodes];
    for(int i=0;i<nodes;i++)
    {
        visited[i] = false;
    }
    vector<int> output = getPath_BFS_helper(graph,nodes,sv,ev,visited);
    delete []visited;
    return output;
}
 
int main()
{
    int nodes, n_edges;
    cin >> nodes >> n_edges;

    int **graph = new int *[nodes];
    for (int i = 0; i < nodes; i++)
    {
        graph[i] = new int[nodes];
        for (int j = 0; j < nodes; j++)
        {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < n_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int sv,ev;
    cin >> sv >> ev;

    vector<int> output = getPath_BFS(graph,nodes,sv,ev);
    for(int i=0;i<output.size();i++)
    {
        cout << output[i] << " ";
    }
}