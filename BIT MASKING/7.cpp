#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int solve(vector<int>& coins,int amount,vector<int>& dp)
{
    if(amount==0)
    {
        return 0;
    }
    if(dp[amount]!=-1)
    {
        return dp[amount];
    }
    int ans = INT_MAX;
    for(auto coin : coins)
    {
        if(amount-coin>=0)
        {
            ans = min(ans,1+solve(coins,amount-coin,dp)); 
        }
    }
    return dp[amount] = ans;
}
 
int main()
{
    int n;
    cin >> n;

    vector<int> coins(n);
    for(int i=0;i<n;i++)
    {
        cin >> coins[i];
    }
    int amount;
    cin >> amount;

    vector<int> dp(amount+1,-1);
    int s = solve(coins,amount,dp);
    cout << s;
}