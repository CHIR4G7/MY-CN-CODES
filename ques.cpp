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

    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        string s = arr[i];
        int x = 0;
        for (int j = 0; j < s.length(); j++)
        {
            x = x || (1 << (s[j] - 'a'));
        }
        nums[i] = x;
    }

    for(int i=0;i<n;i++)
    {
        cout << nums[i] << " ";
    }
}