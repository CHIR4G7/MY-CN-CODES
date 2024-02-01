#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

void solve(int col,vector<string> &board,vector<vector<string> > &ans,int n)
{
    
}

vector<vector<string> > solveNQueens(int n)
{
    vector<vector<string> > ans;
    vector<string> board(n);
    string s(n,' ');
    for(int i=0;i<n;i++)
    {
        board[i] = s;
    }
    solve(0,board,ans,n);
    return ans;
}
 
int main()
{
    int n;
    cin >> n;

    vector<vector<string> > ans = solveNQueens(n);
}