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

    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
    }
    int k ;
    cin >> k;

    vector<int> masks;
    for(auto it : v)
    {
        int mask = 0;
        for(auto i : it)
        {
            int k = i-'a';
            mask = mask|(1<<k);
        }
        masks.push_back(mask);
        // cout << mask << endl;
    }

    int maxCount = 0;
    for(int bitmasks = 0;bitmasks<(1<<10);bitmasks++)
    {
        if(__builtin_popcount(bitmasks)<=k)
        {
            int count = 0;
            for(int i=0;i<n;i++)
            {
                if((masks[i]&bitmasks)==masks[i])
                {
                    count++;
                }
            }
            maxCount = max(maxCount,count);
        }
        
    }
    cout << maxCount;
}