#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int solve(int i,int j,vector<int> &n1,vector<int> &n2)
{
    if(i==n1.size() || j==n2.size())
    {
        return 0;
    }
    
}

int maxCrossedLine(vector<int> &n1,vector<int> &n2)
{
    
}
 
int main()
{
    int n,m;
    cin >> n >> m;

    vector<int> n1(n);
    for(int i=0;i<n;i++)
    {
        cin >> n1[i];
    }

    vector<int> n2(m);
    for(int i=0;i<m;i++)
    {
        cin >> n2[i];
    }

    cout << maxCrossedLine(n1,n2);
}