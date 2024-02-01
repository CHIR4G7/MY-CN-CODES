#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

vector<vector<int> > floyyd( vector<vector<int> > &adjlist,int nodes)
{
    vector<vector<int> > dist_matrix(nodes,vector<int>(nodes,(INT_MAX/2)));
    
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> edge_list(edges, vector<int>(2));
    for (int i = 0; i < edges; i++)
    {
        cin >> edge_list[i][0] >> edge_list[i][1];
    }
    
    vector<vector<int> > adjlist(nodes);
    for(int i=0;i<edges;i++)
    {
        adjlist[edge_list[i][0]].push_back(edge_list[i][1]);
        adjlist[edge_list[i][1]].push_back(edge_list[i][0]);
    }

    vector<vector<int> > ans = floyyd(adjlist,nodes);
}