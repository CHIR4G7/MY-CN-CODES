#include <iostream>
using namespace std;

// void rotate(int *input, int d, int n)
// {
//     for (int j = 1; j <= d; j++)
//     {
//         int temp = input[0];
//         for (int i = 0; i < (n - 1); i++)
//         {
//             input[i] = input[i + 1];
//         }
//         input[(n - 1)] = temp;
//     }
// }

void rotate(int *input, int d, int n)
{
    
     int temp[d];
    for(int i=0;i<d;i++) 
    {
        temp[i]=input[i];
    }
     for(int i=0;i<n-d;i++)
     {
         input[i]=input[i+d];
     }
    
     for(int i=0;i<d;i++)
     {
         input[n-d+i]=temp[i];
     }
}
 
int main()
{
    int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
}