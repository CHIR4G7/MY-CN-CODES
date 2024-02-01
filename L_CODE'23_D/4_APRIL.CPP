#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
int main()
{
    string s;
    cin >> s;

    int count = 0;
    unordered_set<char> map;
    int si = 0;
    int ei = 0;

    while(ei<s.length())
    {
        if(map.find(s[ei])==map.end())//element not in set
        {
            map.insert(s[ei]);
        }
        else
        {
            count+=1;
            while(map.find(s[ei])==map.end())
            {
                map.erase(s[si]);
                si++;
            }
        }
        ei++;
    }
    cout << count << endl;
}
