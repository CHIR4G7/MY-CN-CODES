#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <map>
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


vector<int> findAnagrams(string s, string p)
{
    vector<int> indexes;
    if(p.length()>s.length())
    {
        return indexes;
    }

    vector<int> freq1(26,0);//stroing the frequency of the string p.
    for(int i=0;i<p.length();i++)
    {
        freq1[p[i]-'a']++;
    }


    vector<int> freq2(26,0);
    int si=0;
    int ei=0;

    while(ei<s.length())
    {
        freq2[s[ei]-'a']++;
        if((ei-si+1)==p.length())
        {
            if(checkequal(freq1,freq2)==true)
            {
                indexes.push_back(si);
            }
        }
        if((ei-si+1)<p.length())
        {
            ei++;
        }
        else
        {
            freq2[s[si]-'a']--;
            si++;
            ei++;
        }
    }
    return indexes;
}

int main()
{
    string s;
    cin >> s;

    string p;
    cin >> p;

    for(int i=0;i<findAnagrams(s,p).size();i++)
    {
        cout << findAnagrams(s,p)[i] << " ";
    }
}