#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
 
int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        for(int i=31;i>=0;i--)
        {
            if(n&(1<<i))
            {
                cout << (1<<i)-1 << endl;
                break;
            }
        }
    }
}