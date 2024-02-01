#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;
 
int main()
{

    //TAKING INPUTS
    int n;
    cin >> n;

    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int v;
        cin >> v;
        a.push_back(v);
    }
    vector<int> b;
    for(int i=0;i<n;i++)
    {
        int v;
        cin >> v;
        b.push_back(v);
    }

    //STORING IN PRIORITY QUEUES
    
    //MAX PQ FOR A
    priority_queue<int> p_a;
    for(int i=0;i<n;i++)
    {
        p_a.push(a[i]);
    }
    priority_queue<int, vector<int>, greater<int> > p_b;
    for(int i=0;i<n;i++)
    {
        p_b.push(b[i]);
    }

    //now performing operations
    while(p_a.top()>p_b.top())
    {
        int x = p_a.top();
        int y = p_b.top();
        p_a.pop();
        p_a.push(y);
        p_b.pop();
        p_b.push(x);
    }

    vector<int> ans;
    while(p_a.empty()==false)
    {
        ans.push_back(p_a.top());
        p_a.pop();
    }

    int max = *max_element(ans.begin(),ans.end());
    int min = *min_element(ans.begin(),ans.end());
    cout << max-min << endl;
  
}
