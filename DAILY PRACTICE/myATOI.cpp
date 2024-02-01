#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

string reverse(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    return s;
}

int myAtoi(string s)
{
    int place = 1;
    int ans = 0;
    string s1 = reverse(s);
    for (int i = 0; i < s1.length(); i++)
    {
        ans = ans + place * s1[i];
        place = place * 10;
        if (s1[i] == '-')
        {
            ans = ans * (-1);
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << s << endl;
    // cout << myAtoi(s);
    int place = 1;
    int ans = 0;
    string s1 = reverse(s);

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != '-')
        {
            ans = ans + place * (s1[i] - '0');
            place = place * 10;
        }
        else
        {
            ans = ans * (-1);
        }
    }
    cout << ans;
}