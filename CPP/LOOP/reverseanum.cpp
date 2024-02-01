#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int rev = 0;
    
    while(N!=0)
    {
        int rem = N % 10;
        rev = rev * 10 + rem;
        N = N / 10;
        
    }
    cout << rev;
}