#include <iostream>
using namespace std;

int main()
{
    int S; // the starting value
    int E; //the ending value
    int W; //width 
    
    cin >> S;
    cin >> E;
    cin >> W;
    
    int i = S;
    int celsius;
    
    while(i<=E)
    {
        celsius = (5.0/9) * (i - 32);
        cout << i;
        cout << "\t";
        cout << celsius << endl;
        i = i + W;
    }
}