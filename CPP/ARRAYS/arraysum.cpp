#include <iostream>
using namespace std;
 
int main()
{
    int N;
    cin >> N;

    int arr[100000];
    for(int i = 0; i<N; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    for(int i = 0; i<N; i++)
    {
        sum = sum + arr[i];
    }
    cout << sum;
}