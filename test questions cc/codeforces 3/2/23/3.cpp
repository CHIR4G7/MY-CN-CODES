#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        for (int i = 0; i < n; i++)
        {
            char c;
            cin >> c;
            s = s + c;
        }

        int i = 0;
        int j = s.length() - 1;
        int l = s.length();

        while (i < j)
        {
            if (s[i] == s[j])
            {
                break;
            }
            else
            {
                i++;
                j--;
                l -= 2;
            }
        }
        cout << l << endl;
    }
}