#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;
 
int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }
    int p,q,r;
    cin >> p >> q >> r;

    vector<int> p1;
    p1.push_back(nums[0]);

    vector<int> p2;
    for(int i=2;i<n;i++)
    {
        p2.push_back(nums[i]);
    }
    

    int ans = INT_MIN;

    for(int i=1;i<=n-2;i++)
    {
        int pmax = *max_element(p1.begin(),p1.end());
        int smax = *max_element(p2.begin()+i-1,p2.end());

        int x = ((p*pmax)+(q*nums[i])+(r*smax));
        ans = max(ans,x);
        p1.push_back(nums[i]);
    }
    cout << ans;
}