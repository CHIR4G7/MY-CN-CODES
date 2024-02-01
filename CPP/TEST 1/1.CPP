#include <iostream>
using namespace std;
 
int main()
{
    int N;
    cin >> N;

    int i = 1;
    while(i<=N)
    {
        int space = 1;
        while(space<=(N-i))
        {
            cout << " ";
            space++;
        }
        int j = 1;
        int var = i;
        while(j<=i)
        {
            cout << var;
            var--;
            j++;
        }

       // j = i - 1;
        var = 2;
        while(var<=i)
        {
            cout << var;
            var++;
        }
      
      
        
       cout << endl;
       i++;
    }
}