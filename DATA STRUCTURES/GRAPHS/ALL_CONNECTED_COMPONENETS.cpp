#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;



vector<int> BFS(int **graph,int nodes,bool *&visited,int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    vector<int> v;

    while(q.empty()==false)
    {
        int front = q.front();
        q.pop();
        v.push_back(front);

        for(int i=0;i<nodes;i++)
        {
            if(graph[front][i]==1 && visited[i]==false)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return v;
}

vector<vector<int> >  All_Connected(int **graph,int nodes,bool *&visited)
{
    vector<vector<int> > ans;
    for(int i=0;i<nodes;i++)
    {
        if(visited[i]==false)
        {
            vector<int> a = BFS(graph,nodes,visited,i);
            ans.push_back(a);
        }
    }

    return ans;
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

    bool *visited = new bool[nodes];
    for(int i=0;i<nodes;i++)
    {
        visited[i] = false;
    }

vector<vector<int> > connectedcomponents = All_Connected(graph,nodes,visited);

    for(int i=0;i<connectedcomponents.size();i++)
    {
        sort(connectedcomponents[i].begin(),connectedcomponents[i].end());

        for(int j=0;j<connectedcomponents[i].size();j++)
        {
            cout << connectedcomponents[i][j] << " ";
        }
        cout << endl;
    }

}