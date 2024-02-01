#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int ans  = 0;
    int placevalue = 1;
    
    while(N!=0)
    {
        int rem = N % 10;
        ans = ans + rem * placevalue;
        N = N / 10;
        placevalue = placevalue * 2;
    }
    cout << ans;
}