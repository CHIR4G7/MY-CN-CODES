#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int min_steps(int index,vector<int> &dp)
{
    if(index==0)
    {
        return 1;
    }
    if(index==1)
    {
        return 1;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    dp[index] = min_steps(index-1,dp) + min_steps(index-2,dp);  
    return dp[index];
}


int min_steps(int n)
{
    vector<int> dp(n+1,-1);
    return min_steps(n,dp);
}
 
int main()
{
    int n;
    cin >> n;

    cout << min_steps(n);
}