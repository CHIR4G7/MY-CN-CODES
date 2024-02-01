#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool isMaxHeap(int arr[], int n)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        int pi = i;
        int lci = (2 * (pi) + 1);
        int rci = (2 * (pi) + 2);

        if (lci < n && rci < n)
        {
            if (arr[pi] > arr[lci] && arr[pi] > arr[rci])
            {
                continue;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        else if (lci < n)
        {
            if (arr[pi] < arr[lci])
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)
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
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << isMaxHeap(arr, n) << endl;
}