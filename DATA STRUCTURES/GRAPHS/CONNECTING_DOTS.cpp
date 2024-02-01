#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

void dfs(vector<vector<char> > &graph,int n,int m,int i,int j,vector<vector<bool> > &visited,bool hascycle,char color,int fromX,int fromY)
{
    if(i<0 || j<0 || i>=n || j>=m)
    {
        return;
    }
    if(graph[i][j]!=color)
    {
        return;
    }
    if(visited[i][j]==true)
    {
        hascycle = true;
        return;
    }

    visited[i][j] = true;

    int dx[] = {1,-1,0,0};//eithe in x or in y
    int dy[] = {0,0,1,-1};

    for(int k=0;k<4;++k)
    {
        int nextX = i+dx[k];
        int nextY = j+dy[k];
        if(nextX==fromX && nextY==fromY)
        {
            continue;
        }
        dfs(graph,n,m,nextX,nextY,visited,hascycle,color,i,j);
    }
}

bool HasCycle(vector<vector<char> > &graph,int n,int m)
{
    vector<vector<bool> > visited(n,vector<bool>(m,false));
    bool hascycle = false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j]==false)
            {
                dfs(graph,n,m,i,j,visited,hascycle,graph[i][j],-1,-1);
            }
        }
    }
    return hascycle;
}
 
int main()
{
    int n,m;
    cin >> n >> m;

    vector<vector<char> > graph(n,vector<char>(m));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin >> graph[i][j];
        }
    }
    cout << HasCycle(graph,n,m) << endl;
}