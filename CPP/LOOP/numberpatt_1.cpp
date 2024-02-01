#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int i = 1;
    while(i<=N)
    {
        int j = 1;
        int var = i;
        while(j<=i)
        {
           
           cout << var;
           var = var + 1;
           j = j + 1;

        }
        cout << endl;
        i = i + 1;
    }
}


