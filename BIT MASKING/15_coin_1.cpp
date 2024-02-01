#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int solve(vector<int>& coins,int sum)
{
    if(sum<0)
    {
        return -1;
    }
    if(sum==0)
    {
        return 1;
    }

    int ans = 0;
    for(int i=0;i<coins.size();i++)
    {
        
    }
}

int minWays(vector<int>& coins,int sum)
{
    return solve(coins,sum);
}
 
int main()
{
    int n,x;
    cin >> n >> x;

    vector<int> coins(n);
    for(int i=0;i<n;i++)
    {
        cin >> coins[i];
    }

    int ans = minWays(coins,x);
}