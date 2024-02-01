#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>
using namespace std;

void helper(string s,set<string> &ans,int index,string ds)
{
    if(index==s.length())
    {
        ans.insert(ds);
        return;
    }

    if(s[index]-'0'>=0 && s[index]-'0'<=9)
    {
        helper(s,ans,index+1,ds+s[index]);
    }

    char u = toupper(s[index]);
    char l = tolower(s[index]);
    helper(s,ans,index+1,ds+l);
    helper(s,ans,index+1,ds+u);
}

void allStrings(string s,vector<string> &p)
{
    string ds = "";
    set<string> ans;
    helper(s,ans,0,ds);
   
    for(auto it : ans)
    {
        p.push_back(it);
    }
}
 
int main()
{
    string s;
    cin >> s;

    
    vector<string> p;
    allStrings(s,p);

    for(auto i : p)
    {
        cout << i << endl;
    }
    
}