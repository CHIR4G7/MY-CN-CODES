#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;

void findMedian(int arr[],int n)
{
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
        if((i+1)%2==0)
        {
            cout << 
        }
        else
        {

        }
    }
}
 
int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    findMedian(arr,n);
}