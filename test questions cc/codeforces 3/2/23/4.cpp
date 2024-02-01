#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

// this is function returning number of distinct character of a string
int f(string s)
{
    unordered_map<char, bool> map;
    for (int i = 0; i < s.length(); i++)
    {
        map[s[i]] = true;
    }
    return map.size();
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        for (int i = 0; i < n; i++)
        {
            char c;
            cin >> c;
            s = s + c;
        }

        unordered_map<char, bool> hascome;
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (hascome[s[i]] == true)
            {
                sum = sum + f(s.substr(0, i)) + f(s.substr(i, s.length()));
                break;
            }
            hascome[s[i]] = true;
        }
        if(sum==0)
        {
            sum = s.length();
        }
        cout << sum << endl;
    }
}