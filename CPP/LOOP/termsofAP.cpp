#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int count = 1;
    int i = 1;
    
    while(count<=N)
    {
        if((3*i+2)%4!=0)
        {
            cout << (3*i+2) << " ";
            count++;
        }
        i++;
    }
}