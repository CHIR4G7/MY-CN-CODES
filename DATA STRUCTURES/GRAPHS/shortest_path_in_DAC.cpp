#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <list>
#include <stack>
#include <limits.h>
using namespace std;

class Graph
{
    public :

    unordered_map<int,list<pair<int,int> > > adj;

    void add_edge(int u,int v,int weight)
    {
        pair<int,int> p;
        p.first = v;
        p.second = weight;
        adj[u].push_back(p);
    }

    void printAdjList()
    {
        for(auto i : adj)
        {
            cout << i.first << "->";
            for(auto j : i.second)
            {
                cout << "[" << j.first << "," << j.second << "],";
            }
            cout << endl;
        }
    }

    void dfs(int node,unordered_map<int,bool> &visited,stack<int>&s)
    {
        visited[node] = true;
        for(auto i : adj[node])
        {
            if(visited[i.first]==false)
            {
                dfs(i.first,visited,s);
            }
        }
        s.push(node);
    }

    void getShortestPath(int src,vector<int> &distance,stack<int> &s)
    {
        distance[src] = 0;
        while(s.empty()==false)
        {
            int top = s.top();
            s.pop();

            if(distance[top]!=INT_MAX)
            {
                for(auto i : adj[top])
                {
                    if(distance[top]+i.second < distance[i.first])
                    {
                        distance[i.first] = distance[top] + i.second;
                    }
                }
            }
        }
    }
};
 
int main()
{
    Graph g;
    g.add_edge(0,1,5);
    g.add_edge(0,2,3);
    g.add_edge(1,2,2);
    g.add_edge(1,3,6);
    g.add_edge(2,3,7);
    g.add_edge(2,4,4);
    g.add_edge(2,5,2);
    g.add_edge(3,4,-1);
    g.add_edge(4,5,-2);

    g.printAdjList();

    //topological sort;

    unordered_map<int,bool> visited;
    stack<int> s;

int n = 6;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            g.dfs(i,visited,s);
        }
    }
    
    int src = 1;
    vector<int> distance(n);
    for(int i=0;i<n;i++)
    {
        distance[i] = INT_MAX;
    }

    g.getShortestPath(src,distance,s);

    for(int i=0;i<distance.size();i++)
    {
        cout << distance[i] << " ";
    }
}