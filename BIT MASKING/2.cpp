#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
 
int main()
{
    int n,l,r,x;
    cin >> n >> l >> r >> x;

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
  
  
  int count = 0;

    for(int i=0;i<(1<<n);i++)
    {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int total = 0;
        for(int j=0;j<n;j++)
        {
            if((i&(1<<j))==0)
            {
                if(a[j]>maxi)
                {
                    maxi = a[j];
                }
                if(a[j]<mini)
                {
                    mini = a[j];
                }
                total+=a[j];
            }
        }
        if((maxi-mini)>=x && total>=l && total<=r)
        {
            count++;
        }
    }
    cout << count << endl;
}