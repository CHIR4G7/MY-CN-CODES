#include <iostream>
using namespace std;

int main()
{
    int x; //base
    int n; //power

    cin >> x >> n;

    

    int i = 1;
    int prod = 1;

    while (i <= n)
    {
        prod = prod * x;
        i = i + 1;
    }
    cout << prod << endl;
}