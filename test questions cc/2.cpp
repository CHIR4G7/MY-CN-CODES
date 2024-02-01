#include <iostream>
using namespace std;

int sumofnnumbers(int n)
{
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        sum+=i;
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;

    while (t > 0)
    {
        int n, k;
        cin >> n >> k;

        if (n < k) // balls less than boxes
        {
            cout << "no" << endl;
        }

        else if (k == 1 && n >= 1) // only one box
        {
            cout << "yes" << endl;
        }

        else if (k == n) // equal no. of balls and boxes
        {
            if (k > 1 && n > 1)
            {
                cout << "no" << endl;
            }
            else
            {
                cout << "yes" << endl;
            }
        }

        else if(n>k)
        {
            if(n>=sumofnnumbers(k))
            {
                cout << "yes" << endl;

            }
            else
            {
                cout << "no" << endl;
            }
           
        }
        t--;
    }
}