#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

vector<int> shortest_path_unweighted(vector<pair<int,int> > edges,int nodes,int n_edges,int source,int target)
{
    //creating adjacency list
    unordered_map<int,list<int> > adj;
    for(int i=0;i<n_edges;i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //BFS
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(source);
    visited[source];
    parent[source] = -1;

    while(q.empty()==false)
    {
        int front = q.front();
        q.pop();

        for(auto i : adj[front])
        {
            if(visited[i]==false)
            {
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
        }
    }

    //prepare shortest path
    vector<int> shortest_path;
    int currentNode = target;
    shortest_path.push_back(target);
    while(currentNode!=source)
    {
        currentNode = parent[currentNode];
        shortest_path.push_back(currentNode);
    }
    
    return shortest_path;
}
 
int main()
{
    int nodes,n_edges;
    cin >> nodes >> n_edges;

    vector<pair<int,int> > edges;

    for(int i=0;i<n_edges;i++)
    {
       pair<int,int> p;
       int u,v;
       cin >> u >> v;
       p.first = u;
       p.second = v;
       edges.push_back(p);
    }

    int source,target;
    cin >> source >> target;

    vector<int> shortpath = shortest_path_unweighted(edges,nodes,n_edges,source,target);
    for(int i=0;i<shortpath.size();i++)
    {
        cout << shortpath[i] << " ";
    }
}
