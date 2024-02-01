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

    unordered_map<char,bool> map;
    map['c'] = true;
    map['o'] = true;
    map['d'] = true;
    map['e'] = true;
    map['f'] = true;
    map['o'] = true;
    map['r'] = true;
    map['c'] = true;
    map['e'] = true;
    map['s'] = true;

    while(t--)
    {
        char c;
        cin >> c;

        if(map[c]==true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}