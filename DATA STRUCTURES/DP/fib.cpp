#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

//tabulation and space optimization
int fibo_2(int n,vector<int> &dp)
{
      
}

//memoization (top-down)
int fibo(int n,vector<int> &dp)
{
    if(n<=1)
    {
        return n;
    }

//this is check if the subproblem has been previously solved.
    if(dp[n]!=-1)
    {
        return dp[n];
    }

    dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
    return dp[n];
}
 
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);

    cout << fibo(n,dp) << '\n';
}