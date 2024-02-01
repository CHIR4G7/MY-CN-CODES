#include <iostream>
using namespace std;

void wavePrint(int **input, int nRows, int mCols)
{
    // Write your code here
    int i = 0;
    while (i < mCols)
    {
        if (i % 2 == 0)
        {
            int j = 0;
            while (j < nRows)
            {
                cout << input[j][i] << " ";
                j++;
            }
        }
        else
        {
            int k = (nRows - 1);
            while (k >= 0)
            {
                cout << input[k][i] << " ";
                k--;
            }
        }
        i++;
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
    wavePrint(input, row, col);
    cout << endl;
}