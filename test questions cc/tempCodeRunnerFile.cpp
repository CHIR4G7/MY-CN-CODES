#include <iostream>
using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while (tc > 0)
    {
        int x, y;
        cin >> x >> y;

        int a = ((x * 3) - y);
        if (a >= -1000 && a <= 1000)
        {
            cout << "0"
                 << " " << y << " " << a << endl;
        }
        else
        {
            if (a % 2 == 0)
            {
                cout << a / 2 << " " << y << " " << a / 2 << endl;
            }
            else
            {
                cout << ((a / 2) + 1) << " " << y << " " << ((a / 2) - 1) << endl;
            }
        }
        tc--;
    }
}