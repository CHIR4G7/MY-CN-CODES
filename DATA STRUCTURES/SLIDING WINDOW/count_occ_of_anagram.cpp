#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int count(string s, string pat)
{
    int k = pat.length(); // window size
    int si = 0;
    int ei = 0;
    unordered_map<char, int> map;
    for (int i = 0; i < k; i++)
    {
        map[pat[i]]++;
    }
    int ms = map.size();
    int counts = 0;

    while (ei < s.length())
    {
        map[s[ei]]--;
        if ((ei - si + 1) < k)
        {
            ei++;
        }
        else if ((ei - si + 1) == k)
        {
            
        }
    }
}

int main()
{
    string s;
    cin >> s;

    string pat;
    cin >> pat;
}