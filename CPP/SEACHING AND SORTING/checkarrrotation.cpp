#include <iostream>
using namespace std;

int arrayRotateCheck(int *input, int size)
{
    // Write your code here
    int low = 0, high = size - 1;
    while (low <= high)
    {

        // if first element is mid or
        // last element is mid
        // then simply use modulo so it
        // never goes out of bound.
        int mid = low + (high - low) / 2;
        int prev = (mid - 1 + size) % size;
        int next = (mid + 1) % size;

        if (input[mid] <= input[prev] && input[mid] <= input[next])
            return mid;
        else if (input[mid] <= input[high])
            high = mid - 1;
        else if (input[mid] >= input[low])
            low = mid + 1;
    }
    return 0;
}

int main()
{
    int size;
    cin >> size;
    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    cout << arrayRotateCheck(input, size) << endl;
    delete[] input;
}