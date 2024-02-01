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

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    queue<int> st;
    for(int i=0;i<n-1;i++)
    {
        st.push(arr[i]);
    }

    arr[0] = arr[n-1];

    for(int i=1;i<n;i++)
    {
        int d = st.front();
        st.pop();
        arr[i] = d;
    }
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }

}