#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stack>
using namespace std;

bool checkRedundantBrackets(string expression)
{
    // Write your code here
    stack<int> st;
    if (expression[i] == ')')
    {
        char top = st.top();
        st.pop();
        bool is_it = false; // is the expression redundant.
        if (top == '(')
        {
            is_it = false;
        }
        else
        {
            while (st.empty() == false && top != '(')
            {
                if (top == '+' || top == '-' || top == '*' || top == '/')
                {
                    is_it = true; // signifies that there is a valuable thing in
                                  // bwtween
                }
                top = st.top();
                st.pop();
            }
        }
        if (is_it == false)
        {
            return true;
        }
    }
    else
    {
        st.push(expression[i]);
    }
}
return false;
}

int main()
{
    string s;
    cin >> s;

    cout << countBracketReversals(s);
}