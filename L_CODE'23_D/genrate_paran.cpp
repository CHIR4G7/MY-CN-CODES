#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stack>
using namespace std;

unordered_map<string,bool> map;

bool valid(string &s)
{
    stack<char> st;
    int i = 0;
    int n = s.length();

    while(i<n)
    {
        if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(st.empty())
            {
                return false;
            }
            st.pop();
        }
        i++;
    }
    if(!st.empty())
    {
        return false;
    }
    return true;
}

void helper(string &s,vector<string> &paran,string &ds,vector<bool> &freq)
{
    if(ds.size()==s.length() && (map.find(ds)==map.end()))
    {
        if(valid(ds))
        {
            paran.push_back(ds);
            map[ds] = true;
            return;
        }
    }
    for(int i=0;i<s.length();i++)
    {
        if(freq[i]==false)
        {
            ds.push_back(s[i]);
            freq[i] = true;
            helper(s,paran,ds,freq);
            ds.pop_back();
            freq[i] = false;
        }
    }
}

void generate(string &s,vector<string> &paran)
{
    string ds = "";
    vector<bool> freq(s.length(),false);
    helper(s,paran,ds,freq);
}
 
int main()
{
    int n;
    cin >> n;

    string s="";
    for(int i=0;i<(2*n);i++)
    {
        if(i%2==0)
        {
            s+='(';
        }
        else
        {
            s+=')';
        }
    }
 
    vector<string> paran;
    generate(s,paran);
    for(int i=0;i<paran.size();i++)
    {
        cout << paran[i] << endl;
    }
    cout << valid(s) << endl;
}