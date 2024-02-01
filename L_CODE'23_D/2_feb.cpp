#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>
using namespace std;

bool comparator(string &s1, string &s2, unordered_map<char, int> &map) // true-s1 comes first, false-s2 comes first
{
    if(s1==s2)
    {
        return true;
    }
    else
    {
    int i = 0;
    int j = 0;
    while (i < s1.length() && j < s2.length())
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
            continue;
        }
        else
        {
            if (map[s1[i]] < map[s2[j]])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    if (s1.length() < s2.length())
    {
        return true;
    }
    else
    {
        return false;
    }
    }
}

bool is(vector<string> &words, string &order)
{
    unordered_map<char, int> map;
    for (int i = 0; i < order.length(); i++)
    {
        map[order[i]] = (i + 1);
    }

    int i = 0;
    int j = 1;
    while (j < words.size() && i < words.size())
    {
        if (comparator(words[i], words[j], map)==false)
        {
           return false;
        }
        i++;
        j++;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    vector<string> words;
    for (int i = 0; i < n; i++)
    {
       
        string st;
        cin >> st;
        words.push_back(st);
    }

    string order;
    cin >> order;

   
    cout << is(words,order);
    // unordered_map<char, int> map;
    // for (int i = 0; i < order.length(); i++)
    // {
    //     map[order[i]] = (i + 1);
    // }

    // cout << comparator(s1, s2, map);
    // for(auto i : map)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
}