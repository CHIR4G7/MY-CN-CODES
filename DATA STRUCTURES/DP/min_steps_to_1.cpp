#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

//memoization DP SOLUTION

int helper_dp(int n,vector<int> &dp)
{
    if(n==1)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int a = helper_dp(n-1,dp);
    int b = INT_MAX;
    if(n%2==0)
    {
        b = helper_dp(n/2,dp);
    }
    int c = INT_MAX;
    if(n%3==0)
    {
        c = helper_dp(n/3,dp);
    }
    dp[n] = 1 + min(a,min(b,c));
    return dp[n];
}

int minSteps_DP(int n)
{
    vector<int> dp(n+1,-1);
    return helper_dp(n,dp);
}


//recursive code
int minStepsToOne(int n)
{
    if(n==1)//iska mtlb hai ki vo 1 par pohonch gya hai to 1 se 1 pr jaane ke liye to 0 steps hi lagenge na
    {
        return 0;
    }
    int a = minStepsToOne(n-1);//case jab subtract karenge 1
    int b = INT_MAX;//pehle hi kaafi bada set kardo kyunki hame to min lena hai
    if(n%2==0)
    {
        b = minStepsToOne(n/2);
    }
    int c = INT_MAX;
    if(n%3==0)
    {
        c = minStepsToOne(n/3);
    }
    return 1 + min(a,min(b,c));
}
 
int main()
{
    int n;
    cin >> n;

    cout << minSteps_DP(n) << endl;
}