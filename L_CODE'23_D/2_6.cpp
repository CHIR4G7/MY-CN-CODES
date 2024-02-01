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

    vector<vector<int> > bombs(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        vector<int> v(3);
        for (int j = 0; j < 3; j++)
        {
            cin >> v[i];
        }
        bombs.push_back(v);
    }

    vector<vector<int> > adjlist(n);
    
}