#include <iostream>
using namespace std;

int main()
{
    int N; //integer
    cin >> N;
    
    int sum_even = 0;
    int sum_odd = 0;
    
    while(N!=0)
    {
        int digit;
        digit  = N % 10;
        N = N / 10;
        
        if(digit%2==0)
        {
            sum_even = sum_even + digit;
        }
        else
        {
            sum_odd = sum_odd + digit;
        }
        digit = 0;
    }
    cout << sum_even << "\t" << sum_odd << endl;
}