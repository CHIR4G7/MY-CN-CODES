#include <iostream>
#include <climits>
using namespace std;

void findLargest(int **input, int row, int col)
{
    bool isRow = true;

    int largestSum = INT_MIN;

    int num = 0;

    for (int i = 0; i < row; i++)
    {
        int rowSum = 0;

        for (int j = 0; j < col; j++)
        {
            rowSum += input[i][j];
        }

        if (rowSum > largestSum)
        {
            largestSum = rowSum;

            num = i;
        }
    }
    //////////////////////
    for (int j = 0; j < col; j++)
    {
        int colSum = 0;

        for (int i = 0; i < row; i++)
        {
            colSum += input[i][j];
        }

        if (colSum > largestSum)
        {
            largestSum = colSum;
            num = j;
            isRow = false;
        }
    }

    if (isRow == true)
    {
        cout << "row " << num << " " << largestSum;
    }
    else
    {
        cout << "column " << num << " " << largestSum;
    }
}

int main()
{
    int row, col;
    cin >> row >> col;

    int **input = new int *[row];
    for (int i = 0; i < row; i++)
    {
        input[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            cin >> input[i][j];
        }
    }

    findLargest(input, row, col);
    cout << endl;
}