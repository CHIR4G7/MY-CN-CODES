#include <iostream>
using namespace std;
 
int main()
{
    int t;
    cin >> t;

    while(t>0)
    {
    float x,y;
    cin >> x >> y;

    int a = ((x*3) - y);
    if(a%2==0)
    {
        cout << a / 2 << " " << y << " " << a / 2 << endl;
    }
    else
    {
        cout << "0" << " " << y << " " << a << endl;
    }
    t--;
    }
}