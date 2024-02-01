#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

//HIGHER TIME COMPLEXITY APPROACH

//CREATING THE ADJANCENNY LIST
void prepareAdjList(unordered_map<int,list<int> > &adjList, vector<pair<int,int> > edges)
{
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}


void bfs(unordered_map<int,list<int> > &adjList,unordered_map<int,bool> &visited, vector<int> &ans, int node)
{
    //pehle us node ko queue me daal diya aur use visited mark krdiya
    queue<int> q;
    q.push(node);
    visited[node] = 1;


    while(q.size()!=0)
    {
        //fir use nikala aur uske saare adjacent nodes ko queue me dala, aur us particular node ko ans me daal diya
        int frontNode = q.front();
        q.pop();

        //store frontnode in ans;
        ans.push_back(frontNode);

        //travel all neighbours of front node
        for(auto i : adjList[frontNode])
        {
            if(visited[i]==false)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int,int> > edges)
{
    //MAKING ADJANCENY LIST 
    unordered_map<int,list<int> > adjList;//AB ISKE LIYE UPAR EK FUNCTION BAN DIYA HAI

    vector<int> ans;//ISME HUM FINAL PATH STORE KARENGE

    unordered_map<int,bool> visited;//YE TRACK RAKHEGA KI KONSI NODE VISITED HAI ALREADY

    //prepare adjList
    prepareAdjList(adjList,edges);

    //traverse all componeents of a graph(bascially to handle the disconnected nodes also)
    for(int i=0;i<vertex;i++)//HAR EK NODE KE LIYE JAUNGA MAI.
    {
        if(visited[i]==false)
        {
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}
 
int main()
{
    int nodes;
    cin >> nodes;

    vector<pair<int,int> > edges;

    int n_edges;
    cin >> n_edges;

    for(int i=0;i<n_edges;i++)
    {
       pair<int,int> p;
       int u,v;
       cin >> u >> v;
       p.first = u;
       p.second = v;
       edges.push_back(p);
    }

    //BFS

    vector<int> ans = BFS(nodes,edges);
    for(int i=0;i<nodes;i++)
    {
        cout << ans[i] << " ";
    }

}