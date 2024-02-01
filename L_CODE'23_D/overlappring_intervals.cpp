#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

vector<vector<int> > insert(vector<vector<int> > &intervals, vector<int> &newInterval)
{
    intervals.push_back(newInterval);
    sort(intervals.begin(),intervals.end());
    vector<vector<int> > merged;

    vector<int> tempinterval = intervals[0];

    for(auto i : intervals)
    {
        if(i[0]<=tempinterval[1])
        {
            tempinterval[1] = max(i[1],tempinterval[1]);
        }
        else
        {
            merged.push_back(tempinterval);
            tempinterval = i;
        }
    }
    merged.push_back(tempinterval);
    return merged;
}

 vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int> > merged;
        sort(intervals.begin(),intervals.end());//sort in increasing order wrt to the first index so that we can compare
        vector<int> tempinterval = intervals[0];

        //for(auto i : intervals)
        for(int i=0;i<intervals.size();i++)
        {
            // if(i[0]<=tempinterval[1])
            // {
            //     tempinterval[1] = max(i[1],tempinterval[1]);
            // }
            // else
            // {
            //     merged.push_back(tempinterval);
            //     tempinterval = i;
            // }
            if(intervals[i][0]<=tempinterval[1])
            {
                tempinterval[1] = max(intervals[i][1],tempinterval[1]);
            }
            else
            {
                merged.push_back(tempinterval);
                tempinterval = intervals[i];
            }

        }
        merged.push_back(tempinterval);
        return merged;
    }
 
int main()
{
    int n;
    cin >> n;

    vector<vector<int> > intervals;
    for(int i=0;i<n;i++)
    {
        vector<int> v;
        int a,b;
        cin >> a >> b;
        v.push_back(a);
        v.push_back(b);
        intervals.push_back(v);
    }

    vector<int> newInterval;
    for(int i=0;i<2;i++)
    {
        int a;
        cin >> a;
        newInterval.push_back(a);
    }

    vector<vector<int> > merged = insert(intervals,newInterval);
    for(int i=0;i<merged.size();i++)
    {
        cout << merged[i][0] << " " << merged[i][1] << endl;
    }
}