#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

void dfs(int node,vector<bool> &visited,vector<vector<int> > &adjlist,int nodes)
{
    visited[node] = true;
    for(auto i : adjlist[node])
    {
        if(visited[i]==false)
        {
            dfs(i,visited,adjlist,nodes);
        }
    }
}

vector<int> findsmallestsetofvertices(int n,vector<vector<int> > &edges)
{
    vector<int> nodes;
    vector<vector<int> > adjlist(n);
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
    }

    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            nodes.push_back(i);
            dfs(i,visited,adjlist,n);
        }
    }
    return nodes;
}

//approach 2 
//indegree count--LEETCODE SOLUTION HAI WAHAN QUESTION ME
//those having zero indegree are the only ondes that cannot be reached from one another hence only those are required to traverse the whole graph

vector<int> findsmallestsetofvertices_2(int n,vector<vector<int> > &edges)
{
    vector<int> nodes;
    vector<int> indegree(n);
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][0];
        indegree[v]++;
    }
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            nodes.push_back(i);
        }
    }
    return nodes;
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

    vector<int> ans = findsmallestsetofvertices(nodes,edges);
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
}