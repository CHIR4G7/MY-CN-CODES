#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stack>
using namespace std;
 
vector<int> stockspan(vector<int> &a)
{
    stack<pair<int,int> > s;
    vector<int > ans;

    for(int i=0;i<a.size();i++)
    {
        int days = 1;
        while(s.empty()==false && s.top().first<a[i])
        {
            days+= s.top().second;
            s.pop();
        }
        s.push({a[i],days});
        ans.push_back(days);
    }
    return ans;
}

int main()
{
    vector<int> a = {100,80,60,70,60,75,85};

    vector<int> res = stockspan(a);
    for(int i=0;i<res.size();i++)
    {
        cout << res[i] << " ";
    }

}