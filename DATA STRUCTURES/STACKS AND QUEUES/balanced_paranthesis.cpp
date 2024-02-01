#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string s)
{
    stack<char> check;

    // s[i]=='(' || s[i]=='{' || s[i]=='['
    // s[i]==')' || s[i]=='}' || s[i]==']'

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            check.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (i == 0)
            {
                continue;
            }
            else
            {
                if ((check.top() == '(' && s[i] == ')') || (check.top() == '{' && s[i] == '}') || (check.top() == '[') && s[i] == ']')
                {
                    check.pop();
                }
            }
        }
        else
        {
            continue;
        }
    }
    if (check.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s;
    cin >> s;

    cout << isBalanced(s);
}