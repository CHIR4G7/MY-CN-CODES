#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

pair<int, int> search(vector<vector<int>> &matrix, int x)
{
    int n = matrix.size();
    int row = 0;
    int si = 0;
    int ei = n - 1;
    pair<int, int> ans = make_pair(-1, -1);

    while (row < n)
    {
        while (si <= ei)
        {
            int mid = (si + ei) / 2;
            if (matrix[row][mid] == x)
            {
                return make_pair(row, mid);
                // return {row,mid};
            }
            else if (matrix[row][mid] > x)
            {
                ei = mid - 1;
            }
            else if (matrix[row][mid] < x)
            {
                si = mid + 1;
            }
        }
        row++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int x;
    cin >> x;

    pair<int, int> ans = search(matrix, x);
    cout << ans.first << " " << ans.second;
}