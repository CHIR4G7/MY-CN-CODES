#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool isPossible(int x, int y, int rows, int cols)
{
    if (x >= 0 && x < rows && y >= 0 && y < cols)
    {
        return true;
    }
    return false;
}

void solve(vector<vector<int> > &grid, vector<vector<bool> > &visited, int i, int j, int rows, int cols, int &count)
{
    if (i == rows - 1 && j == cols - 1)
    {
        count += 1;
        return;
    }

    if (isPossible(i + 1, j, rows, cols))
    {
        visited[i][j] = true;
        solve(grid,visited,i+1,j,rows,cols,count);
    }
    if(isPossible(i,j+1,rows,cols))
    {
        visited[i][j] = true;
        solve(grid,visited,i,j+1,rows,cols,count);
    }

    visited[i][j] = false;
}

int paths(vector<vector<int> > &grid, int rows, int cols)
{
    vector<vector<bool> > visited(rows, vector<bool>(cols, false));
    int count = 0;
    solve(grid, visited, 0, 0, rows, cols, count);
    return count;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int> > grid(m, vector<int>(n, 1));
    int count = paths(grid, m, n);
    cout << count;
}
