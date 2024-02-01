#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s)
    {
        int count=0;
        int si = 0;
        int max = 0;
        int len = s.length();
        unordered_map<char,int> map;
        
        while(si<len)
        {
            for(int i=si;i<len;i++)
            {
                if(map.count(s[i])==0)
                {
                    count++;
                    // map[s[i]] = 1;
                }
                else
                {
                    if(max<count)
                    {
                        max = count;
                    }
                    count = 0;
                    // map.clear();
                    si = i;
                    break;
                }
            }
        }
    }
 
int main()
{
	string s;
	cin >> s;

	cout << lengthOfLongestSubstring(s) << endl;

}