#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;

class object
{
public:
    int value;
    int index;
    int arr_num;

    object()
    {
    }
};

vector<int> mergerksortedarrays(vector<vector<int> *> input)
{
   
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < input.size(); i++)
        for (int j = 0; j < input[i]->size(); j++)
            pq.push(input[i]->at(j));
    vector<int> v;
    while (!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}


int main()
{
    vector<vector<int> *> input;
    int k;
    cin >> k;

    for (int j = 1; j <= k; j++)
    {
        int size;
        cin >> size;

        vector<int> *current = new vector<int>;
        for (int i = 0; i < size; i++)
        {
            int a;
            cin >> a;
            current->push_back(a);
        }
    }
}