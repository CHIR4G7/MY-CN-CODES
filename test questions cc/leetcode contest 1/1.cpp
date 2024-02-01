#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

long long find(vector<int> &nums, int lower, int upper)
{
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
    int lower, upper;
    cin >> lower >> upper;
    long long count = 0;

    map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]--;
        if (map[nums[i]] == 0)
        {
            map.erase(nums[i]);
        }

        int x = lower - nums[i];
        int y = upper - nums[i];

        for (auto i : map)
        {
            if (i.first >= x && i.first <= y)
            {

                count += i.second;
            }
        }
    }
    cout << count;
}