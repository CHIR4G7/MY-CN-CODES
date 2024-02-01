#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int i = 1;
    while(i<=N)
    {
        //spaces
        int space = 1;
        while(space<=(N-i))
        {
            cout << " ";
            space++;
        }
        
        int j = 1;
        int var = i;//2
        while(j<=i)
        {
            cout << var;
            var++;
            j++;
        }
        
        j = 2 * (i-1);
        while(j>=i)
        {
            cout << j;
            j--;
        }
        cout << endl;
        i++;
    }
}