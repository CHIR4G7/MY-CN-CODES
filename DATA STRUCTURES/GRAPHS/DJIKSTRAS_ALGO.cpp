#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <limits.h>
#include <list>
using namespace std;

// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbTNkMXl5dXVwZmxXN2tscFJNQ2lvVEVRSGxhZ3xBQ3Jtc0trUGN0SmRfTVJTSGVIVkRsUHV4T3lwZ1pfSERHWDB5OHc5cTNfQjU0TmhZcHpTT25wZGhON0VkaE1wbC0wWU1GYl82aFNlTGhVa3Eta2FLbnNqUDFvSFBKUUttdHg4di1VSnEwcUlsUTY2WG1yNllaTQ&q=https%3A%2F%2Fwww.codingninjas.com%2Fcodestudio%2Fproblems%2Fdijkstra-s-shortest-path_920469%3FleftPanelTab%3D0%26utm_source%3Dyoutube%26utm_medium%3Daffiliate%26utm_campaign%3DLovebabbar&v=dVUR3Rm6biE

// vector<int> Djikstras(int nodes,vector<vector<int> > adj[],int source)
// {
//     priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    
//     vector<int> dist(nodes);
//     for(int i=0;i<nodes;i++)
//     {
//         dist[i] =   INT_MAX;
//     }
//     dist[source] = 0;
//     pq.push(make_pair(0,source));

//     while(pq.empty()==false)
//     {
//         int dist_from_source = pq.top().first;
//         int node = pq.top().second;
//         pq.pop();

//         for(auto it : adj[node])
//         {
//             int edgeweight = it[1];
//             int adjNode = it[0];

//             if(dist_from_source+edgeweight < dist[adjNode])
//             {
//                 dist[adjNode] = dist_from_source + edgeweight;
//                 pq.push(make_pair(dist[adjNode],adjNode));
//             }
//         }
//     }
//     return dist;
// }

vector<int> Dijkstras(vector<vector<int> > &edges,int nodes,int n_edges,int source)
{
    //create adjlist
    unordered_map<int,list<pair<int,int> > > adjlist;
    for(int i=0;i<n_edges;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        pair<int,int> p1;
        p1.first = v;
        p1.second = w;

        // adjlist[u].push_back(make_pair(v,w));
        adjlist[u].push_back(p1);

        pair<int,int> p2;
        p2.first = u;
        p2.second = w;
        // adjlist[v].push_back(make_pair(u,w));
        adjlist[v].push_back(p2);
    }

   priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
   vector<int> distance(nodes);
    for(int i=0;i<nodes;i++)
    {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;
    pair<int,int> p;
    p.first = 0;
    p.second = source;
    pq.push(p);

    while(pq.empty()==false)
    {
        int dist_from_source = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto it : adjlist[node])
        {
            int edgeweight = it.second;
            int adj_node = it.first;

            if(dist_from_source + edgeweight < distance[adj_node])
            {
                distance[adj_node] = edgeweight + dist_from_source;
                pair<int,int> add;
                add.first = distance[adj_node];
                add.second = adj_node;
                pq.push(add);
        }
    }
    return distance;
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
       for(int i=0;i<3;i++)
       {
        int a;
        cin >> a;
        u_v.push_back(a);
       }
       edges.push_back(u_v);
    }

    vector<int> ans = Dijkstras(edges,nodes,n_edges,0);
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
    
}
