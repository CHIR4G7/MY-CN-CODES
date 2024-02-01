#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

void k_sorted_array(int arr[], int n, int k)
{
    priority_queue<int> pq; // storing the first k-1 elements in the queue

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    // now we have pushed first k elements into the priority queue

    int j = 0; // to keep track of the index in the sorted array where the element has to go

    for (int i = k; i < n; i++)
    {
        arr[j] = pq.top();//storing the topmost element of the pq(heapified and max element is at the top) .
        pq.pop();// and then removing that element from the priority queue cuz we're done with it.
        pq.push(arr[i]);//and then again inserting the new element inside the priority and again making the heap and get max element from it.
        j++;//updateing sorted index;
    }

    while(pq.size()!=0)
    {
        arr[j] = pq.top();
        pq.pop();
        j++;
    }
}

int main()
{
    // maintain a priority queue of size k;
    int arr[] = {10,12,6,7,9};
    k_sorted_array(arr,5,3);
    for(int i=0;i<5;i++)
    {
        cout << arr[i] << " ";
    }
}