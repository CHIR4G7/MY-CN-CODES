#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int f(vector<int> &people,int limits)
{
    sort(people.begin(),people.end());
    int si = 0;
    int ei = 0;

    int boats = 0;
    int weight = 0;

    int n = people.size();
    while(ei<n)
    {
        weight+=people[ei];
        if(weight<limits)
        {
            ei++;
        }
        else if(weight==limits)
        {
            boats++;
            si = ei+1;
            ei = si;
        }
        else
        {
            while(weight>limits)
            {
                weight-=people[ei];
                ei--;
            }
            boats++;
        }
    }
    return boats;
}
 
int main()
{
    int n;
    cin >> n;

    vector<int> people;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        people.push_back(a);
    }
    int limit;
    cin >> limit;

    cout << f(people,limit);
}