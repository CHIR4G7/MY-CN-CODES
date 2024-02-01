#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> ksmallest(int arr[], int n, int k)
{
    
    priority_queue<int > pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    

    vector<int> ans;
    while (pq.size() != 0)
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    vector<int> ans;
    ans = ksmallest(arr,n,k);
    for(int i=0;i<k;i++)
    {
        cout << ans[i] << " ";
    }
}