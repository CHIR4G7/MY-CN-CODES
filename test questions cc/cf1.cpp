#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
using namespace std;

int point(char c)
{
    if (c == 'S')
    {
        return 0;
    }
    else if (c == 'M')
    {
        return 1;
    }
    else if (c == 'L')
    {
        return 2;
    }
}

int main()
{

    int tc;
    cin >> tc;

    while (tc--)
    {
        string s, t;
        cin >> s >> t;

        int count = 0;
        // check the last char;
        int len_s = s.length();
        int len_t = t.length();

        if (s[len_s - 1] != t[len_t - 1])
        {
            char c1 = s[len_s - 1];
            char c2 = t[len_t - 1];

            if (point(c1) > point(c2))
            {
                cout << ">" << endl;
            }
            else if (point(c1) < point(c2))
            {
                cout << "<" << endl;
            }
        }
        else
        {
            int count1 = 0;
            if (s[len_s - 1] == 'S')
            {
                count1 = ((-1) * (len_s - 2));
            }
            else if (s[len_s - 1] == 'L')
            {
                count1 = (len_s - 2);
            }

            int count2 = 0;
            if (t[len_t - 1] == 'S')
            {
                count2 = ((-1) * (len_t - 2));
            }
            else if (t[len_t - 1] == 'L')
            {
                count2 = (len_t - 2);
            }

            if (count1 > count2)
            {
                cout << ">" << endl;
            }
            else if (count1 < count2)
            {
                cout << "<" << endl;
            }
            else
            {
                cout << "=" << endl;
            }
        }
    }
}