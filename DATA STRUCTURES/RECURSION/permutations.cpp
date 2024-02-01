#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool checkequal(vector<int> a,vector<int> b)
{
    for(int i=0;i<26;i++)
    {
        if(a[i]!=b[i])
        {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1,string s2)
{
    if(s2.length()<s1.length())
    {
        return false;
    }
    vector<int> freq_s1(26,0);
    for(int i=0;i<s1.length();i++)
    {
        freq_s1[s1[i]-'a']++;
    }

    vector<int> freq_s2(26,0);
    int si = 0;
    int ei = 0;

    while(ei<s2.length())
    {
        freq_s2[s2[ei]-'a']++;
        
        if((ei-si+1)==s1.length())
        {
            if(checkequal(freq_s1,freq_s2)==true)
            {
                return true;
            }
        }

        if((ei-si+1)<s1.length())
        {
            ei++;
        }
        else
        {
            freq_s2[s2[si]-'a']--;
            si++;
            ei++;
        }
    }
    return false;
}
 
int main()
{
    string s1;
    cin >> s1;

    string s2;
    cin >> s2;

    cout << checkInclusion(s1,s2);
}