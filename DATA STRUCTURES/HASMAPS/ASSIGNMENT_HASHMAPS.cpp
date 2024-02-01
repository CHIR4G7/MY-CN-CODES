#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
using namespace std;

string uniquechar(string str)
{
    unordered_map<char, int> map;
    string s;

    for (int i = 0; i < str.length(); i++)
    {
        if (map.count(str[i]) == 0)
        {
            map[str[i]]++;
            s = s + str[i];
        }
    }

    return s;
}

vector<int> long_cons_seq(vector<int> v)
{
    unordered_map<int, int> map;
    for (int i = 0; i < v.size(); i++)
    {
        if (map.count(v[i]) == 0)
        {
            map[v[i]] = 1;
        }
        else
        {
            map[v[i]]++;
        }
    }

    int count = 0;
    int l = 0, h = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if(map.count(v[i]+1)==0)
        {
            continue;
        }
        else
        {
            l = 
        }
    }
}

int main()
{
    // string c;
    // cin >> c;
    // cout << c << endl;

    // cout << uniquechar(c) << endl;

    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
}