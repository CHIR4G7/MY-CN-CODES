#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int longestSubsnorepeat(string s)
{
    unordered_map<char,int> chars;

    int i = 0;
    int j = 0;

    int n = s.length();
    int maxl = INT_MIN;

    while(j<n)
    {
        chars[s[j]]++;
        if(chars.size()==(j-i+1))
        {
            maxl = max(maxl,(j-i+1));
        }
        else if(chars.size()<(j-i+1))
        {
            while(chars.size()<(j-i+1))
            {
                chars[s[i]]--;
                if(chars[i]==0)
                {
                    chars.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    return maxl;
}
 
int main()
{
    string s;
    cin >> s;

    int count = longestSubsnorepeat(s);
    cout << count;
}