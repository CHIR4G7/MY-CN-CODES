#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int gcd(int x,int y)
{
    int result = min(x,y);
    while(result>0)
    {
        if(x%result==0 && x%result==0)
        {
            break;
        }
        result--;
    }
    return result;
}

int solve(vector<int> &nums,vector<bool> &taken,int operations)
{
    int maxs = 0;
    for(int i=0;i<)
}

int maxScore(vector<int> &nums)
{
    int n = nums.size();
    int maxop = (n/2);//maximum operations to be performed.

    vector<bool> taken(n,false);
    int ans = solve(nums,taken,1);
    return ans;
}

int main()
{
    // int n;
    // cin >> n;

    // vector<int> nums(n);
    // for(int i=0;i<n;i++)
    // {
    //     cin >> nums[i];
    // }

    // cout << maxScore(nums) << endl;
    cout << gcd(10,4);
}