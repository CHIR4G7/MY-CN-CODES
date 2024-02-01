#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// PRIORTIY QUEUEU IN STL
#include <queue>
#include "MINpriorityqueue.h"
using namespace std;

// MIN HEAP SORT
void heapsort_min(int arr[], int n)
{
    // building a heap (minheap)
    for (int i = 1; i < n; i++)
    {
        int childrenindex = i;

        while (childrenindex > 0)
        {
            int parentindex = (childrenindex - 1) / 2;
            if (arr[childrenindex] < arr[parentindex])
            {
                int temp = arr[childrenindex];
                arr[childrenindex] = arr[parentindex];
                arr[parentindex] = temp;
            }
            else
            {
                break;
            }
            childrenindex = parentindex;
        }
    }

    // calling remove function
    int size = n;
    while (size > 1)
    {

        int temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;

        size--;
        int pi = 0;
        int lci = (2 * (pi) + 1);
        int rci = (2 * (pi) + 2);

        while (lci < size)
        {
            int minindex = pi;
            if (arr[minindex] > arr[lci])
            {
                minindex = lci;
            }
            if (rci < size && arr[minindex] > arr[rci])
            {
                minindex = rci;
            }
            if (minindex == pi)
            {
                break;
            }

            int temp = arr[minindex];
            arr[minindex] = arr[pi];
            arr[pi] = temp;

            pi = minindex;
            lci = (2 * (pi) + 1);
            rci = (2 * (pi) + 2);
        }
    }
}

// MAX HEAP SORT

void heapsort_max(int arr[], int n)
{
    // building a max heap;
    for (int i = 1; i < n; i++)
    {
        int childindex = i;
        while (childindex > 0)
        {
            int pi = (childindex - 1) / 2;
            if (arr[childindex] > arr[pi])
            {
                int temp = arr[childindex];
                arr[childindex] = arr[pi];
                arr[pi] = temp;
            }
            else
            {
                break;
            }
            childindex = pi;
        }
    }

    // removing elements
    int size = n;

    while (size > 1)
    {
        int temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;

        size--;

        int pi = 0;
        int lci = (2 * (pi) + 1);
        int rci = (2 * (pi) + 2);

        while (lci < size)
        {
            int maxindex = pi;
            if (arr[maxindex] < arr[lci])
            {
                maxindex = lci;
            }
            if (rci < size && arr[maxindex] < arr[rci])
            {
                maxindex = rci;
            }
            if (maxindex == pi)
            {
                break;
            }

            int temp = arr[maxindex];
            arr[maxindex] = arr[pi];
            arr[pi] = temp;

            pi = maxindex;
            lci = 2 * ((pi) + 1);
            rci = 2 * ((pi) + 2);
        }
    }
}

int main()
{
    // int arr[] = {2,6,8,5,4,3};
    // heapsort_max(arr, 6);
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // heapsort_min(arr,6);
    //  for (int i = 0; i < 6; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    
}