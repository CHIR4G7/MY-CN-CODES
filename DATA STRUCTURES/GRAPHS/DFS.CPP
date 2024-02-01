#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

void dfs(int node,int nodes,unordered_map<int,vector<int> > &adjList,vector<int> &component,vector<bool> &visited)
{
    visited[node] = true;
    component.push_back(node);
    for(auto n : adjList[node])
    {
        if(visited[n]==false)
        {
            dfs(n,nodes,adjList,component,visited);
        }
    }
}

void DepthFirstSearch(int nodes,vector<vector<int> > &edges,vector<vector<int> > &paths)
{
    //adjacency list
    unordered_map<int,vector<int> > adjList;
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(nodes,false);
    for(int i=0;i<nodes;i++)
    {
        if(visited[i]==false)
        {
            vector<int> component;
            dfs(i,nodes,adjList,component,visited);
            paths.push_back(component);
        }
    }
}

int main()
{
    int nodes,n_edges;
    cin >> nodes >> n_edges;

    vector<vector<int> > edges;
    for(int i=0;i<n_edges;i++)
    {
        vector<int> p;
        for(int i=0;i<2;i++)
        {
            int u;
            cin >> u;
            p.push_back(u);
        }
        edges.push_back(p);
    }

    vector<vector<int> > DFS_paths;
    DepthFirstSearch(nodes,edges,DFS_paths);
    for(int i=0;i<DFS_paths.size();i++)
    {
        for(int j=0;j<DFS_paths[i].size();j++)
        {
            cout << DFS_paths[i][j] << " ";
        }
        cout << endl;
    }
}