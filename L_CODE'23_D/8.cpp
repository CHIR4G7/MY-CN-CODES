#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <list>
#include <limits.h>
using namespace std;

int maxPoints(vector<vector<int> > &points)
{
    int n = points.size();

    unordered_map<pair<double, double>, list<vector<int> > > lines;
    // map me first pe honge (m,c) ka pair, aur second me points ka array jo us line ko satisfy kr rhe
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }

            if ((points[j][1] - points[i][1]) == 0) // parallel to x
            {
                pair<double, double> x;
                x.first = 0;
                x.second = (1.0) * points[j][1];
                lines[x].push_back(points[i]);
                lines[x].push_back(points[j]);
            }
            else if ((points[j][0] - points[i][0]) == 0)
            {
                pair<int, int> y;
                y.first = INT_MAX;
                y.second = (1.0) * points[j][0];
                lines[y].push_back(points[i]);
                lines[y].push_back(points[j]);
            }
            else
            {
                double m = (1.0) * (points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                double c = (1.0) * (((1.0) * (points[j][1])) - ((1.0) * (m) * (points[j][0])));

                pair<double, double> n;
                n.first = m;
                n.second = c;
                lines[n].push_back(points[i]);
                lines[n].push_back(points[j]);
            }
        }
    }

    int max = 0;

    for(auto i : lines)
    {
        int size = i.second.size();
        if(size>max)
        {
            max = size;
        }
    }
    return max;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int> > points;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < 2; j++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        points.push_back(v);
    }

   
}