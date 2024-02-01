#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

 long long solve(int i,int j,vector<long long>& arr,bool turn,vector<vector<long long> >& dp)
    {
        if(i>j)
        {
            return 0;
        }
        int start = 0;
        int end = 0;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(turn==true)
        {
            start = arr[i] + solve(i+1,j,arr,!turn,dp);
            end = arr[j] + solve(i,j-1,arr,!turn,dp);
            return dp[i][j] = max(start,end);
        }
        if(turn==false)
        {
            start =  solve(i+1,j,arr,!turn,dp);
            end =  solve(i,j-1,arr,!turn,dp);
            return dp[i][j] = min(start,end);
        }
    }

long long maxScore(vector<long long>& arr)
{
    // bool turn = true;//first player ki turn;
    long long n = arr.size();
    // return solve(0,n-1,arr,turn);
     vector<vector<long long> > dp(n+1,vector<long long>(n+1,-1));
        bool turn = true;//your turn first
        return solve(0,n-1,arr,turn,dp);
}
 
int main()
{
    long long n;
    cin >> n;

    vector<long long> arr(n);
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    long long ans = maxScore(arr);
    cout << ans;
}