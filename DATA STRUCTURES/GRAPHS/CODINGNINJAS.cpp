#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool dfs(vector<vector<bool> > &visited, vector<vector<char> > &board,int i,int j,int n,int m,string s)
{
    if(s.length()==0)
    {
        return true;
    }
    if(i<0 || j<0 || i>=m || j>=n)
    {
        return false;
    }

    int row[] = {i-1,i,i+1};
    int col[] = {j-1,j,j+1};

    for(int p = 0;p<3;p++)
    {
        for(int q = 0;q<3;q++)
        {
            if(row[p]==i && col[q]==j)
            {
                continue;
            }
            int r = row[p];
            int c = col[q];
            if(r<0 || c<0 || r>=m || c>=n)
            {
                continue;
            }
            if(board[r][c]==s[0] && visited[r][c]==false)
            {
                visited[r][c] = true;
                bool checked = dfs(visited,board,r,c,n,m,s.substr(1));
                if(checked)
                {
                    return checked;
                }
                else
                {
                    visited[r][c] = false;
                }
            }
        }
    }
    return false;
}

bool HasPath(vector<vector<char> > &board,int n,int m)
{
    vector<vector<bool> > visited(n,vector<bool>(m,false));
    string s = "CODINGNINJAS";

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]==s[0])
            {
                if(dfs(visited,board,i,j,n,m,s.substr(1)))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
 
int main()
{
    int n,m;
    cin >> n >> m;

    vector<vector<char> > board(n,vector<char>(m));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> board[i][j];
        }
    }
    cout << HasPath(board,n,m);
}