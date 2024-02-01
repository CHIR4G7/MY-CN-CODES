#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stack>
using namespace std;

int countBracketReversals(string input)
{
    int len = input.length();
    if(len%2!=0)
    {
        return -1;
    }
    stack<char> st;
    for(int i=0;i<len;i++)
    {
        if(input[i]=='}' && st.empty()==false)
        {
            if(st.top()=='{')
            {
                st.pop();
            }
            else
            {
                st.push(input[i]);
            }
        }
        else
        {
            st.push(input[i]);
        }
    }
    int red_len = st.size();
    int n = 0;//{
    while(st.empty()==false && st.top()=='{')
    {
        st.pop();
        n++;
    }
    return (red_len/2 + n%2);
}
 
int main()
{
    string s;
    cin >> s;
}