#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int bs(vector<int> &a,int &key)
{
   
    int n = a.size();
    int si = 0;
    int ei = n-1;
    int mid = (si+ei)/2;

    while(si<=ei)
    {
        mid = (si+ei)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        if(a[si]<a[mid])//left sorted
        {
            if(key>=a[si] && key<a[mid])
            {
                ei = mid-1;
            }
            else
            {
                si = mid+1;
            }
        }
        else//right sorted
        {
            if(key>a[mid] && key<=a[ei])
            {
                si = mid+1;
            }
            else
            {
                ei = mid-1;
            }
        }
    }
    return -1;
}
 
int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int key;
    cin >> key;

    int index = bs(a,key);
    cout << index;
}