#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

void topo(int node, vector<bool> &visited,stack<int> &s,unordered_map<int,list<int> > &adj)
{
    visited[node] = true;
    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
            topo(neighbour,visited,s,adj);
        }
    }
    s.push(node);
}

vector<int> TopologicalSort(vector<vector<int> > &edges, int v, int e)  {
    // Write your code here
    //create adjacency list
    unordered_map<int,list<int> > adj;
    for(int i=0;i<e;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
    vector<bool> visited(v);
    stack<int> s;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            topo(i,visited,s,adj);
        }
    }
    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main()
{
    int nodes,n_edges;
    cin >> nodes >> n_edges;

    vector<vector<int> > edges;
    for(int i=0;i<n_edges;i++)
    {
        vector<int> u_v;
       for(int i=0;i<2;i++)
       {
        int a;
        cin >> a;
        u_v.push_back(a);
       }
       edges.push_back(u_v);
    }

    vector<int> ans = TopologicalSort(edges,nodes,n_edges);
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
}