#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int main()
{
    string s, chars;
    cin >> s >> chars;

    int n = chars.length();
    vector<int> vals;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vals.push_back(a);
    }
    unordered_map<char, int> map;
    for (int i = 0; i < chars.size(); i++)
    {
        map[chars[i]] = vals[i];
    }
    vector<int> nums(s.length(), 0);
    for (int i = 0; i < s.length(); i++)
    {
        if (map.find(s[i]) != map.end())
        {
            nums[i] = map[s[i]];
        }
        else
        {
            int k = s[i];
            nums[i] = (k-96);
        }
    }
    for(int i=0;i<nums.size();i++)
    {
        cout << nums[i] << " ";
    }
}