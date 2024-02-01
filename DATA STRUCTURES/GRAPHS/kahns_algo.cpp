#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> ToplogicalSort_kahns(vector<vector<int> > edges,int nodes,int n_edges)
{
    //create adjacency list
    unordered_map<int,list<int> > adj;
    for(int i=0;i<n_edges;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }

    //find all indegrres
    vector<int> indegrees(nodes);
    for(auto i : adj)
    {
        for(auto j : i.second)
        {
            indegrees[j]++;
        }
    }

    //0 indegree walo ko push kardo
    queue<int> q;
    for(int i=0;i<nodes;i++)
    {
        if(indegrees[i]==0)
        {
            q.push(i);
        }
    }

    //DO BFS
    vector<int> ans;
    while(q.empty()==false)
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(auto neighbour : adj[front])
        {
            indegrees[neighbour]--;
            if(indegrees[neighbour]==0)
            {
                q.push(neighbour);
            }
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
        vector<int> u_v;
       for(int i=0;i<2;i++)
       {
        int a;
        cin >> a;
        u_v.push_back(a);
       }
       edges.push_back(u_v);
    }

    vector<int> ans = ToplogicalSort_kahns(edges,nodes,n_edges);
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
}