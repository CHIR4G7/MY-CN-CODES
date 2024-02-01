#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
 
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
    vector<pair<int,int> > pairs;
    int si = -1;
    int ei = 0;

    while(ei<n)
    {
        if(nums[ei]==0)
        {
            si = ei;
            while(nums[ei]==0 && ei<n)
            {
                ei++;
            }
            pair<int,int> p;
            p.first = si;
            p.second = ei-1;
            pairs.push_back(p);
        }
        ei++;
    }
 
    long long count = 0;
    for(int i=0;i<pairs.size();i++)
    {
        int k = (pairs[i].second - pairs[i].first)+1;
        count+=(k*(k+1))/2;
    }
    cout << count;
}