#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int canCompleteCircuit(vector<int> &gas,vector<int> &cost)
{
    //find a poisition to start
    int current = 0;
    int start = 0;
    int total_gas = 0;
    int total_fuel = 0;
    int n = gas.size();

    for(int i=0;i<n;i++)
    {
        total_fuel+=cost[i];
        total_gas+=gas[i];
    }

    if(total_gas < total_fuel)
    {
        return -1;
    }

    for(int i=0;i<n;i++)
    {
        current+=(gas[i]-cost[i]);
        if(current<0)
        {
            start = i+1;
            current = 0;
        }   
    }
    return start;
}
 
int main()
{
    int n;
    cin >> n;

    vector<int> gas;
    vector<int> cost;

    for(int i=0;i<n;i++)
    {
        int g,c;
        cin >> g >> c;

        gas[i] = g;
        cost[i] = c;
    }

    cout << canCompleteCircuit(gas,cost);
}
