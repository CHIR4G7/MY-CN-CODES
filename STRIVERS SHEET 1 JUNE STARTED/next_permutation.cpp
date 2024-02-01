#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <cmath>
using namespace std;

vector<int> nextPerm(vector<int> &a)
{
    int n = a.size();

    int k = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1] && i > k)
        {
            k = i;
        }
    }

    if (k == -1)
    {
        sort(a.begin(), a.end());
        return a;
    }
    else
    {
        for (int i = n - 1; i >= k; i--)
        {
            if(a[i]>a[k])
            {
                swap(a[i],a[k]);
                break;
            }
        }
    }
    sort(a.begin()+k+1,a.end());
    return a;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> ans = nextPerm(a);
    for(int i=0;i<n;i++)
    {
        cout << ans[i] << " ";
    }
}