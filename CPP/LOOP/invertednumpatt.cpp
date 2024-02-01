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
        int var = N - i + 1;
        while(j<=(N-i+1))
        {
             cout << var;
            j++;
        }
        cout << endl;
        i++;
        var++;
    }
}