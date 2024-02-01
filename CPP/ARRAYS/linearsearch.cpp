#include <iostream>
using namespace std;

int linearSearch(int arr[], int N, int X)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == X)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int val;
    cin >> val;
    cout << linearSearch(arr, n, val) << endl;
}