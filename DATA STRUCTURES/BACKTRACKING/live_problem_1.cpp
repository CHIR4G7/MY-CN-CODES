#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define N 9

// step-3
bool findEmptyLocation(int grid[N][N], int &row, int &col)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; i++)
        {
            if (grid[i][j] == 0)
            {
                row = i; // passed by refernce
                col = j; // passed by refernce
                return true;
            }
        }
    }
    return false;
}

// step's-4(safe functions)
bool IsSafe_row(int grid[N][N], int row, int val)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == val)
        {
            return false;
        }
    }
    return true;
}

bool IsSafe_col(int grid[N][N], int col, int val)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[i][col] == val)
        {
            return false;
        }
    }
    return true;
}

bool IsSafe_3_3(int grid[N][N], int row, int col, int val)
{
    int rf = (row - (row % 3)); // row factor of the given element
    int cf = (col - (col % 3)); // col factor of the given element
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + rf][j + cf] == val)
            {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int grid[N][N], int row, int col, int val)
{
    if (IsSafe_3_3(grid, row, col, val) && IsSafe_col(grid, col, val) && IsSafe_row(grid, row, val))
    {
        return true;
    }
    return false;
}

// step-2
bool solvesudoku(int grid[N][N])
{
    // find empty location
    int row, col;
    if (!findEmptyLocation(grid, row, col))
    {
        return true;
    }
    // fill value from 1 to 9.
    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(grid, row, col, i))
        {
            grid[row][col] = i;
            if (solvesudoku(grid))
            {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

// step -1
int main()
{
    int grid[N][N];
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            grid[i][j] = s[j] - '0';
        }
    }

    if (solvesudoku(grid))
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
}