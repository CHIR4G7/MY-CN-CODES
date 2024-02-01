#include <iostream>
using namespace std;

void arrange(int *arr, int n)
{

    if (n % 2 == 0)
    {
        for (int i = 0; i < (n / 2); i++)
        {
            arr[i] = (2 * i + 1);
        }
        for (int i = 0; i < (n / 2); i++)
        {
            arr[(n / 2) + i] = (n - (2 * i));
        }
    }

    else
    {
        for (int i = 0; i <= (n / 2); i++)
        {
            arr[i] = (2 * i + 1);
        }
        for (int i = 0; i <= (n / 2 - 1); i++)
        {
            arr[(n / 2 + 1) + i] = ((n - 1) - (2 * i));
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    arrange(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
}