#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int frindMinArrowShots(vector<vector<int> > &points)
{
    //first sort the arrayin ascending order.
    sort(points.begin(),points.end());
    int n = points.size();
    int count = 1;

    int lastPosition = points[0][1];;//target

    for(int i=0;i<n;i++)
    {
        if(points[i][0]>lastPosition)
        {
            count++;
            lastPosition = points[i][1];
        }
        else
        {
            lastPosition = min(lastPosition,points[1][1]);
        }
    }
    return count;
}
 
int main()
{
    int n;
    cin >> n;

    vector<vector<int> > points;

    for(int i=0;i<n;i++)
    {
        vector<int> v;
        for(int j=0;j<2;j++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        points.push_back(v);
    }
    cout << frindMinArrowShots(points) << endl;
}