#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

//tabulation
int helper_dp_tab(int n,vector<int> &heights)
{
    vector<int> dp(n,0);
    dp[0] = 0;
    for(int i=1;i<n;i++)
    {
        int fs = dp[i-1] + abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i>1)
        {
            ss = dp[i-2] + abs(heights[i]-heights[i-2]);
        }
        dp[i] = min(fs,ss);
    }
    return dp[n-1];
}

//memoization
int helper_dp(int index,vector<int> &heights,vector<int> &dp)
{
    if(index==0)
    {
        return 0;
    }

    //if already calculated then return here only no need to go for calculation again
    if(dp[index]!=-1)
    {
        return dp[index];
    }

    //if not that calcilate and then save the answer 
    int left = helper_dp(index-1,heights,dp) + abs(heights[index]-heights[index-1]);
    int right = INT_MAX;
    if(index>1)
    {
        right = helper_dp(index-2,heights,dp) + abs(heights[index]-heights[index-2]);
    }
    dp[index] = min(left,right);
    return dp[index];
}

int helper_rec(int index,vector<int> &heights)
{
    if(index==0)
    {
        return 0;
    }
    int left = helper_rec(index-1,heights) + abs(heights[index]-heights[index-1]);

    //THIS RIGHT RECURSION CALL WILL NOT HAPPEN ALWAYS BECAUSE IT CAN NOT BE CALLED FOR INDEX 1,
    int right = INT_MAX;

//in this case ths right rec call will be made.
    if(index>1)
    {
        right = helper_rec(index-2,heights) + abs(heights[index]-heights[index-2]);
    }
    return min(left,right);
}

int frogJump(int n,vector<int> &heights)
{
    //return helper_rec(n-1,heights); //for simple recursive solution.

    //now writing the dp solution memoization
    // vector<int> dp(n+1,-1);
    // return helper_dp(n-1,heights,dp);

    //tabulation
    return helper_dp_tab(n,heights);

}
 
int main()
{
    int n;
    cin >> n;

    vector<int> heights;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        heights.push_back(a);
    }

    cout << frogJump(n,heights);
}