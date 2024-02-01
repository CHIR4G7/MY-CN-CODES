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
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    int si = 0; // start of window
    int ei = 0; // ending of a window
    int sum = 0;
    int max = INT16_MIN;

    // move the window while j is not equal to the size of the array
    while (ei < n)
    {
        // mera pehla task hai ki j ko vaha tk le jau jitna size mujhe subarr ki chahiye
        // uske saath saath mai sum bhi krta jaunga
        sum = sum + arr[ei];
        if ((ei - si + 1) < k)
        {
            ei++;
        }
        else if ((ei - si + 1) == k)
        {
            if (sum > max)
            {
                max = sum;
            }
            //si hata diya aur fir isko si++ krke ek block aage move kara diya.
            sum = sum - arr[si];
            si++;
            //fir ei+++ taaki aage vale ko sum me add kr sake.
            ei++;
        }
    }
    cout << max << endl;
}