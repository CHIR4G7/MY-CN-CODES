#include <iostream>
using namespace std;

int main()
{
    int N;
    int choice;
    
    cin >> N;
    cin >> choice;
    
    int sum = 0;
    int product = 1;
    
    if(choice==1)
    {
        for(int i = 1; i<=N; i++)
        {
            sum+=i;
        }
        cout << sum;
    }
    else if(choice==2)
    {
        for(int i = 1; i<=N; i++)
        {
            product*=i;
        }
        cout << product;
    }
    else
    {
        cout << "-1";
    }
    
}

