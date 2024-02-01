#include <iostream>
using namespace std;

int findSecondLargest(int *input, int n)
{
   int l = -2147483648; //largest
    int sl = -2147483648; //second largest

    for (int i = 0; i < n; i++)
    {
        if (input[i] > l)
        {
            sl = l;
            l = input[i];
        }
        else if (input[i]<l && input[i] > sl)
        {
        
            
                sl = input[i];
            
        }
       
       
    }
    return sl;
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

		cout << findSecondLargest(input, size) << endl;

		delete[] input;
}