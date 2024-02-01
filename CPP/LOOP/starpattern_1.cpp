#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int i = 1;
    while(i<=N)
    {
        int space = 1;
        while(space<=(N-i))
        {
            cout << " ";
            space++;
        }
        int j = 1;
        while(j<=(2*i-1))
        {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
}