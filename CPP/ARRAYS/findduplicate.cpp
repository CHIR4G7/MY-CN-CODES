#include <iostream>
using namespace std;

int duplicateNumber(int *arr, int size)
{
    for(int i = 0; i<size; i++)
    {
        int flag = 1;
        for(int j = 0;j<size; j++)
        {
            if(i==j)
            {
                continue;
            }
            else
            {
                if(arr[i]==arr[j])
                {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag==0)
        {
            return arr[i];
        }
    }
}
 
int main()
{
    int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << duplicateNumber(input, size) << endl;
}