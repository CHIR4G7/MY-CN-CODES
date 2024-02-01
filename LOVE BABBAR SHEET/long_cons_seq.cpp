#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;

int longCons(vector<int> &arr,int n)
{
    priority_queue<int,vector<int>,greater<int> > pq;
    // priority_queue<int> pq;
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
    }

    int maxc = 0;

    while(pq.size()!=0)
    {
        int t1 = pq.top();
        pq.pop();

        int count = 1;

        while(pq.size()!=0)
        {
            if(pq.top()==(t1+1))
            {
                t1 = pq.top();
                count++;
                pq.pop();
            }
            else
            {
                maxc = max(maxc,count);
                break;
            }
        }
    }
    return maxc;
}
 
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    cout << longCons(arr,n) << endl;
  
}