#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stack>
using namespace std;

int *stockSpan(int *price,int size)
{
    int *Span[size];
    for(int i=0;i<size;i++)
    {
        stack<int> s;
        for(int j=0;j<=i;j++)
        {
            if(price[j]<=price[i])
            {
                s.push()
            }
        }
    }
}
 
int main()
{
    int size;
    cin >> size;

    int price[size];
    for(int i=0;i<size;i++)
    {
        cin >> price[i];
    }
}