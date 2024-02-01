#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int solve(vector<int> &coins, int amount,vector<int>& dp)
{
    if(amount<0)
    {
        return -1;
    }
    if(amount==0)
    {
        return 0;
    }
    if(dp[amount]!=-2)
    {
        return dp[amount];
    }
    int ans = 1e9;
    for (int i = 0; i < coins.size(); i++)
    {
        int val = solve(coins,amount-coins[i],dp);
        if(val!=-1)
        {
            ans = min(ans,1+val);
        }
        
    }
    return dp[amount] = ans;
}

int minCoins(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> dp(amount+1,-2);
    if(solve(coins,amount,dp)==1e9)
    {
        return -1;
    }
    return solve(coins,amount,dp);
}

int main()
{
    int n;
    int x;
   
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    
    int ans = minCoins(coins, x);
    cout << ans;
}