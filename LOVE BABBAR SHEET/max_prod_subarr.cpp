#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int maxProd(vector<int> &nums, int n)
{
    int maxp = INT_MIN;
    int prod = 1;

    for (int i = 0; i < n; i++)
    {
        if(prod==0)
        {
            prod = 1;
        }
        prod*=nums[i];
        maxp = max(maxp,prod);
    }
    prod = 1;
    for(int j=(n-1);j>=0;j--)
    {
        if(prod==0)
        {
            prod = 1;
        }
        prod*=nums[j];
        maxp = max(maxp,prod);
    }
    return maxp;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << maxProd(nums, n);
}