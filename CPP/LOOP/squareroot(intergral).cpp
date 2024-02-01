#include<iostream>
using namespace std;

int main() 
{
	int N;
    cin >> N;
    
    int i = 0;//test case was missed
    while(i<=N)
    {
        if(i*i==N)
        {
            cout << i;
            break;
        }
        if(i*i>N)
        {
            cout << (i-1);
            break;
        }
        i++;
    }
}