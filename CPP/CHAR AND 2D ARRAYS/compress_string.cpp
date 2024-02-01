#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

string compress(string &input)
{
    if(input.length()==0)
    {
        return "";
    }
    int si = 0;
    int ei = 0;

    string out = "";
    while(si<input.length())
    {
        while((ei<input.length()) && (input[ei] == input[si]))
        {
            ei++;
        }
        int totalcharCount = ei - si;

        if(totalcharCount!=1)
        {
            out += input[si];
            out += (char)(totalcharCount+'0');
        }
        else
        {
            out+=input[si];
        }
        si = ei;
    }
    return out;
}

int main()
{
    string s;
    cin >> s;

    string ans = compress(s);
    cout << ans;
}

