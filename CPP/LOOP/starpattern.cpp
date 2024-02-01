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
        int temp = 1;
        while(temp<=(2*i-1))
        {
            cout << "*";
            temp++;
        }
        cout << endl;
        i = i + 1;
    }
}