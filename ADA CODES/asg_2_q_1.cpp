#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool isPalindrome(string s)
{
    int n = s.length();
    int i = 0;
    int j = n-1;

    while(i<=j)
    {
        if(s[i]!=s[j])
        {
           return false;
        }
        i++;
        j--;
    }
    return true;
}
 
int main()
{
    string s;
    cin >> s;

    cout << isPalindrome(s) << endl;
   
}