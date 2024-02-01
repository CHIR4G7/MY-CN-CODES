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

    int rem_length = (n);
    int i = 0;
    int jumps = 0;
    while(rem_length>0)
    {
        if(arr[i]==0)
        {
            return -1;
        }

        i = i + arr[i];
        rem_length = rem_length - i;
        jumps++;
    }
    cout << jumps;
}