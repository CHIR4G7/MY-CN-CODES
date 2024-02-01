#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

class Item
{
public:
    int value;
    int weight;
};

static bool cmp(Item &i1, Item &i2)
{
    return ((double)i1.value / (double)i1.weight) > ((double)i2.value / (double)i2.weight);
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    sort(arr, arr + n, cmp);
    double profit = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            profit += arr[i].value;
        }
        else
        {
            profit += arr[i].value * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return profit;
}

int main()
{
    int n;
    cin >> n;

    Item *arr = new Item[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].value >> arr[i].weight;
    }

    int w;
    cin >> w;

    cout << fractionalKnapsack(w, arr, n);
}