#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

void addsub(vector<int> &array, int si, int ei)
{
    bool turn = true; // if true add else subtract
    for (int i = si; i <= ei; i++)
    {
        if (turn == true)
        {
            array[i] = array[i] + 1;
            turn = false;
        }
        else
        {
            array[i] = array[i] - 1;
            turn = true;
        }
    }
}

int main()
{

    int tc;
    cin >> tc;

    while (tc--)
    {

        int n, q;
        cin >> n >> q; // q-number of quries

        // main vector
        vector<int> array;

        for (int i = 0; i < n; i++)
        {
            int c;
            cin >> c;
            array.push_back(c);
        }

        // index containing vector
        vector<vector<int>> queries;

        for (int i = 0; i < q; i++)
        {
            vector<int> a;
            int c;
            cin >> c;
            a.push_back(c);
            cin >> c;
            a.push_back(c);
            queries.push_back(a);
        }

        // performing calculations
        for (int i = 0; i < q; i++)
        {
            addsub(array, (queries[i][0] - 1), (queries[i][1] - 1));
        }

        long long int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum = sum + array[i];
        }
        cout << sum << endl;
    }
}