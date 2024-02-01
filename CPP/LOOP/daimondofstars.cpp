#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    if (N % 2 != 0)
    {
        int N1 = (N + 1) / 2;
        int i = 1;
        while (i <= (N1))
        {
            int space_1 = 1;
            while (space_1 <= (N1 - i))
            {
                cout << " ";
                space_1++;
            }
            int j = 1;
            while (j <= (2 * i - 1))
            {
                cout << "*";
                j++;
            }
            cout << endl;
            i++;
        }
        
        int N2 = N1 - 1;
        int m = N2;
        while(m>=1)
        {
            int space_2 = 1;
            while(space_2<=(N2-m+1))
            {
                cout << " ";
                space_2++;
            }

            int k = 1;
            while(k<=(2*m-1))
            {
                cout << "*";
                k++;
            }
            cout <<  endl;
            m--;
        }
    }
}