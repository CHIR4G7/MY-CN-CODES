#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

void helper(vector<int> &nums,int index,int k,vector<vector<int> > &subarrays,vector<int> &ds)
{
    if(index==nums.size() || index+1==k)
    {
        
    }
}

void generate(vector<int> &nums,int k,vector<vector<int> > &subarrays)
{
    vector<int> ds;
    helper(nums,0,k,subarrays,ds);
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

    int k;
    cin >> k;

    vector<vector<int> > subarrays;
    generate(nums,k,subarrays);
}
