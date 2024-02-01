#include <iostream>
using namespace std;

bool checkMember(int n)
{

    int a = 0; // f(1)
    int b = 1; // f(2)
    int c;

    for (int i = 3; i <= 100; i++)
    {
        c = a + b;
        a = b;
        b = c;

        if (c == n)
        {
            return true;
            break;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    if (checkMember(n) == true)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}