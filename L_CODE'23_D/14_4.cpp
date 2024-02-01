#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stack>
using namespace std;

bool validate(vector<int> &pushed, vector<int> &popped)
{
    stack<int> s;
    int j = 0;

    for (int i = 0; i < pushed.size(); i++)
    {
        s.push(pushed[i]);
        if (!s.empty() && popped[j] == s.top() && j<popped.size()) 
        {
            s.pop();
            j++;
        }
    }
    return j==popped.size();
    
}

int main()
{
    int n;
    cin >> n;

    vector<int> pushed;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pushed.push_back(a);
    }

    vector<int> popped;
    for (int j = 0; j < n; j++)
    {
        int a;
        cin >> a;
        popped.push_back(a);
    }

    cout << validate(pushed,popped);
}