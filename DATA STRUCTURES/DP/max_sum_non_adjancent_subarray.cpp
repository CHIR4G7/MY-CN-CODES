#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int helper_tab(int n,vector<int> &nums)
{
    vector<int> dp(n,-1);
    dp[0] = nums[0];//fromt base case of memoization
    int neg = 0;//stroing the negative index part as it cant be stored in the array.

    for(int i=1;i<=n;i++)
    {
        int take = nums[i];
        if(i>1)
        {
            take += dp[i-2];
        }
        int nottake = 0 + dp[i-1];
        dp[i] = max(take,nottake); 
    }
    return dp[n];
}

int helper_memo(int index,vector<int> &nums,vector<int> &dp)
{
    if(index==0)
    {
        return nums[index];
    }
    if(index<0)
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    int pick = nums[index] + helper_memo(index-2,nums,dp);
    int notpick = helper_memo(index-1,nums,dp);
    dp[index] = max(pick,notpick);
    return dp[index];
}

int helper(int index,vector<int> &nums)
{
    if(index==0)
    {
        return nums[index];//we are going it pick it up becuse if we reached here enas we have not picked index 1, so we can pick it and we will pick it;
    }
    if(index<0)
    {
        return 0;
    }
    int pick = nums[index] + helper(index-2,nums);
    int notpick = helper(index-1,nums);
    return max(pick,notpick);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    //return helper(n-1,nums);

    //memoization
    // vector<int> dp(n,-1);
    // return helper_memo(n-1,nums,dp);

    //tabulation
    return helper_tab(n,nums);
}
 
int main()
{
    int n;
    cin >> n;

    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    cout << maximumNonAdjacentSum(nums);
}