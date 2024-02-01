#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

void permutehelp(vector<vector<int> >&ans,vector<int> &ds,vector<int> &nums,int freq[])
{
    if(ds.size()==nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(freq[i]==0)
        {
            freq[i]=1;
            ds.push_back(nums[i]);
            permutehelp(ans,ds,nums,freq);
            ds.pop_back();
            freq[i] = 0;
        }
    }
}

vector<vector<int> > permute(vector<int> &nums)
{
    vector<vector<int> > ans;
    vector<int> ds;
    int freq[nums.size()];
    for(int i=0;i<nums.size();i++)
    {
        freq[i] = 0;
    }
    permutehelp(ans,ds,nums,freq);
    return ans;
}
 
int main()
{
    int n;
    cin >> n;

    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }
}