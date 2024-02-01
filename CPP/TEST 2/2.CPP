#include <iostream>
using namespace std;

void Leaders(int *arr, int len)
{

    int k = 0;

    for (int i = 0; i < len; i++)
    {
        int count = 0;
        for (int j = (i + 1); j < len; j++)
        {

            if (arr[i] >= arr[j])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        if (count == (len - i - 1))
        {
            cout << arr[i] << " ";
        }
    }
}

int main()
{
    int len;
    cin >> len;
    int *arr = new int[len + 1];

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    Leaders(arr, len);
}
