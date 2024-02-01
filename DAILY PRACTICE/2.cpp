#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int main()
{
    long long int n;
    long long int k;
    cin >> n >> k;

    if(n%2==0)
    {
        if(k<(n/2))
        {
            cout << (2*(k)-1) << endl;
        }
        else
        {
            k = k - (n/2) + 1;
            cout << (2*k) << endl;
        }
    }
    else
    {
        if(k<=(n/2))
        {
            cout << (2*(k)-1) << endl;
        }
        else
        {
            k = k - (n/2) - 1;
            cout << (2*k) << endl;
        }
    }

    
}