#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int dx[8] = {-1,1,0,0,-1,-1,1,1};
int dy[8] = {0,0,1,-1,-1,1,1,-1};

int dfs(int i,int j,vector<vector<char> >& matrix,vector<vector<bool> >& visited)
{
    visited[i][j] = true;
    char prev = matrix[i][j];
    int temp = 1;
    for(int k=0;k<8;k++)
    {
        int nx = i+dx[k];
        int ny = j+dy[k];

        if(nx>=0 && nx<matrix.size() && ny>=0 && ny<matrix[0].size() && visited[nx][ny]==false && matrix[nx][ny]==(char)(prev+1))
        {
            temp = 1+dfs(nx,ny,matrix,visited);
        }
    }
    // visited[i][j] = false;
    return temp;
}

int longestPath(vector<vector<char> >& matrix,int n,int m)
{

    vector<vector<bool> > visited(n,vector<bool>(m,false));
    int length = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]=='A' && visited[i][j]==false)
            {
                length = max(length,dfs(i,j,matrix,visited));
            }
        }
    }
    return length;
}
 
int main()
{
    int n,m;
    cin >> n >> m;

    vector<vector<char> > matrix(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> matrix[i][j];
        }
    }

    int pathlength = longestPath(matrix,n,m);
    cout << pathlength;
    // char c = 'A';
    // cout << (char)(c+1);
}