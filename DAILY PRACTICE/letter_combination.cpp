#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

string keys[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

vector<string> helper(string digits,vector<string> ans,int i,string s)
{
    if(i==digits.length())//i=index on string
    {
        ans.push_back(s);
        return ans;
    }
    string small = keys[digits[i]-'0'];
    for(int j=0;j<small.length();j++)
    {
        helper(digits,ans,i+1,s+small[j]);
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;

}

int main()
{
    string digits;
    cin >> digits;
}