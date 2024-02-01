#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int countPaths(int i, int j, int m, int n,vector<vector<int> > &dp)
{
    if (i == (m - 1) && j == (n - 1))
    {
        return 1;
    }
    if (i >= m || j >= n)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    return dp[i][j] = countPaths(i + 1, j, m, n,dp) + countPaths(i, j + 1, m, n,dp);
}



int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int> > dp(m,vector<int>(n,-1));

    int paths = countPaths(0, 0, m, n,dp);
    cout << paths;
}