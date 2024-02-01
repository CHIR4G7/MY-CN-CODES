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
        int a,b;
        cin >> a >> b;

        for(int i=31;i>=0;i--)
        {
            if(a&(1<<i) && (b&(1<<i)))
            {
                //toggling the bits is done using xor operator
                a = (a^(1<<i));
                b = (b^(1<<i));
            }
        }
        cout << a+b << endl;
    }
    return 0;
}