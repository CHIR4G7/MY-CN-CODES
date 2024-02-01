#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool check(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9')
        {
            return true;
            // for (int j = i + 1; j < s.length(); i++)
            // {
            //     if (s[j] < 33 || s[j] > 126)
            //     {
            //         return false;
            //     }
            // }
            // return true;
        }
    }
    return false;
}

int main()
{
    string s;
    getline(cin, s);

    if (check(s))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}