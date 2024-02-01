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

    vector<vector<int> > forces;
    for(int i=0;i<n;i++)
    {
        vector<int> p;
        for(int j=0;j<3;j++)
        {
            int a;
            cin >> a;
            p.push_back(a);
        }
        forces.push_back(p);
    }

    bool eq = true;

    for(int i=0;i<3;i++)
    {
        int sum = 0;
        for(int j=0;j<n;j++)
        {
            sum+=forces[j][i];
        }
        if(sum!=0)
        {
            eq = false;
            break;
        }
    }
    if(eq==true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}