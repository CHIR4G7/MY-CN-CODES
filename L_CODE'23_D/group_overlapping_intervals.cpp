#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int> > ranges;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        int a, b;
        cin >> a >> b;
        v.push_back(a);
        v.push_back(b);
        ranges.push_back(v);
    }

    sort(ranges.begin(), ranges.end());
    // for(int i=0;i<n;i++)
    // {
    //     cout << ranges[i][0] << " " << ranges[i][1] << endl;
    // }
    unordered_map<int, bool> map;
    for (int i = 0; i < n - 1; i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ranges[i][1]>ranges[j][0])
            {
                map[i] = true;
                map[j] = true;
            }
        }
    }
    cout << map.size();

}