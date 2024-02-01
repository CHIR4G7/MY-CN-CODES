#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>
using namespace std;

void helper(vector<int> &nums,set<vector<int> > &subs,vector<int> &ds,int idx)
{
    if(idx == nums.size())
    {
        if(ds.size()>=2)
        {
            subs.insert(ds);
        }
        return;
    }

    if(ds.empty() || ds.back()<=nums[idx])
    {
        ds.push_back(nums[idx]);
        helper(nums,subs,ds,idx+1);
        ds.pop_back();
    }
    helper(nums,subs,ds,idx+1);
}

vector<vector<int> > findSubs(vector<int> &nums)
{
    vector<vector<int> > ans;
    set<vector<int> > subs;
    vector<int> ds;

    helper(nums,subs,ds,0);
    for(auto i : subs)
    {
        ans.push_back(i);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    vector<vector<int> > a = findSubs(nums);
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}