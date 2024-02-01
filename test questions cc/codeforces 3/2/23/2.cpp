#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool checker(string s, int n)
{
    // initial coordinates
    int x = 0;
    int y = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'U')
        {
            y++;
        }
        else if (s[i] == 'D')
        {
            y--;
        }
        else if (s[i] == 'L')
        {
            x--;
        }
        else if (s[i] == 'R')
        {
            x++;
        }

        // check
        if (x == 1 && y == 1)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s = "";
        for (int i = 0; i < n; i++)
        {
            char c;
            cin >> c;
            s = s + c;
        }

        if (checker(s, n) == true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}