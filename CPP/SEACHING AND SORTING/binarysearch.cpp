#include <iostream>
using namespace std;

int binarySearch(int *input, int n, int val)
{
    int start = 0;
    int end = (n - 1);
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (val == input[mid])
        {
            return mid;
        }
        else if (val > input[mid])
        {
            start = mid + 1;
            mid = (start + end) / 2;
        }
        else
        {
            end = mid - 1;
            mid = (start + end) / 2;
        }
    }
    return -1;
}

int main()
{
    int size;
    cin >> size;
    int *input = new int[size];

    for (int i = 0; i < size; ++i)
    {
        cin >> input[i];
    }

    int val;
    cin >> val;
    cout << binarySearch(input, size, val) << endl;

    delete[] input;
    return 0;
}