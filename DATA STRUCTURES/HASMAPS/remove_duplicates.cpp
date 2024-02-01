#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

vector<int> removeduplicates(vector<int> a)
{
    int size = a.size();
    vector<int> output;
    unordered_map<int, bool> seen;

    for (int i = 0; i < size; i++)
    {
        if (seen.count(a[i]) > 0)
        {
            continue;
        }
        seen[a[i]] = true;
        output.push_back(a[i]);
    }
    return output;
}

int main()
{
    vector<int> p;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        p.push_back(a);
    }

    vector<int> output = removeduplicates(p);
    for(int i=0;i<output.size();i++)
    {
        cout << output[i] << " ";
    }
}