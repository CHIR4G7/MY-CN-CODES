#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    if(N==1 || N==2)
    {
        cout << "1";
    }
    
    else
    {
        int a = 1;
        int b = 1;
        int c;
        for(int i = 3; i<=N; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        cout << c << endl;
    }
}