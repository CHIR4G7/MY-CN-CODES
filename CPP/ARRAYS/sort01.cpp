#include <iostream>
using namespace std;

void sortZeroesAndOne(int *input, int size)
{
 for(int i=0;i<size;i++)
    {
        if(input[i]==0)
        {
            continue;
        }
        else 
        {
            for(int j =i+1;j<size;j++)
            {
                if(input[j]==0)
                {
                    int temp = input[i];
                    input[i] = input[j];
                    input[j] = temp;
                }
                else
                {
                    continue;
                }
            }
        }
    }

    
}

// void sortZeroesAndOne(int *input, int size)
// {
//     int count_0 = 0;

//     for(int i = 0;i<size;i++)
//     {
//         if(input[i]==0)
//         {
//             count_0++;
//         }
//     }

//     for(int i = 0;i<(count_0);i++)
//     {
//         input[i] = 0;
//     }

//     for(int i = (count_0);i<size;i++)
//     {
//         input[i] = 1;
//     }

    
// }

int main()
{
    int size;

    cin >> size;
    int *input = new int[size];

    for (int i = 0; i < size; ++i)
    {
        cin >> input[i];
    }

    sortZeroesAndOne(input, size);

    for (int i = 0; i < size; ++i)
    {
        cout << input[i] << " ";
    }

    cout << endl;
    delete[] input;
}