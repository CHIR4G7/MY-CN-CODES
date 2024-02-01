#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int power(int n,int k)
{
    if(k==0)
    {
        return 1;
    }
    int small = power(n,k-1);
    return n*small;
}
 
int main()
{
    int n,k;
    cin >> n >> k;

    cout << power(n,k);
}