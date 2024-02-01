#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int pairSum(vector<int> a, int n)
{
    unordered_map<int, int> map; // isme ham frequqncy of element store karengd
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (map.count(a[i]) == 0)
        {
            map[a[i]] = 1;
        }
        else
        {
            map[a[i]] += 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int k = a[i];
        int m = (-1) * a[i];

        count = count + (map[k] * map[m]);
        map[k] = 0;
        map[m] = 0;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        a.push_back(c);
    }
    cout << pairSum(a, n);
}