#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    long place = 1;//int ki jagah long use krna tha kyunki jab bada intger aayga to zyada space lega
    long ans = 0;
    
    while(N!=0)
    {
        int rem = N % 2;
        
        ans = ans + place * rem;
        place = place * 10;
        N = N / 2;
    }
    cout << ans;
}