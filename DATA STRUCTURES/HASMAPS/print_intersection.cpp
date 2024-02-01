#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

void printintersection(vector<int> arr1, int n, vector<int> arr2, int m)
{
    unordered_map<int, int> map_arr1;
    for (int i = 0; i < n; i++)
    {
        if (map_arr1.count(arr1[i]) == 0)
        {
            map_arr1[arr1[i]] = 1;
        }
        else
        {
            map_arr1[arr1[i]] += 1;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (map_arr1.count(arr2[i]) == 1)
        {
            while (map_arr1[arr2[i]] > 0)
            {
                cout << arr2[i] << endl;
                map_arr1[arr2[i]] -= 1;
            }
        }
        else
        {
            continue;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr1;

    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        arr1.push_back(c);
    }

    int m;
    cin >> m;

    vector<int> arr2;

    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;
        arr2.push_back(c);
    }

    printintersection(arr1, n, arr2, m);
}