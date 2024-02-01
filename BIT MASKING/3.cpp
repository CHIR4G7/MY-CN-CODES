#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int solve(int i,int j,vector<int>& a,bool turn,vector<vector<int> >& dp)
{
    if(i>j)
    {
        return 0;
    }
    int end = 0;
    int start = 0;
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    if(turn==true)
    {
        start = a[i] + solve(i+1,j,a,!turn,dp);
        end = a[j] + solve(i,j-1,a,!turn,dp);
        return dp[i][j] =  max(start,end);
    }
    if(turn==false)
    {
        start =  solve(i+1,j,a,!turn,dp);
        end =  solve(i,j-1,a,!turn,dp);
        return dp[i][j] =  min(start,end);
    }
}
 
int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    bool turn  = true;//my turn
    vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
    int ans = solve(0,n-1,a,turn,dp);
    cout << ans;
}