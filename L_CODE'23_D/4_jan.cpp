#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int minimumRounds(vector<int> &tasks)
{
    map<int,int> map;
    for(int i=0;i<tasks.size();i++)
    {
        if(map.find(tasks[i])!=map.end())
        {
            map[tasks[i]]++;
        }
        else
        {
            map[tasks[i]] = 1;
        }
    }

    int count = 0;
    for(auto i : map)
    {
        if(i.second < 2)
        {
            return -1;
        }
        else
        {
           count += ((i.second+2)/3);
        }
    }
    return count;
}
 
int main()
{
    int n;
    cin >> n;

    vector<int> tasks;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        tasks.push_back(a);
    }

    cout << minimumRounds(tasks) << '\n';
}