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
        char startch = 'A' + i - 1;
        while(j<=i)
        {
            char ch = startch + j - 1;
            cout << ch;
            j++;
        }
        cout << endl;
        i++;
    }
}