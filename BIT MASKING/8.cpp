#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int solve(int index,string s,vector<int>& dp)
{
    if(index<s.length() && s[index]=='0')
    {
        return 0;
    }
    if(index>=s.length())
    {
        return 1;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    int one  = 0;
    int two = 0;

    if(s[index]!='0')
    {
        one += solve(index+1,s,dp);
    }
    if(index!=s.length()-1 && s[index]!='0' && stoi(s.substr(index,2))<=26)
    {
        two += solve(index+2,s,dp);
    }
    return dp[index] = one+two;

}

int numWays(string s)
{
    int n = s.length();
    vector<int> dp(n+1,-1);
    return solve(0,s,dp);
}
 
int main()
{
    string s;
    cin >> s;

    
    cout << numWays(s);
}