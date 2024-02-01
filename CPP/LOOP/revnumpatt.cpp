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
        int var = 1;
        while(j<=i)
        {
            cout << i - var + 1;
            j++;
            var++;
        }
        cout << endl;
        i++;
        
    }
}