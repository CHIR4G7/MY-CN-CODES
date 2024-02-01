#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

//memoization
int helper_dp_memo(int index,vector<int> &heights,int k, vector<int> &dp)
{
    if(index==0)
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    int min_steps = INT_MAX;
    for(int j=1;j<=k;j++)
    {
        int jump_energy = INT_MAX;
        if(index>=j)
        {
            jump_energy = helper_dp_memo(index-j,heights,k,dp) + abs(heights[index]-heights[index-j]);
        }
        dp[index] = min(min_steps,jump_energy);
    }
    return dp[index-1];
}

int helper(int index, vector<int> &heights, int k)
{
    if (index == 0)
    {
        return 0;
    }
    int min_steps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        int jump_energy = INT_MAX;
        if (index >= j)
        {
           jump_energy = helper(index - j, heights, k) + abs(heights[index] - heights[index - j]);
        }
        min_steps = min(min_steps, jump_energy);
    }
    return min_steps;
}

int frogJump(int n, vector<int> &heights, int k)
{
    //return helper(n - 1, heights, k);

    //memoization
    vector<int> dp(n+1,-1);
    return helper_dp_memo(n-1,heights,k,dp);
}

int main()
{
    int n = 5;
    vector<int> heights;
    for (int i = 0; i < 5; i++)
    {
        int a;
        cin >> a;
        heights.push_back(a);
    }

    int k;
    cin >> k;
    cout << frogJump(n, heights, k);
}