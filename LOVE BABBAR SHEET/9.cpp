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

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    sort(arr,arr+n);
    int diff = arr[n-1] - arr[0];

    int maxi = arr[n-1];
    int mini = arr[0];
    for(int i=1;i<n;i++)
    {
        maxi = max(arr[i-1]+k,arr[n-1]-k);
        mini = min(arr[0]+k,arr[i]-k);

        diff = min(diff,maxi-mini);
    }
    cout << diff;
}