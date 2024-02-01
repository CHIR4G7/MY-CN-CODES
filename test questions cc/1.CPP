#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc>0)
    {
    int n;
    cin >> n;

    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int k;
    cin >> k;

    int *b = new int[k];
    for (int i = 0; i < k; i++)
    {
        cin >> b[i];
    }

    int *count = new int[n];
    for (int i = 0; i < n; i++)
    {
        count[a[i] - 1]++;
    }
    for (int i = 0; i < k; i++)
    {
        count[b[i] - 1]++;
    }

    delete []a;
    delete []b;
    delete []count;
    tc--;
    }
}