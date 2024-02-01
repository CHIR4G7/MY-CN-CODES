#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int i = 1;
    while(i<=N)
    {
        int j = 1;
        char startch = 'A';
        while(j<=i)
        {
            char ch = startch + i - 1;
            cout << ch;
            j++;
        }
        cout << endl;
        i++;
    }
}

