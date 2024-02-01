#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool cmp(vector<int> v1,vector<int> v2)
{
    return v1[1] > v2[1];
}

int solve(int index,vector<vector<int> >& a)
{
    if(index<0)
    {
        return 0;
    }
    int nottake = solve(index-1,a);
    int take = INT_MIN;
   
    if(index==a.size()-1 || (index!=a.size()-1 && a[index][1]<a[index+1][0]))
    {
        take = a[index][2] + solve(index-1,a);
    }
    return max(nottake,take);
}
 
int main()
{
    int n;
    cin >> n;

    vector<vector<int> > a(n,vector<int>(3));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> a[i][j];
        }
    }
    sort(a.begin(),a.end(),cmp);
    // for(int i=0;i<n;i++)
    // {
    //     cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl;
    // }
    // cout << endl;
    cout << solve(n-1,a);

    // int ans = solve(0,a);
}