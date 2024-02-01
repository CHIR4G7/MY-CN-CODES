#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int highestFrequency(vector<int> a)
{
    unordered_map<int, int> map;
    int max = 0;
    int index = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if(map.count(a[i]) == 0)
        {
            map[a[i]] = 1;
        }
        else
        {
            map[a[i]] += 1;
            if(max <= map[a[i]])
            {
                max = map[a[i]];
                index = i;

            }
        }
    }
    return a[index];
}

int main()
{
    vector<int> a;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        a.push_back(c);
    }
    cout << highestFrequency(a);
}