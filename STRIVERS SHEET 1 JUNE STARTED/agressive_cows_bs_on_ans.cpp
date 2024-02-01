#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool canPlaceCows(vector<int> &a, int distance, int cows)
{
    int n = a.size();
    int cowCorrd = a[0];
    int cowsPlaced = cows - 1;

    for (int i = 1; i < n; i++)
    {
        if ((a[i] - cowCorrd) >= distance)
        {
            cowsPlaced++;
            cowCorrd = a[i];
        }
        if (cowCorrd == cows)
        {
            return true;
        }
    }
    return false;
}

int largestMinDist(vector<int> &a, int cows)
{
    int n = a.size();
    sort(a.begin(), a.end());
    int lo = 1;
    int hi = a[n - 1] - a[0]; // maximum distnace bw two cows
    int ans = -1;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (canPlaceCows(a, mid, cows) == true)
        {
            ans = mid;
            lo = mid + 1; // find argest
        }
        else
        {
            hi = mid - 1;
        }
    }
    return ans;
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

    int cows;
    cin >> cows; 

    int ans = largestMinDist(a, cows);
    cout << ans;
}