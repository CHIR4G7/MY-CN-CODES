#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N; // no of rows
    cin >> N;

    int i = 1;
    while (i <= N)
    {
        int j = (N - i + 1);
        int var = 1;

        while (j >= 1)
        {
            cout << var;
            var++;
            j--;
        }

        j = i - 1;
        int stars = 2 * j;
        while (stars != 0)
        {
            cout << "*";
            stars--;
        }

        int k = (N - i + 1);
        while (k >= 1)
        {
            cout << k;
            k--;
        }

        cout << endl;
        i++;
    }
}