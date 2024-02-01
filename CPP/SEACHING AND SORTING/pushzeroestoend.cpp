#include <iostream>
using namespace std;

void pushZeroesEnd(int *input, int size)
{
  int count_0 = 0;

    for(int i = 0;i<size;i++)
    {
        if(input[i]==0)
        {
            count_0++;
        }
    }

    int k = 0;
    while(k<(size-count_0))
    {
        for(int i = 0;i<size;i++)
        {
            if(input[i]!=0)
            {
                input[k] = input[i];
                k++;
            }
        }
    }

    for(int i = (size-count_0);i<size;i++)
    {
        input[i] = 0;
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

		pushZeroesEnd(input, size);

		for (int i = 0; i < size; i++)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
}