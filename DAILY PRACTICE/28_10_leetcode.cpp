#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int maxA(vector<int> &height)
{
    vector<pair<int, int>> l_b;
    for (int i = 0; i < height.size(); i++)
    {
        pair<int, int> p;
        p.first = height[i];
        p.second = i;
        l_b.push_back(p);
    }

    for (int i = l_b.size() - 1; i >= 0; i++)
    {
        
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> height;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        height.push_back(a);
    }

    vector<pair<int, int>> l_b;
    for (int i = 0; i < height.size(); i++)
    {
        pair<int, int> p;
        p.first = height[i];
        p.second = i;
        l_b.push_back(p);
    }

    sort(l_b.begin(), l_b.end());

    for (int i = 0; i < l_b.size(); i++)
    {
        cout << l_b[i].first << " " << l_b[i].second << endl;
    }
}