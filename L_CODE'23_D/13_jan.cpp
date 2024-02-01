#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <list>
using namespace std;

int dfs(int node,string s,unordered_map<int, list<int>> &adj)
{
    for(auto i : adj[node])
    {
        dfs(i,s,adj);
        if(s[node]!=s[i])
        {
            
        }
    }
}

int longestPath(vector<int> &parent, string s)
{
    unordered_map<int, list<int>> adj;
    for (int i = 1; i < parent.size(); i++)
    {
        adj[parent[i]].push_back(i);
        adj[i].push_back(parent[i]);
    }
    dfs(0,s,adj);
}

int main()
{
    int nodes;
    cin >> nodes;

    vector<int> parent;
    for (int i = 0; i < nodes; i++)
    {
        int a;
        cin >> a;
        parent.push_back(a);
    }
    string s;
    cin >> s;
}