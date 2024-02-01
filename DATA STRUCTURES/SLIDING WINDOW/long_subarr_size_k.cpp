// variable size sliding window(positive numbers only )
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int main()
{
    int arr[] = {4, 1, 1, 1, 2, 3, 5};
    int si = 0;
    int ei = 0;
    int k;
    cin >> k;

    long long int sum = 0;
    int maxi = 0;
    while (ei < 7)
    {
        sum = sum + arr[ei]; // calculations
        if (sum < k)
        {
            ei++;
        }
        else if (sum == k)
        {
            maxi = max(maxi, (ei - si + 1));
            ei++;
        }
        if (sum > k)
        {
            while(sum>k)
            {
                sum = sum - arr[si];
                si++;
            }
            ei++;
        }
    }
    cout << maxi << endl;
}