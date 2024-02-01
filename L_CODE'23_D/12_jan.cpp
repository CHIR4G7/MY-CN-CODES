#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <list>
using namespace std;

vector<int> dfs(int node,unordered_map<int,list<int> > &adj,string labels,unordered_map<int,bool> &visited,vector<int> &v)
{
    visited[node] = true;
    //to store count of all alphabets in a subtree
    vector<int> nodeCounts(26);
    //us charatcer ko to 1 kardo jo node pr hai
    nodeCounts[labels[node]-'a'] = 1;

    for(auto i : adj[node])
    {
        if(visited[i]==false)
        {
            vector<int> child(26);
            child = dfs(i,adj,labels,visited,v);
            for(int i=0;i<26;i++)
            {
                nodeCounts[i]+=child[i];
            }
        }
    }
    v[node] = nodeCounts[labels[node]-'a'];
    return nodeCounts;
}

vector<int> countSubTrees(int n, vector<vector<int> > &edges,string labels)
{
    unordered_map<int,list<int> > adj;
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    vector<int> v(n,0);
    dfs(0,adj,labels,visited,v);

}
 
int main()
{
    int nodes,n_edges;
    cin >> nodes >> n_edges;

    vector<vector<int> > edges;
    for(int i=0;i<n_edges;i++)
    {
        int u,v;
        cin >> u >> v;
        vector<int> x;
        x.push_back(u);
        x.push_back(v);
        edges.push_back(x);
    }

    string labels;
    cin >> labels;
}