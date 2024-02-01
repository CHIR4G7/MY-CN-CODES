#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <cctype>
using namespace std;

bool detectcapitaluse(string word)
{
    int n = word.length();

    bool c1 = true;
    bool c2 = true;
    bool c3 = true;

    // c-1
    for (int i = 0; i < n; i++)
    {
        if (isupper(word[i]) == false)
        {
            c1 = false;
            break;
        }
    }
    if (c1 == true)
    {
        return true;
    }

    // c-2
    for (int i = 0; i < n; i++)
    {
        if (islower(word[i]) == false)
        {
            c2 = false;
            break;
        }
    }
    if (c2 == true)
    {
        return true;
    }

    // c3
    if (isupper(word[0]) == false)
    {
        c3 = false;
    }
    if (c3 == true)
    {
        for (int i = 1; i < n; i++)
        {
            if (islower(word[i]) == false)
            {
                c3 = false;
                break;
            }
        }
    }
    if (c3 == true)
    {
        return true;
    }
    return false;
}

int main()
{
    string s;
    cin >> s;

    cout << detectcapitaluse(s) << endl;
}