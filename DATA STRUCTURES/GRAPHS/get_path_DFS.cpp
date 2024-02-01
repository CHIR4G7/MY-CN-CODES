#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

vector<int> *getPath_DFS_helper(int **graph, int nodes, int sv, int ev, bool *visited)
{
    if (sv == ev)
    {
        vector<int> *output = new vector<int>();
        output->push_back(sv);
        return output;
    }
    visited[sv] = true;
    for (int i = 0; i < nodes; i++)
    {
        if (graph[sv][i] == 1 && visited[i] == false)
        {
            vector<int> *smalloutput = getPath_DFS_helper(graph, nodes, i, ev, visited);
            if (smalloutput != NULL)
            {
                smalloutput->push_back(sv);//pichli nodes aa rhe hain ham starting vertex ko usme add kr rhe hain v
                return smalloutput;
            }
        }
    }
    return NULL;
}

vector<int> *getPath_DFS(int **graph, int nodes, int sv, int ev)
{
    bool *visited = new bool[nodes];
    for (int i = 0; i < nodes; i++)
    {
        visited[i] = false;
    }
    vector<int> *output = getPath_DFS_helper(graph, nodes, sv, ev, visited);
    delete[] visited;
    return output;
}

int main()
{

    // GRAPH CREATION.
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
    int sv, ev;
    cin >> sv >> ev;

    vector<int> *ans = getPath_DFS(graph, nodes, sv, ev);

    if (ans->size() != 0)
    {
        for (int i = 0; i < ans->size(); i++)
        {
            cout << ans->at(i) << " ";
        }
    }

    for (int i = 0; i < nodes; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
}