#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

void addSolution(vector<vector<int> > &board,vector<vector<int> > &ans,int n)
{
    vector<int> temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row,int col,vector<vector<int> > &board,int n)
{
    int x = row;
    int y = col;
    //check same row
    while(y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        y--;
    }

    x= row;
    y = col;

    //check daigonal
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }

    x= row;
    y = col;

    while(x<n && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x++;
        y--;
    }
    return true;
}

void solve(vector<vector<int> > &ans,vector<vector<int> > &board,int col,int n)
{
    //base case
    if(col==n)
    {
        addSolution(board,ans,n);
        return;
    }
    //solve 1 case and rest recursion
    for(int row=0;row<n;row++)
    {
        if(isSafe(row,col,board,n))
        {
            //if safe
            board[row][col] = 1;
            solve(ans,board,col+1,n);
            board[row][col] = 0;
        }
    }
}

vector<vector<int> > NQueens(int n)
{
    vector<vector<int> > board(n,vector<int>(n,0));
    vector<vector<int> > ans;

    solve(ans,board,0,n);
    return ans;
}
 
int main()
{
    int n;
    cin >> n;

    vector<vector<int> > ans = NQueens(n);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}