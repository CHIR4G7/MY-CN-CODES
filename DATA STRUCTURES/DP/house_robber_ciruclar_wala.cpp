#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

long long helper(vector<int> &nums,int index,vector<long long> &dp)
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
    long long pick = nums[index] + helper(nums,index-2,dp);
    long long notpick = helper(nums,index-1,dp);
    dp[index] = max(pick,notpick);
    return dp[index];
}

long long maxnonadj(vector<int> &nums,int n)
{
    vector<long long> dp(n+1,-1);
    long long ans = helper(nums,n-1,dp);
    return ans;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    if(n==1)
    {
        return valueInHouse[n-1];
    }
    vector<int> left;
    for(int i=0;i<n-1;i++)
    {
        left.push_back(valueInHouse[i]);
    }

    vector<int> right;
    for(int i=1;i<n;i++)
    {
        right.push_back(valueInHouse[i]);
    }

    long long l = maxnonadj(left,n-1);
    long long r = maxnonadj(right,n-1);
    return max(l,r);
    
}
 
int main()
{
    int n;
    cin >> n;

    vector<int> valueInhouse(n);
    for(int i=0;i<n;i++)
    {
        cin >> valueInhouse[i];
    }

    cout << houseRobber(valueInhouse);
}