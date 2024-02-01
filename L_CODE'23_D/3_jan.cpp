#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int minDeletionsize(vector<string> &strs)
{
    int n = strs.size(); // number of strings;
    int m = strs[0].length();//size of each string;(all of them of same size)
    vector<vector<char> > v;

//creating a 2-D vector so that i can traverse column by column;
    for (int i = 0; i < n; i++)
    {
        string s = strs[i];
        vector<char> c;
        for (int i = 0; i < s.length(); i++)
        {
            c.push_back(s[i]);
        }
        v.push_back(c);
    }

    //now maintaining a count of non-lexographically sorted columns;
    int count = 0;
    bool isLexo = true;
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n-1;i++)
        {
            if(v[i][j] > v[i+1][j])//if there re not lexographically increasing then make is lexo false and break out of that row loop and traversing it further is useless.
            {
                isLexo = false;
                break;
            }
        }
        if(isLexo==false)//if is lexo false for a column then increase count corresponding tot hat column and again make islexo true for the next iteration of column.
        {
            count++;
            isLexo = true;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    vector<string> strs;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        strs.push_back(s);
    }

    // int n = strs.size(); // number of strings;
    int m = strs[0].length();
    vector<vector<char> > v;

    for (int i = 0; i < n; i++)
    {
        string s = strs[i];
        vector<char> c;
        for (int i = 0; i < s.length(); i++)
        {
            c.push_back(s[i]);
        }
        v.push_back(c);
    }

    cout << minDeletionsize(strs) << endl;
   
}