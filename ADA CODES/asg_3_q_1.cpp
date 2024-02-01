#include <iostream>
using namespace std;
#include <stack>

void insertBottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
    }
    else
    {
        int a = s.top();
        s.pop();
        insertBottom(s, x);
        s.push(a);
    }
}

void reverse(stack<int> &s)
{
    if (!s.empty())
    {
        int x = s.top();
        s.pop();
        reverse(s);  // recursive call will continue until the stack is empty.
        insertBottom(s, x);  //Once the stack is empty, the insertBottom() function will be called repeatedly, starting with the last element popped from the stack.
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s.push(a);
    }

    reverse(s);

    for (int i = 0; i < n; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
}
//time complexity: O(n^2)
    //space complexity: O👎