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

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            sum+=a[i]/2;
        }
        else
        {
            a[i + 1] += a[i] / 2;
            a[i] %= 2;
            sum+=a[i];
        }
    }
    cout << sum;
}