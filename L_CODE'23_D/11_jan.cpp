#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <list>
using namespace std;

void dfs(unordered_map<int,list<int> > &adj,unordered_map<int,bool> &visited,int nodes,int sv,int ev,vector<int> &output)
{
    
    if(sv==ev)
    {
        output.push_back(sv);
        return;
    }
    visited[sv] = true;
    for(auto i : adj[sv])
    {
        if(visited[i]==false)
        {
            dfs(adj,visited,nodes,i,ev,output);
            if(output.size()!=0)
            {
                output.push_back(sv);
                return;
            }
        }
    }
    return;
}

// int mintime(int nodes,vector<vector<int> > &edges,vector<bool> &hasApple)
// {
//     //create adjacency matrix wt a extra parameter of has apple bool type in it
//     unordered_map<int,list<int> > adj;
//     int n_edges = edges.size();
//     for(int i=0;i<n_edges;i++)
//     {
//         int u = edges[i][0];
//         int v = edges[i][1];

//         adj[v].push_back(u);
//         adj[u].push_back(v);
//     }

//     unordered_map<int,bool> visited;
//     int count = 0;

//     for(int i=0;i<nodes;i++)
//     {
//         if(hasApple[i]==true)
//         {
//             vector<int> ans = dfs(adj,visited,nodes,0,i);
//             count+=(ans.size()-1);
//         }
//     }
//     return count;

// }
 
int main()
{
    int nodes,n_edges;
    cin >> nodes >> n_edges;

    vector<vector<int> > edges;
    for(int i=0;i<n_edges;i++)
    {
        vector<int> v;
        for(int j=0;j<2;j++)
        {
            int p,q;
            cin >> p >> q;
            v.push_back(p);
            v.push_back(q);
        }
        edges.push_back(v);
    }

    unordered_map<int,list<int> > adj;
   
    for(int i=0;i<n_edges;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    unordered_map<int,bool> visited;

    vector<int> ans;
    dfs(adj,visited,nodes,0,2,ans);
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }

}