#include <iostream>
#include <cstring>
using namespace std;
 
int main()
{
    int N,M; //N-rows,M-cols
    cin >> N >> M;

    int arr[1000][1000];

    for(int i =0;i<N;i++)
    {
        for(int j = 0;j<M;j++)
        {
            cin >> arr[i][j];
        }
    }
    
    //first approach
     for(int i = 0;i<M;i++)
    {
        int sum = 0;
        for(int j = 0;j<N;j++)
        {
            sum  = sum + arr[j][i];

        }
        cout << sum << " ";
    }

    
   //  second approach
   // int i = 0;
   //  while (i < M)
   //  {
   //      int sum = 0;
   //      for (int j = 0; j < N; j++)
   //      {
   //          sum += arr[j][i];
   //      }
   //      cout << sum << " ";
   //      i++;
   //  }
    return 0;
}