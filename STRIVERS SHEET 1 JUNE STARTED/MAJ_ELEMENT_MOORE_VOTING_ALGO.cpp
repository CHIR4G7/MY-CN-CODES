#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int Majority_ele(vector<int> &nums)
{
    int n = nums.size();

    // MOORE'S VOTING ALGORITHM
    int element = nums[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == element)
        {
            count++;
        }
        else if (nums[i] != element && count != 0)
        {
            count--;
        }
        else if (nums[i] != element && count == 0)
        {
            element = nums[i];
            count = 1;
        }
    }
    // we have our potential candiadte for the majority element. now just confirm that its occurence are greater than [n/2]..
    int majCount = n / 2;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == element)
        {
            c++;
        }
    }
    if (c >= majCount)
    {
        return element;
    }
    return -1;
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

    int majorityEle = Majority_ele(nums);
    cout << majorityEle;
}