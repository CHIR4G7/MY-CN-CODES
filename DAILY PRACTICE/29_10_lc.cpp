#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

vector<vector<int> > threeSum(vector<int> &nums)
{
    vector<vector<int> > ans;
    int si = 0;
    int ei = 0;
    int k = 3; // window size
    int sum = 0;

    while (ei < k)
    {
        sum = sum + nums[ei];
        if ((ei - si + 1) < k)
        {
            ei++;
        }
        else if ((ei - si + 1) == k)
        {
            if (sum == 0)
            {
                vector<int> p;
                for (int i = si; i <= ei; i++)
                {
                    p.push_back(nums[i]);
                }
                sum = sum - nums[si];
                si++;
                ei++;
                sum = sum + nums[ei];
                ans.push_back(p);
            }
            else
            {
                sum = sum - nums[si];
                si++;
                ei++;
                sum = sum + nums[ei];
            }
        }
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
    vector<vector<int> > ans = threeSum(nums);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;ans[i].size();i++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}