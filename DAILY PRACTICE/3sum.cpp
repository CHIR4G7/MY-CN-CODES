#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    // first sort it
    vector<vector<int> >ans;
    sort(nums.begin(),nums.end());

    for(int i=0;i<nums.size()-2;i++)//one value fixed now use two pointer.
    {
        if(i==0 || nums[i-1]!=nums[i])
        {
            int low = i+1;
            int high = nums.size()-1;
            int sum = -nums[i];
        }
    }

}

int main()
{
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }
}