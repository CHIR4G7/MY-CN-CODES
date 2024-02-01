#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;


//CREATING AN ADJANCENCY LIST USING VECTOR'S 
vector<vector<int> > printAdjacency(int n, int e, vector<vector<int> > edges)
{
    //vector<int> v[n] - is types se jab me array banata hu to vector ke andar ban jaata hai , aur fir mai usko v[i][j] aise access krta hu.
    vector<int> ans[n];//n - nodes hai to adjanceny list me to sab hi hoge ..to unko list me daal diya
    // ek vector me uske saare neighbours ko store kara liye us particular node ke.
    for(int i=0;i<e;i++)
    {
        int u = edges[i][0];//pehle wale element us list ka u hoga aur similarly doosar wala v.
        int v = edges[i][1];

//undirected graph.
        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int> > adj_list(n);//ek 2-d vector banaya aur usme ab sbko, jo uspar ans vector bana haua hai usko daal dunga.
    for(int i=0;i<n;i++)
    {
        adj_list[i].push_back(i);
        for(int j=0;j<ans[i].size();i++)
        {
            adj_list[i].push_back(ans[i][j]);
        }
    }
    return adj_list;
}


 
int main()
{
    int n;
    cout << "number of nodes : ";
    cin >> n;

    int e;
    cout << "number of edges : ";
    cin >> e;

    vector<vector<int> > edges;
    //undirected graph;
    for(int i=0;i<e;i++)
    {
        vector<int> u_v;
        for(int j=0;j<2;j++)
        {
            int a;
            cin >> a;
            u_v.push_back(a);
        }
        edges.push_back(u_v);
    }
    vector<vector<int> > adj = printAdjacency(n,e,edges);
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
   
}