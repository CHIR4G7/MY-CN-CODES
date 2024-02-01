#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <limits.h>
using namespace std;

int maxIceCream(vector<int> &costs,int coins)
{
    int n = costs.size();
    int icecream = 0;

    while(icecream<=n && costs[icecream]<=coins)
    {
        coins-=costs[icecream];
        icecream++;
    }
    return icecream;
}
 
int main()
{
    int n_icecreams;
    cin >> n_icecreams;

    vector<int> costs;
    for(int i=0;i<n_icecreams;i++)
    {
        int a;
        cin >> a;
        costs.push_back(a);
    }
    int coins;
    cin >> coins;

    cout << maxIceCream(costs,coins) << "\0";
}