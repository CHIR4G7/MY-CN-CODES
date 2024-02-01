#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int path(vector<vector<int> > &grid, int row, int col, vector<vector<bool> > &visited)
{
    queue<pair<int, int> > pending;
    pending.push(make_pair(row, col));
    visited[row][col] = true;
    // int sum = grid[row][col];
    int sum = 0;

    while (pending.size() != 0)
    {
        pair<int, int> cell = pending.front();
        sum += grid[cell.first][cell.second];

        pending.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = cell.first + dy[i];
            int y = cell.second + dx[i];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] != 0 && visited[x][y]==false)
            {
                pending.push(make_pair(x, y));
                visited[x][y] = true;
            }
        }
    }
    return sum;
}

int findMaxFish(vector<vector<int> > &grid)
{
    vector<vector<bool> > visited(grid.size(), vector<bool>(grid[0].size(), false));
    int maxi = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] != 0 && visited[i][j] == false)
            {
                int sum = path(grid, i, j, visited);
                maxi = max(maxi, sum);
            }
        }
    }
    return maxi;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int> > grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << findMaxFish(grid);
    // cout << INT_MIN;
}