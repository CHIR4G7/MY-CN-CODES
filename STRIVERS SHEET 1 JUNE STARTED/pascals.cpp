#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
 
int main()
{
    int numrows;
    cin >> numrows;

    vector<vector<int> > ans(numrows);
    for(int i=0;i<numrows;i++)
    {
        ans[i].resize(i+1,1);
        //this j will iterate over every new row that is being created.
        //1 st aur last index of every row par to 1 hi rahega na isliye unke beech ke indexes pr iterate kiya.
        for(int j=1;j<i;j++)
        {
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }

    for(int i=0;i<numrows;i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}